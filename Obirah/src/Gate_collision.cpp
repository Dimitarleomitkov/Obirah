#include "../includes/Gameplay.h"

bool Gate_collide (e_Directions direction, Gamespace& gamespace)
{
    // Find out which level we are on
    uint16_t current_map_level = gamespace.get_map_level ();
    Player dummy_player = gamespace.get_player();

    // Get the current tile index
    uint16_t current_tile_index = dummy_player.PositionX() * gamespace.get_map_width() + dummy_player.PositionY();

    switch (current_map_level) {
        case 1:
            gamespace.set_map_level (2);
            dummy_player.set_PositionX (0);
            if (direction == D_LEFT) {
                dummy_player.set_PositionY (5);
            } else if (direction == D_RIGHT) {
                dummy_player.set_PositionY (6);
            }
            // Set the player
            gamespace.set_player (dummy_player);
            gamespace.generate_level ();
            break;
        case 2:
            gamespace.set_map_level (1);
            dummy_player.set_PositionX (11);
            if (direction == D_LEFT) {
                dummy_player.set_PositionY (5);
            } else if (direction == D_RIGHT) {
                dummy_player.set_PositionY (6);
            }
            // Set the player
            gamespace.set_player (dummy_player);
            gamespace.generate_level ();
            break;
        case 4:
            gamespace.set_map_level (5);
            dummy_player.set_PositionX (11);
            if (direction == D_LEFT) {
                dummy_player.set_PositionY (dummy_player.PositionY() + 9 - 1);
            } else if (direction == D_RIGHT) {
                dummy_player.set_PositionY (dummy_player.PositionY() + 9 + 1);
            } else {
                dummy_player.set_PositionY (dummy_player.PositionY() + 9);
            }
            // Set the player
            gamespace.set_player (dummy_player);
            gamespace.generate_level ();
            break;
        case 5:
            switch (direction) {
                case D_UP:
                    // Right exit
                    switch (current_tile_index) {
                        case 6 * 43 + 42:
                            gamespace.set_message ("To be implemented...\n");
                            return true;
                    }
                    break;
                case D_LEFT:
                    // Bottom exit
                    switch (current_tile_index) {
                        case 11 * 43 + 33:
                        case 11 * 43 + 34:
                        case 11 * 43 + 36:
                            gamespace.set_map_level (4);
                            dummy_player.set_PositionX (0);
                            dummy_player.set_PositionY (dummy_player.PositionY() - 9 - 1);
                            // Set the player
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                    break;
                case D_DOWN:
                    // Right exit
                    switch (current_tile_index) {
                        case 5 * 43 + 42:
                            gamespace.set_message ("To be implemented...\n");
                            return true;
                    }
                    // Bottom exit
                    switch (current_tile_index) {
                        case 10 * 43 + 32:
                        case 10 * 43 + 33:
                        case 10 * 43 + 35:
                        case 10 * 43 + 36:
                            gamespace.set_map_level (4);
                            dummy_player.set_PositionX (0);
                            dummy_player.set_PositionY (dummy_player.PositionY() - 9);
                            // Set the player
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                    break;
                case D_RIGHT:
                    // Right exit
                    switch (current_tile_index) {
                        case 5 * 43 + 41:
                        case 6 * 43 + 41:
                            gamespace.set_message ("To be implemented...\n");
                            return true;
                    }
                    // Bottom exit
                    switch (current_tile_index) {
                        case 11 * 43 + 32:
                        case 11 * 43 + 34:
                        case 11 * 43 + 35:
                            gamespace.set_map_level (4);
                            dummy_player.set_PositionX (0);
                            dummy_player.set_PositionY (dummy_player.PositionY() - 9 + 1);
                            // Set the player
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                    break;
            }
            break;
        default:
            break;
    }

    return false;
}
