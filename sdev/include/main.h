#pragma once

void Main();
extern "C" __declspec(dllexport) void DllExport();

namespace hook
{
    void cmd();
    void custom_game();
    void item_icon();
    void misc();
}

inline int g_showCostume = false;
inline int g_showPet = false;
inline int g_showWings = false;
inline int g_showEft = false;
inline int g_showMobEft = false;
