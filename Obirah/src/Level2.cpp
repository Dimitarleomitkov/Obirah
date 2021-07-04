#include "../includes/Gamespace.h"
#include "../includes/Terrain.h"
#include "../includes/Npc.h"

void CreateLevel2 (Gamespace& gamespace)
{
    // Set the height and width for the level
    gamespace.set_map_width (12);
    gamespace.set_map_height (12);

    // Make a working copy of the width and height for this function
    uint8_t map_width = gamespace.get_map_width ();
    uint8_t map_height = gamespace.get_map_height ();

    // Create the map
    uint16_t* dummy_map_tiles = new uint16_t[map_width * map_height];

    uint8_t i = 0;
    uint8_t j = 0;

    for (j = 0; j < map_width; ++j) {
        dummy_map_tiles[j] = DOWNWALL;
    }
    j = 0;
    for (i = 1; i < map_height - 1; ++i) {
        dummy_map_tiles [i * map_width + j] = WALL;
        for (j = 1; j < map_width - 1; ++j) {
            dummy_map_tiles[i * map_width + j] = EMPTY;
        }
        dummy_map_tiles [i * map_width + j] = WALL;
        j = 0;
    }
    for (j = 0; j < map_width; ++j) {
        dummy_map_tiles[i * map_width + j] = DOWNWALL;
    }

    // House 1
    dummy_map_tiles[19] = WALL;
    dummy_map_tiles[31] = WALL;
    dummy_map_tiles[43] = WALL;
    dummy_map_tiles[55] = DOWNWALL;
    dummy_map_tiles[56] = DOOR;
    dummy_map_tiles[57] = DOWNWALL;
    dummy_map_tiles[58] = DOWNWALL;

    // House 2
    dummy_map_tiles[25] = DOWNWALL;
    dummy_map_tiles[26] = DOWNWALL;
    dummy_map_tiles[27] = DOWNWALL;
    dummy_map_tiles[28] = DOWNWALL;
    dummy_map_tiles[40] = WALL;
    dummy_map_tiles[52] = DOOR;
    dummy_map_tiles[64] = WALL;
    dummy_map_tiles[73] = DOWNWALL;
    dummy_map_tiles[74] = DOWNWALL;
    dummy_map_tiles[75] = DOWNWALL;
    dummy_map_tiles[76] = WALL;

    // House 3
    dummy_map_tiles[116] = DOOR;
    dummy_map_tiles[117] = DOWNWALL;
    dummy_map_tiles[118] = DOWNWALL;

    // Gates
    dummy_map_tiles[112] = WALL;
    dummy_map_tiles[115] = WALL;
    dummy_map_tiles[124] = WALL;
    dummy_map_tiles[127] = WALL;
    dummy_map_tiles[136] = WALL;
    dummy_map_tiles[137] = GATE;
    dummy_map_tiles[138] = GATE;
    dummy_map_tiles[139] = WALL;

    // NPCs
    NPChar Nira (2, 10, "Nira");
    NPChar Jack (4, 2, "Jack");
    NPChar Rick (10, 10, "Rick");


    NPChar* new_npcs = new NPChar[3];

    new_npcs[0] = Nira;
    new_npcs[1] = Jack;
    new_npcs[2] = Rick;

    gamespace.set_NPCs (new_npcs, 3);

    // Trees
    dummy_map_tiles[106] = TREE;
    dummy_map_tiles[110] = TREE;

    // Bushes
    dummy_map_tiles[18] = BUSH;

    // Set the map in the gamespace
    gamespace.set_map_tiles (map_width * map_height, dummy_map_tiles);
}
