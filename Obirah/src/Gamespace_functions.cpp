#include "../includes/Gamespace.h"

void populate_terrain (Gamespace& gamespace)
{
    unsigned int n_npc = gamespace.get_number_of_npcs ();

    NPChar dummy_npc;
    int x_pos = 0;
    int y_pos = 0;
    int map_width = gamespace.get_map_width ();
    int index = 0;

    // Populate the Player tile
    Player dummy_hero;
    dummy_hero = gamespace.get_player ();
    x_pos = dummy_hero.PositionX ();
    y_pos = dummy_hero.PositionY ();
    index = x_pos * map_width + y_pos;
    gamespace.set_tile (index, PLAYER);

    // Go through every NPC and populate the tile
    for (unsigned int i = 0; i < n_npc; ++i) {
        dummy_npc = gamespace.get_NPC (i);
        x_pos = dummy_npc.get_position_x ();
        y_pos = dummy_npc.get_position_y ();
        index = x_pos * map_width + y_pos;
        gamespace.set_tile (index, NPC);
    }

    Enemy dummy_enemy;

    // Go through every Enemy and populate the tile
    for (unsigned int i = 0; i < gamespace.get_number_of_enemies(); ++i) {
        dummy_enemy = gamespace.get_enemy(i);
        x_pos = dummy_enemy.position_X ();
        y_pos = dummy_enemy.position_Y ();
        index = x_pos * map_width + y_pos;
        gamespace.set_tile (index, ENEMY);
    }
}
