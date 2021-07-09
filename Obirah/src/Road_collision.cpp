#include "../includes/Gameplay.h"

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
                            gamespace.set_map_level (3);
                            dummy_player.set_PositionX (0);
                            dummy_player.set_PositionY (dummy_player.PositionY() - 22 - 1);
                            // Set the player
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                    break;
                case D_DOWN:
                    switch (current_tile_index) {
                        case 28 * 30 + 24:
                        case 28 * 30 + 25:
                        case 28 * 30 + 26:
                        case 28 * 30 + 27:
                            gamespace.set_map_level (3);
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
                            gamespace.set_map_level (3);
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
                    // Upper left exit
                    switch (current_tile_index) {
                        case 1 * 33 + 1:
                        case 1 * 33 + 2:
                        case 1 * 33 + 3:
                        case 1 * 33 + 4:
                        case 1 * 33 + 5:
                            gamespace.set_map_level (2);
                            dummy_player.set_PositionX (29);
                            dummy_player.set_PositionY (dummy_player.PositionY() - 18);
                            // Set the player
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                    // Bottom right exit
                    switch (current_tile_index) {
                        case 15 * 33 + 32:
                            gamespace.set_message ("To be implemented...\n");
                            return false;
                    }
                    // Upper right exit
                    switch (current_tile_index) {
                        case 1 * 33 + 29:
                        case 1 * 33 + 30:
                        case 1 * 33 + 31:
                            gamespace.set_map_level (4);
                            dummy_player.set_PositionX (28);
                            dummy_player.set_PositionY (dummy_player.PositionY() - 18);
                            // Set the player
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                    break;
                case D_LEFT:
                    // Upper left exit
                    switch (current_tile_index) {
                        case 0 * 33 + 2:
                        case 0 * 33 + 3:
                        case 0 * 33 + 4:
                        case 0 * 33 + 5:
                            gamespace.set_map_level (2);
                            dummy_player.set_PositionX (29);
                            dummy_player.set_PositionY (dummy_player.PositionY() - 18 - 1);
                            // Set the player
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                    // Upper right exit
                    switch (current_tile_index) {
                        case 0 * 33 + 30:
                        case 0 * 33 + 31:
                            gamespace.set_map_level (4);
                            dummy_player.set_PositionX (28);
                            dummy_player.set_PositionY (dummy_player.PositionY() - 18 - 1);
                            // Set the player
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                    break;
                case D_DOWN:
                    // Bottom right exit
                    switch (current_tile_index) {
                        case 13 * 33 + 32:
                            gamespace.set_message ("To be implemented...\n");
                            return false;
                    }
                    break;
                case D_RIGHT:
                    // Upper left exit
                    switch (current_tile_index) {
                        case 0 * 33 + 1:
                        case 0 * 33 + 2:
                        case 0 * 33 + 3:
                        case 0 * 33 + 4:
                            gamespace.set_map_level (2);
                            dummy_player.set_PositionX (29);
                            dummy_player.set_PositionY (dummy_player.PositionY() - 18 + 1);
                            // Set the player
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                    // Bottom right exit
                    switch (current_tile_index) {
                        case 14 * 33 + 31:
                            gamespace.set_message ("To be implemented...\n");
                            return false;
                    }
                    // Upper right exit
                    switch (current_tile_index) {
                        case 0 * 33 + 29:
                        case 0 * 33 + 30:
                            gamespace.set_map_level (4);
                            dummy_player.set_PositionX (28);
                            dummy_player.set_PositionY (dummy_player.PositionY() - 18 + 1);
                            // Set the player
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                    break;
            }
            break;
        case 4:
            switch (direction) {
                case D_UP:
                    break;
                case D_LEFT:
                    // Bottom exit
                    switch (current_tile_index) {
                        case 28 * 33 + 12:
                        case 28 * 33 + 13:
                            gamespace.set_map_level (3);
                            dummy_player.set_PositionX (0);
                            dummy_player.set_PositionY (dummy_player.PositionY() + 18 - 1);
                            // Set the player
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                    break;
                case D_DOWN:
                    // Bottom exit
                    switch (current_tile_index) {
                        case 27 * 33 + 11:
                        case 27 * 33 + 12:
                        case 27 * 33 + 13:
                            gamespace.set_map_level (3);
                            dummy_player.set_PositionX (0);
                            dummy_player.set_PositionY (dummy_player.PositionY() + 18);
                            // Set the player
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                    break;
                case D_RIGHT:
                    // Bottom exit
                    switch (current_tile_index) {
                        case 28 * 33 + 11:
                        case 28 * 33 + 12:
                            gamespace.set_map_level (3);
                            dummy_player.set_PositionX (0);
                            dummy_player.set_PositionY (dummy_player.PositionY() + 18 + 1);
                            // Set the player
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                    break;
            }
            break;
            return false;
        case 5:
            return false;
        default:
            break;
    }

    return false;
}
