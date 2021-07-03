#ifndef TERRAIN_H
#define TERRAIN_H

#include <stdint.h>
#include <iostream>
#include <iomanip>

#include "Player.h"

class Terrain
{
    public:
        // c'tors
        Terrain();
        Terrain(Player *character);

        // d'tor
        virtual ~Terrain();

        // functions to create the levels
        void CreateLevel(void);
        void CreateLevel1(void);

        enum e_TileType{
            EMPTY = 0,
            PLAYER = 1,
            NPC = 2,
            ENEMY = 3,
            DOOR = 4,
            GATE = 5,
            TREE = 6,
            BUSH = 7,
            WALL = 8,
            DOWNWALL = 9,
            UNKNOWN = 10
        };

        void Draw(Player* character);
        void IncreaseLevel(void);
        uint16_t Width(void);
        uint16_t Height(void);
        uint16_t Tile(uint16_t);
        void ChangeTile(uint32_t tileIndex, e_TileType tileType);
    protected:
    private:
        uint16_t m_levelWidth;
        uint16_t m_levelHeight;
        uint16_t m_level;
        uint16_t *m_tiles;
};

#endif // TERRAIN_H
