#pragma once
#include "framework.hxx"
#include "o_functions.hxx"

LRESULT CALLBACK hk_WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK hk_wglSwapBuffers(HDC);
int __cdecl hk_SDL_SetRelativeMouseMode(int);
