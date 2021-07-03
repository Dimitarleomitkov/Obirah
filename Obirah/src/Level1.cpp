#include "../include/Terrain.h"

void Terrain::CreateLevel1(void)
{
    m_levelWidth = 12;
    m_levelHeight = 12;
    m_tiles = new uint16_t[m_levelWidth * m_levelHeight];

    int i = 0;
    int j = 0;

    for (j = 0; j < m_levelWidth; ++j) {
        m_tiles[j] = DOWNWALL;
    }
    j = 0;
    for (i = 1; i < m_levelHeight - 1; ++i) {
        m_tiles [i * m_levelWidth + j] = WALL;
        for (j = 1; j < m_levelWidth - 1; ++j) {
            m_tiles[i * m_levelWidth + j] = EMPTY;
        }
        m_tiles [i * m_levelWidth + j] = WALL;
        j = 0;
    }
    for (j = 0; j < m_levelWidth; ++j) {
        m_tiles[i * m_levelWidth + j] = DOWNWALL;
    }

    // House 1
    m_tiles[19] = WALL;
    m_tiles[31] = WALL;
    m_tiles[43] = WALL;
    m_tiles[55] = DOWNWALL;
    m_tiles[56] = DOOR;
    m_tiles[57] = DOWNWALL;
    m_tiles[58] = DOWNWALL;

    // House 2
    m_tiles[25] = DOWNWALL;
    m_tiles[26] = DOWNWALL;
    m_tiles[27] = DOWNWALL;
    m_tiles[28] = DOWNWALL;
    m_tiles[40] = WALL;
    m_tiles[52] = DOOR;
    m_tiles[64] = WALL;
    m_tiles[73] = DOWNWALL;
    m_tiles[74] = DOWNWALL;
    m_tiles[75] = DOWNWALL;
    m_tiles[76] = WALL;

    // House 3
    m_tiles[116] = DOOR;
    m_tiles[117] = DOWNWALL;
    m_tiles[118] = DOWNWALL;

    // Gates
    m_tiles[112] = WALL;
    m_tiles[115] = WALL;
    m_tiles[124] = WALL;
    m_tiles[127] = WALL;
    m_tiles[136] = WALL;
    m_tiles[137] = GATE;
    m_tiles[138] = GATE;
    m_tiles[139] = WALL;

    // NPCs
    m_tiles[34] = NPC;
    m_tiles[50] = NPC;
    m_tiles[130] = NPC;

    // Trees
    m_tiles[106] = TREE;
    m_tiles[110] = TREE;

    // Bushes
    m_tiles[18] = BUSH;
}
