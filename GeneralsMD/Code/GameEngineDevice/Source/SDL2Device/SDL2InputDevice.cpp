#include "SDL2InputDevice.h"
#include "CrossPlatform.h"
#include <cstring>
#include <algorithm>

SDL2InputDevice::SDL2InputDevice()
{
    m_keyStates.resize(256, 0);
    m_prevKeyStates.resize(256, 0);
}

SDL2InputDevice::~SDL2InputDevice()
{
    Shutdown();
}

bool SDL2InputDevice::Initialize(void* windowHandle)
{
    if (m_initialized) {
        return true;
    }

    // Initialize SDL video and game controller subsystems
    if (SDL_InitSubSystem(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_HAPTIC) < 0) {
        return false;
    }

    // Initialize keyboard state
    const uint8_t* keyState = SDL_GetKeyboardState(nullptr);
    for (int i = 0; i < 256 && i < SDL_NUM_SCANCODES; i++) {
        m_keyStates[i] = keyState[i];
        m_prevKeyStates[i] = keyState[i];
    }

    // Scan for existing gamepads
    for (int i = 0; i < SDL_NumJoysticks(); i++) {
        if (SDL_IsGameController(i)) {
            SDL_GameController* gc = SDL_GameControllerOpen(i);
            if (gc) {
                m_gamepads.push_back(gc);
                m_gamepadNames.push_back(SDL_GameControllerName(gc));
            }
        }
    }

    m_initialized = true;
    return true;
}

void SDL2InputDevice::Shutdown()
{
    if (!m_initialized) {
        return;
    }

    // Close all gamepads
    for (auto* gc : m_gamepads) {
        if (gc) {
            SDL_GameControllerClose(gc);
        }
    }
    m_gamepads.clear();
    m_gamepadNames.clear();

    SDL_QuitSubSystem(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_HAPTIC);
    m_initialized = false;
}

void SDL2InputDevice::Poll()
{
    if (!m_initialized) {
        return;
    }

    // Store previous states
    m_prevKeyStates = m_keyStates;
    m_prevMouseButtons = m_mouseButtons;
    m_mouseDeltaX = 0;
    m_mouseDeltaY = 0;

    // Get current keyboard state
    const uint8_t* keyState = SDL_GetKeyboardState(nullptr);
    for (int i = 0; i < 256 && i < SDL_NUM_SCANCODES; i++) {
        m_keyStates[i] = keyState[i];
    }

    // Get mouse state
    int x, y;
    uint32_t mask = SDL_GetMouseState(&x, &y);
    m_mouseX = x;
    m_mouseY = y;
    m_mouseButtons = mask;

    // Process SDL events
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_MOUSEMOTION:
                m_mouseDeltaX += event.motion.xrel;
                m_mouseDeltaY += event.motion.yrel;
                break;

            case SDL_TEXTINPUT:
                if (m_textInputEnabled) {
                    // Convert UTF-8 to wide string
                    std::mbstate_t state = std::mbstate_t();
                    const char* mb = event.text.text;
                    size_t len = std::strlen(mb);
                    wchar_t wc;
                    size_t result = std::mbrtowc(&wc, mb, len, &state);
                    if (result > 0) {
                        m_textInputBuffer += wc;
                    }
                }
                break;

            case SDL_CONTROLLERDEVICEADDED:
                if (SDL_IsGameController(event.cdevice.which)) {
                    SDL_GameController* gc = SDL_GameControllerOpen(event.cdevice.which);
                    if (gc) {
                        m_gamepads.push_back(gc);
                        m_gamepadNames.push_back(SDL_GameControllerName(gc));
                    }
                }
                break;

            case SDL_CONTROLLERDEVICEREMOVED:
                for (size_t i = 0; i < m_gamepads.size(); i++) {
                    if (m_gamepads[i] == event.cdevice.which) {
                        SDL_GameControllerClose(m_gamepads[i]);
                        m_gamepads.erase(m_gamepads.begin() + i);
                        m_gamepadNames.erase(m_gamepadNames.begin() + i);
                        break;
                    }
                }
                break;
        }
    }
}

bool SDL2InputDevice::IsKeyDown(KeyCode key) const
{
    if (!m_initialized || static_cast<size_t>(key) >= m_keyStates.size()) {
        return false;
    }
    return m_keyStates[static_cast<size_t>(key)] != 0;
}

bool SDL2InputDevice::IsKeyUp(KeyCode key) const
{
    return !IsKeyDown(key);
}

bool SDL2InputDevice::WasKeyPressed(KeyCode key) const
{
    if (!m_initialized || static_cast<size_t>(key) >= m_keyStates.size()) {
        return false;
    }
    return m_keyStates[static_cast<size_t>(key)] != 0 && 
           m_prevKeyStates[static_cast<size_t>(key)] == 0;
}

const char* SDL2InputDevice::GetKeyName(KeyCode key) const
{
    SDL_Keycode sym = static_cast<SDL_Keycode>(key);
    return SDL_GetKeyName(sym);
}

int32_t SDL2InputDevice::GetMouseX() const
{
    return m_mouseX;
}

int32_t SDL2InputDevice::GetMouseY() const
{
    return m_mouseY;
}

int32_t SDL2InputDevice::GetMouseDeltaX() const
{
    return m_mouseDeltaX;
}

int32_t SDL2InputDevice::GetMouseDeltaY() const
{
    return m_mouseDeltaY;
}

bool SDL2InputDevice::IsMouseButtonDown(MouseButton button) const
{
    uint32_t mask = 0;
    switch (button) {
        case MB_LEFT: mask = SDL_BUTTON_LMASK; break;
        case MB_RIGHT: mask = SDL_BUTTON_RMASK; break;
        case MB_MIDDLE: mask = SDL_BUTTON_MMASK; break;
        case MB_X1: mask = SDL_BUTTON_X1MASK; break;
        case MB_X2: mask = SDL_BUTTON_X2MASK; break;
    }
    return (m_mouseButtons & mask) != 0;
}

bool SDL2InputDevice::WasMouseButtonPressed(MouseButton button) const
{
    uint32_t mask = 0;
    switch (button) {
        case MB_LEFT: mask = SDL_BUTTON_LMASK; break;
        case MB_RIGHT: mask = SDL_BUTTON_RMASK; break;
        case MB_MIDDLE: mask = SDL_BUTTON_MMASK; break;
        case MB_X1: mask = SDL_BUTTON_X1MASK; break;
        case MB_X2: mask = SDL_BUTTON_X2MASK; break;
    }
    return (m_mouseButtons & mask) != 0 && (m_prevMouseButtons & mask) == 0;
}

void SDL2InputDevice::SetMousePosition(int32_t x, int32_t y)
{
    if (m_initialized) {
        SDL_WarpMouseInWindow(nullptr, x, y);
        m_mouseX = x;
        m_mouseY = y;
    }
}

void SDL2InputDevice::ShowCursor(bool show)
{
    m_cursorVisible = show;
    if (show) {
        SDL_ShowCursor(SDL_ENABLE);
    } else {
        SDL_ShowCursor(SDL_DISABLE);
    }
}

bool SDL2InputDevice::IsCursorVisible() const
{
    return m_cursorVisible;
}

bool SDL2InputDevice::IsGamepadConnected(int32_t index) const
{
    return index >= 0 && static_cast<size_t>(index) < m_gamepads.size();
}

float SDL2InputDevice::GetGamepadAxis(int32_t index, GamepadAxis axis) const
{
    if (!IsGamepadConnected(index)) {
        return 0.0f;
    }

    SDL_GameControllerAxis sdlAxis = SDL_CONTROLLER_AXIS_INVALID;
    switch (axis) {
        case GPA_LEFT_STICK_X: sdlAxis = SDL_CONTROLLER_AXIS_LEFTX; break;
        case GPA_LEFT_STICK_Y: sdlAxis = SDL_CONTROLLER_AXIS_LEFTY; break;
        case GPA_RIGHT_STICK_X: sdlAxis = SDL_CONTROLLER_AXIS_RIGHTX; break;
        case GPA_RIGHT_STICK_Y: sdlAxis = SDL_CONTROLLER_AXIS_RIGHTY; break;
        case GPA_TRIGGER_LEFT: sdlAxis = SDL_CONTROLLER_AXIS_TRIGGERLEFT; break;
        case GPA_TRIGGER_RIGHT: sdlAxis = SDL_CONTROLLER_AXIS_TRIGGERRIGHT; break;
    }

    if (sdlAxis == SDL_CONTROLLER_AXIS_INVALID) {
        return 0.0f;
    }

    int16_t value = SDL_GameControllerGetAxis(m_gamepads[index], sdlAxis);
    // Normalize from [-32768, 32767] to [-1.0, 1.0]
    return value / 32767.0f;
}

bool SDL2InputDevice::IsGamepadButtonDown(int32_t index, GamepadButton button) const
{
    if (!IsGamepadConnected(index)) {
        return false;
    }

    SDL_GameControllerButton sdlButton = SDL_CONTROLLER_BUTTON_INVALID;
    switch (button) {
        case GPB_A: sdlButton = SDL_CONTROLLER_BUTTON_A; break;
        case GPB_B: sdlButton = SDL_CONTROLLER_BUTTON_B; break;
        case GPB_X: sdlButton = SDL_CONTROLLER_BUTTON_X; break;
        case GPB_Y: sdlButton = SDL_CONTROLLER_BUTTON_Y; break;
        case GPB_BACK: sdlButton = SDL_CONTROLLER_BUTTON_BACK; break;
        case GPB_GUIDE: sdlButton = SDL_CONTROLLER_BUTTON_GUIDE; break;
        case GPB_START: sdlButton = SDL_CONTROLLER_BUTTON_START; break;
        case GPB_LEFT_STICK: sdlButton = SDL_CONTROLLER_BUTTON_LEFTSTICK; break;
        case GPB_RIGHT_STICK: sdlButton = SDL_CONTROLLER_BUTTON_RIGHTSTICK; break;
        case GPB_LEFT_SHOULDER: sdlButton = SDL_CONTROLLER_BUTTON_LEFTSHOULDER; break;
        case GPB_RIGHT_SHOULDER: sdlButton = SDL_CONTROLLER_BUTTON_RIGHTSHOULDER; break;
        case GPB_DPAD_UP: sdlButton = SDL_CONTROLLER_BUTTON_DPAD_UP; break;
        case GPB_DPAD_DOWN: sdlButton = SDL_CONTROLLER_BUTTON_DPAD_DOWN; break;
        case GPB_DPAD_LEFT: sdlButton = SDL_CONTROLLER_BUTTON_DPAD_LEFT; break;
        case GPB_DPAD_RIGHT: sdlButton = SDL_CONTROLLER_BUTTON_DPAD_RIGHT; break;
    }

    if (sdlButton == SDL_CONTROLLER_BUTTON_INVALID) {
        return false;
    }

    return SDL_GameControllerGetButton(m_gamepads[index], sdlButton) != 0;
}

bool SDL2InputDevice::WasGamepadButtonPressed(int32_t index, GamepadButton button) const
{
    // Simplified implementation - would need to track previous gamepad state
    return IsGamepadButtonDown(index, button);
}

const char* SDL2InputDevice::GetGamepadName(int32_t index) const
{
    if (!IsGamepadConnected(index)) {
        return "";
    }
    return m_gamepadNames[index].c_str();
}

int32_t SDL2InputDevice::GetConnectedGamepadCount() const
{
    return static_cast<int32_t>(m_gamepads.size());
}

void SDL2InputDevice::SetGamepadRumble(int32_t index, float lowFreq, float highFreq, uint32_t durationMs)
{
    if (!IsGamepadConnected(index)) {
        return;
    }

    SDL_Haptic* haptic = SDL_GameControllerGetHaptic(m_gamepads[index]);
    if (haptic) {
        SDL_HapticRumblePlay(haptic, std::max(lowFreq, highFreq), durationMs);
    }
}

void SDL2InputDevice::StopGamepadRumble(int32_t index)
{
    if (!IsGamepadConnected(index)) {
        return;
    }

    SDL_Haptic* haptic = SDL_GameControllerGetHaptic(m_gamepads[index]);
    if (haptic) {
        SDL_HapticStopAll(haptic);
    }
}

void SDL2InputDevice::EnableTextInput(bool enable)
{
    m_textInputEnabled = enable;
    if (enable) {
        SDL_StartTextInput();
    } else {
        SDL_StopTextInput();
        m_textInputBuffer.clear();
    }
}

bool SDL2InputDevice::IsTextInputEnabled() const
{
    return m_textInputEnabled;
}

const wchar_t* SDL2InputDevice::GetTextInputText() const
{
    return m_textInputBuffer.c_str();
}

KeyCode SDL2InputDevice::SDLKeyToKeyCode(SDL_Keycode sym) const
{
    // Map SDL keys to our KeyCode enum
    // This is a simplified mapping
    return static_cast<KeyCode>(sym);
}

MouseButton SDL2InputDevice::SDLMouseButtonToEnum(uint8_t button) const
{
    switch (button) {
        case SDL_BUTTON_LEFT: return MB_LEFT;
        case SDL_BUTTON_RIGHT: return MB_RIGHT;
        case SDL_BUTTON_MIDDLE: return MB_MIDDLE;
        case SDL_BUTTON_X1: return MB_X1;
        case SDL_BUTTON_X2: return MB_X2;
        default: return MB_LEFT;
    }
}

GamepadButton SDL2InputDevice::SDLGamepadButtonToEnum(SDL_GameControllerButton button) const
{
    // Map SDL gamecontroller buttons to our enum
    return static_cast<GamepadButton>(button);
}

GamepadAxis SDL2InputDevice::SDLGamepadAxisToEnum(SDL_GameControllerAxis axis) const
{
    // Map SDL gamecontroller axes to our enum
    return static_cast<GamepadAxis>(axis);
}
