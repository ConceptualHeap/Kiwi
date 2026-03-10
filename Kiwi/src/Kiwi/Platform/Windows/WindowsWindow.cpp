#include <kwpch.h>
#include "WindowsWindow.h"
#include "SDL_events.h"
#include "SDL_init.h"
#include "SDL_video.h"
#include "Kiwi/Log.h"

#include "Kiwi/Events/ApplicationEvent.h"
#include "Kiwi/Events/KeyEvent.h"
#include "Kiwi/Events/MouseEvent.h"

namespace Kiwi {
    enum KeyEventType {
        KEY_PRESS = 0,
        KEY_RELEASE,
        KEY_REPEAT
    };

    static bool s_SDLInitialized = false;

    Window* Window::Create(const WindowProps& props) {
#ifdef KW_PLATFORM_WINDOWS
        return new WindowsWindow(props);
#endif
    }

    WindowsWindow::WindowsWindow(const WindowProps& props) {
        init(props);
    }
    WindowsWindow::~WindowsWindow() {
        destroy();
    }

    void WindowsWindow::init(const WindowProps& props) {
        m_Title = props.Title;
        m_Width = props.Width;
        m_Height = props.Height;

        KW_CORE_INFO("Creating window {} {}x{}", props.Title, props.Width, props.Height);

        if (!s_SDLInitialized) {
            bool success = SDL_Init(SDL_INIT_VIDEO);
            KW_CORE_ASSERT(success, "Couldn't initialize SDL!");

            s_SDLInitialized = true;
        }

        m_Window = SDL_CreateWindow(m_Title.c_str(), (int)m_Width, (int)m_Height, SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE);

        // Set Callbacks

        setSizeCallbackFn([&](int width, int height) {
            m_Width = width;
            m_Height = height;

            WindowResizeEvent event(width, height);
            m_EventCallback(event);
        });

        setCloseCallbackFn([&]() {
            WindowCloseEvent event;
            m_EventCallback(event);
        });

        setKeyCallbackFn([&](int key, int type) {
            switch (type) {
                case KEY_PRESS : {
                    KeyPressedEvent event(key, 0);
                    m_EventCallback(event);
                    break;
                }
                case KEY_RELEASE : {
                    KeyReleasedEvent event(key);
                    m_EventCallback(event);
                    break;
                }
                case KEY_REPEAT : {
                    KeyPressedEvent event(key, 1);
                    m_EventCallback(event);
                    break;
                }
            }
        });

        setMouseButtonCallbackFn([&](int button, int type) {
            switch (type) {
                case SDL_EVENT_MOUSE_BUTTON_DOWN : {
                    MouseButtonPressedEvent event(button);
                    m_EventCallback(event);
                    break;
                }
                case SDL_EVENT_MOUSE_BUTTON_UP : {
                    MouseButtonReleasedEvent event(button);
                    m_EventCallback(event);
                    break;
                }
            }
        });

        setScrollCallbackFn([&](float xOffset, float yOffset) {
            MouseScrolledEvent event(xOffset, yOffset);
            m_EventCallback(event);
        });

        setCursorPosCallbackFn([&](float xPos, float yPos) {
            MouseMovedEvent event(xPos, yPos);
            m_EventCallback(event);
        });
    }
    void WindowsWindow::destroy() {
        SDL_DestroyWindow(m_Window);
    }

    void WindowsWindow::onUpdate() {
        SDL_Event event;
        SDL_PollEvent(&event);

        if (event.window.type == SDL_EVENT_QUIT) {
            m_CloseCallbackFn();
        }
        if (event.window.type == SDL_EVENT_WINDOW_RESIZED) {
            int w, h;
            SDL_GetWindowSizeInPixels(m_Window, &w, &h);
            m_SizeCallbackFn(w, h);
        }
        if (event.type == SDL_EVENT_KEY_DOWN && !event.key.repeat) {
            m_KeyCallbackFn(event.key.key, KEY_PRESS);
        }
        if (event.type == SDL_EVENT_KEY_DOWN && event.key.repeat) {
            m_KeyCallbackFn(event.key.key, KEY_REPEAT);
        }
        if (event.type == SDL_EVENT_KEY_UP) {
            m_KeyCallbackFn(event.key.key, KEY_RELEASE);
        }
        if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
            m_MouseButtonCallbackFn(event.button.button, event.type);
        }
        if (event.type == SDL_EVENT_MOUSE_BUTTON_UP) {
            m_MouseButtonCallbackFn(event.button.button, event.type);
        }
        if (event.type == SDL_EVENT_MOUSE_WHEEL) {
            m_ScrollCallbackFn(event.wheel.x, event.wheel.y);
        }
        if (event.type == SDL_EVENT_MOUSE_MOTION) {
            m_CursorPosCallbackFn(event.motion.x, event.motion.y);
        }
    }
}
