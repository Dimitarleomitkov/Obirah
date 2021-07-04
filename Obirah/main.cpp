#include "includes/Gameplay.h"
#include "includes/Gamespace.h"
#include <iostream>

using namespace std;

int main ()
{
    e_Commands inputCommand = INVALID;
    // Create the world
    static Gamespace gamespace;

    while (inputCommand != EXIT) {
        // The world ticks once
        worldFrame (gamespace);
        // Take an input from the player
        inputCommand = PlayerInput (gamespace);
    }

    return 0;
}
