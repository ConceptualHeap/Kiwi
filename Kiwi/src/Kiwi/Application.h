#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"
#include "LayerStack.h"

namespace Kiwi {

    class KIWI_API Application {
    public:
        Application();
        virtual ~Application();

        void run();

        void onEvent(Event& e);

        inline void pushLayer(Layer* layer) { m_LayerStack.pushLayer(layer); }
        inline void pushOverlay(Layer* layer) { m_LayerStack.pushOverlay(layer); }

        inline std::unique_ptr<Window>& getWindow() { return m_Window; }
        inline static Application& Get() { return *s_Instance; }

    private:
        bool onWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;

        static Application* s_Instance;
    };

    Application* CreateApplication();

}
