#pragma once
#include "framework.hxx"

namespace globals {
    inline HWND game_hwnd;
}

namespace config {
    inline volatile bool continue_execution = true;

    namespace menu {
        inline bool active = true;
    }
}

