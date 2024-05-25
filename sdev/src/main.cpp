#include <include/main.h>
#include <util/include/util.h>

void Main()
{
    hook::cmd();
    hook::custom_game();
    hook::item_icon();
    hook::misc();

    float camera_limit = 30.0f;
    util::write_memory((void*)0x7484DC, &camera_limit, sizeof(float));
}
