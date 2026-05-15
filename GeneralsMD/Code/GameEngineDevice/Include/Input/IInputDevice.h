#pragma once
#ifndef __IINPUTDEVICE_H__
#define __IINPUTDEVICE_H__

#include <cstdint>
#include <cstddef>

/**
 * Key codes for keyboard input
 */
enum class KeyCode : uint16_t
{
    Unknown = 0,
    
    // Letters
    A = 1, B, C, D, E, F, G, H, I, J, K, L, M,
    N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
    
    // Numbers
    Num0 = 10, Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9,
    
    // Function keys
    F1 = 20, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
    
    // Special keys
    Escape = 40,
    Space,
    Tab,
    Backspace,
    Enter,
    Shift,
    Ctrl,
    Alt,
    
    // Arrow keys
    Up = 60,
    Down,
    Left,
    Right,
    
    // Modifier keys
    LShift = 70,
    RShift,
    LCtrl,
    RCtrl,
    LAlt,
    RAlt,
    
    // Navigation
    Insert = 80,
    Delete,
    Home,
    End,
    PageUp,
    PageDown,
    
    // Numpad
    NumPad0 = 100,
    NumPad1,
    NumPad2,
    NumPad3,
    NumPad4,
    NumPad5,
    NumPad6,
    NumPad7,
    NumPad8,
    NumPad9,
    NumPadAdd,
    NumPadSubtract,
    NumPadMultiply,
    NumPadDivide,
    NumPadDecimal,
    NumPadEnter,
    
    // Media keys
    PlayPause = 130,
    VolumeUp,
    VolumeDown,
    Mute,
    
    MaxKeyCodes
};

/**
 * Mouse buttons
 */
enum class MouseButton : uint8_t
{
    None = 0,
    Left = 1,
    Right = 2,
    Middle = 3,
    XButton1 = 4,
    XButton2 = 5,
    MaxButtons
};

/**
 * Gamepad axes
 */
enum class GamepadAxis : uint8_t
{
    None = 0,
    LeftStickX = 1,
    LeftStickY = 2,
    RightStickX = 3,
    RightStickY = 4,
    LeftTrigger = 5,
    RightTrigger = 6,
    MaxAxes
};

/**
 * Gamepad buttons
 */
enum class GamepadButton : uint8_t
{
    None = 0,
    A = 1,
    B = 2,
    X = 3,
    Y = 4,
    LeftBumper = 5,
    RightBumper = 6,
    Back = 7,
    Start = 8,
    LeftStick = 9,
    RightStick = 10,
    DPadUp = 11,
    DPadDown = 12,
    DPadLeft = 13,
    DPadRight = 14,
    MaxButtons
};

/**
 * IInputDevice - Abstract Input Device Interface (Phase 1)
 * 
 * This is the core abstraction layer for input backends.
 * Implementations include:
 * - Win32InputDevice (legacy DirectInput/Win32)
 * - SDL2InputDevice (SDL2 cross-platform)
 */
class IInputDevice
{
public:
    virtual ~IInputDevice() = default;

    // Initialization
    virtual bool Initialize(void* windowHandle) = 0;
    virtual void Shutdown() = 0;
    virtual void Poll() = 0;

    // Keyboard
    virtual bool IsKeyDown(KeyCode key) const = 0;
    virtual bool IsKeyUp(KeyCode key) const = 0;
    virtual bool WasKeyPressed(KeyCode key) const = 0;
    virtual const char* GetKeyName(KeyCode key) const = 0;

    // Mouse
    virtual int32_t GetMouseX() const = 0;
    virtual int32_t GetMouseY() const = 0;
    virtual int32_t GetMouseDeltaX() const = 0;
    virtual int32_t GetMouseDeltaY() const = 0;
    virtual bool IsMouseButtonDown(MouseButton button) const = 0;
    virtual bool WasMouseButtonPressed(MouseButton button) const = 0;
    virtual void SetMousePosition(int32_t x, int32_t y) = 0;
    virtual void ShowCursor(bool show) = 0;
    virtual bool IsCursorVisible() const = 0;

    // Gamepad/Joystick
    virtual bool IsGamepadConnected(int32_t index) const = 0;
    virtual float GetGamepadAxis(int32_t index, GamepadAxis axis) const = 0;
    virtual bool IsGamepadButtonDown(int32_t index, GamepadButton button) const = 0;
    virtual bool WasGamepadButtonPressed(int32_t index, GamepadButton button) const = 0;
    virtual const char* GetGamepadName(int32_t index) const = 0;
    virtual int32_t GetConnectedGamepadCount() const = 0;

    // Force Feedback (Rumble)
    virtual void SetGamepadRumble(int32_t index, float lowFreq, float highFreq, uint32_t durationMs) = 0;
    virtual void StopGamepadRumble(int32_t index) = 0;

    // Text Input
    virtual void EnableTextInput(bool enable) = 0;
    virtual bool IsTextInputEnabled() const = 0;
    virtual const wchar_t* GetTextInputText() const = 0;
};

#endif // __IINPUTDEVICE_H__
