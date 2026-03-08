#pragma once

#include "Core.h"

namespace Kiwi {

    class KIWI_API Application {
        public:
        Application();
        ~Application();

        void run();
        private:
    };

    Application* CreateApplication();

}
