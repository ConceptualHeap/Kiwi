#pragma once

#include "SDL_video.h"
#include <Kiwi/Window.h>

namespace Kiwi {
    class WindowsWindow : public Window {
    public:
        WindowsWindow(const WindowProps& props);
        virtual ~WindowsWindow();

        void onUpdate() override;

        inline uint32_t getWidth() const override { return m_Width; }
        inline uint32_t getHeight() const override { return m_Height; }

        inline void setEventCallback(const EventCallbackFn& callback) override { m_EventCallback = callback; }

    private:
        virtual void init(const WindowProps& props);
        virtual void destroy();

        void setSizeCallbackFn(std::function<void(int, int)> fn) { m_SizeCallbackFn = fn; }
        void setCloseCallbackFn(std::function<void(void)> fn) { m_CloseCallbackFn = fn; }
        void setKeyCallbackFn(std::function<void(int, int)> fn) { m_KeyCallbackFn = fn; }
        void setMouseButtonCallbackFn(std::function<void(int, int)> fn) { m_MouseButtonCallbackFn = fn; }
        void setScrollCallbackFn(std::function<void(int, int)> fn) { m_ScrollCallbackFn = fn; }
        void setCursorPosCallbackFn(std::function<void(int, int)> fn) { m_CursorPosCallbackFn = fn; }

    private:
        SDL_Window* m_Window;

        std::string m_Title;
        uint32_t m_Width;
        uint32_t m_Height;

        EventCallbackFn m_EventCallback;

        std::function<void(int, int)> m_SizeCallbackFn;
        std::function<void(void)> m_CloseCallbackFn;
        std::function<void(int, int)> m_KeyCallbackFn;
        std::function<void(int, int)> m_MouseButtonCallbackFn;
        std::function<void(float, float)> m_ScrollCallbackFn;
        std::function<void(float, float)> m_CursorPosCallbackFn;
    };
}
