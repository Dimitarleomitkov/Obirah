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

void Player_move_up (Gamespace& gamespace)
{
    // Check for collision
    bool collision = check_collision (D_UP, gamespace);

    if (collision == true) {
        return;
    } else {
        Player dummy_player = gamespace.get_player();
        uint16_t tile_index = dummy_player.PositionX() * gamespace.get_map_width() + dummy_player.PositionY();

        dummy_player.MoveUp(1);
        gamespace.set_player(dummy_player);
        gamespace.set_tile(tile_index, gamespace.get_original_map_tile(tile_index));
    }
}

void Player_move_left (Gamespace& gamespace)
{
    // Check for collision
    bool collision = check_collision (D_LEFT, gamespace);

    if (collision == true) {
        return;
    } else {
        Player dummy_player = gamespace.get_player();
        uint16_t tile_index = dummy_player.PositionX() * gamespace.get_map_width() + dummy_player.PositionY();

        dummy_player.MoveLeft(1);
        gamespace.set_player(dummy_player);
        gamespace.set_tile(tile_index, gamespace.get_original_map_tile(tile_index));
    }
}

void Player_move_down (Gamespace& gamespace)
{
    // Check for collision
    bool collision = check_collision (D_DOWN, gamespace);

    if (collision == true) {
        return;
    } else {
        Player dummy_player = gamespace.get_player();
        uint16_t tile_index = dummy_player.PositionX() * gamespace.get_map_width() + dummy_player.PositionY();

        dummy_player.MoveDown(1);
        gamespace.set_player(dummy_player);
        gamespace.set_tile(tile_index, gamespace.get_original_map_tile(tile_index));
    }
}

void Player_move_right (Gamespace& gamespace)
{
    // Check for collision
    bool collision = check_collision (D_RIGHT, gamespace);

    if (collision == true) {
        return;
    } else {
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

    uint16_t index;
    e_TileType dummy_tile;

    switch (direction) {
        case D_UP:
            // Calculate the tile index
            index = (x_pos - 1) * gamespace.get_map_width() + y_pos;
            // Get the tile
            dummy_tile = gamespace.get_map_tile(index);
            if (dummy_tile != EMPTY && dummy_tile != ROAD) {
                break;
            }
            return false;
        case D_LEFT:
            // Calculate the tile index
            index = x_pos * gamespace.get_map_width() + (y_pos - 1);
            // Get the tile
            dummy_tile = gamespace.get_map_tile(index);
            if (dummy_tile != EMPTY && dummy_tile != ROAD) {
                break;
            }
            return false;
        case D_DOWN:
            // Calculate the tile index
            index = (x_pos + 1) * gamespace.get_map_width() + y_pos;
            // Get the tile
            dummy_tile = gamespace.get_map_tile(index);
            if (dummy_tile != EMPTY && dummy_tile != ROAD) {
                break;
            }
            return false;
        case D_RIGHT:
            // Calculate the tile index
            index = x_pos * gamespace.get_map_width() + (y_pos + 1);
            // Get the tile
            dummy_tile = gamespace.get_map_tile(index);
            if (dummy_tile != EMPTY && dummy_tile != ROAD) {
                break;
            }
            return false;
        default:
            std::cerr << "No such direction.\n" << std::endl;
            break;
    }

    // Handle the collision
    switch (dummy_tile) {
        case EMPTY:
            // Something has gone seriously wrong
            break;
        case PLAYER:
            // Something has gone seriously wrong
            break;
        case NPC:
            // Something else should happen here
            break;
        case ENEMY:
            // Something else should happen here
            break;
        case DOOR:
            // Something else should happen here
            break;
        case GATE:
            // Something else should happen here
            break;
        case TREE:
            gamespace.set_message ("There is a tree in the way.\n");
            break;
        case BUSH:
            gamespace.set_message ("There is a lovely flowery bush in the way.\n");
            break;
        case ROAD:
            // Something has gone seriously wrong
            break;
        case WALL:
            gamespace.set_message ("There is a wall in the way.\n");
            break;
        case DOWNWALL:
            gamespace.set_message ("There is a wall in the way.\n");
            break;
        case WATER:
            // Something else should happen here
            break;
        case STONE:
            gamespace.set_message ("There is a boulder in the way.\n");
            break;
        case UNKNOWN:
            // Something else should happen here
            break;
    }

    return true;
}
