#pragma once

#include "Kiwi/Core.h"
#include "Kiwi/Events/Event.h"

namespace Kiwi {
    class KIWI_API Layer {
    public:
        Layer(const std::string& name = "Layer") : m_DebugName(name) {}
        virtual ~Layer() {}

        virtual void onAttach() {}
        virtual void onDetach() {}
        virtual void onUpdate() {}
        virtual void onEvent(Event& e)  {}

        inline const std::string& getName() const { return m_DebugName; }

    protected:
        std::string m_DebugName;
    };
}
