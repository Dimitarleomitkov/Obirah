#include "../includes/Gameplay.h"
#include "../includes/Gamespace.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void worldFrame (Gamespace& gamespace) {
    // Clear the screen
    clear_screen ();
    // Move the NPCs
    npc_move (gamespace);
    // Move the Enemies

    // Draw the world
    gamespace.draw_world();
    // Print the message
    std::cout << gamespace.get_message();
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
            Player_move_up (gamespace);
            break;
        case LEFT:
            Player_move_left (gamespace);
            break;
        case DOWN:
            Player_move_down (gamespace);
            break;
        case RIGHT:
            Player_move_right (gamespace);
            break;
        case EXIT:
            return command;
        // DEBUG commands
        case NEXT_LEVEL:
            if (gamespace.get_map_level() == 6) {
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
        // DEBUG commands
        case '>':
            return NEXT_LEVEL;
        case '<':
            return PREVIOUS_LEVEL;
        default:
            return INVALID;
    }
}

void Player_move_up (Gamespace& gamespace)
{
    Player dummy_player = gamespace.get_player ();
    if (dummy_player.PositionX() == 0) {
        return;
    }

    // Check for collision
    bool collision = check_collision (D_UP, gamespace);

    if (collision == false) {
        uint16_t tile_index = dummy_player.PositionX() * gamespace.get_map_width() + dummy_player.PositionY();

        dummy_player.MoveUp(1);
        gamespace.set_player(dummy_player);
        gamespace.set_tile(tile_index, gamespace.get_original_map_tile(tile_index));
    }
}

void Player_move_left (Gamespace& gamespace)
{
    Player dummy_player = gamespace.get_player();
    if (dummy_player.PositionY() == 0) {
        return;
    }

    // Check for collision
    bool collision = check_collision (D_LEFT, gamespace);

    if (collision == false) {
        uint16_t tile_index = dummy_player.PositionX() * gamespace.get_map_width() + dummy_player.PositionY();

        dummy_player.MoveLeft(1);
        gamespace.set_player(dummy_player);
        gamespace.set_tile(tile_index, gamespace.get_original_map_tile(tile_index));
    }
}

void Player_move_down (Gamespace& gamespace)
{
    Player dummy_player = gamespace.get_player();
    if (dummy_player.PositionX() == gamespace.get_map_height() - 1) {
        return;
    }

    // Check for collision
    bool collision = check_collision (D_DOWN, gamespace);

    if (collision == false) {
        uint16_t tile_index = dummy_player.PositionX() * gamespace.get_map_width() + dummy_player.PositionY();

        dummy_player.MoveDown(1);
        gamespace.set_player(dummy_player);
        gamespace.set_tile(tile_index, gamespace.get_original_map_tile(tile_index));
    }
}

void Player_move_right (Gamespace& gamespace)
{
    Player dummy_player = gamespace.get_player();
    if (dummy_player.PositionY() == gamespace.get_map_width() - 1) {
        return;
    }

    // Check for collision
    bool collision = check_collision (D_RIGHT, gamespace);

    if (collision == false) {
        Player dummy_player = gamespace.get_player();
        uint16_t tile_index = dummy_player.PositionX() * gamespace.get_map_width() + dummy_player.PositionY();

        dummy_player.MoveRight(1);
        gamespace.set_player(dummy_player);
        gamespace.set_tile(tile_index, gamespace.get_original_map_tile(tile_index));
    }
}

bool check_collision (e_Directions direction, Gamespace& gamespace)
{
    // Get the position of the player
    uint16_t x_pos = gamespace.get_player().PositionX();
    uint16_t y_pos = gamespace.get_player().PositionY();
    gamespace.set_message ("");

    e_TileType collision_tile;

    switch (direction) {
        case D_UP:
            --x_pos;
            collision_tile = gamespace.get_map_tile(x_pos * gamespace.get_map_width() + y_pos);
            break;
        case D_LEFT:
            --y_pos;
            collision_tile = gamespace.get_map_tile(x_pos * gamespace.get_map_width() + y_pos);
            break;
        case D_DOWN:
            ++x_pos;
            collision_tile = gamespace.get_map_tile(x_pos * gamespace.get_map_width() + y_pos);
            break;
        case D_RIGHT:
            ++y_pos;
            collision_tile = gamespace.get_map_tile(x_pos * gamespace.get_map_width() + y_pos);
            break;
        default :
            break;
    }

    // Handle the collision
    switch (collision_tile) {
        case EMPTY:
            if (Empty_collide(gamespace)) {
                return true;
            } else {
                return false;
            }
        case PLAYER:
            // Something has gone terribly wrong
            break;
        case NPC:

            return true;
        case ENEMY:

            return true;
        case DOOR:
            Door_collide (direction, gamespace);
            return true;
        case GATE:
            Gate_collide (direction, gamespace);
            return true;
        case TREE:
            gamespace.set_message ("There is a tree in the way.\n");
            return true;
        case BUSH:
            gamespace.set_message ("There is a lovely flowery bush in the way.\n");
            return true;
        case ROAD:
            if (Road_collide(direction, gamespace)) {
                return true;
            } else {
                return false;
            }
            return false;
        case WALL:
            gamespace.set_message ("There is a wall in the way.\n");
            return true;
        case DOWNWALL:
            gamespace.set_message ("There is a wall in the way.\n");
            return true;
        case WATER:

            return true;
        case STONE:
            gamespace.set_message ("There is a boulder in the way.\n");
            return true;
        case UNKNOWN:

            return true;
        default:
            return false;
    }
    return false;
}
