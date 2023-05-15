#include "framework.hxx"
#include "render/menu.hxx"
#include "common/globals.hxx"

void draw_menu() 
{
    begin_frame();

    ImGui::Begin("My Window");
    if (ImGui::Button("Unload", ImVec2(150, 50))) {
        config::continue_execution = false;
    }
    ImGui::End();

    end_frame();
}

static void begin_frame() 
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
}

static void end_frame() 
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
