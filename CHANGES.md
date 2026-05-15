# C&C Generals Source Code — Bug Fix Changelog

## Overview
This document tracks all bug fixes applied to the C&C Generals source code
based on a comprehensive code review conducted on 2026-05-15.

---

## Critical Fixes (Undefined Behavior / Crashes)

### [FIX-001] Damage.h — Undefined Behavior in Bit Flag Operations
- **File:** `Generals/Code/GameEngine/Include/GameLogic/Damage.h`
- **Bug:** `1UL << (dt - 1)` is undefined behavior when `dt == 0` (DAMAGE_EXPLOSION, DEATH_NORMAL). Shifting by -1 is UB.
- **Fix:** Added early-return guards in all 6 bit flag functions (get/set/clear for both DamageType and DeathType). When `dt == 0`, get returns false, set/clear return flags unchanged.

### [FIX-002] AIUpdate.cpp — Crate Pickup Permanently Broken
- **File:** `Generals/Code/GameEngine/Source/GameLogic/Object/Update/AIUpdate.cpp`
- **Bug:** `m_crateCreated` was set to `INVALID_ID` BEFORE being used in `findObjectByID()`, so the function always searched for INVALID_ID and always returned NULL.
- **Fix:** Save `m_crateCreated` to a local variable before clearing it, then use the saved ID.

### [FIX-003] shdrenderer.cpp — Double-Free in Destructor
- **File:** `GeneralsMD/Code/Libraries/Source/WWVegas/wwshade/shdrenderer.cpp`
- **Bug:** `REF_PTR_RELEASE(MeshCategories[i])` followed by `delete MeshCategories[i]` — double-free since REF_PTR_RELEASE already deletes when ref count hits zero.
- **Fix:** Removed the `delete MeshCategories[i]` line, keeping only `REF_PTR_RELEASE`.

### [FIX-004] PartitionManager.h — Missing Virtual Destructor
- **File:** `Generals/Code/GameEngine/Include/GameLogic/PartitionManager.h`
- **Bug:** `PartitionFilter` is a polymorphic base class with no virtual destructor. Deleting through a base pointer is UB. 15+ derived classes affected.
- **Fix:** Added `virtual ~PartitionFilter() {}` to the class.

### [FIX-005] GameLogic.cpp — Logic Bug in Start Position Assignment
- **File:** `Generals/Code/GameEngine/Source/GameLogic/System/GameLogic.cpp`
- **Bug:** `if (posIdx >= 0 || posIdx >= numPlayers)` — the `||` makes the condition always true for positive values. Should be `&&`.
- **Fix:** Changed to `if (posIdx >= 0 && posIdx < numPlayers)`.

### [FIX-006] GameLogic.cpp — Infinite Loop in Observer Position
- **File:** `Generals/Code/GameEngine/Source/GameLogic/System/GameLogic.cpp`
- **Bug:** `while (posIdx == -1)` loop could spin forever if all start positions are taken.
- **Fix:** Added safety counter with max 100 iterations.

### [FIX-007] strtrim — Undefined Behavior With Overlapping strcpy (4 files)
- **Files:** WinMain.cpp, textureCompress.cpp, buildVersionUpdate.cpp, MapCacheBuilder/WinMain.cpp
- **Bug:** `strcpy(buffer, source)` where source and buffer may overlap — undefined behavior per C standard.
- **Fix:** Replaced with `memmove(buffer, source, strlen(source) + 1)`.

### [FIX-008] Locomotor.cpp — Copy Constructor/Assignment Missing Fields
- **File:** `Generals/Code/GameEngine/Source/GameLogic/Object/Locomotor.cpp`
- **Bug:** Copy constructor missing `m_donutTimer`. Assignment operator missing `m_angleOffset`, `m_offsetIncrement`, `m_donutTimer`.
- **Fix:** Added missing field copies to both functions.

### [FIX-009] SpawnBehavior.cpp — Backwards Duplicate Detection Logic
- **File:** `Generals/Code/GameEngine/Source/GameLogic/Object/Behavior/SpawnBehavior.cpp`
- **Bug:** `if (prevName.compare(*tempName))` returns non-zero for DIFFERENT strings, so the code was skipping unique entries instead of duplicates.
- **Fix:** Changed to `if (!prevName.compare(*tempName))`.

### [FIX-010] AUD_Channel.cpp — Double ListNodeRemove Race Condition
- **File:** `Generals/Code/Libraries/Source/WPAudio/AUD_Device.cpp`
- **Bug:** `audioRemoveChannel` called `ListNodeRemove` twice on the same node — once outside the lock, once inside. Race condition + list corruption.
- **Fix:** Removed the first `ListNodeRemove` and `dev->channels--` from outside the lock; now only done once inside the lock.

---

## Security Fixes

### [FIX-011] CHATAPI.CPP — Format String Vulnerability
- **File:** `GeneralsMD/Code/Tools/PATCHGET/CHATAPI.CPP`
- **Bug:** `sprintf(name, Fetch_String(TXT_TITLE))` uses user-facing string as format argument — stack-based information leak / code execution.
- **Fix:** Changed to `sprintf(name, "%s", Fetch_String(TXT_TITLE))`.

### [FIX-012] CHATAPI.CPP — Division by Zero
- **File:** `GeneralsMD/Code/Tools/PATCHGET/CHATAPI.CPP`
- **Bug:** `(bytesread * 100) / totalsize` divides by zero when totalsize is 0.
- **Fix:** Added guard: `totalsize > 0 ? (bytesread * 100) / totalsize : 0`.

### [FIX-013] CHATAPI.CPP — exit(0) in Window Procedure
- **File:** `GeneralsMD/Code/Tools/PATCHGET/CHATAPI.CPP`
- **Bug:** `exit(0)` in WM_CLOSE handler terminates process without cleanup.
- **Fix:** Replaced with `return 0`.

### [FIX-014] textureCompress.cpp — Command Injection
- **File:** `GeneralsMD/Code/Tools/textureCompress/textureCompress.cpp`
- **Bug:** Filenames passed directly to `system()` — shell metacharacters execute arbitrary commands.
- **Fix:** Wrapped filenames in double quotes in the command string. Added TODO for making nvdxt path configurable.

### [FIX-015] textureCompress.cpp — Wrong CreateFile Error Check
- **File:** `GeneralsMD/Code/Tools/textureCompress/textureCompress.cpp`
- **Bug:** `if (!h)` — CreateFile returns INVALID_HANDLE_VALUE on failure, not NULL.
- **Fix:** Changed to `if (h == INVALID_HANDLE_VALUE)`.

### [FIX-016] blowfish.cpp — Silent Encryption Without Key
- **File:** `Generals/Code/Libraries/Source/WWVegas/WWLib/blowfish.cpp`
- **Bug:** When no key is set, Encrypt() silently copies plaintext to ciphertext and returns success.
- **Fix:** Now returns 0 (error) instead of copying data and returning length.

### [FIX-017] blowfish.cpp — Key Material Not Securely Cleared
- **File:** `Generals/Code/Libraries/Source/WWVegas/WWLib/blowfish.cpp`
- **Bug:** Destructor doesn't securely clear key data from memory.
- **Fix:** Added `memset(P_Encrypt, 0, sizeof(P_Encrypt))` etc. after Submit_Key(NULL, 0).

### [FIX-018] rc4.cpp — Global Static Swap Byte (Thread Safety)
- **File:** `Generals/Code/Libraries/Source/WWVegas/WWLib/rc4.cpp`
- **Bug:** `static unsigned char RC4_Temp_Byte` used in swap macro — not thread-safe, and the macro lacks do/while(0) wrapping.
- **Fix:** Replaced with local variable approach: `do { unsigned char _rc4_tmp = (a); (a) = (b); (b) = _rc4_tmp; } while(0)`.

### [FIX-019] rc4.cpp — Division by Zero with Zero-Length Key
- **File:** `Generals/Code/Libraries/Source/WWVegas/WWLib/rc4.cpp`
- **Bug:** `Prepare_Key` with `key_data_len == 0` causes division by zero.
- **Fix:** Added `if (key_data_len == 0) return;` guard.

---

## Buffer Overflow Fixes

### [FIX-020] wwdebug.cpp — vsprintf With No Length Limit (3 functions)
- **File:** `GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug/wwdebug.cpp`
- **Bug:** `vsprintf(buffer, format, va)` into 4096-byte stack buffer with no length limit. Appears in Printf, Printf_Warning, Printf_Error.
- **Fix:** Replaced with `vsnprintf(buffer, sizeof(buffer), format, va); buffer[sizeof(buffer) - 1] = '\0';`.

### [FIX-021] ini.cpp — Stack Buffer Overflow in Section Name
- **File:** `Generals/Code/Libraries/Source/WWVegas/WWLib/ini.cpp`
- **Bug:** `strcpy(section, buffer)` where section is 64 bytes but buffer can be much larger.
- **Fix:** Changed to `strncpy(section, buffer, sizeof(section) - 1); section[sizeof(section) - 1] = '\0';`.

### [FIX-022] texture.cpp — Buffer Overflow in Texture Name Loading
- **File:** `GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2/texture.cpp`
- **Bug:** `cload.Read(&name, cload.Cur_Chunk_Length())` with no bounds check on 256-byte `name` buffer.
- **Fix:** Added bounds check: verify `chunkLen < sizeof(name)` before reading, and null-terminate.

---

## Shader Fixes

### [FIX-023] UI.hlsl — Syntax Error in Sampler Declaration
- **File:** `GeneralsMD/Shaders/UI.hlsl`
- **Bug:** `SamplerState UI Sampler : register(s0);` — space in identifier name makes this not compile.
- **Fix:** Changed to `SamplerState UISampler : register(s0);`.

### [FIX-024] Unit.hlsl / Terrain.hlsl — Wrong Normal Transformation
- **Files:** `GeneralsMD/Shaders/Unit.hlsl`, `GeneralsMD/Shaders/Terrain.hlsl`
- **Bug:** `mul(input.Normal, (float3x3)World)` — normals must be transformed by inverse transpose of world matrix.
- **Fix:** Changed to `normalize(mul(input.Normal, (float3x3)WorldInverseTranspose))`. Added `WorldInverseTranspose` matrix to Shared.hlsli PerObject cbuffer.

### [FIX-025] Shadows.hlsl — Missing Shadow Bias
- **File:** `GeneralsMD/Shaders/PostProcess/Shadows.hlsl`
- **Bug:** No bias applied causes shadow acne.
- **Fix:** Added `float bias = 0.001f;` and subtracted from `shadowPos.z` in comparison.

### [FIX-026] DLSS.hlsl — Misleading Name + Unused Uniforms
- **File:** `GeneralsMD/Shaders/PostProcess/DLSS.hlsl`
- **Bug:** Named "DLSS" but is just bilinear upscale. Unused Sharpness and JitterOffset uniforms waste GPU resources.
- **Fix:** Added clarifying comment. Removed unused uniforms.

### [FIX-027] Shared.hlsli — Padding Naming + Missing Matrix
- **File:** `GeneralsMD/Shaders/Shared.hlsli`
- **Fix:** Renamed `Padding0` to `_Padding0` with comment. Added `float4x4 WorldInverseTranspose` to PerObject cbuffer.

---

## Threading / Unix Fixes

### [FIX-028] thread.cpp — Unix Threading Was a No-Op
- **File:** `Generals/Code/Libraries/Source/WWVegas/WWLib/thread.cpp`
- **Bug:** On Unix, `Execute()` just returned without starting a thread. `Stop()` and `Set_Priority()` also no-ops.
- **Fix:** Implemented Unix threading using `pthread_create`. Added `Internal_Thread_Function_Posix` static function. Added data race warning comment.

### [FIX-029] mutex.cpp — Unix Mutexes Were No-Ops
- **File:** `Generals/Code/Libraries/Source/WWVegas/WWLib/mutex.cpp`
- **Bug:** On Unix, Lock/Unlock/constructor/destructor all did nothing.
- **Fix:** Implemented Unix mutex support using `pthread_mutex_t`. Constructor uses `pthread_mutex_init`, destructor uses `pthread_mutex_destroy`, Lock uses `pthread_mutex_lock`, Unlock uses `pthread_mutex_unlock`.

---

## Other Fixes

### [FIX-030] Weapon.cpp — NULL Dereference Potential
- **File:** `Generals/Code/GameEngine/Source/GameLogic/Object/Weapon.cpp`
- **Bug:** `stricmp(token, MIN_LABEL)` where token can be NULL from `getNextTokenOrNull()`.
- **Fix:** Added NULL check: `if (token != NULL && stricmp(token, MIN_LABEL) == 0)`.

### [FIX-031] Weapon.cpp — Duplicate UNDERSIZE Constant
- **File:** `Generals/Code/GameEngine/Source/GameLogic/Object/Weapon.cpp`
- **Bug:** `UNDERSIZE` constant defined 3 times in the same file.
- **Fix:** Moved to single file-scope definition.

### [FIX-032] ActiveBody.cpp — Division by Zero
- **File:** `Generals/Code/GameEngine/Source/GameLogic/Object/Body/ActiveBody.cpp`
- **Bug:** `m_currentHealth / m_maxHealth` with no zero check on m_maxHealth.
- **Fix:** Changed to `(m_maxHealth > 0.0f) ? (m_currentHealth / m_maxHealth) : 0.0f`.

### [FIX-033] SpawnBehavior.cpp — Division by Zero
- **File:** `Generals/Code/GameEngine/Source/GameLogic/Object/Behavior/SpawnBehavior.cpp`
- **Bug:** `1.0f / spawnCount` with no zero check.
- **Fix:** Added `if (spawnCount > 0)` guard.

### [FIX-034] sha.cpp — Multiple Issues
- **File:** `Generals/Code/Libraries/Source/WWVegas/WWLib/sha.cpp`
- **Fixes:** `<iostream.h>` → `<iostream>`, min macro parentheses, _rotl n==0 guard, const_cast instead of C-style cast.

### [FIX-035] rawfile.cpp — Unix READ|WRITE Opens Write-Only
- **File:** `Generals/Code/Libraries/Source/WWVegas/WWLib/rawfile.cpp`
- **Bug:** Unix `fopen(Filename, "w")` for READ|WRITE mode truncates and can't read.
- **Fix:** Changed to `fopen(Filename, "w+")`.

### [FIX-036] rawfile.cpp — Transfer_Block_Size Wrong Parentheses
- **File:** `Generals/Code/Libraries/Source/WWVegas/WWLib/rawfile.cpp`
- **Bug:** `(int)((unsigned)UINT_MAX)-16L` parsed as `(int)(UINT_MAX) - 16` instead of `(int)(UINT_MAX - 16)`.
- **Fix:** Corrected parentheses to `(int)((unsigned)UINT_MAX - 16L)`.

### [FIX-037] registry.cpp/h — Method Name Typo
- **Files:** `Generals/Code/Libraries/Source/WWVegas/WWLib/registry.cpp`, `registry.h`
- **Bug:** `Deleta_All_Values` — typo for "Delete".
- **Fix:** Renamed to `Delete_All_Values`.

### [FIX-038] GameLogic.h — Anonymous Enum
- **File:** `Generals/Code/GameEngine/Include/GameLogic/GameLogic.h`
- **Fix:** Named the enum `GameMode` instead of anonymous.

### [FIX-039] WeaponSetUpgrade.h — Wrong Include Guard
- **File:** `Generals/Code/GameEngine/Include/GameLogic/Module/WeaponSetUpgrade.h`
- **Fix:** Changed `__DEFAULTDIE_H_` to `__WEAPONSETUPGRADE_H_`.

### [FIX-040] AITNGuard.h — Uninitialized Pointer
- **File:** `Generals/Code/GameEngine/Include/GameLogic/AITNGuard.h`
- **Bug:** `m_attackState` not initialized in AITNGuardInnerState constructor.
- **Fix:** Added `m_attackState(NULL)` to initializer list.

### [FIX-041] Object.h — const Bool Return Type + Illegal Qualifier
- **File:** `Generals/Code/GameEngine/Include/GameLogic/Object.h`
- **Fix:** Removed `const` from `const Bool` return types. Removed illegal `Object::` qualifier from member declaration inside class.

### [FIX-042] textureCompress.cpp — O(n^2) Case Conversion
- **File:** `GeneralsMD/Code/Tools/textureCompress/textureCompress.cpp`
- **Bug:** Character-by-character `replace` loop is O(n^2).
- **Fix:** Replaced with `std::transform(filename.begin(), filename.end(), filename.begin(), ::tolower)`.

### [FIX-043] buildVersionUpdate.cpp — feof Before fread + Unsafe strtok
- **File:** `GeneralsMD/Code/Tools/buildVersionUpdate/buildVersionUpdate.cpp`
- **Bug:** `feof` before `fread` is a classic C bug. Five consecutive strtok calls without NULL checks.
- **Fix:** Changed to check `fread` return value. Added NULL checks after each strtok call.

### [FIX-044] WinMain.cpp — RegisterClass Without Return Check
- **File:** `GeneralsMD/Code/Main/WinMain.cpp`
- **Bug:** `RegisterClass(&wndClass)` return value not checked.
- **Fix:** Added return value check with error handling.

### [FIX-045] texture.cpp — Use-After-Null in Load_Locked_Surface
- **File:** `GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2/texture.cpp`
- **Bug:** `D3DTexture->Release()` while D3DTexture is still non-NULL (window for dangling access).
- **Fix:** Set D3DTexture to NULL first, then release via saved pointer.

### [FIX-046] VulkanRenderDevice.cpp — Null Device + Empty Formats + Throw
- **File:** `GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2/VulkanBackend/VulkanRenderDevice.cpp`
- **Fixes:** Added null device guard in Shutdown(). Added empty formats check in ChooseSwapSurfaceFormat(). Replaced throw with error logging in frame loop.

### [FIX-047] AUD_StreamBuffering.cpp / AUD_Cache.cpp — Pointer-to-uint Casts
- **Files:** `Generals/Code/Libraries/Source/WPAudio/AUD_StreamBuffering.cpp`, `AUD_Cache.cpp`
- **Bug:** Casting pointers to `uint` truncates on 64-bit platforms.
- **Fix:** Replaced with `uintptr_t` or `reinterpret_cast<uint8_t*>` arithmetic.

---

## CMake / Build System Fixes

### [FIX-048] Root CMakeLists.txt — Deprecated CMake Practices
- **File:** `CMakeLists.txt`
- **Fixes:** Replaced `add_definitions` with `add_compile_definitions`. Replaced `set(CMAKE_CXX_FLAGS ...)` with `add_compile_options`.

### [FIX-049] GeneralsMD CMakeLists.txt — Duplicate Flags
- **File:** `GeneralsMD/CMakeLists.txt`
- **Fix:** Removed duplicate `/fp:precise` flag. Added TODO for `include_directories` → `target_include_directories`.

---

## Test Fixes

### [FIX-050] test_ini_parser.cpp — Meaningless Test
- **File:** `GeneralsMD/Test/Unit/test_ini_parser.cpp`
- **Bug:** `EXPECT_TRUE(true)` — test that can never fail.
- **Fix:** Replaced with `ASSERT_NO_THROW`, added `ParsesSimpleKeyValue` and `HandlesMissingKeys` tests.
