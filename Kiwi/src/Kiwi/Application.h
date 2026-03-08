#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Kiwi {

    class KIWI_API Application {
        public:
        Application();
        virtual ~Application();

        void run();
        private:
    };

    Application* CreateApplication();

}
