#include <Kiwi.h>

class Sandbox : public Kiwi::Application {
public:
    Sandbox() {}
    ~Sandbox() {}
private:
};

Kiwi::Application* Kiwi::CreateApplication() {
    return new Sandbox();
}
