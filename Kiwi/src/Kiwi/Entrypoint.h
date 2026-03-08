#pragma once

#include "Application.h"
#include "Log.h"

extern Kiwi::Application* Kiwi::CreateApplication();

int main(int argc, char** argv) {
    Kiwi::Logger::Init();

    auto app = Kiwi::CreateApplication();
    app->run();
    delete app;
}
