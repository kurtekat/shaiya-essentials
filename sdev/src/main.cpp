#include <include/main.h>
#include <util/include/util.h>

void Main()
{
    hook::camera_limit();
    hook::cmd();
    hook::custom_game();
    hook::gui();
    hook::item_icon();
    hook::name_color();
    hook::packet();
    hook::vehicle();
}
