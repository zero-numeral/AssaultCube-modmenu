#pragma once

#ifdef DEBUG
    #define _CRT_SECURE_NO_WARNINGS
    #define DEBUG_MSG(...) printf(__VA_ARGS__)
#else
    #define DEBUG_MSG(...)
#endif

#include <iostream>
#include <windows.h>
#include <GL/gl.h>
