#pragma once
#include "framework.hxx"

using wndproc_t = LRESULT (CALLBACK*)(HWND, UINT, WPARAM, LPARAM);
inline wndproc_t o_WndProc;

using wglSwapBuffers_t = BOOL (CALLBACK*)(HDC);
inline wglSwapBuffers_t o_wglSwapBuffers;
