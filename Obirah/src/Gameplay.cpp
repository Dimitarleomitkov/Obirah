#include "../includes/Gameplay.h"
#include "../includes/Gamespace.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void worldFrame (Gamespace& gamespace) {
    clear_screen ();
    npc_move (gamespace);
    gamespace.draw_world ();
}

void clear_screen (void)
{
    system ("cls");
}

void npc_move (Gamespace& gamespace)
{
    // Initialize random seed
    srand (time(NULL));
    int random_number = 0;

    // Go through the NPCs
    for (int i = 0; i < gamespace.get_number_of_npcs(); ++i) {
        NPChar dummy = gamespace.get_NPC (i);
        // Check if the NPC is engaged
        if (dummy.get_engaged_flag()) {
            continue;
        }

        // Roll random number from 1 to 10 to know whether to move
        random_number = rand() % 10 + 1;

        if (random_number != 3) {
            continue;
        }
        // Roll a random direction
        uint16_t direction = rand() % 4;
        switch (direction) {
            case D_UP:
                // Check if there is an EMPTY space for the NPC to move to
                if (gamespace.get_map_tile((dummy.get_position_x() - 1) * gamespace.get_map_width() + dummy.get_position_y()) != EMPTY) {
                    return;
                } else {
                    // Set the occupied tile to EMPTY
                    gamespace.set_tile (dummy.get_position_x() * gamespace.get_map_width() + dummy.get_position_y(), EMPTY);
                    // Move the NPC's coordinate
                    dummy.set_position_x (dummy.get_position_x() - 1);
                    // Save the NPC
                    gamespace.set_NPC (&dummy, i);
                }
                break;
            case D_LEFT:
                // Check if there is an EMPTY space for the NPC to move to
                if (gamespace.get_map_tile(dummy.get_position_x() * gamespace.get_map_width() + dummy.get_position_y() - 1) != EMPTY) {
                    return;
                } else {
                    // Set the occupied tile to EMPTY
                    gamespace.set_tile (dummy.get_position_x() * gamespace.get_map_width() + dummy.get_position_y(), EMPTY);
                    // Move the NPC's coordinate
                    dummy.set_position_y (dummy.get_position_y() - 1);
                    // Save the NPC
                    gamespace.set_NPC (&dummy, i);
                }
                break;
            case D_DOWN:
                // Check if there is an EMPTY space for the NPC to move to
                if (gamespace.get_map_tile((dummy.get_position_x() + 1) * gamespace.get_map_width() + dummy.get_position_y()) != EMPTY) {
                    return;
                } else {
                    // Set the occupied tile to EMPTY
                    gamespace.set_tile (dummy.get_position_x() * gamespace.get_map_width() + dummy.get_position_y(), EMPTY);
                    // Move the NPC's coordinate
                    dummy.set_position_x (dummy.get_position_x() + 1);
                    // Save the NPC
                    gamespace.set_NPC (&dummy, i);
                }
                break;
            case D_RIGHT:
                // Check if there is an EMPTY space for the NPC to move to
                if (gamespace.get_map_tile(dummy.get_position_x() * gamespace.get_map_width() + dummy.get_position_y() + 1) != EMPTY) {
                    return;
                } else {
                    // Set the occupied tile to EMPTY
                    gamespace.set_tile (dummy.get_position_x() * gamespace.get_map_width() + dummy.get_position_y(), EMPTY);
                    // Move the NPC's coordinate
                    dummy.set_position_y (dummy.get_position_y() + 1);
                    // Save the NPC
                    gamespace.set_NPC (&dummy, i);
                }
                break;
            default:
                std::cerr << "Unknown behaviour" << std::endl;
                break;
        }
    }
}

e_Commands PlayerInput(Gamespace& gamespace)
{
    e_Commands command = INVALID;
    char input;

    // Get an input until it is a proper one
    do {
        input = tolower (getch());
        command = ParseInput(input);
    } while (command == INVALID);

    switch (command) {
        case UP:
            break;
        case LEFT:
            break;
        case DOWN:
            break;
        case RIGHT:
            break;
        case EXIT:
            return command;
        case NEXT_LEVEL:
            if (gamespace.get_map_level() == 5) {
                break;
            }
            gamespace.set_map_level (gamespace.get_map_level() + 1);
            gamespace.generate_level ();
            break;
        case PREVIOUS_LEVEL:
            if (gamespace.get_map_level() == 1) {
                break;
            }
            gamespace.set_map_level (gamespace.get_map_level() - 1);
            gamespace.generate_level ();
            break;
        default:
            break;
    }

    return command;
}

e_Commands ParseInput (char input)
{
    switch (input) {
        case 'w':
            return UP;
        case 'a':
            return LEFT;
        case 's':
            return DOWN;
        case 'd':
            return RIGHT;
        case 'q':
            return EXIT;
        case '>':
            return NEXT_LEVEL;
        case '<':
            return PREVIOUS_LEVEL;
        default:
            return INVALID;
    }
}
