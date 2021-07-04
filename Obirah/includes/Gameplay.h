#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Gamespace.h"

enum e_Commands {
    INVALID = 0,
    EXIT = 1,
    UP = 2,
    LEFT = 3,
    DOWN = 4,
    RIGHT = 5
};

enum e_Directions {
    D_UP = 0,
    D_LEFT = 1,
    D_DOWN = 2,
    D_RIGHT = 3
};

void clear_screen (void);
void worldFrame (Gamespace& gamespace);
void npc_move (Gamespace& gamespace);
e_Commands PlayerInput (void);
e_Commands ParseInput (char input);

#endif // GAMEPLAY_H
