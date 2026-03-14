#include <Kiwi.h>

class ExampleLayer : public Kiwi::Layer {
public:
    ExampleLayer() : Layer("Example") {}

    void onUpdate() override {
    }

    void onEvent(Kiwi::Event &e) override {
        KW_TRACE("{}", e.toString());
    }
};

class Sandbox : public Kiwi::Application {
public:
    Sandbox() {
        KW_INFO("Hellew :3");
        pushLayer(new ExampleLayer());
        // Todo
        // pushOverlay(new Kiwi::ImGuiLayer());
    }
    ~Sandbox() {
        KW_INFO("Bai bai :3");
    }
private:
};

Kiwi::Application* Kiwi::CreateApplication() {
    return new Sandbox();
}
