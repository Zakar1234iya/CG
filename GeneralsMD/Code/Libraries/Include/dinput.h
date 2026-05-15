#pragma once
#ifndef __DINPUT_H__
#define __DINPUT_H__

/*******************************************************************************
 * dinput.h  —  Compile-time stub for DirectInput scan code constants
 *
 * PURPOSE
 *   Provides the DIK_* keyboard scan code constants required by KeyDefs.h
 *   on non-Windows platforms where <dinput.h> does not exist.
 *
 *   On Windows the real dinput.h (from the DirectX SDK or Windows SDK)
 *   provides these values — this stub is only used when that header is
 *   unavailable.
 *
 *   This header defines ONLY constants — no COM interfaces, no types.
 *   The actual DirectInput runtime is handled by Win32DIKeyboard.cpp on
 *   Windows and SDL2InputDevice.cpp on Linux.
 *
 * CALLERS
 *   - KeyDefs.h : #include <dinput.h> and uses DIK_* constants to define
 *                 the KeyDefType enum.
 ******************************************************************************/

/* ─── DirectInput version ─────────────────────────────────────────────────── */
#ifndef DIRECTINPUT_VERSION
#define DIRECTINPUT_VERSION 0x800
#endif

/* ─── Keyboard scan codes (DIK_*) ─────────────────────────────────────────── */
/* Values taken from the DirectX 8 SDK dinput.h. These are hardware scan   */
/* codes and are the same regardless of platform — they correspond to the   */
/* physical key positions on a standard US PC keyboard.                     */

#define DIK_ESCAPE          0x01
#define DIK_1               0x02
#define DIK_2               0x03
#define DIK_3               0x04
#define DIK_4               0x05
#define DIK_5               0x06
#define DIK_6               0x07
#define DIK_7               0x08
#define DIK_8               0x09
#define DIK_9               0x0A
#define DIK_0               0x0B
#define DIK_MINUS           0x0C    /* - on main keyboard                  */
#define DIK_EQUALS          0x0D    /* = on main keyboard                  */
#define DIK_BACK            0x0E    /* backspace                           */
#define DIK_TAB             0x0F
#define DIK_Q               0x10
#define DIK_W               0x11
#define DIK_E               0x12
#define DIK_R               0x13
#define DIK_T               0x14
#define DIK_Y               0x15
#define DIK_U               0x16
#define DIK_I               0x17
#define DIK_O               0x18
#define DIK_P               0x19
#define DIK_LBRACKET        0x1A
#define DIK_RBRACKET        0x1B
#define DIK_RETURN          0x1C    /* Enter on main keyboard              */
#define DIK_LCONTROL        0x1D
#define DIK_A               0x1E
#define DIK_S               0x1F
#define DIK_D               0x20
#define DIK_F               0x21
#define DIK_G               0x22
#define DIK_H               0x23
#define DIK_J               0x24
#define DIK_K               0x25
#define DIK_L               0x26
#define DIK_SEMICOLON       0x27
#define DIK_APOSTROPHE      0x28
#define DIK_GRAVE           0x29    /* accent grave                       */
#define DIK_LSHIFT          0x2A
#define DIK_BACKSLASH       0x2B
#define DIK_Z               0x2C
#define DIK_X               0x2D
#define DIK_C               0x2E
#define DIK_V               0x2F
#define DIK_B               0x30
#define DIK_N               0x31
#define DIK_M               0x32
#define DIK_COMMA           0x33
#define DIK_PERIOD          0x34
#define DIK_SLASH           0x35
#define DIK_RSHIFT          0x36
#define DIK_NUMPADSTAR      0x37    /* * on numeric keypad                 */
#define DIK_LALT            0x38    /* left Alt                            */
#define DIK_SPACE           0x39
#define DIK_CAPSLOCK        0x3A
#define DIK_F1              0x3B
#define DIK_F2              0x3C
#define DIK_F3              0x3D
#define DIK_F4              0x3E
#define DIK_F5              0x3F
#define DIK_F6              0x40
#define DIK_F7              0x41
#define DIK_F8              0x42
#define DIK_F9              0x43
#define DIK_F10             0x44
#define DIK_NUMLOCK         0x45
#define DIK_SCROLL          0x46    /* Scroll Lock                         */
#define DIK_NUMPAD7         0x47
#define DIK_NUMPAD8         0x48
#define DIK_NUMPAD9         0x49
#define DIK_NUMPADMINUS     0x4A    /* - on numeric keypad                 */
#define DIK_NUMPAD4         0x4B
#define DIK_NUMPAD5         0x4C
#define DIK_NUMPAD6         0x4D
#define DIK_NUMPADPLUS      0x4E    /* + on numeric keypad                 */
#define DIK_NUMPAD1         0x4F
#define DIK_NUMPAD2         0x50
#define DIK_NUMPAD3         0x51
#define DIK_NUMPAD0         0x52
#define DIK_NUMPADPERIOD    0x53    /* . on numeric keypad                 */

/* ─── Extended / interspersed scan codes ──────────────────────────────────── */
#define DIK_F11             0x57
#define DIK_F12             0x58

#define DIK_NUMPADENTER     0x9C    /* Enter on numeric keypad             */
#define DIK_RCONTROL        0x9D

#define DIK_NUMPADSLASH     0xB5    /* / on numeric keypad                 */
#define DIK_SYSRQ           0xB7
#define DIK_RALT            0xB8

#define DIK_HOME            0xC7
#define DIK_UPARROW         0xC8
#define DIK_PGUP            0xC9
#define DIK_LEFTARROW       0xCB
#define DIK_RIGHTARROW      0xCD
#define DIK_END             0xCF
#define DIK_DOWNARROW       0xD0
#define DIK_PGDN            0xD1
#define DIK_INSERT          0xD2
#define DIK_DELETE          0xD3

/* ─── International / OEM keys (guarded in KeyDefs.h with #ifndef) ──────── */
#ifndef DIK_OEM_102
#define DIK_OEM_102        0x56    /* < > | on UK/Germany keyboards       */
#endif

#ifndef DIK_KANA
#define DIK_KANA           0x70    /* (Japanese keyboard)                 */
#endif

#ifndef DIK_CONVERT
#define DIK_CONVERT        0x79    /* (Japanese keyboard)                 */
#endif

#ifndef DIK_NOCONVERT
#define DIK_NOCONVERT      0x7B    /* (Japanese keyboard)                 */
#endif

#ifndef DIK_YEN
#define DIK_YEN            0x7D    /* (Japanese keyboard)                 */
#endif

#ifndef DIK_CIRCUMFLEX
#define DIK_CIRCUMFLEX     0x90    /* (Japanese keyboard)                 */
#endif

#ifndef DIK_KANJI
#define DIK_KANJI          0x94    /* (Japanese keyboard)                 */
#endif

#endif /* __DINPUT_H__ */
