#include "main.hxx"

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,
    DWORD fdwReason,
    LPVOID lpvReserved)
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hinstDLL);
        EnumWindows(enumerate_windows, GetCurrentProcessId());
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)start, hinstDLL, 0, 0);
    }

    return TRUE;
}

BOOL WINAPI enumerate_windows(HWND hWnd, LPARAM lParam)
{
	DWORD dwProcessId(NULL);
	GetWindowThreadProcessId(hWnd, &dwProcessId);
 
	if(dwProcessId == lParam)
	{
		globals::game_hwnd = hWnd;
		return FALSE;
	}
 
	return TRUE;
}

void CALLBACK start(HMODULE hLibModule)
{
#ifdef DEBUG
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
#endif

    bool success = initialize();
    if (success) {
        mainloop();
    }
    clean_up();

#ifdef DEBUG
    Sleep(5000);
    fclose(stdout);
    FreeConsole();
#endif

    FreeLibraryAndExitThread(hLibModule, 0);
}
 
bool initialize() 
{
    o_WndProc = (wndproc_t)SetWindowLongPtr(globals::game_hwnd, GWLP_WNDPROC, (LONG_PTR)hk_WndProc);

    if (MH_Initialize() != MH_OK) {
        DEBUG_MSG("minhook init error");
        return false;
    }

    if (MH_CreateHookApi(L"opengl32.dll", "wglSwapBuffers", reinterpret_cast<LPVOID>(hk_wglSwapBuffers), reinterpret_cast<LPVOID*>(&o_wglSwapBuffers)) != MH_OK) {
        DEBUG_MSG("wglSwapBuffers hook error");
        return false;
    }

    if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) {
        DEBUG_MSG("error occurred while enabling hooks");
        return false;
    }

    return true;
}

void mainloop() 
{
    while (config::continue_execution) {
        Sleep(100);
    }
}

void clean_up() 
{
    MH_Uninitialize();
    SetWindowLongPtr(globals::game_hwnd, GWLP_WNDPROC, (LONG_PTR)o_WndProc);
    deinitialize_imgui();
}