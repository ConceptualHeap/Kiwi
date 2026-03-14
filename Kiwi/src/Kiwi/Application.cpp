#include "Kiwi/Input.h"
#include "SDL3/SDL_keycode.h"
#include "kwpch.h"

#include "Application.h"
#include "Log.h"

namespace Kiwi {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application* Application::s_Instance = NULL;

    Application::Application() {
        s_Instance = this;

        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->setEventCallback(BIND_EVENT_FN(onEvent));
    }

    Application::~Application() {}

    void Application::onEvent(Event& e) {
        EventDispatcher dispatcher(e);
        dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); ) {
            (*--it)->onEvent(e);
            if (e.isHandled()) {
                break;
            }
        }
    }

    void Application::run() {
        while (m_Running) {
            for (Layer* layer : m_LayerStack) {
                layer->onUpdate();
            }

            if (Input::IsKeyPressed(SDLK_ESCAPE)) m_Running = false;

            m_Window->onUpdate();
        }
    }

    bool Application::onWindowClose(WindowCloseEvent& event) {
        m_Running = false;
        return true;
    }

}
