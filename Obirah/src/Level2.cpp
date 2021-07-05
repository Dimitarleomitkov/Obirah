#include "../includes/Gamespace.h"
#include "../includes/Terrain.h"
#include "../includes/Npc.h"

void CreateLevel2 (Gamespace& gamespace)
{
	// Despawn the NPCs
	gamespace.despawn_npcs ();

	// Clear all tiles
	gamespace.clear_tiles ();

	// Set the name of the level
    gamespace.set_map_name("Mitsko Forest");

	// Set the height and width for the level
	gamespace.set_map_width (30);
	gamespace.set_map_height (30);

	// Make a working copy of the width and height for this function
	uint8_t map_width = gamespace.get_map_width ();
	uint8_t map_height = gamespace.get_map_height ();

	// Create the map
	uint16_t* dummy_map_tiles = new uint16_t[map_width * map_height];

	dummy_map_tiles[0 * 30 + 0] = DOWNWALL;
	dummy_map_tiles[0 * 30 + 1] = DOWNWALL;
	dummy_map_tiles[0 * 30 + 2] = DOWNWALL;
	dummy_map_tiles[0 * 30 + 3] = DOWNWALL;
	dummy_map_tiles[0 * 30 + 4] = WALL;
	dummy_map_tiles[0 * 30 + 5] = GATE;
	dummy_map_tiles[0 * 30 + 6] = GATE;
	dummy_map_tiles[0 * 30 + 7] = WALL;
	dummy_map_tiles[0 * 30 + 8] = DOWNWALL;
	dummy_map_tiles[0 * 30 + 9] = DOWNWALL;
	dummy_map_tiles[0 * 30 + 10] = DOWNWALL;
	dummy_map_tiles[0 * 30 + 11] = DOWNWALL;
	dummy_map_tiles[0 * 30 + 12] = TREE;
	dummy_map_tiles[0 * 30 + 13] = TREE;
	dummy_map_tiles[0 * 30 + 14] = TREE;
	dummy_map_tiles[0 * 30 + 15] = TREE;
	dummy_map_tiles[0 * 30 + 16] = TREE;
	dummy_map_tiles[0 * 30 + 17] = TREE;
	dummy_map_tiles[0 * 30 + 18] = BUSH;
	dummy_map_tiles[0 * 30 + 19] = BUSH;
	dummy_map_tiles[0 * 30 + 20] = BUSH;
	dummy_map_tiles[0 * 30 + 21] = BUSH;
	dummy_map_tiles[0 * 30 + 22] = BUSH;
	dummy_map_tiles[0 * 30 + 23] = BUSH;
	dummy_map_tiles[0 * 30 + 24] = TREE;
	dummy_map_tiles[0 * 30 + 25] = TREE;
	dummy_map_tiles[0 * 30 + 26] = TREE;
	dummy_map_tiles[0 * 30 + 27] = TREE;
	dummy_map_tiles[0 * 30 + 28] = TREE;
	dummy_map_tiles[0 * 30 + 29] = TREE;
	dummy_map_tiles[1 * 30 + 0] = TREE;
	dummy_map_tiles[1 * 30 + 1] = EMPTY;
	dummy_map_tiles[1 * 30 + 2] = EMPTY;
	dummy_map_tiles[1 * 30 + 3] = EMPTY;
	dummy_map_tiles[1 * 30 + 4] = WALL;
	dummy_map_tiles[1 * 30 + 5] = ROAD;
	dummy_map_tiles[1 * 30 + 6] = ROAD;
	dummy_map_tiles[1 * 30 + 7] = WALL;
	dummy_map_tiles[1 * 30 + 8] = EMPTY;
	dummy_map_tiles[1 * 30 + 9] = BUSH;
	dummy_map_tiles[1 * 30 + 10] = EMPTY;
	dummy_map_tiles[1 * 30 + 11] = EMPTY;
	dummy_map_tiles[1 * 30 + 12] = EMPTY;
	dummy_map_tiles[1 * 30 + 13] = EMPTY;
	dummy_map_tiles[1 * 30 + 14] = EMPTY;
	dummy_map_tiles[1 * 30 + 15] = EMPTY;
	dummy_map_tiles[1 * 30 + 16] = EMPTY;
	dummy_map_tiles[1 * 30 + 17] = EMPTY;
	dummy_map_tiles[1 * 30 + 18] = EMPTY;
	dummy_map_tiles[1 * 30 + 19] = EMPTY;
	dummy_map_tiles[1 * 30 + 20] = EMPTY;
	dummy_map_tiles[1 * 30 + 21] = EMPTY;
	dummy_map_tiles[1 * 30 + 22] = EMPTY;
	dummy_map_tiles[1 * 30 + 23] = EMPTY;
	dummy_map_tiles[1 * 30 + 24] = EMPTY;
	dummy_map_tiles[1 * 30 + 25] = EMPTY;
	dummy_map_tiles[1 * 30 + 26] = EMPTY;
	dummy_map_tiles[1 * 30 + 27] = EMPTY;
	dummy_map_tiles[1 * 30 + 28] = EMPTY;
	dummy_map_tiles[1 * 30 + 29] = TREE;
	dummy_map_tiles[2 * 30 + 0] = TREE;
	dummy_map_tiles[2 * 30 + 1] = EMPTY;
	dummy_map_tiles[2 * 30 + 2] = EMPTY;
	dummy_map_tiles[2 * 30 + 3] = EMPTY;
	dummy_map_tiles[2 * 30 + 4] = WALL;
	dummy_map_tiles[2 * 30 + 5] = ROAD;
	dummy_map_tiles[2 * 30 + 6] = ROAD;
	dummy_map_tiles[2 * 30 + 7] = WALL;
	dummy_map_tiles[2 * 30 + 8] = EMPTY;
	dummy_map_tiles[2 * 30 + 9] = EMPTY;
	dummy_map_tiles[2 * 30 + 10] = EMPTY;
	dummy_map_tiles[2 * 30 + 11] = EMPTY;
	dummy_map_tiles[2 * 30 + 12] = EMPTY;
	dummy_map_tiles[2 * 30 + 13] = EMPTY;
	dummy_map_tiles[2 * 30 + 14] = EMPTY;
	dummy_map_tiles[2 * 30 + 15] = EMPTY;
	dummy_map_tiles[2 * 30 + 16] = BUSH;
	dummy_map_tiles[2 * 30 + 17] = EMPTY;
	dummy_map_tiles[2 * 30 + 18] = EMPTY;
	dummy_map_tiles[2 * 30 + 19] = EMPTY;
	dummy_map_tiles[2 * 30 + 20] = TREE;
	dummy_map_tiles[2 * 30 + 21] = BUSH;
	dummy_map_tiles[2 * 30 + 22] = EMPTY;
	dummy_map_tiles[2 * 30 + 23] = EMPTY;
	dummy_map_tiles[2 * 30 + 24] = EMPTY;
	dummy_map_tiles[2 * 30 + 25] = EMPTY;
	dummy_map_tiles[2 * 30 + 26] = EMPTY;
	dummy_map_tiles[2 * 30 + 27] = TREE;
	dummy_map_tiles[2 * 30 + 28] = EMPTY;
	dummy_map_tiles[2 * 30 + 29] = TREE;
	dummy_map_tiles[3 * 30 + 0] = BUSH;
	dummy_map_tiles[3 * 30 + 1] = EMPTY;
	dummy_map_tiles[3 * 30 + 2] = TREE;
	dummy_map_tiles[3 * 30 + 3] = EMPTY;
	dummy_map_tiles[3 * 30 + 4] = BUSH;
	dummy_map_tiles[3 * 30 + 5] = ROAD;
	dummy_map_tiles[3 * 30 + 6] = ROAD;
	dummy_map_tiles[3 * 30 + 7] = BUSH;
	dummy_map_tiles[3 * 30 + 8] = EMPTY;
	dummy_map_tiles[3 * 30 + 9] = EMPTY;
	dummy_map_tiles[3 * 30 + 10] = TREE;
	dummy_map_tiles[3 * 30 + 11] = TREE;
	dummy_map_tiles[3 * 30 + 12] = TREE;
	dummy_map_tiles[3 * 30 + 13] = TREE;
	dummy_map_tiles[3 * 30 + 14] = TREE;
	dummy_map_tiles[3 * 30 + 15] = EMPTY;
	dummy_map_tiles[3 * 30 + 16] = BUSH;
	dummy_map_tiles[3 * 30 + 17] = EMPTY;
	dummy_map_tiles[3 * 30 + 18] = EMPTY;
	dummy_map_tiles[3 * 30 + 19] = EMPTY;
	dummy_map_tiles[3 * 30 + 20] = EMPTY;
	dummy_map_tiles[3 * 30 + 21] = BUSH;
	dummy_map_tiles[3 * 30 + 22] = EMPTY;
	dummy_map_tiles[3 * 30 + 23] = BUSH;
	dummy_map_tiles[3 * 30 + 24] = EMPTY;
	dummy_map_tiles[3 * 30 + 25] = EMPTY;
	dummy_map_tiles[3 * 30 + 26] = EMPTY;
	dummy_map_tiles[3 * 30 + 27] = TREE;
	dummy_map_tiles[3 * 30 + 28] = EMPTY;
	dummy_map_tiles[3 * 30 + 29] = BUSH;
	dummy_map_tiles[4 * 30 + 0] = TREE;
	dummy_map_tiles[4 * 30 + 1] = EMPTY;
	dummy_map_tiles[4 * 30 + 2] = EMPTY;
	dummy_map_tiles[4 * 30 + 3] = EMPTY;
	dummy_map_tiles[4 * 30 + 4] = EMPTY;
	dummy_map_tiles[4 * 30 + 5] = ROAD;
	dummy_map_tiles[4 * 30 + 6] = ROAD;
	dummy_map_tiles[4 * 30 + 7] = ROAD;
	dummy_map_tiles[4 * 30 + 8] = EMPTY;
	dummy_map_tiles[4 * 30 + 9] = EMPTY;
	dummy_map_tiles[4 * 30 + 10] = TREE;
	dummy_map_tiles[4 * 30 + 11] = TREE;
	dummy_map_tiles[4 * 30 + 12] = TREE;
	dummy_map_tiles[4 * 30 + 13] = TREE;
	dummy_map_tiles[4 * 30 + 14] = TREE;
	dummy_map_tiles[4 * 30 + 15] = EMPTY;
	dummy_map_tiles[4 * 30 + 16] = EMPTY;
	dummy_map_tiles[4 * 30 + 17] = EMPTY;
	dummy_map_tiles[4 * 30 + 18] = BUSH;
	dummy_map_tiles[4 * 30 + 19] = EMPTY;
	dummy_map_tiles[4 * 30 + 20] = BUSH;
	dummy_map_tiles[4 * 30 + 21] = BUSH;
	dummy_map_tiles[4 * 30 + 22] = EMPTY;
	dummy_map_tiles[4 * 30 + 23] = EMPTY;
	dummy_map_tiles[4 * 30 + 24] = EMPTY;
	dummy_map_tiles[4 * 30 + 25] = EMPTY;
	dummy_map_tiles[4 * 30 + 26] = EMPTY;
	dummy_map_tiles[4 * 30 + 27] = EMPTY;
	dummy_map_tiles[4 * 30 + 28] = EMPTY;
	dummy_map_tiles[4 * 30 + 29] = TREE;
	dummy_map_tiles[5 * 30 + 0] = BUSH;
	dummy_map_tiles[5 * 30 + 1] = EMPTY;
	dummy_map_tiles[5 * 30 + 2] = EMPTY;
	dummy_map_tiles[5 * 30 + 3] = EMPTY;
	dummy_map_tiles[5 * 30 + 4] = EMPTY;
	dummy_map_tiles[5 * 30 + 5] = EMPTY;
	dummy_map_tiles[5 * 30 + 6] = ROAD;
	dummy_map_tiles[5 * 30 + 7] = ROAD;
	dummy_map_tiles[5 * 30 + 8] = ROAD;
	dummy_map_tiles[5 * 30 + 9] = EMPTY;
	dummy_map_tiles[5 * 30 + 10] = EMPTY;
	dummy_map_tiles[5 * 30 + 11] = EMPTY;
	dummy_map_tiles[5 * 30 + 12] = EMPTY;
	dummy_map_tiles[5 * 30 + 13] = TREE;
	dummy_map_tiles[5 * 30 + 14] = TREE;
	dummy_map_tiles[5 * 30 + 15] = EMPTY;
	dummy_map_tiles[5 * 30 + 16] = EMPTY;
	dummy_map_tiles[5 * 30 + 17] = EMPTY;
	dummy_map_tiles[5 * 30 + 18] = EMPTY;
	dummy_map_tiles[5 * 30 + 19] = EMPTY;
	dummy_map_tiles[5 * 30 + 20] = BUSH;
	dummy_map_tiles[5 * 30 + 21] = BUSH;
	dummy_map_tiles[5 * 30 + 22] = EMPTY;
	dummy_map_tiles[5 * 30 + 23] = EMPTY;
	dummy_map_tiles[5 * 30 + 24] = EMPTY;
	dummy_map_tiles[5 * 30 + 25] = EMPTY;
	dummy_map_tiles[5 * 30 + 26] = TREE;
	dummy_map_tiles[5 * 30 + 27] = EMPTY;
	dummy_map_tiles[5 * 30 + 28] = EMPTY;
	dummy_map_tiles[5 * 30 + 29] = TREE;
	dummy_map_tiles[6 * 30 + 0] = TREE;
	dummy_map_tiles[6 * 30 + 1] = EMPTY;
	dummy_map_tiles[6 * 30 + 2] = EMPTY;
	dummy_map_tiles[6 * 30 + 3] = EMPTY;
	dummy_map_tiles[6 * 30 + 4] = BUSH;
	dummy_map_tiles[6 * 30 + 5] = EMPTY;
	dummy_map_tiles[6 * 30 + 6] = TREE;
	dummy_map_tiles[6 * 30 + 7] = ROAD;
	dummy_map_tiles[6 * 30 + 8] = ROAD;
	dummy_map_tiles[6 * 30 + 9] = ROAD;
	dummy_map_tiles[6 * 30 + 10] = TREE;
	dummy_map_tiles[6 * 30 + 11] = TREE;
	dummy_map_tiles[6 * 30 + 12] = EMPTY;
	dummy_map_tiles[6 * 30 + 13] = TREE;
	dummy_map_tiles[6 * 30 + 14] = TREE;
	dummy_map_tiles[6 * 30 + 15] = TREE;
	dummy_map_tiles[6 * 30 + 16] = TREE;
	dummy_map_tiles[6 * 30 + 17] = EMPTY;
	dummy_map_tiles[6 * 30 + 18] = BUSH;
	dummy_map_tiles[6 * 30 + 19] = EMPTY;
	dummy_map_tiles[6 * 30 + 20] = BUSH;
	dummy_map_tiles[6 * 30 + 21] = BUSH;
	dummy_map_tiles[6 * 30 + 22] = EMPTY;
	dummy_map_tiles[6 * 30 + 23] = TREE;
	dummy_map_tiles[6 * 30 + 24] = EMPTY;
	dummy_map_tiles[6 * 30 + 25] = EMPTY;
	dummy_map_tiles[6 * 30 + 26] = TREE;
	dummy_map_tiles[6 * 30 + 27] = EMPTY;
	dummy_map_tiles[6 * 30 + 28] = EMPTY;
	dummy_map_tiles[6 * 30 + 29] = TREE;
	dummy_map_tiles[7 * 30 + 0] = TREE;
	dummy_map_tiles[7 * 30 + 1] = EMPTY;
	dummy_map_tiles[7 * 30 + 2] = EMPTY;
	dummy_map_tiles[7 * 30 + 3] = EMPTY;
	dummy_map_tiles[7 * 30 + 4] = EMPTY;
	dummy_map_tiles[7 * 30 + 5] = EMPTY;
	dummy_map_tiles[7 * 30 + 6] = EMPTY;
	dummy_map_tiles[7 * 30 + 7] = ROAD;
	dummy_map_tiles[7 * 30 + 8] = ROAD;
	dummy_map_tiles[7 * 30 + 9] = ROAD;
	dummy_map_tiles[7 * 30 + 10] = TREE;
	dummy_map_tiles[7 * 30 + 11] = TREE;
	dummy_map_tiles[7 * 30 + 12] = EMPTY;
	dummy_map_tiles[7 * 30 + 13] = TREE;
	dummy_map_tiles[7 * 30 + 14] = TREE;
	dummy_map_tiles[7 * 30 + 15] = TREE;
	dummy_map_tiles[7 * 30 + 16] = TREE;
	dummy_map_tiles[7 * 30 + 17] = EMPTY;
	dummy_map_tiles[7 * 30 + 18] = EMPTY;
	dummy_map_tiles[7 * 30 + 19] = EMPTY;
	dummy_map_tiles[7 * 30 + 20] = BUSH;
	dummy_map_tiles[7 * 30 + 21] = BUSH;
	dummy_map_tiles[7 * 30 + 22] = EMPTY;
	dummy_map_tiles[7 * 30 + 23] = EMPTY;
	dummy_map_tiles[7 * 30 + 24] = EMPTY;
	dummy_map_tiles[7 * 30 + 25] = EMPTY;
	dummy_map_tiles[7 * 30 + 26] = EMPTY;
	dummy_map_tiles[7 * 30 + 27] = EMPTY;
	dummy_map_tiles[7 * 30 + 28] = EMPTY;
	dummy_map_tiles[7 * 30 + 29] = TREE;
	dummy_map_tiles[8 * 30 + 0] = TREE;
	dummy_map_tiles[8 * 30 + 1] = EMPTY;
	dummy_map_tiles[8 * 30 + 2] = EMPTY;
	dummy_map_tiles[8 * 30 + 3] = EMPTY;
	dummy_map_tiles[8 * 30 + 4] = EMPTY;
	dummy_map_tiles[8 * 30 + 5] = EMPTY;
	dummy_map_tiles[8 * 30 + 6] = BUSH;
	dummy_map_tiles[8 * 30 + 7] = ROAD;
	dummy_map_tiles[8 * 30 + 8] = ROAD;
	dummy_map_tiles[8 * 30 + 9] = ROAD;
	dummy_map_tiles[8 * 30 + 10] = TREE;
	dummy_map_tiles[8 * 30 + 11] = EMPTY;
	dummy_map_tiles[8 * 30 + 12] = EMPTY;
	dummy_map_tiles[8 * 30 + 13] = EMPTY;
	dummy_map_tiles[8 * 30 + 14] = EMPTY;
	dummy_map_tiles[8 * 30 + 15] = EMPTY;
	dummy_map_tiles[8 * 30 + 16] = EMPTY;
	dummy_map_tiles[8 * 30 + 17] = TREE;
	dummy_map_tiles[8 * 30 + 18] = EMPTY;
	dummy_map_tiles[8 * 30 + 19] = EMPTY;
	dummy_map_tiles[8 * 30 + 20] = EMPTY;
	dummy_map_tiles[8 * 30 + 21] = BUSH;
	dummy_map_tiles[8 * 30 + 22] = EMPTY;
	dummy_map_tiles[8 * 30 + 23] = EMPTY;
	dummy_map_tiles[8 * 30 + 24] = EMPTY;
	dummy_map_tiles[8 * 30 + 25] = EMPTY;
	dummy_map_tiles[8 * 30 + 26] = EMPTY;
	dummy_map_tiles[8 * 30 + 27] = EMPTY;
	dummy_map_tiles[8 * 30 + 28] = EMPTY;
	dummy_map_tiles[8 * 30 + 29] = TREE;
	dummy_map_tiles[9 * 30 + 0] = TREE;
	dummy_map_tiles[9 * 30 + 1] = EMPTY;
	dummy_map_tiles[9 * 30 + 2] = EMPTY;
	dummy_map_tiles[9 * 30 + 3] = EMPTY;
	dummy_map_tiles[9 * 30 + 4] = EMPTY;
	dummy_map_tiles[9 * 30 + 5] = EMPTY;
	dummy_map_tiles[9 * 30 + 6] = EMPTY;
	dummy_map_tiles[9 * 30 + 7] = ROAD;
	dummy_map_tiles[9 * 30 + 8] = ROAD;
	dummy_map_tiles[9 * 30 + 9] = ROAD;
	dummy_map_tiles[9 * 30 + 10] = BUSH;
	dummy_map_tiles[9 * 30 + 11] = EMPTY;
	dummy_map_tiles[9 * 30 + 12] = TREE;
	dummy_map_tiles[9 * 30 + 13] = EMPTY;
	dummy_map_tiles[9 * 30 + 14] = TREE;
	dummy_map_tiles[9 * 30 + 15] = EMPTY;
	dummy_map_tiles[9 * 30 + 16] = EMPTY;
	dummy_map_tiles[9 * 30 + 17] = EMPTY;
	dummy_map_tiles[9 * 30 + 18] = EMPTY;
	dummy_map_tiles[9 * 30 + 19] = EMPTY;
	dummy_map_tiles[9 * 30 + 20] = EMPTY;
	dummy_map_tiles[9 * 30 + 21] = BUSH;
	dummy_map_tiles[9 * 30 + 22] = EMPTY;
	dummy_map_tiles[9 * 30 + 23] = TREE;
	dummy_map_tiles[9 * 30 + 24] = EMPTY;
	dummy_map_tiles[9 * 30 + 25] = EMPTY;
	dummy_map_tiles[9 * 30 + 26] = TREE;
	dummy_map_tiles[9 * 30 + 27] = TREE;
	dummy_map_tiles[9 * 30 + 28] = BUSH;
	dummy_map_tiles[9 * 30 + 29] = BUSH;
	dummy_map_tiles[10 * 30 + 0] = BUSH;
	dummy_map_tiles[10 * 30 + 1] = EMPTY;
	dummy_map_tiles[10 * 30 + 2] = BUSH;
	dummy_map_tiles[10 * 30 + 3] = EMPTY;
	dummy_map_tiles[10 * 30 + 4] = EMPTY;
	dummy_map_tiles[10 * 30 + 5] = EMPTY;
	dummy_map_tiles[10 * 30 + 6] = EMPTY;
	dummy_map_tiles[10 * 30 + 7] = ROAD;
	dummy_map_tiles[10 * 30 + 8] = ROAD;
	dummy_map_tiles[10 * 30 + 9] = ROAD;
	dummy_map_tiles[10 * 30 + 10] = EMPTY;
	dummy_map_tiles[10 * 30 + 11] = EMPTY;
	dummy_map_tiles[10 * 30 + 12] = EMPTY;
	dummy_map_tiles[10 * 30 + 13] = EMPTY;
	dummy_map_tiles[10 * 30 + 14] = TREE;
	dummy_map_tiles[10 * 30 + 15] = TREE;
	dummy_map_tiles[10 * 30 + 16] = TREE;
	dummy_map_tiles[10 * 30 + 17] = EMPTY;
	dummy_map_tiles[10 * 30 + 18] = EMPTY;
	dummy_map_tiles[10 * 30 + 19] = EMPTY;
	dummy_map_tiles[10 * 30 + 20] = EMPTY;
	dummy_map_tiles[10 * 30 + 21] = BUSH;
	dummy_map_tiles[10 * 30 + 22] = EMPTY;
	dummy_map_tiles[10 * 30 + 23] = EMPTY;
	dummy_map_tiles[10 * 30 + 24] = EMPTY;
	dummy_map_tiles[10 * 30 + 25] = EMPTY;
	dummy_map_tiles[10 * 30 + 26] = TREE;
	dummy_map_tiles[10 * 30 + 27] = TREE;
	dummy_map_tiles[10 * 30 + 28] = BUSH;
	dummy_map_tiles[10 * 30 + 29] = TREE;
	dummy_map_tiles[11 * 30 + 0] = BUSH;
	dummy_map_tiles[11 * 30 + 1] = EMPTY;
	dummy_map_tiles[11 * 30 + 2] = EMPTY;
	dummy_map_tiles[11 * 30 + 3] = EMPTY;
	dummy_map_tiles[11 * 30 + 4] = EMPTY;
	dummy_map_tiles[11 * 30 + 5] = EMPTY;
	dummy_map_tiles[11 * 30 + 6] = EMPTY;
	dummy_map_tiles[11 * 30 + 7] = ROAD;
	dummy_map_tiles[11 * 30 + 8] = ROAD;
	dummy_map_tiles[11 * 30 + 9] = ROAD;
	dummy_map_tiles[11 * 30 + 10] = BUSH;
	dummy_map_tiles[11 * 30 + 11] = EMPTY;
	dummy_map_tiles[11 * 30 + 12] = EMPTY;
	dummy_map_tiles[11 * 30 + 13] = EMPTY;
	dummy_map_tiles[11 * 30 + 14] = EMPTY;
	dummy_map_tiles[11 * 30 + 15] = EMPTY;
	dummy_map_tiles[11 * 30 + 16] = EMPTY;
	dummy_map_tiles[11 * 30 + 17] = EMPTY;
	dummy_map_tiles[11 * 30 + 18] = TREE;
	dummy_map_tiles[11 * 30 + 19] = EMPTY;
	dummy_map_tiles[11 * 30 + 20] = TREE;
	dummy_map_tiles[11 * 30 + 21] = EMPTY;
	dummy_map_tiles[11 * 30 + 22] = EMPTY;
	dummy_map_tiles[11 * 30 + 23] = EMPTY;
	dummy_map_tiles[11 * 30 + 24] = EMPTY;
	dummy_map_tiles[11 * 30 + 25] = EMPTY;
	dummy_map_tiles[11 * 30 + 26] = TREE;
	dummy_map_tiles[11 * 30 + 27] = TREE;
	dummy_map_tiles[11 * 30 + 28] = EMPTY;
	dummy_map_tiles[11 * 30 + 29] = TREE;
	dummy_map_tiles[12 * 30 + 0] = BUSH;
	dummy_map_tiles[12 * 30 + 1] = EMPTY;
	dummy_map_tiles[12 * 30 + 2] = TREE;
	dummy_map_tiles[12 * 30 + 3] = EMPTY;
	dummy_map_tiles[12 * 30 + 4] = EMPTY;
	dummy_map_tiles[12 * 30 + 5] = EMPTY;
	dummy_map_tiles[12 * 30 + 6] = EMPTY;
	dummy_map_tiles[12 * 30 + 7] = ROAD;
	dummy_map_tiles[12 * 30 + 8] = ROAD;
	dummy_map_tiles[12 * 30 + 9] = ROAD;
	dummy_map_tiles[12 * 30 + 10] = EMPTY;
	dummy_map_tiles[12 * 30 + 11] = EMPTY;
	dummy_map_tiles[12 * 30 + 12] = EMPTY;
	dummy_map_tiles[12 * 30 + 13] = TREE;
	dummy_map_tiles[12 * 30 + 14] = EMPTY;
	dummy_map_tiles[12 * 30 + 15] = EMPTY;
	dummy_map_tiles[12 * 30 + 16] = EMPTY;
	dummy_map_tiles[12 * 30 + 17] = TREE;
	dummy_map_tiles[12 * 30 + 18] = EMPTY;
	dummy_map_tiles[12 * 30 + 19] = EMPTY;
	dummy_map_tiles[12 * 30 + 20] = EMPTY;
	dummy_map_tiles[12 * 30 + 21] = EMPTY;
	dummy_map_tiles[12 * 30 + 22] = EMPTY;
	dummy_map_tiles[12 * 30 + 23] = TREE;
	dummy_map_tiles[12 * 30 + 24] = BUSH;
	dummy_map_tiles[12 * 30 + 25] = EMPTY;
	dummy_map_tiles[12 * 30 + 26] = TREE;
	dummy_map_tiles[12 * 30 + 27] = TREE;
	dummy_map_tiles[12 * 30 + 28] = EMPTY;
	dummy_map_tiles[12 * 30 + 29] = BUSH;
	dummy_map_tiles[13 * 30 + 0] = TREE;
	dummy_map_tiles[13 * 30 + 1] = EMPTY;
	dummy_map_tiles[13 * 30 + 2] = EMPTY;
	dummy_map_tiles[13 * 30 + 3] = EMPTY;
	dummy_map_tiles[13 * 30 + 4] = BUSH;
	dummy_map_tiles[13 * 30 + 5] = EMPTY;
	dummy_map_tiles[13 * 30 + 6] = BUSH;
	dummy_map_tiles[13 * 30 + 7] = ROAD;
	dummy_map_tiles[13 * 30 + 8] = ROAD;
	dummy_map_tiles[13 * 30 + 9] = ROAD;
	dummy_map_tiles[13 * 30 + 10] = EMPTY;
	dummy_map_tiles[13 * 30 + 11] = EMPTY;
	dummy_map_tiles[13 * 30 + 12] = EMPTY;
	dummy_map_tiles[13 * 30 + 13] = TREE;
	dummy_map_tiles[13 * 30 + 14] = TREE;
	dummy_map_tiles[13 * 30 + 15] = TREE;
	dummy_map_tiles[13 * 30 + 16] = TREE;
	dummy_map_tiles[13 * 30 + 17] = TREE;
	dummy_map_tiles[13 * 30 + 18] = EMPTY;
	dummy_map_tiles[13 * 30 + 19] = EMPTY;
	dummy_map_tiles[13 * 30 + 20] = EMPTY;
	dummy_map_tiles[13 * 30 + 21] = EMPTY;
	dummy_map_tiles[13 * 30 + 22] = EMPTY;
	dummy_map_tiles[13 * 30 + 23] = EMPTY;
	dummy_map_tiles[13 * 30 + 24] = BUSH;
	dummy_map_tiles[13 * 30 + 25] = EMPTY;
	dummy_map_tiles[13 * 30 + 26] = TREE;
	dummy_map_tiles[13 * 30 + 27] = TREE;
	dummy_map_tiles[13 * 30 + 28] = EMPTY;
	dummy_map_tiles[13 * 30 + 29] = TREE;
	dummy_map_tiles[14 * 30 + 0] = BUSH;
	dummy_map_tiles[14 * 30 + 1] = EMPTY;
	dummy_map_tiles[14 * 30 + 2] = EMPTY;
	dummy_map_tiles[14 * 30 + 3] = TREE;
	dummy_map_tiles[14 * 30 + 4] = EMPTY;
	dummy_map_tiles[14 * 30 + 5] = EMPTY;
	dummy_map_tiles[14 * 30 + 6] = BUSH;
	dummy_map_tiles[14 * 30 + 7] = ROAD;
	dummy_map_tiles[14 * 30 + 8] = ROAD;
	dummy_map_tiles[14 * 30 + 9] = ROAD;
	dummy_map_tiles[14 * 30 + 10] = EMPTY;
	dummy_map_tiles[14 * 30 + 11] = EMPTY;
	dummy_map_tiles[14 * 30 + 12] = TREE;
	dummy_map_tiles[14 * 30 + 13] = EMPTY;
	dummy_map_tiles[14 * 30 + 14] = EMPTY;
	dummy_map_tiles[14 * 30 + 15] = EMPTY;
	dummy_map_tiles[14 * 30 + 16] = EMPTY;
	dummy_map_tiles[14 * 30 + 17] = TREE;
	dummy_map_tiles[14 * 30 + 18] = EMPTY;
	dummy_map_tiles[14 * 30 + 19] = TREE;
	dummy_map_tiles[14 * 30 + 20] = TREE;
	dummy_map_tiles[14 * 30 + 21] = EMPTY;
	dummy_map_tiles[14 * 30 + 22] = EMPTY;
	dummy_map_tiles[14 * 30 + 23] = EMPTY;
	dummy_map_tiles[14 * 30 + 24] = EMPTY;
	dummy_map_tiles[14 * 30 + 25] = EMPTY;
	dummy_map_tiles[14 * 30 + 26] = TREE;
	dummy_map_tiles[14 * 30 + 27] = TREE;
	dummy_map_tiles[14 * 30 + 28] = EMPTY;
	dummy_map_tiles[14 * 30 + 29] = TREE;
	dummy_map_tiles[15 * 30 + 0] = BUSH;
	dummy_map_tiles[15 * 30 + 1] = EMPTY;
	dummy_map_tiles[15 * 30 + 2] = EMPTY;
	dummy_map_tiles[15 * 30 + 3] = EMPTY;
	dummy_map_tiles[15 * 30 + 4] = EMPTY;
	dummy_map_tiles[15 * 30 + 5] = EMPTY;
	dummy_map_tiles[15 * 30 + 6] = EMPTY;
	dummy_map_tiles[15 * 30 + 7] = ROAD;
	dummy_map_tiles[15 * 30 + 8] = ROAD;
	dummy_map_tiles[15 * 30 + 9] = ROAD;
	dummy_map_tiles[15 * 30 + 10] = EMPTY;
	dummy_map_tiles[15 * 30 + 11] = EMPTY;
	dummy_map_tiles[15 * 30 + 12] = TREE;
	dummy_map_tiles[15 * 30 + 13] = EMPTY;
	dummy_map_tiles[15 * 30 + 14] = TREE;
	dummy_map_tiles[15 * 30 + 15] = EMPTY;
	dummy_map_tiles[15 * 30 + 16] = TREE;
	dummy_map_tiles[15 * 30 + 17] = TREE;
	dummy_map_tiles[15 * 30 + 18] = EMPTY;
	dummy_map_tiles[15 * 30 + 19] = EMPTY;
	dummy_map_tiles[15 * 30 + 20] = EMPTY;
	dummy_map_tiles[15 * 30 + 21] = BUSH;
	dummy_map_tiles[15 * 30 + 22] = EMPTY;
	dummy_map_tiles[15 * 30 + 23] = EMPTY;
	dummy_map_tiles[15 * 30 + 24] = EMPTY;
	dummy_map_tiles[15 * 30 + 25] = EMPTY;
	dummy_map_tiles[15 * 30 + 26] = TREE;
	dummy_map_tiles[15 * 30 + 27] = TREE;
	dummy_map_tiles[15 * 30 + 28] = EMPTY;
	dummy_map_tiles[15 * 30 + 29] = TREE;
	dummy_map_tiles[16 * 30 + 0] = BUSH;
	dummy_map_tiles[16 * 30 + 1] = EMPTY;
	dummy_map_tiles[16 * 30 + 2] = EMPTY;
	dummy_map_tiles[16 * 30 + 3] = EMPTY;
	dummy_map_tiles[16 * 30 + 4] = EMPTY;
	dummy_map_tiles[16 * 30 + 5] = EMPTY;
	dummy_map_tiles[16 * 30 + 6] = EMPTY;
	dummy_map_tiles[16 * 30 + 7] = ROAD;
	dummy_map_tiles[16 * 30 + 8] = ROAD;
	dummy_map_tiles[16 * 30 + 9] = ROAD;
	dummy_map_tiles[16 * 30 + 10] = EMPTY;
	dummy_map_tiles[16 * 30 + 11] = EMPTY;
	dummy_map_tiles[16 * 30 + 12] = EMPTY;
	dummy_map_tiles[16 * 30 + 13] = EMPTY;
	dummy_map_tiles[16 * 30 + 14] = EMPTY;
	dummy_map_tiles[16 * 30 + 15] = EMPTY;
	dummy_map_tiles[16 * 30 + 16] = EMPTY;
	dummy_map_tiles[16 * 30 + 17] = TREE;
	dummy_map_tiles[16 * 30 + 18] = EMPTY;
	dummy_map_tiles[16 * 30 + 19] = TREE;
	dummy_map_tiles[16 * 30 + 20] = EMPTY;
	dummy_map_tiles[16 * 30 + 21] = EMPTY;
	dummy_map_tiles[16 * 30 + 22] = EMPTY;
	dummy_map_tiles[16 * 30 + 23] = EMPTY;
	dummy_map_tiles[16 * 30 + 24] = EMPTY;
	dummy_map_tiles[16 * 30 + 25] = EMPTY;
	dummy_map_tiles[16 * 30 + 26] = TREE;
	dummy_map_tiles[16 * 30 + 27] = TREE;
	dummy_map_tiles[16 * 30 + 28] = EMPTY;
	dummy_map_tiles[16 * 30 + 29] = BUSH;
	dummy_map_tiles[17 * 30 + 0] = TREE;
	dummy_map_tiles[17 * 30 + 1] = EMPTY;
	dummy_map_tiles[17 * 30 + 2] = EMPTY;
	dummy_map_tiles[17 * 30 + 3] = TREE;
	dummy_map_tiles[17 * 30 + 4] = TREE;
	dummy_map_tiles[17 * 30 + 5] = EMPTY;
	dummy_map_tiles[17 * 30 + 6] = EMPTY;
	dummy_map_tiles[17 * 30 + 7] = ROAD;
	dummy_map_tiles[17 * 30 + 8] = ROAD;
	dummy_map_tiles[17 * 30 + 9] = ROAD;
	dummy_map_tiles[17 * 30 + 10] = BUSH;
	dummy_map_tiles[17 * 30 + 11] = EMPTY;
	dummy_map_tiles[17 * 30 + 12] = EMPTY;
	dummy_map_tiles[17 * 30 + 13] = TREE;
	dummy_map_tiles[17 * 30 + 14] = EMPTY;
	dummy_map_tiles[17 * 30 + 15] = BUSH;
	dummy_map_tiles[17 * 30 + 16] = EMPTY;
	dummy_map_tiles[17 * 30 + 17] = EMPTY;
	dummy_map_tiles[17 * 30 + 18] = TREE;
	dummy_map_tiles[17 * 30 + 19] = BUSH;
	dummy_map_tiles[17 * 30 + 20] = EMPTY;
	dummy_map_tiles[17 * 30 + 21] = EMPTY;
	dummy_map_tiles[17 * 30 + 22] = EMPTY;
	dummy_map_tiles[17 * 30 + 23] = EMPTY;
	dummy_map_tiles[17 * 30 + 24] = EMPTY;
	dummy_map_tiles[17 * 30 + 25] = EMPTY;
	dummy_map_tiles[17 * 30 + 26] = TREE;
	dummy_map_tiles[17 * 30 + 27] = TREE;
	dummy_map_tiles[17 * 30 + 28] = EMPTY;
	dummy_map_tiles[17 * 30 + 29] = TREE;
	dummy_map_tiles[18 * 30 + 0] = BUSH;
	dummy_map_tiles[18 * 30 + 1] = EMPTY;
	dummy_map_tiles[18 * 30 + 2] = TREE;
	dummy_map_tiles[18 * 30 + 3] = EMPTY;
	dummy_map_tiles[18 * 30 + 4] = EMPTY;
	dummy_map_tiles[18 * 30 + 5] = EMPTY;
	dummy_map_tiles[18 * 30 + 6] = TREE;
	dummy_map_tiles[18 * 30 + 7] = ROAD;
	dummy_map_tiles[18 * 30 + 8] = ROAD;
	dummy_map_tiles[18 * 30 + 9] = ROAD;
	dummy_map_tiles[18 * 30 + 10] = BUSH;
	dummy_map_tiles[18 * 30 + 11] = EMPTY;
	dummy_map_tiles[18 * 30 + 12] = EMPTY;
	dummy_map_tiles[18 * 30 + 13] = EMPTY;
	dummy_map_tiles[18 * 30 + 14] = TREE;
	dummy_map_tiles[18 * 30 + 15] = EMPTY;
	dummy_map_tiles[18 * 30 + 16] = EMPTY;
	dummy_map_tiles[18 * 30 + 17] = EMPTY;
	dummy_map_tiles[18 * 30 + 18] = EMPTY;
	dummy_map_tiles[18 * 30 + 19] = EMPTY;
	dummy_map_tiles[18 * 30 + 20] = EMPTY;
	dummy_map_tiles[18 * 30 + 21] = EMPTY;
	dummy_map_tiles[18 * 30 + 22] = EMPTY;
	dummy_map_tiles[18 * 30 + 23] = EMPTY;
	dummy_map_tiles[18 * 30 + 24] = TREE;
	dummy_map_tiles[18 * 30 + 25] = EMPTY;
	dummy_map_tiles[18 * 30 + 26] = EMPTY;
	dummy_map_tiles[18 * 30 + 27] = BUSH;
	dummy_map_tiles[18 * 30 + 28] = EMPTY;
	dummy_map_tiles[18 * 30 + 29] = TREE;
	dummy_map_tiles[19 * 30 + 0] = BUSH;
	dummy_map_tiles[19 * 30 + 1] = EMPTY;
	dummy_map_tiles[19 * 30 + 2] = EMPTY;
	dummy_map_tiles[19 * 30 + 3] = TREE;
	dummy_map_tiles[19 * 30 + 4] = EMPTY;
	dummy_map_tiles[19 * 30 + 5] = EMPTY;
	dummy_map_tiles[19 * 30 + 6] = EMPTY;
	dummy_map_tiles[19 * 30 + 7] = ROAD;
	dummy_map_tiles[19 * 30 + 8] = ROAD;
	dummy_map_tiles[19 * 30 + 9] = ROAD;
	dummy_map_tiles[19 * 30 + 10] = BUSH;
	dummy_map_tiles[19 * 30 + 11] = EMPTY;
	dummy_map_tiles[19 * 30 + 12] = EMPTY;
	dummy_map_tiles[19 * 30 + 13] = EMPTY;
	dummy_map_tiles[19 * 30 + 14] = EMPTY;
	dummy_map_tiles[19 * 30 + 15] = TREE;
	dummy_map_tiles[19 * 30 + 16] = TREE;
	dummy_map_tiles[19 * 30 + 17] = EMPTY;
	dummy_map_tiles[19 * 30 + 18] = EMPTY;
	dummy_map_tiles[19 * 30 + 19] = BUSH;
	dummy_map_tiles[19 * 30 + 20] = EMPTY;
	dummy_map_tiles[19 * 30 + 21] = EMPTY;
	dummy_map_tiles[19 * 30 + 22] = EMPTY;
	dummy_map_tiles[19 * 30 + 23] = EMPTY;
	dummy_map_tiles[19 * 30 + 24] = EMPTY;
	dummy_map_tiles[19 * 30 + 25] = EMPTY;
	dummy_map_tiles[19 * 30 + 26] = EMPTY;
	dummy_map_tiles[19 * 30 + 27] = EMPTY;
	dummy_map_tiles[19 * 30 + 28] = EMPTY;
	dummy_map_tiles[19 * 30 + 29] = TREE;
	dummy_map_tiles[20 * 30 + 0] = BUSH;
	dummy_map_tiles[20 * 30 + 1] = EMPTY;
	dummy_map_tiles[20 * 30 + 2] = EMPTY;
	dummy_map_tiles[20 * 30 + 3] = TREE;
	dummy_map_tiles[20 * 30 + 4] = EMPTY;
	dummy_map_tiles[20 * 30 + 5] = EMPTY;
	dummy_map_tiles[20 * 30 + 6] = EMPTY;
	dummy_map_tiles[20 * 30 + 7] = EMPTY;
	dummy_map_tiles[20 * 30 + 8] = ROAD;
	dummy_map_tiles[20 * 30 + 9] = ROAD;
	dummy_map_tiles[20 * 30 + 10] = ROAD;
	dummy_map_tiles[20 * 30 + 11] = BUSH;
	dummy_map_tiles[20 * 30 + 12] = EMPTY;
	dummy_map_tiles[20 * 30 + 13] = BUSH;
	dummy_map_tiles[20 * 30 + 14] = EMPTY;
	dummy_map_tiles[20 * 30 + 15] = EMPTY;
	dummy_map_tiles[20 * 30 + 16] = EMPTY;
	dummy_map_tiles[20 * 30 + 17] = EMPTY;
	dummy_map_tiles[20 * 30 + 18] = TREE;
	dummy_map_tiles[20 * 30 + 19] = EMPTY;
	dummy_map_tiles[20 * 30 + 20] = EMPTY;
	dummy_map_tiles[20 * 30 + 21] = EMPTY;
	dummy_map_tiles[20 * 30 + 22] = EMPTY;
	dummy_map_tiles[20 * 30 + 23] = EMPTY;
	dummy_map_tiles[20 * 30 + 24] = EMPTY;
	dummy_map_tiles[20 * 30 + 25] = EMPTY;
	dummy_map_tiles[20 * 30 + 26] = TREE;
	dummy_map_tiles[20 * 30 + 27] = EMPTY;
	dummy_map_tiles[20 * 30 + 28] = EMPTY;
	dummy_map_tiles[20 * 30 + 29] = BUSH;
	dummy_map_tiles[21 * 30 + 0] = BUSH;
	dummy_map_tiles[21 * 30 + 1] = EMPTY;
	dummy_map_tiles[21 * 30 + 2] = EMPTY;
	dummy_map_tiles[21 * 30 + 3] = EMPTY;
	dummy_map_tiles[21 * 30 + 4] = EMPTY;
	dummy_map_tiles[21 * 30 + 5] = BUSH;
	dummy_map_tiles[21 * 30 + 6] = EMPTY;
	dummy_map_tiles[21 * 30 + 7] = TREE;
	dummy_map_tiles[21 * 30 + 8] = EMPTY;
	dummy_map_tiles[21 * 30 + 9] = ROAD;
	dummy_map_tiles[21 * 30 + 10] = ROAD;
	dummy_map_tiles[21 * 30 + 11] = ROAD;
	dummy_map_tiles[21 * 30 + 12] = EMPTY;
	dummy_map_tiles[21 * 30 + 13] = EMPTY;
	dummy_map_tiles[21 * 30 + 14] = EMPTY;
	dummy_map_tiles[21 * 30 + 15] = EMPTY;
	dummy_map_tiles[21 * 30 + 16] = EMPTY;
	dummy_map_tiles[21 * 30 + 17] = EMPTY;
	dummy_map_tiles[21 * 30 + 18] = EMPTY;
	dummy_map_tiles[21 * 30 + 19] = EMPTY;
	dummy_map_tiles[21 * 30 + 20] = EMPTY;
	dummy_map_tiles[21 * 30 + 21] = EMPTY;
	dummy_map_tiles[21 * 30 + 22] = EMPTY;
	dummy_map_tiles[21 * 30 + 23] = EMPTY;
	dummy_map_tiles[21 * 30 + 24] = EMPTY;
	dummy_map_tiles[21 * 30 + 25] = EMPTY;
	dummy_map_tiles[21 * 30 + 26] = TREE;
	dummy_map_tiles[21 * 30 + 27] = EMPTY;
	dummy_map_tiles[21 * 30 + 28] = EMPTY;
	dummy_map_tiles[21 * 30 + 29] = WATER;
	dummy_map_tiles[22 * 30 + 0] = TREE;
	dummy_map_tiles[22 * 30 + 1] = EMPTY;
	dummy_map_tiles[22 * 30 + 2] = EMPTY;
	dummy_map_tiles[22 * 30 + 3] = TREE;
	dummy_map_tiles[22 * 30 + 4] = EMPTY;
	dummy_map_tiles[22 * 30 + 5] = EMPTY;
	dummy_map_tiles[22 * 30 + 6] = EMPTY;
	dummy_map_tiles[22 * 30 + 7] = EMPTY;
	dummy_map_tiles[22 * 30 + 8] = BUSH;
	dummy_map_tiles[22 * 30 + 9] = EMPTY;
	dummy_map_tiles[22 * 30 + 10] = ROAD;
	dummy_map_tiles[22 * 30 + 11] = ROAD;
	dummy_map_tiles[22 * 30 + 12] = ROAD;
	dummy_map_tiles[22 * 30 + 13] = BUSH;
	dummy_map_tiles[22 * 30 + 14] = EMPTY;
	dummy_map_tiles[22 * 30 + 15] = TREE;
	dummy_map_tiles[22 * 30 + 16] = EMPTY;
	dummy_map_tiles[22 * 30 + 17] = EMPTY;
	dummy_map_tiles[22 * 30 + 18] = EMPTY;
	dummy_map_tiles[22 * 30 + 19] = EMPTY;
	dummy_map_tiles[22 * 30 + 20] = EMPTY;
	dummy_map_tiles[22 * 30 + 21] = EMPTY;
	dummy_map_tiles[22 * 30 + 22] = TREE;
	dummy_map_tiles[22 * 30 + 23] = EMPTY;
	dummy_map_tiles[22 * 30 + 24] = EMPTY;
	dummy_map_tiles[22 * 30 + 25] = EMPTY;
	dummy_map_tiles[22 * 30 + 26] = EMPTY;
	dummy_map_tiles[22 * 30 + 27] = EMPTY;
	dummy_map_tiles[22 * 30 + 28] = EMPTY;
	dummy_map_tiles[22 * 30 + 29] = BUSH;
	dummy_map_tiles[23 * 30 + 0] = TREE;
	dummy_map_tiles[23 * 30 + 1] = EMPTY;
	dummy_map_tiles[23 * 30 + 2] = BUSH;
	dummy_map_tiles[23 * 30 + 3] = BUSH;
	dummy_map_tiles[23 * 30 + 4] = BUSH;
	dummy_map_tiles[23 * 30 + 5] = EMPTY;
	dummy_map_tiles[23 * 30 + 6] = EMPTY;
	dummy_map_tiles[23 * 30 + 7] = EMPTY;
	dummy_map_tiles[23 * 30 + 8] = EMPTY;
	dummy_map_tiles[23 * 30 + 9] = EMPTY;
	dummy_map_tiles[23 * 30 + 10] = ROAD;
	dummy_map_tiles[23 * 30 + 11] = ROAD;
	dummy_map_tiles[23 * 30 + 12] = ROAD;
	dummy_map_tiles[23 * 30 + 13] = ROAD;
	dummy_map_tiles[23 * 30 + 14] = ROAD;
	dummy_map_tiles[23 * 30 + 15] = ROAD;
	dummy_map_tiles[23 * 30 + 16] = ROAD;
	dummy_map_tiles[23 * 30 + 17] = ROAD;
	dummy_map_tiles[23 * 30 + 18] = ROAD;
	dummy_map_tiles[23 * 30 + 19] = ROAD;
	dummy_map_tiles[23 * 30 + 20] = ROAD;
	dummy_map_tiles[23 * 30 + 21] = ROAD;
	dummy_map_tiles[23 * 30 + 22] = ROAD;
	dummy_map_tiles[23 * 30 + 23] = ROAD;
	dummy_map_tiles[23 * 30 + 24] = BUSH;
	dummy_map_tiles[23 * 30 + 25] = EMPTY;
	dummy_map_tiles[23 * 30 + 26] = TREE;
	dummy_map_tiles[23 * 30 + 27] = EMPTY;
	dummy_map_tiles[23 * 30 + 28] = EMPTY;
	dummy_map_tiles[23 * 30 + 29] = BUSH;
	dummy_map_tiles[24 * 30 + 0] = BUSH;
	dummy_map_tiles[24 * 30 + 1] = EMPTY;
	dummy_map_tiles[24 * 30 + 2] = EMPTY;
	dummy_map_tiles[24 * 30 + 3] = EMPTY;
	dummy_map_tiles[24 * 30 + 4] = EMPTY;
	dummy_map_tiles[24 * 30 + 5] = EMPTY;
	dummy_map_tiles[24 * 30 + 6] = EMPTY;
	dummy_map_tiles[24 * 30 + 7] = EMPTY;
	dummy_map_tiles[24 * 30 + 8] = EMPTY;
	dummy_map_tiles[24 * 30 + 9] = EMPTY;
	dummy_map_tiles[24 * 30 + 10] = ROAD;
	dummy_map_tiles[24 * 30 + 11] = ROAD;
	dummy_map_tiles[24 * 30 + 12] = ROAD;
	dummy_map_tiles[24 * 30 + 13] = ROAD;
	dummy_map_tiles[24 * 30 + 14] = ROAD;
	dummy_map_tiles[24 * 30 + 15] = ROAD;
	dummy_map_tiles[24 * 30 + 16] = ROAD;
	dummy_map_tiles[24 * 30 + 17] = ROAD;
	dummy_map_tiles[24 * 30 + 18] = ROAD;
	dummy_map_tiles[24 * 30 + 19] = ROAD;
	dummy_map_tiles[24 * 30 + 20] = ROAD;
	dummy_map_tiles[24 * 30 + 21] = ROAD;
	dummy_map_tiles[24 * 30 + 22] = ROAD;
	dummy_map_tiles[24 * 30 + 23] = ROAD;
	dummy_map_tiles[24 * 30 + 24] = EMPTY;
	dummy_map_tiles[24 * 30 + 25] = EMPTY;
	dummy_map_tiles[24 * 30 + 26] = EMPTY;
	dummy_map_tiles[24 * 30 + 27] = EMPTY;
	dummy_map_tiles[24 * 30 + 28] = EMPTY;
	dummy_map_tiles[24 * 30 + 29] = TREE;
	dummy_map_tiles[25 * 30 + 0] = BUSH;
	dummy_map_tiles[25 * 30 + 1] = EMPTY;
	dummy_map_tiles[25 * 30 + 2] = EMPTY;
	dummy_map_tiles[25 * 30 + 3] = TREE;
	dummy_map_tiles[25 * 30 + 4] = EMPTY;
	dummy_map_tiles[25 * 30 + 5] = TREE;
	dummy_map_tiles[25 * 30 + 6] = EMPTY;
	dummy_map_tiles[25 * 30 + 7] = TREE;
	dummy_map_tiles[25 * 30 + 8] = EMPTY;
	dummy_map_tiles[25 * 30 + 9] = EMPTY;
	dummy_map_tiles[25 * 30 + 10] = ROAD;
	dummy_map_tiles[25 * 30 + 11] = ROAD;
	dummy_map_tiles[25 * 30 + 12] = ROAD;
	dummy_map_tiles[25 * 30 + 13] = ROAD;
	dummy_map_tiles[25 * 30 + 14] = ROAD;
	dummy_map_tiles[25 * 30 + 15] = ROAD;
	dummy_map_tiles[25 * 30 + 16] = ROAD;
	dummy_map_tiles[25 * 30 + 17] = ROAD;
	dummy_map_tiles[25 * 30 + 18] = ROAD;
	dummy_map_tiles[25 * 30 + 19] = ROAD;
	dummy_map_tiles[25 * 30 + 20] = ROAD;
	dummy_map_tiles[25 * 30 + 21] = ROAD;
	dummy_map_tiles[25 * 30 + 22] = ROAD;
	dummy_map_tiles[25 * 30 + 23] = ROAD;
	dummy_map_tiles[25 * 30 + 24] = EMPTY;
	dummy_map_tiles[25 * 30 + 25] = BUSH;
	dummy_map_tiles[25 * 30 + 26] = TREE;
	dummy_map_tiles[25 * 30 + 27] = EMPTY;
	dummy_map_tiles[25 * 30 + 28] = EMPTY;
	dummy_map_tiles[25 * 30 + 29] = TREE;
	dummy_map_tiles[26 * 30 + 0] = BUSH;
	dummy_map_tiles[26 * 30 + 1] = EMPTY;
	dummy_map_tiles[26 * 30 + 2] = EMPTY;
	dummy_map_tiles[26 * 30 + 3] = EMPTY;
	dummy_map_tiles[26 * 30 + 4] = EMPTY;
	dummy_map_tiles[26 * 30 + 5] = EMPTY;
	dummy_map_tiles[26 * 30 + 6] = EMPTY;
	dummy_map_tiles[26 * 30 + 7] = EMPTY;
	dummy_map_tiles[26 * 30 + 8] = BUSH;
	dummy_map_tiles[26 * 30 + 9] = BUSH;
	dummy_map_tiles[26 * 30 + 10] = EMPTY;
	dummy_map_tiles[26 * 30 + 11] = EMPTY;
	dummy_map_tiles[26 * 30 + 12] = EMPTY;
	dummy_map_tiles[26 * 30 + 13] = EMPTY;
	dummy_map_tiles[26 * 30 + 14] = EMPTY;
	dummy_map_tiles[26 * 30 + 15] = EMPTY;
	dummy_map_tiles[26 * 30 + 16] = EMPTY;
	dummy_map_tiles[26 * 30 + 17] = EMPTY;
	dummy_map_tiles[26 * 30 + 18] = EMPTY;
	dummy_map_tiles[26 * 30 + 19] = EMPTY;
	dummy_map_tiles[26 * 30 + 20] = EMPTY;
	dummy_map_tiles[26 * 30 + 21] = EMPTY;
	dummy_map_tiles[26 * 30 + 22] = ROAD;
	dummy_map_tiles[26 * 30 + 23] = ROAD;
	dummy_map_tiles[26 * 30 + 24] = ROAD;
	dummy_map_tiles[26 * 30 + 25] = TREE;
	dummy_map_tiles[26 * 30 + 26] = TREE;
	dummy_map_tiles[26 * 30 + 27] = TREE;
	dummy_map_tiles[26 * 30 + 28] = EMPTY;
	dummy_map_tiles[26 * 30 + 29] = TREE;
	dummy_map_tiles[27 * 30 + 0] = BUSH;
	dummy_map_tiles[27 * 30 + 1] = EMPTY;
	dummy_map_tiles[27 * 30 + 2] = TREE;
	dummy_map_tiles[27 * 30 + 3] = EMPTY;
	dummy_map_tiles[27 * 30 + 4] = EMPTY;
	dummy_map_tiles[27 * 30 + 5] = EMPTY;
	dummy_map_tiles[27 * 30 + 6] = EMPTY;
	dummy_map_tiles[27 * 30 + 7] = EMPTY;
	dummy_map_tiles[27 * 30 + 8] = EMPTY;
	dummy_map_tiles[27 * 30 + 9] = EMPTY;
	dummy_map_tiles[27 * 30 + 10] = EMPTY;
	dummy_map_tiles[27 * 30 + 11] = TREE;
	dummy_map_tiles[27 * 30 + 12] = TREE;
	dummy_map_tiles[27 * 30 + 13] = EMPTY;
	dummy_map_tiles[27 * 30 + 14] = EMPTY;
	dummy_map_tiles[27 * 30 + 15] = EMPTY;
	dummy_map_tiles[27 * 30 + 16] = TREE;
	dummy_map_tiles[27 * 30 + 17] = TREE;
	dummy_map_tiles[27 * 30 + 18] = TREE;
	dummy_map_tiles[27 * 30 + 19] = TREE;
	dummy_map_tiles[27 * 30 + 20] = EMPTY;
	dummy_map_tiles[27 * 30 + 21] = EMPTY;
	dummy_map_tiles[27 * 30 + 22] = EMPTY;
	dummy_map_tiles[27 * 30 + 23] = ROAD;
	dummy_map_tiles[27 * 30 + 24] = ROAD;
	dummy_map_tiles[27 * 30 + 25] = ROAD;
	dummy_map_tiles[27 * 30 + 26] = EMPTY;
	dummy_map_tiles[27 * 30 + 27] = EMPTY;
	dummy_map_tiles[27 * 30 + 28] = EMPTY;
	dummy_map_tiles[27 * 30 + 29] = TREE;
	dummy_map_tiles[28 * 30 + 0] = TREE;
	dummy_map_tiles[28 * 30 + 1] = EMPTY;
	dummy_map_tiles[28 * 30 + 2] = TREE;
	dummy_map_tiles[28 * 30 + 3] = EMPTY;
	dummy_map_tiles[28 * 30 + 4] = EMPTY;
	dummy_map_tiles[28 * 30 + 5] = EMPTY;
	dummy_map_tiles[28 * 30 + 6] = EMPTY;
	dummy_map_tiles[28 * 30 + 7] = EMPTY;
	dummy_map_tiles[28 * 30 + 8] = EMPTY;
	dummy_map_tiles[28 * 30 + 9] = EMPTY;
	dummy_map_tiles[28 * 30 + 10] = EMPTY;
	dummy_map_tiles[28 * 30 + 11] = EMPTY;
	dummy_map_tiles[28 * 30 + 12] = EMPTY;
	dummy_map_tiles[28 * 30 + 13] = EMPTY;
	dummy_map_tiles[28 * 30 + 14] = EMPTY;
	dummy_map_tiles[28 * 30 + 15] = EMPTY;
	dummy_map_tiles[28 * 30 + 16] = EMPTY;
	dummy_map_tiles[28 * 30 + 17] = EMPTY;
	dummy_map_tiles[28 * 30 + 18] = EMPTY;
	dummy_map_tiles[28 * 30 + 19] = EMPTY;
	dummy_map_tiles[28 * 30 + 20] = BUSH;
	dummy_map_tiles[28 * 30 + 21] = EMPTY;
	dummy_map_tiles[28 * 30 + 22] = EMPTY;
	dummy_map_tiles[28 * 30 + 23] = BUSH;
	dummy_map_tiles[28 * 30 + 24] = ROAD;
	dummy_map_tiles[28 * 30 + 25] = ROAD;
	dummy_map_tiles[28 * 30 + 26] = ROAD;
	dummy_map_tiles[28 * 30 + 27] = EMPTY;
	dummy_map_tiles[28 * 30 + 28] = BUSH;
	dummy_map_tiles[28 * 30 + 29] = BUSH;
	dummy_map_tiles[29 * 30 + 0] = BUSH;
	dummy_map_tiles[29 * 30 + 1] = TREE;
	dummy_map_tiles[29 * 30 + 2] = BUSH;
	dummy_map_tiles[29 * 30 + 3] = TREE;
	dummy_map_tiles[29 * 30 + 4] = TREE;
	dummy_map_tiles[29 * 30 + 5] = TREE;
	dummy_map_tiles[29 * 30 + 6] = TREE;
	dummy_map_tiles[29 * 30 + 7] = TREE;
	dummy_map_tiles[29 * 30 + 8] = TREE;
	dummy_map_tiles[29 * 30 + 9] = TREE;
	dummy_map_tiles[29 * 30 + 10] = TREE;
	dummy_map_tiles[29 * 30 + 11] = BUSH;
	dummy_map_tiles[29 * 30 + 12] = TREE;
	dummy_map_tiles[29 * 30 + 13] = BUSH;
	dummy_map_tiles[29 * 30 + 14] = TREE;
	dummy_map_tiles[29 * 30 + 15] = TREE;
	dummy_map_tiles[29 * 30 + 16] = TREE;
	dummy_map_tiles[29 * 30 + 17] = TREE;
	dummy_map_tiles[29 * 30 + 18] = TREE;
	dummy_map_tiles[29 * 30 + 19] = TREE;
	dummy_map_tiles[29 * 30 + 20] = TREE;
	dummy_map_tiles[29 * 30 + 21] = TREE;
	dummy_map_tiles[29 * 30 + 22] = BUSH;
	dummy_map_tiles[29 * 30 + 23] = ROAD;
	dummy_map_tiles[29 * 30 + 24] = ROAD;
	dummy_map_tiles[29 * 30 + 25] = ROAD;
	dummy_map_tiles[29 * 30 + 26] = ROAD;
	dummy_map_tiles[29 * 30 + 27] = ROAD;
	dummy_map_tiles[29 * 30 + 28] = BUSH;
	dummy_map_tiles[29 * 30 + 29] = TREE;

	// NPCs


	// Enemies


	// Set the map in the gamespace
	gamespace.set_map_tiles (map_width * map_height, dummy_map_tiles);
}
