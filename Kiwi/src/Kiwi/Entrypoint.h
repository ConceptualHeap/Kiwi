#pragma once

#ifdef KW_PLATFORM_WINDOWS

extern Kiwi::Application* Kiwi::CreateApplication();

int main(int argc, char** argv) {
    Kiwi::Log::Init();
    Kiwi::Log::GetCoreLogger()->warn("Log initialized");
    Kiwi::Log::GetCoreLogger()->info("Hellew :3");

    auto app = Kiwi::CreateApplication();
    app->run();
    delete app;
}

#endif
