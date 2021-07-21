#ifndef GAMESPACE_H
#define GAMESPACE_H

#include <stdint.h>
#include <string>
#include "Npc.h"
#include "Terrain.h"
#include "Player.h"
#include "Enemy.h"

class Gamespace
{
    public:
        // c'tors
        Gamespace ();

        // d'tor
        virtual ~Gamespace ();

        // Function to create the levels
        void generate_level (void);

        // Function to draw the world
        void draw_world (void);

        // Function to despawn all NPCs
        void despawn_npcs (void);

        // Function to despawn all Enemies
        void despawn_enemies (void);

        // Function to clear all tiles
        void clear_tiles (void);

        // Get functions
        bool get_game_started (void);
        Player get_player (void);
        uint16_t get_map_level (void);
        std::string get_map_name (void);
        e_TileType* get_map_tiles (void);
        e_TileType get_map_tile (uint16_t index);
        e_TileType* get_original_map_tiles (void);
        e_TileType get_original_map_tile (uint16_t index);
        uint8_t get_map_width (void);
        uint8_t get_map_height (void);

        NPChar* get_NPCs (void);
        NPChar get_NPC (uint16_t index);
        NPChar get_NPC (uint16_t X, uint16_t Y);

        Enemy get_enemy (uint16_t index);
        unsigned int get_number_of_enemies (void);

        uint16_t get_number_of_npcs (void);
        std::string get_message (void);
        uint16_t get_story_stage (void);

        // Set functions
        void set_game_started (bool Game_Started);
        void set_player (Player player);
        void set_map_level (uint16_t new_map_level);
        void set_map_name (std::string Name);
        void set_map_tiles (uint16_t length, e_TileType* new_map_tiles);
        void set_map_tile (e_TileType new_map_tile);
        void set_tile (uint16_t index, e_TileType type);
        void set_map_width (unsigned int new_map_width);
        void set_map_height (unsigned int new_map_height);

        void set_NPCs (NPChar* NPCs, unsigned int length);
        void set_NPC (NPChar* Npc, uint16_t index);

        void set_enemy (Enemy& E);

        void set_message (std::string new_msg);
        void set_story_stage (uint16_t stage);

    protected:
    private:
        // The player
        Player hero;
        // Flag to indicate whether the game has started
        bool game_started;
        // The map_level the world is currently in
        uint16_t map_level;
        // Name of the map_level
        std::string map_name;
        // The tiles of the map
        e_TileType* original_map_tiles;
        e_TileType* map_tiles;
        // The map width
        unsigned int map_width;
        // The map height
        unsigned int map_height;
        // All the NPCs in a level
        NPChar* npcs;
        uint16_t number_of_npcs;
        // Message for the player
        std::string message;
        // All the Enemies in a level
        std::vector<Enemy> enemies;
        // Story counter
        uint16_t story_stage;
};

void CreateLevel1 (Gamespace& gamespace);
void CreateLevel2 (Gamespace& gamespace);
void CreateLevel3 (Gamespace& gamespace);
void CreateLevel4 (Gamespace& gamespace);
void CreateLevel5 (Gamespace& gamespace);
void CreateLevel6 (Gamespace& gamespace);
void CreateLevel7 (Gamespace& gamespace);
void CreateLevel99 (Gamespace& gamespace);

void populate_terrain (Gamespace& gamespace);

#endif // GAMESPACE_H
