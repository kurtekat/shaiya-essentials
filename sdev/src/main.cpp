#include <include/main.h>
#include <util/include/util.h>

void Main()
{
    hook::camera_limit();
    hook::cmd();
    hook::custom_game();
    hook::item_icon();
    hook::misc();
    hook::vehicle();
}
