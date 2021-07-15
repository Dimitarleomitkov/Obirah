#include "../includes/Gameplay.h"

bool NPC_collide (e_Directions direction, Gamespace& gamespace)
{
    // Get the position of the player
    uint16_t x_pos = gamespace.get_player().PositionX();
    uint16_t y_pos = gamespace.get_player().PositionY();

    // Get the encountered NPC
    NPChar dummy_NPC;
    switch (direction) {
        case D_UP:
            dummy_NPC = gamespace.get_NPC (x_pos - 1, y_pos);
            break;
        case D_LEFT:
            dummy_NPC = gamespace.get_NPC (x_pos, y_pos - 1);
            break;
        case D_DOWN:
            dummy_NPC = gamespace.get_NPC (x_pos + 1, y_pos);
            break;
        case D_RIGHT:
            dummy_NPC = gamespace.get_NPC (x_pos, y_pos + 1);
            break;
    }

    switch (gamespace.get_map_level()) {
        case 1:
            if (dummy_NPC.get_name() == "Nira") {
                Nira_1_window (dummy_NPC, gamespace);
            } else if (dummy_NPC.get_name() == "Jack") {
                Jack_1_window (dummy_NPC, gamespace);
            } else if (dummy_NPC.get_name() == "Rick") {
                Rick_1_window (dummy_NPC, gamespace);
            }
            break;
        case 5:
            break;
        default:
            break;
    }

    return false;
}
