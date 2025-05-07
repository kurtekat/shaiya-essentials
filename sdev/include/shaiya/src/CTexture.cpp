#include "include/shaiya/include/CTexture.h"
using namespace shaiya;

int CTexture::CreateFromFile(CTexture* texture, const char* path, const char* fileName/*.tga*/, int w, int h)
{
    typedef int(__thiscall* LPFN)(CTexture*, const char*, const char*, int, int);
    return (*(LPFN)0x57B560)(texture, path, fileName, w, h);
}
