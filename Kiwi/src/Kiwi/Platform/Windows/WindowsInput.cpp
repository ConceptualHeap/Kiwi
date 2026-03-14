#include "kwpch.h"

#ifdef KW_PLATFORM_WINDOWS

#include "Kiwi/Platform/Windows/WindowsWindow.h"
#include "Kiwi/Application.h"
#include "SDL3/SDL_events.h"

#include "WindowsInput.h"

namespace Kiwi {
    Input* Input::s_Instance = new WindowsInput();

    bool WindowsInput::isKeyPressedImpl(int keycode) {
        auto window = (WindowsWindow*)Application::Get().getWindow().get();
        if (window->getEvent().key.down && window->getEvent().key.key == keycode) return true;
        return false;
    }
    bool WindowsInput::isMouseButtonPressedImpl(int button) {
        auto window = (WindowsWindow*)Application::Get().getWindow().get();
        if (window->getEvent().button.down && window->getEvent().button.button == button) return true;
        return false;
    }
    float WindowsInput::getMouseXImpl() {
        auto window = (WindowsWindow*)Application::Get().getWindow().get();
        return window->getEvent().motion.x;
    }
    float WindowsInput::getMouseYImpl() {
        auto window = (WindowsWindow*)Application::Get().getWindow().get();
        return window->getEvent().motion.y;
    }
}

#endif
