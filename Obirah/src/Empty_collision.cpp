#include "../includes/Gameplay.h"

bool Empty_collide (e_Directions direction, Gamespace& gamespace)
{
    Player dummy_player = gamespace.get_player();

    // Find out which level we are on
    uint16_t current_map_level = gamespace.get_map_level ();

    // Get the current tile index
    uint16_t current_tile_index = dummy_player.PositionX() * gamespace.get_map_width() + dummy_player.PositionY();

    // Check whether there is a collision with a road somewhere on the level
    switch (current_map_level) {
        // Mitsko Bridge
        case 3:
            switch (direction) {
                case D_UP:
                    // Bottom right exit
                    switch (current_tile_index) {
                        case 14 * 33 + 32:
                            gamespace.set_map_level (4);
                            dummy_player.set_PositionX (1);
                            dummy_player.set_PositionY (0);
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                    break;
                case D_DOWN:
                    // Bottom right exit
                    switch (current_tile_index) {
                        case 14 * 33 + 32:
                            gamespace.set_map_level (4);
                            dummy_player.set_PositionX (3);
                            dummy_player.set_PositionY (0);
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                    break;
                case D_RIGHT:
                    // Bottom right exit
                    switch (current_tile_index) {
                        case 13 * 33 + 31:
                        case 15 * 33 + 31:
                            gamespace.set_map_level (4);
                            dummy_player.set_PositionX (dummy_player.PositionX() - 12);
                            dummy_player.set_PositionY (0);
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                    break;
                default:
                    break;
            }
            break;
        // Mitsko Woods
        case 4:
            switch (direction) {
                case D_UP:
                    // Top Left
                    switch (current_tile_index) {
                        case 2 * 25 + 0:
                            gamespace.set_map_level (3);
                            dummy_player.set_PositionX (13);
                            dummy_player.set_PositionY (32);
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                    break;
                case D_LEFT:
                    // Top Left
                    switch (current_tile_index) {
                        case 1 * 25 + 1:
                        case 3 * 25 + 1:
                            gamespace.set_map_level (3);
                            dummy_player.set_PositionX (dummy_player.PositionX() + 12);
                            dummy_player.set_PositionY (32);
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                    // Bottom Left
                    switch (current_tile_index) {
                        case 13 * 25 + 1:
                            gamespace.set_map_level (5);
                            dummy_player.set_PositionX (8);
                            dummy_player.set_PositionY (37);
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                    break;
                        case D_DOWN:
                    // Top Left
                    switch (current_tile_index) {
                        case 2 * 25 + 0:
                            gamespace.set_map_level (3);
                            dummy_player.set_PositionX (15);
                            dummy_player.set_PositionY (32);
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                    break;
                default:
                    break;
            }
            break;
        // Mitsko River
        case 5:
            switch (direction) {
                case D_RIGHT:
                    // Right center
                    switch (current_tile_index) {
                        case 8 * 38 + 36:
                            gamespace.set_map_level (4);
                            dummy_player.set_PositionX (13);
                            dummy_player.set_PositionY (0);
                            gamespace.set_player (dummy_player);
                            gamespace.generate_level ();
                            return true;
                    }
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }

    return false;
}
