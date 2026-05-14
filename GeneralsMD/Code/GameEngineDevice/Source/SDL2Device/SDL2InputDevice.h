#pragma once

#include "IInputDevice.h"
#include <SDL2/SDL.h>
#include <vector>
#include <string>

/**
 * SDL2 Input Device - Phase 4 Implementation
 * Cross-platform input backend using SDL2
 */
class SDL2InputDevice : public IInputDevice
{
public:
    SDL2InputDevice();
    ~SDL2InputDevice() override;

    // IInputDevice Interface
    bool Initialize(void* windowHandle) override;
    void Shutdown() override;
    void Poll() override;

    // Keyboard
    bool IsKeyDown(KeyCode key) const override;
    bool IsKeyUp(KeyCode key) const override;
    bool WasKeyPressed(KeyCode key) const override;
    const char* GetKeyName(KeyCode key) const override;

    // Mouse
    int32_t GetMouseX() const override;
    int32_t GetMouseY() const override;
    int32_t GetMouseDeltaX() const override;
    int32_t GetMouseDeltaY() const override;
    bool IsMouseButtonDown(MouseButton button) const override;
    bool WasMouseButtonPressed(MouseButton button) const override;
    void SetMousePosition(int32_t x, int32_t y) override;
    void ShowCursor(bool show) override;
    bool IsCursorVisible() const override;

    // Gamepad/Joystick
    bool IsGamepadConnected(int32_t index) const override;
    float GetGamepadAxis(int32_t index, GamepadAxis axis) const override;
    bool IsGamepadButtonDown(int32_t index, GamepadButton button) const override;
    bool WasGamepadButtonPressed(int32_t index, GamepadButton button) const override;
    const char* GetGamepadName(int32_t index) const override;
    int32_t GetConnectedGamepadCount() const override;

    // Force Feedback (Rumble)
    void SetGamepadRumble(int32_t index, float lowFreq, float highFreq, uint32_t durationMs) override;
    void StopGamepadRumble(int32_t index) override;

    // Text Input
    void EnableTextInput(bool enable) override;
    bool IsTextInputEnabled() const override;
    const wchar_t* GetTextInputText() const override;

private:
    KeyCode SDLKeyToKeyCode(SDL_Keycode sym) const;
    MouseButton SDLMouseButtonToEnum(uint8_t button) const;
    GamepadButton SDLGamepadButtonToEnum(SDL_GameControllerButton button) const;
    GamepadAxis SDLGamepadAxisToEnum(SDL_GameControllerAxis axis) const;

    bool m_initialized = false;
    bool m_textInputEnabled = false;
    
    int32_t m_mouseX = 0;
    int32_t m_mouseY = 0;
    int32_t m_mouseDeltaX = 0;
    int32_t m_mouseDeltaY = 0;
    uint32_t m_mouseButtons = 0;
    uint32_t m_prevMouseButtons = 0;
    bool m_cursorVisible = true;

    std::vector<uint8_t> m_keyStates;
    std::vector<uint8_t> m_prevKeyStates;
    
    std::vector<SDL_GameController*> m_gamepads;
    std::vector<std::string> m_gamepadNames;
    
    std::wstring m_textInputBuffer;
};
