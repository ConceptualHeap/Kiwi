#pragma once

#ifdef KW_PLATFORM_WINDOWS

#include "Kiwi/Input.h"

namespace Kiwi {
    class KIWI_API WindowsInput : public Input {
    protected:
        bool isKeyPressedImpl(int keycode) override;
        bool isMouseButtonPressedImpl(int button) override;
        float getMouseXImpl() override;
        float getMouseYImpl() override;
    };
}

#endif
