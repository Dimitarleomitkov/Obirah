#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Player.h"
#include "Terrain.h"

enum e_Commands {
    INVALID = 0,
    EXIT = 1,
    UP = 2,
    LEFT = 3,
    DOWN = 4,
    RIGHT = 5
};

void Input (char* buff, const uint16_t inputLength);
e_Commands PlayerInput (Player* character, Terrain* gamespace);
void HandleInput (e_Commands command, Player* character, Terrain* gamespace);
bool CheckValidUpMove (Player* character, Terrain* gamespace);
bool CheckValidLeftMove (Player* character, Terrain* gamespace);
bool CheckValidDownMove (Player* character, Terrain* gamespace);
bool CheckValidRightMove (Player* character, Terrain* gamespace);
bool CheckMove (Terrain* gamespace, uint16_t tilePosition);
e_Commands ParseInput (char* input);

#endif // GAMEPLAY_H
