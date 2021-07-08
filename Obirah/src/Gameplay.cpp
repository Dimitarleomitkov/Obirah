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

bool Empty_collide (Gamespace& gamespace)
{
    // TODO: check for hidden collision

    return false;
}

bool Gate_collide (e_Directions direction, Gamespace& gamespace)
{
    // Find out which level we are on
    uint16_t current_map_level = gamespace.get_map_level ();
    Player dummy_player = gamespace.get_player();

    switch (current_map_level) {
        case 1:
            gamespace.set_map_level(2);
            dummy_player.set_PositionX (0);
            if (direction == D_LEFT) {
                dummy_player.set_PositionY (5);
            } else {
                dummy_player.set_PositionY (6);
            }
            // Set the player
            gamespace.set_player (dummy_player);
            gamespace.generate_level ();
            break;
        case 2:
            gamespace.set_map_level(1);
            dummy_player.set_PositionX (11);
            if (direction == D_LEFT) {
                dummy_player.set_PositionY (5);
            } else {
                dummy_player.set_PositionY (6);
            }
            // Set the player
            gamespace.set_player (dummy_player);
            gamespace.generate_level ();
            break;
        default:
            break;
    }

    return false;
}

bool Door_collide (e_Directions direction, Gamespace& gamespace)
{
    // TODO: Find out whether the player has a key

    Player dummy_player = gamespace.get_player();
    // Get the tile index on the Player's position
    uint16_t tile_index = dummy_player.PositionX() * gamespace.get_map_width() + dummy_player.PositionY();

    switch (direction) {
        case D_UP:
            dummy_player.MoveUp ();
            gamespace.set_player (dummy_player);
            gamespace.set_tile(tile_index, gamespace.get_original_map_tile(tile_index));
            break;
        case D_LEFT:
            dummy_player.MoveLeft ();
            gamespace.set_player (dummy_player);
            gamespace.set_tile(tile_index, gamespace.get_original_map_tile(tile_index));
            break;
        case D_DOWN:
            dummy_player.MoveDown ();
            gamespace.set_player (dummy_player);
            gamespace.set_tile(tile_index, gamespace.get_original_map_tile(tile_index));
            break;
        case D_RIGHT:
            dummy_player.MoveRight ();
            gamespace.set_player (dummy_player);
            gamespace.set_tile(tile_index, gamespace.get_original_map_tile(tile_index));
            break;
    }
    return false;
}

bool Road_collide (e_Directions direction, Gamespace& gamespace)
{
    Player dummy_player = gamespace.get_player();

    // Find out which level we are on
    uint16_t current_map_level = gamespace.get_map_level ();

    // Get the current tile index
    uint16_t current_tile_index = dummy_player.PositionX() * gamespace.get_map_width() + dummy_player.PositionY();

    // Check whether there is a collision with a road somewhere on the level
    switch (current_map_level) {
        case 1:
            return false;
        case 2:
            switch (direction) {
                case D_UP:
                    break;
                case D_LEFT:
                    switch (current_tile_index) {
                        case 29 * 30 + 24:
                        case 29 * 30 + 25:
                        case 29 * 30 + 26:
                        case 29 * 30 + 27:
                            gamespace.set_map_level(3);
                            dummy_player.set_PositionX (0);
                            dummy_player.set_PositionY (dummy_player.PositionY() - 22 - 1);
                            // Set the player
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                case D_DOWN:
                    switch (current_tile_index) {
                        case 28 * 30 + 24:
                        case 28 * 30 + 25:
                        case 28 * 30 + 26:
                        case 28 * 30 + 27:
                            gamespace.set_map_level(3);
                            dummy_player.set_PositionX (0);
                            dummy_player.set_PositionY (dummy_player.PositionY() - 22);
                            // Set the player
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                    break;
                case D_RIGHT:
                    switch (current_tile_index) {
                        case 29 * 30 + 23:
                        case 29 * 30 + 24:
                        case 29 * 30 + 25:
                        case 29 * 30 + 26:
                            gamespace.set_map_level(3);
                            dummy_player.set_PositionX (0);
                            dummy_player.set_PositionY (dummy_player.PositionY() - 22 + 1);
                            // Set the player
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                    break;
            }
            break;
        case 3:
            switch (direction) {
                case D_UP:
                    switch (current_tile_index) {
                        case 1 * 33 + 1:
                        case 1 * 33 + 2:
                        case 1 * 33 + 3:
                        case 1 * 33 + 4:
                        case 1 * 33 + 5:
                            gamespace.set_map_level(2);
                            dummy_player.set_PositionX (29);
                            dummy_player.set_PositionY (dummy_player.PositionY() + 22);
                            // Set the player
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                    break;
                case D_LEFT:
                    switch (current_tile_index) {
                        case 0 * 33 + 2:
                        case 0 * 33 + 3:
                        case 0 * 33 + 4:
                        case 0 * 33 + 5:
                            gamespace.set_map_level(2);
                            dummy_player.set_PositionX (29);
                            dummy_player.set_PositionY (dummy_player.PositionY() + 22 - 1);
                            // Set the player
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                case D_DOWN:
                    break;
                case D_RIGHT:
                    switch (current_tile_index) {
                        case 0 * 33 + 1:
                        case 0 * 33 + 2:
                        case 0 * 33 + 3:
                        case 0 * 33 + 4:
                            gamespace.set_map_level(2);
                            dummy_player.set_PositionX (29);
                            dummy_player.set_PositionY (dummy_player.PositionY() + 22 + 1);
                            // Set the player
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                    break;
            }
            break;
        case 4:
            return false;
        case 5:
            return false;
        default:
            break;
    }

    return false;
}
