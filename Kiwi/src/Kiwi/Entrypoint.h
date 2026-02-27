#pragma once

#ifdef KW_PLATFORM_WINDOWS

extern Kiwi::Application* Kiwi::CreateApplication();

int main(int argc, char** argv) {
    auto app = Kiwi::CreateApplication();
    app->run();
    delete app;
}

#endif
