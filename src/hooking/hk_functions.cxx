#include "hooking/hk_functions.hxx"
#include "render/imgui.hxx"
#include "render/menu.hxx"
#include "common/globals.hxx"

LRESULT CALLBACK hk_WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    using namespace config;

    switch (msg) 
    {
    case WM_KEYDOWN:
        if (wParam == VK_INSERT) {
            menu::active ^= true;
            o_SDL_SetRelativeMouseMode(!menu::active);
        }   
    }

    if (menu::active) {
        ImGui_ImplWin32_WndProcHandler(hwnd, msg, wParam, lParam);
        return 1;
    }

    return CallWindowProc(o_WndProc, hwnd, msg, wParam, lParam);
}

BOOL CALLBACK hk_wglSwapBuffers(HDC hdc) 
{
    using namespace config;

    static bool imgui_initialized = false;
    if (!imgui_initialized) {
        imgui_initialized = true;
        initialize_imgui();
    }

    if (menu::active) {
        draw_menu();
    }

    return o_wglSwapBuffers(hdc);
}

int __cdecl hk_SDL_SetRelativeMouseMode(int enable) 
{
    using namespace config;

    if (menu::active) {
        enable = 0;
    }

    return o_SDL_SetRelativeMouseMode(enable);
}
