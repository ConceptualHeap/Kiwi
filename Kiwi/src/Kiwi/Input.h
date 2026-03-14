#pragma once

#include "Kiwi/Core.h"

namespace Kiwi {

    class KIWI_API Input {
    public:
        static inline bool IsKeyPressed(int button) { return s_Instance->isKeyPressedImpl(button); }
        static inline bool IsMouseButtonPressed(int button) { return s_Instance->isMouseButtonPressedImpl(button); }
        static inline float GetMouseX() { return s_Instance->getMouseXImpl(); }
        static inline float GetMouseY() { return s_Instance->getMouseYImpl(); }

    protected:
        virtual bool isKeyPressedImpl(int keycode) = 0;
        virtual bool isMouseButtonPressedImpl(int button) = 0;
        virtual float getMouseXImpl() = 0;
        virtual float getMouseYImpl() = 0;

    private:
        static Input* s_Instance;
    };

}
