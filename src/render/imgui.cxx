#include "render/imgui.hxx"
#include "common/globals.hxx"

void initialize_imgui() {
    ImGui::CreateContext();

    ImGui_ImplWin32_Init(globals::game_hwnd);
    ImGui_ImplOpenGL3_Init();
}

void deinitialize_imgui() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
}