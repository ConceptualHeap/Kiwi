#pragma once

#include "Event.h"

namespace Kiwi {
    class KIWI_API MouseMovedEvent : public Event {
    public:
        MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}
        inline float getX() const { return m_MouseX; }
        inline float getY() const { return m_MouseY; }
        std::string toString() const override {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseMoved);
        EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);
    private:
        float m_MouseX;
        float m_MouseY;
    };

    class KIWI_API MouseButtonEvent : public Event {
    public:
        inline int getMouseButton() const { return m_Button; }
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
    protected:
        MouseButtonEvent(int button) : m_Button(button) {}
        int m_Button;
    };

    class KIWI_API MouseButtonPressedEvent : public MouseButtonEvent {
    public:
        MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}
        std::string toString() const override {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_Button;
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseButtonPressed);
    };

    class KIWI_API MouseButtonReleasedEvent : public MouseButtonEvent {
    public:
        MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}
        std::string toString() const override {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_Button;
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseButtonReleased);
    };
}
