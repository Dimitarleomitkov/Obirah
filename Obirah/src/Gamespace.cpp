#include "../includes/Gamespace.h"
#include "../includes/Terrain.h"
#include <iostream>
#include <iomanip>


//ctors
Gamespace::Gamespace ()
{
    map_level = 1;
    map_tiles = nullptr;
    map_width = 0;
    map_height = 0;
    npcs = nullptr;
    number_of_npcs = 0;
    generate_level ();
}

//dtor
Gamespace::~Gamespace()
{
    // If there is a need for something.
}

// functions to create the levels
void Gamespace::generate_level (void)
{
    switch (map_level) {
        case 1:
            CreateLevel1 (*this);
            break;
        case 2:
            CreateLevel2 (*this);
            break;
        case 3:
            CreateLevel3 (*this);
            break;
        case 4:
            CreateLevel4 (*this);
            break;
        case 5:
            CreateLevel5 (*this);
            break;
        case 6:
            CreateLevel6 (*this);
            break;
        default:
            std::cout << "UNSUPPORTED LEVEL!" << std::endl;
            break;
    }
}

void Gamespace::draw_world (void)
{
    uint8_t i, j;

    // Populate the terrain
    populate_terrain (*this);

    // Number the grid
    std::cout << std::setw(4) << " ";
    for (j = 0; j < map_width; ++j) {
        if (j < 10) {
            std::cout << " ";
        }
        std::cout << (int) j;
    }
    std::cout << " - " << get_map_name() << std::endl;

    // Draw the tiles
    for (i = 0; i < map_height; ++i) {
        std::cout << std::setw(4) << (int) i;
        for (j = 0; j < map_width; ++j) {
            std::cout << " ";
            switch (map_tiles[i * map_width + j]) {
                case EMPTY:
                    std::cout << " ";
                    break;
                case PLAYER:
                    std::cout << "O";
                    break;
                case NPC:
                    std::cout << "N";
                    break;
                case ENEMY:
                    std::cout << "X";
                    break;
                case DOOR:
                    std::cout << "D";
                    break;
                case GATE:
                    std::cout << "G";
                    break;
                case TREE:
                    std::cout << "T";
                    break;
                case BUSH:
                    std::cout << "*";
                    break;
                case ROAD:
                    std::cout << "H";
                    break;
                case WALL:
                    std::cout << "|";
                    break;
                case DOWNWALL:
                    std::cout << "_";
                    break;
                case WATER:
                    std::cout << "~";
                    break;
                case STONE:
                    std::cout << "n";
                    break;
                case UNKNOWN:
                    std::cout << "?";
                    break;
                default:
                    std::cout << "()";
                    break;
            }
        }
        std::cout << std::endl;
    }
}

void Gamespace::despawn_npcs (void)
{
    if (npcs != nullptr) {
        number_of_npcs = 0;
        delete[] npcs;
        npcs = nullptr;
    }

}

void Gamespace::clear_tiles (void)
{
    if (map_tiles != nullptr) {
        map_width = 0;
        map_height = 0;
        delete[] map_tiles;
        delete[] original_map_tiles;
        map_tiles = nullptr;
        original_map_tiles = nullptr;
    }
}

// Getters
Player Gamespace::get_player (void)
{
    return hero;
}

uint16_t Gamespace::get_map_level (void)
{
    return map_level;
}

std::string Gamespace::get_map_name (void)
{
    return map_name;
}

e_TileType* Gamespace::get_map_tiles (void)
{
    return map_tiles;
}

e_TileType Gamespace::get_map_tile (uint16_t index)
{
    return map_tiles[index];
}

e_TileType* Gamespace::get_original_map_tiles (void)
{
    return original_map_tiles;
}

e_TileType Gamespace::get_original_map_tile (uint16_t index)
{
    return original_map_tiles[index];
}

uint8_t Gamespace::get_map_width (void)
{
    return map_width;
}

uint8_t Gamespace::get_map_height (void)
{
    return map_height;
}

NPChar* Gamespace::get_NPCs (void)
{
    return npcs;
}

NPChar Gamespace::get_NPC (uint16_t index)
{
    return npcs[index];
}

uint16_t Gamespace::get_number_of_npcs (void)
{
    return number_of_npcs;
}

std::string Gamespace::get_message (void)
{
    return message;
}

// Setters
void Gamespace::set_player (Player player)
{
    hero = player;
}

void Gamespace::set_map_level (uint16_t new_map_level)
{
    map_level = new_map_level;
}

void Gamespace::set_map_name (std::string Name)
{
    map_name = Name;
}

void Gamespace::set_map_tiles (uint16_t length, e_TileType* new_map_tiles)
{
    original_map_tiles = new e_TileType[length];
    map_tiles = new e_TileType[length];
    for (int i = 0; i < length; ++i) {
        original_map_tiles[i] = new_map_tiles[i];
        map_tiles[i] = new_map_tiles[i];
    }
}

void Gamespace::set_tile (uint16_t index, e_TileType type)
{
    map_tiles[index] = type;
}

void Gamespace::set_map_width (unsigned int new_map_width)
{
    map_width = new_map_width;
}

void Gamespace::set_map_height (unsigned int new_map_height)
{
    map_height = new_map_height;
}

void Gamespace::set_NPCs (NPChar* NPCs, unsigned int length)
{
    number_of_npcs = length;
    // Create the new NPCs
    npcs = new NPChar[number_of_npcs];
    for (unsigned int i = 0; i < number_of_npcs; ++i) {
        npcs[i] = NPCs[i];
    }
}

void Gamespace::set_NPC (NPChar* Npc, uint16_t index)
{
    npcs[index] = *Npc;
}

void Gamespace::set_message (std::string new_msg)
{
    message = new_msg;
}
