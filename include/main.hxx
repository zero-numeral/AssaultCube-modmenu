#pragma once
#include "framework.hxx"
#include "MinHook.h"
#include "common/globals.hxx"
#include "hooking/hk_functions.hxx"
#include "render/imgui.hxx"

void mainloop();
void clean_up();
bool initialize();
void CALLBACK start(HMODULE);
BOOL WINAPI enumerate_windows(HWND, LPARAM);
