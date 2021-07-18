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

    while (exit_flag == 0) {
        draw_menu (gamespace);
        exit_flag = Menu_Input (ingame_command, gamespace);
        while (ingame_command != GAME_MENU) {
           // The world ticks once
            worldFrame (gamespace);
            // Take an input from the player
            ingame_command = PlayerInput (gamespace);
            // Check if player is dead
            if (gamespace.get_player().get_Health() == 0) {
                ingame_command = restart_game (gamespace);
            }
        }
    }

    return 0;
}
