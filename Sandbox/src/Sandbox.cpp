#include <Kiwi.h>

class Sandbox : public Kiwi::Application {
public:
    Sandbox() {
        KW_INFO("Hellew :3");
    }
    ~Sandbox() {
        KW_INFO("Bai bai :3");
    }
private:
};

Kiwi::Application* Kiwi::CreateApplication() {
    return new Sandbox();
}
