#include "kwpch.h"

#include "Application.h"
#include "Kiwi/Events/ApplicationEvent.h"
#include "Log.h"

namespace Kiwi {
    Application::Application() {}

    Application::~Application() {}

    void Application::run() {
        WindowResizeEvent e(1366, 768);
        KW_CORE_TRACE("{}", e.toString());

        while (true) {}
    }

}
