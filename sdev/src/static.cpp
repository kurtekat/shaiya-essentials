#include <include/static.h>
using namespace shaiya;

void Static::DrawRect(D3DCOLOR argb, long x, long y, long w, long h)
{
    typedef void(__cdecl* LPFN)(D3DCOLOR, long, long, long, long);
    (*(LPFN)0x4B6180)(argb, x, y, w, h);
}

void Static::GetMsg(int type, int line, int unknown)
{
    typedef void(__cdecl* LPFN)(int, int, int);
    (*(LPFN)0x423150)(type, line, unknown);
}

void Static::PlayWav(const char* filename, D3DVECTOR* pos, float volume, bool repeat)
{
    typedef void(__thiscall* LPFN)(void*, const char*, D3DVECTOR*, float, bool);
    (*(LPFN)0x56C650)((void*)0x22B4030, filename, pos, volume, repeat);
}
