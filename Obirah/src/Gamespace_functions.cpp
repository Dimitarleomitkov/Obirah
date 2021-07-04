#include "../includes/Gamespace.h"

void populate_terrain (Gamespace& gamespace)
{
    unsigned int length = gamespace.get_number_of_npcs ();

    NPChar dummy_npc;
    int x_pos = 0;
    int y_pos = 0;
    int map_width = gamespace.get_map_width ();
    int index = 0;

    // Go through every NPC and populate the tile
    for (unsigned int i = 0; i < length; ++i) {
        dummy_npc = gamespace.get_NPC (i);
        x_pos = dummy_npc.get_position_x ();
        y_pos = dummy_npc.get_position_y ();
        index = x_pos * map_width + y_pos;
        gamespace.set_tile (index, NPC);
    }
}
