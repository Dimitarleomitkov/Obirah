#include "../includes/Gameplay.h"
#include <string>

bool Enemy_collide (e_Directions direction, Gamespace& gamespace)
{
    std::string msg = "You have encountered ";
    msg += gamespace.get_enemy(0).get_name();
    msg += ".";
    gamespace.set_message (msg);

    return true;
}
