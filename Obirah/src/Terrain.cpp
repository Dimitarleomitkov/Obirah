#include "../include/Terrain.h"

//ctors
Terrain::Terrain()
{
    m_level = 1;
}

Terrain::Terrain(Player* character)
{
    m_level = 1;
    CreateLevel();
}

// functions to create the levels
void Terrain::CreateLevel(void)
{
    switch (m_level) {
        case 1:
            CreateLevel1();
            break;
        default:
            using namespace std;
            cout << "UNSUPPORTED LEVEL!" << endl;
            break;
    }
}

//dtor
Terrain::~Terrain()
{
    delete m_tiles;
}

void Terrain::Draw(Player* character)
{
    using namespace std;
    uint8_t i, j;
    uint16_t spaceNorth = m_levelHeight - (m_levelHeight - character->PositionY());
    uint16_t spaceSouth = m_levelHeight - character->PositionY();
    uint16_t spaceEast = m_levelWidth - character->PositionX();
    uint16_t spaceWest = m_levelWidth - (m_levelWidth - character->PositionX());
    uint16_t visibilityNorth = character->Awareness();
    uint16_t visibilitySouth = character->Awareness();
    uint16_t visibilityEast = character->Awareness();
    uint16_t visibilityWest = character->Awareness();

    if (character->Awareness() > spaceNorth) {
        visibilityNorth = spaceNorth;
    }
    if (character->Awareness() > spaceSouth) {
        visibilitySouth = spaceSouth;
    }
    if (character->Awareness() > spaceEast) {
        visibilityEast = spaceEast;
    }
    if (character->Awareness() > spaceWest) {
        visibilityWest = spaceWest;
    }

    m_tiles[character->PositionY() * m_levelWidth + character->PositionX()] = PLAYER;

    cout << setw(4) << " ";
    for (j = character->PositionX() - visibilityWest; j <= character->PositionX() + visibilityEast; ++j) {
        if (j >= m_levelWidth) {
            continue;
        }
        if (j < 10) {
            cout << " ";
        }
        cout << (int) j;
    }
    cout << endl;

    for (i = character->PositionY() - visibilityNorth; i <= character->PositionY() + visibilitySouth; ++i) {
        if (i >= m_levelHeight) {
            continue;
        }
        cout << setw(4) << (int) i;
        for (j = character->PositionX() - visibilityWest; j <= character->PositionX() + visibilityEast; ++j) {
            if (j >= m_levelWidth) {
                continue;
            }
            cout << " ";
            switch (m_tiles[i * m_levelWidth + j]) {
                case EMPTY:
                    cout << " ";
                    break;
                case PLAYER:
                    cout << "O";
                    break;
                case NPC:
                    cout << "N";
                    break;
                case ENEMY:
                    cout << "X";
                    break;
                case DOOR:
                    cout << "D";
                    break;
                case GATE:
                    cout << "G";
                    break;
                case TREE:
                    cout << "T";
                    break;
                case BUSH:
                    cout << "*";
                    break;
                case WALL:
                    cout << "|";
                    break;
                case DOWNWALL:
                    cout << "_";
                    break;
                case UNKNOWN:
                    cout << "?";
                    break;
                default:
                    cout << "()";
                    break;
            }
        }
        cout << endl;
    }
}

void Terrain::IncreaseLevel(void)
{
    ++m_level;
}

uint16_t Terrain::Width (void)
{
    return m_levelWidth;
}

uint16_t Terrain::Height (void)
{
    return m_levelHeight;
}

uint16_t Terrain::Tile(uint16_t position)
{
    return m_tiles[position];
}

void Terrain::ChangeTile(uint32_t tileIndex, e_TileType tileType)
{
    m_tiles[tileIndex] = tileType;
}
