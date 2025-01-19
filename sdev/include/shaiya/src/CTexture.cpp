#include "include/shaiya/include/CTexture.h"
using namespace shaiya;

BOOL CTexture::CreateFromFile(CTexture* texture, const char* path, const char* fileName/*.tga*/, long w, long h)
{
    typedef BOOL(__thiscall* LPFN)(CTexture*, const char*, const char*, long, long);
    return (*(LPFN)0x57B560)(texture, path, fileName, w, h);
}
