#pragma once

#include <kwpch.h>
#include <Kiwi/Core.h>
#include <Kiwi/Events/Event.h>

namespace Kiwi {
    struct WindowProps {
        std::string Title;
        uint32_t Width;
        uint32_t Height;

        WindowProps(const std::string& title = "Kiwi Engine", uint32_t width = 1280, uint32_t height = 720)
            : Title(title), Width(width), Height(height) {}
    };

    class KIWI_API Window {
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() {}

        virtual void onUpdate() = 0;

        virtual uint32_t getWidth() const = 0;
        virtual uint32_t getHeight() const = 0;
        virtual void* getNativeWindow() const = 0;

        virtual void setEventCallback(const EventCallbackFn& callback) = 0;

        static Window* Create(const WindowProps& props = WindowProps());
    };
}
