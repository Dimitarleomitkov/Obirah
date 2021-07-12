#include "includes/Gameplay.h"
#include "includes/Gamespace.h"
#include "includes/Menu.h"
#include <iostream>

using namespace std;

int main ()
{
    // Command for the menu
    bool exit_flag = 0;
    // Command for the game
    e_Commands ingame_command = GAME_MENU;
    // Create the world
    static Gamespace gamespace;
    // Game started flag
    static bool game_started = 0;

    while (exit_flag == 0) {
        draw_menu (game_started);
        exit_flag = Menu_Input (ingame_command, game_started);
        while (ingame_command != GAME_MENU) {
           // The world ticks once
            worldFrame (gamespace);
            // Take an input from the player
            ingame_command = PlayerInput (gamespace);
        }
    }

    return 0;
}
