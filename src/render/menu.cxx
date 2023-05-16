#include "framework.hxx"
#include "render/menu.hxx"
#include "common/globals.hxx"

void draw_menu() 
{
    GLfloat view_port[4] = { 0 };
    glGetFloatv(GL_VIEWPORT, view_port);

    begin_frame();

    ImGui::SetNextWindowSize({view_port[2]*0.4f, view_port[3]*0.4f}, ImGuiCond_FirstUseEver);
    ImGui::Begin("Menu", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar);
        static const std::vector<std::pair<const char*, void(*)()>> tabs {
            {"ESP", draw_esp_tab},
            {"Aimbot", draw_aimbot_tab},
            {"Misc", draw_misc_tab}
        };

        if (ImGui::BeginTabBar("MainTabs", ImGuiTabBarFlags_NoCloseWithMiddleMouseButton | ImGuiTabBarFlags_NoTabListScrollingButtons | ImGuiTabBarFlags_NoTooltip)) 
        {
            float item_width = ImGui::GetWindowWidth() / tabs.size();

            for (auto [tab_name, drawing_routine] : tabs) {
                ImGui::SetNextItemWidth(item_width);
                if (ImGui::BeginTabItem(tab_name)) {
                    drawing_routine();
                    ImGui::EndTabItem();
                }
            }
            ImGui::EndTabBar();
        }
    ImGui::End();

    end_frame();
}

void begin_frame() 
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
}

void draw_esp_tab() 
{
    ImGui::Text("ESP");
}

void draw_aimbot_tab() 
{
    ImGui::Text("Aimbot");
}

void draw_misc_tab() 
{
    ImGui::Text("Misc");
    if (ImGui::Button("Unload", {150, 30})) {
        config::continue_execution = false;
    }
}

void end_frame() 
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
