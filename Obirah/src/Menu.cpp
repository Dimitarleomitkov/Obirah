#include "../includes/Menu.h"
#include <conio.h>
#include <iostream>
#include <string>

static int selector_position = 0;

void draw_menu (bool game_started)
{
    unsigned int menu_length = 4;
    std::string menu_items[menu_length] = {"New Game", "Load Game", "Save Game", "Exit"};
    std::string menu_items2[menu_length] = {"Continue Game", "Load Game", "Save Game", "Exit"};
    int i = 0;

    // Clear the screen
    system ("cls");

    if (game_started == 0) {
        for (i = 0; i < selector_position; ++i) {
            std::cout << menu_items[i] << std::endl;
        }
        std::cout << ">>" << menu_items[i] << "<<" << std::endl;
        ++i;
        for (i; i < menu_length; ++i) {
            std::cout << menu_items[i] << std::endl;
        }
    } else {
        for (i = 0; i < selector_position; ++i) {
            std::cout << menu_items2[i] << std::endl;
        }
        std::cout << ">>" << menu_items2[i] << "<<" << std::endl;
        ++i;
        for (i; i < menu_length; ++i) {
            std::cout << menu_items2[i] << std::endl;
        }
    }
}

bool Menu_Input (e_Commands& game_command, bool& game_started)
{
    e_Commands_Menu command = MENU_INVALID;
    char input;

    // Get an input until it is a proper one
    do {
        input = tolower (getch());
        command = ParseMenuInput(input);
    } while (command == MENU_INVALID);

    switch (command) {
        case MENU_UP:
            if (selector_position > 0) {
                --selector_position;
            }
            break;
        case MENU_DOWN:
            if (selector_position < 3) {
                ++selector_position;
            }
            break;
        case MENU_SELECT:
            switch (selector_position) {
                // New/Continue Game
                case 0:
                    if (game_started == false) {
                        game_started = true;
                        system ("cls");
                        std::cout << "The sun rises over the roofs of the nearby houses. Unfamiliar surroundings..." << std::endl;
                        getch();
                    }
                    game_command = INVALID;
                    break;
                // Load Game
                case 1:
                    break;
                // Save Game
                case 2:
                    break;
                // Exit
                case 3:
                    return true;
            }
            break;
        default:
            break;
    }

    return false;
}

e_Commands_Menu ParseMenuInput (char input)
{
    switch (input) {
        case 'w':
            return MENU_UP;
        case 's':
            return MENU_DOWN;
        case '\r':
            return MENU_SELECT;
        case '\n':
            return MENU_SELECT;
        default:
            return MENU_INVALID;
    }
}
