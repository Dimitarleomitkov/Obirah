#include "../includes/Gamespace.h"
#include "../includes/Terrain.h"
#include "../includes/Npc.h"

void CreateLevel1 (Gamespace& gamespace)
{
    // Despawn the NPCs
    gamespace.despawn_npcs ();

    // Clear all tiles
    gamespace.clear_tiles ();

    // Set the height and width for the level
    gamespace.set_map_width (12);
    gamespace.set_map_height (12);

    // Make a working copy of the width and height for this function
    uint8_t map_width = gamespace.get_map_width ();
    uint8_t map_height = gamespace.get_map_height ();

    // Create the map
    uint16_t* dummy_map_tiles = new uint16_t[map_width * map_height];

    dummy_map_tiles[0 * 12 + 0] = DOWNWALL;
    dummy_map_tiles[0 * 12 + 1] = DOWNWALL;
    dummy_map_tiles[0 * 12 + 2] = DOWNWALL;
    dummy_map_tiles[0 * 12 + 3] = DOWNWALL;
    dummy_map_tiles[0 * 12 + 4] = DOWNWALL;
    dummy_map_tiles[0 * 12 + 5] = DOWNWALL;
    dummy_map_tiles[0 * 12 + 6] = DOWNWALL;
    dummy_map_tiles[0 * 12 + 7] = DOWNWALL;
    dummy_map_tiles[0 * 12 + 8] = DOWNWALL;
    dummy_map_tiles[0 * 12 + 9] = DOWNWALL;
    dummy_map_tiles[0 * 12 + 10] = DOWNWALL;
    dummy_map_tiles[0 * 12 + 11] = DOWNWALL;
    dummy_map_tiles[1 * 12 + 0] = WALL;
    dummy_map_tiles[1 * 12 + 1] = EMPTY;
    dummy_map_tiles[1 * 12 + 2] = EMPTY;
    dummy_map_tiles[1 * 12 + 3] = EMPTY;
    dummy_map_tiles[1 * 12 + 4] = EMPTY;
    dummy_map_tiles[1 * 12 + 5] = EMPTY;
    dummy_map_tiles[1 * 12 + 6] = BUSH;
    dummy_map_tiles[1 * 12 + 7] = WALL;
    dummy_map_tiles[1 * 12 + 8] = EMPTY;
    dummy_map_tiles[1 * 12 + 9] = EMPTY;
    dummy_map_tiles[1 * 12 + 10] = EMPTY;
    dummy_map_tiles[1 * 12 + 11] = WALL;
    dummy_map_tiles[2 * 12 + 0] = WALL;
    dummy_map_tiles[2 * 12 + 1] = DOWNWALL;
    dummy_map_tiles[2 * 12 + 2] = DOWNWALL;
    dummy_map_tiles[2 * 12 + 3] = DOWNWALL;
    dummy_map_tiles[2 * 12 + 4] = DOWNWALL;
    dummy_map_tiles[2 * 12 + 5] = EMPTY;
    dummy_map_tiles[2 * 12 + 6] = EMPTY;
    dummy_map_tiles[2 * 12 + 7] = WALL;
    dummy_map_tiles[2 * 12 + 8] = EMPTY;
    dummy_map_tiles[2 * 12 + 9] = EMPTY;
    dummy_map_tiles[2 * 12 + 10] = EMPTY;
    dummy_map_tiles[2 * 12 + 11] = WALL;
    dummy_map_tiles[3 * 12 + 0] = WALL;
    dummy_map_tiles[3 * 12 + 1] = EMPTY;
    dummy_map_tiles[3 * 12 + 2] = EMPTY;
    dummy_map_tiles[3 * 12 + 3] = EMPTY;
    dummy_map_tiles[3 * 12 + 4] = WALL;
    dummy_map_tiles[3 * 12 + 5] = EMPTY;
    dummy_map_tiles[3 * 12 + 6] = EMPTY;
    dummy_map_tiles[3 * 12 + 7] = WALL;
    dummy_map_tiles[3 * 12 + 8] = EMPTY;
    dummy_map_tiles[3 * 12 + 9] = EMPTY;
    dummy_map_tiles[3 * 12 + 10] = EMPTY;
    dummy_map_tiles[3 * 12 + 11] = WALL;
    dummy_map_tiles[4 * 12 + 0] = WALL;
    dummy_map_tiles[4 * 12 + 1] = EMPTY;
    dummy_map_tiles[4 * 12 + 2] = EMPTY;
    dummy_map_tiles[4 * 12 + 3] = EMPTY;
    dummy_map_tiles[4 * 12 + 4] = DOOR;
    dummy_map_tiles[4 * 12 + 5] = EMPTY;
    dummy_map_tiles[4 * 12 + 6] = EMPTY;
    dummy_map_tiles[4 * 12 + 7] = DOWNWALL;
    dummy_map_tiles[4 * 12 + 8] = DOOR;
    dummy_map_tiles[4 * 12 + 9] = DOWNWALL;
    dummy_map_tiles[4 * 12 + 10] = DOWNWALL;
    dummy_map_tiles[4 * 12 + 11] = WALL;
    dummy_map_tiles[5 * 12 + 0] = WALL;
    dummy_map_tiles[5 * 12 + 1] = EMPTY;
    dummy_map_tiles[5 * 12 + 2] = EMPTY;
    dummy_map_tiles[5 * 12 + 3] = EMPTY;
    dummy_map_tiles[5 * 12 + 4] = WALL;
    dummy_map_tiles[5 * 12 + 5] = EMPTY;
    dummy_map_tiles[5 * 12 + 6] = EMPTY;
    dummy_map_tiles[5 * 12 + 7] = EMPTY;
    dummy_map_tiles[5 * 12 + 8] = EMPTY;
    dummy_map_tiles[5 * 12 + 9] = EMPTY;
    dummy_map_tiles[5 * 12 + 10] = EMPTY;
    dummy_map_tiles[5 * 12 + 11] = WALL;
    dummy_map_tiles[6 * 12 + 0] = WALL;
    dummy_map_tiles[6 * 12 + 1] = DOWNWALL;
    dummy_map_tiles[6 * 12 + 2] = DOWNWALL;
    dummy_map_tiles[6 * 12 + 3] = DOWNWALL;
    dummy_map_tiles[6 * 12 + 4] = WALL;
    dummy_map_tiles[6 * 12 + 5] = EMPTY;
    dummy_map_tiles[6 * 12 + 6] = PLAYER;
    dummy_map_tiles[6 * 12 + 7] = EMPTY;
    dummy_map_tiles[6 * 12 + 8] = EMPTY;
    dummy_map_tiles[6 * 12 + 9] = EMPTY;
    dummy_map_tiles[6 * 12 + 10] = EMPTY;
    dummy_map_tiles[6 * 12 + 11] = WALL;
    dummy_map_tiles[7 * 12 + 0] = WALL;
    dummy_map_tiles[7 * 12 + 1] = EMPTY;
    dummy_map_tiles[7 * 12 + 2] = EMPTY;
    dummy_map_tiles[7 * 12 + 3] = EMPTY;
    dummy_map_tiles[7 * 12 + 4] = EMPTY;
    dummy_map_tiles[7 * 12 + 5] = EMPTY;
    dummy_map_tiles[7 * 12 + 6] = EMPTY;
    dummy_map_tiles[7 * 12 + 7] = EMPTY;
    dummy_map_tiles[7 * 12 + 8] = EMPTY;
    dummy_map_tiles[7 * 12 + 9] = EMPTY;
    dummy_map_tiles[7 * 12 + 10] = EMPTY;
    dummy_map_tiles[7 * 12 + 11] = WALL;
    dummy_map_tiles[8 * 12 + 0] = WALL;
    dummy_map_tiles[8 * 12 + 1] = EMPTY;
    dummy_map_tiles[8 * 12 + 2] = EMPTY;
    dummy_map_tiles[8 * 12 + 3] = EMPTY;
    dummy_map_tiles[8 * 12 + 4] = EMPTY;
    dummy_map_tiles[8 * 12 + 5] = EMPTY;
    dummy_map_tiles[8 * 12 + 6] = EMPTY;
    dummy_map_tiles[8 * 12 + 7] = EMPTY;
    dummy_map_tiles[8 * 12 + 8] = EMPTY;
    dummy_map_tiles[8 * 12 + 9] = EMPTY;
    dummy_map_tiles[8 * 12 + 10] = TREE;
    dummy_map_tiles[8 * 12 + 11] = WALL;
    dummy_map_tiles[9 * 12 + 0] = WALL;
    dummy_map_tiles[9 * 12 + 1] = EMPTY;
    dummy_map_tiles[9 * 12 + 2] = TREE;
    dummy_map_tiles[9 * 12 + 3] = EMPTY;
    dummy_map_tiles[9 * 12 + 4] = WALL;
    dummy_map_tiles[9 * 12 + 5] = ROAD;
    dummy_map_tiles[9 * 12 + 6] = ROAD;
    dummy_map_tiles[9 * 12 + 7] = WALL;
    dummy_map_tiles[9 * 12 + 8] = DOOR;
    dummy_map_tiles[9 * 12 + 9] = DOWNWALL;
    dummy_map_tiles[9 * 12 + 10] = DOWNWALL;
    dummy_map_tiles[9 * 12 + 11] = WALL;
    dummy_map_tiles[10 * 12 + 0] = WALL;
    dummy_map_tiles[10 * 12 + 1] = EMPTY;
    dummy_map_tiles[10 * 12 + 2] = EMPTY;
    dummy_map_tiles[10 * 12 + 3] = EMPTY;
    dummy_map_tiles[10 * 12 + 4] = WALL;
    dummy_map_tiles[10 * 12 + 5] = ROAD;
    dummy_map_tiles[10 * 12 + 6] = ROAD;
    dummy_map_tiles[10 * 12 + 7] = WALL;
    dummy_map_tiles[10 * 12 + 8] = EMPTY;
    dummy_map_tiles[10 * 12 + 9] = EMPTY;
    dummy_map_tiles[10 * 12 + 10] = EMPTY;
    dummy_map_tiles[10 * 12 + 11] = WALL;
    dummy_map_tiles[11 * 12 + 0] = DOWNWALL;
    dummy_map_tiles[11 * 12 + 1] = DOWNWALL;
    dummy_map_tiles[11 * 12 + 2] = DOWNWALL;
    dummy_map_tiles[11 * 12 + 3] = DOWNWALL;
    dummy_map_tiles[11 * 12 + 4] = WALL;
    dummy_map_tiles[11 * 12 + 5] = GATE;
    dummy_map_tiles[11 * 12 + 6] = GATE;
    dummy_map_tiles[11 * 12 + 7] = WALL;
    dummy_map_tiles[11 * 12 + 8] = DOWNWALL;
    dummy_map_tiles[11 * 12 + 9] = DOWNWALL;
    dummy_map_tiles[11 * 12 + 10] = DOWNWALL;
    dummy_map_tiles[11 * 12 + 11] = DOWNWALL;


    // NPCs
    NPChar Nira (2, 10, "Nira");
    NPChar Jack (4, 2, "Jack");
    NPChar Rick (10, 10, "Rick");


    NPChar* new_npcs = new NPChar[3];

    new_npcs[0] = Nira;
    new_npcs[1] = Jack;
    new_npcs[2] = Rick;

    gamespace.set_NPCs (new_npcs, 3);

    // Set the map in the gamespace
    gamespace.set_map_tiles (map_width * map_height, dummy_map_tiles);
}
