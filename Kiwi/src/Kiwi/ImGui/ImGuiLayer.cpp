#include "kwpch.h"
#include "backends/imgui_impl_sdl3.h"
#include "imgui_internal.h"
#include "ImGuiLayer.h"
#include "imgui.h"
#include "Kiwi/Application.h"

namespace Kiwi {
    ImGuiLayer::ImGuiLayer() : Layer("Imgui Layer") {}
    ImGuiLayer::~ImGuiLayer() {}

    void ImGuiLayer::onAttach() {
        ImGui::CreateContext();
        ImGui::StyleColorsDark();

        ImGuiIO& io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

        ImGui_ImplSDL3_InitForVulkan((SDL_Window*)Application::Get().getWindow()->getNativeWindow());
    }
    void ImGuiLayer::onDetach() {
        ImGui::Shutdown();
    }
    void ImGuiLayer::onUpdate() {
        ImGuiIO& io = ImGui::GetIO();
        Application& app = Application::Get();
        io.DisplaySize = ImVec2(app.getWindow()->getWidth(), app.getWindow()->getHeight());

        ImGui_ImplSDL3_NewFrame();
        ImGui::NewFrame();

        bool showDemo = true;
        ImGui::ShowDemoWindow(&showDemo);

        ImGui::Render();
        ImGui::EndFrame();
    }
    void ImGuiLayer::onEvent(Event& event) {}
}
