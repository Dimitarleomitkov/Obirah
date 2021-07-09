#include "../includes/Gameplay.h"

bool find_key (Gamespace& gamespace)
{
    // Find out which level we are on
    uint16_t current_map_level = gamespace.get_map_level ();
    Player dummy_player = gamespace.get_player();
    // Get the tile index on the Player's position
    uint16_t tile_index = dummy_player.PositionX() * gamespace.get_map_width() + dummy_player.PositionY();

    switch (current_map_level) {
        case 5:
            switch (tile_index) {
                case 10 * 43 + 13:
                    return false;
            }
        default:
            return true;
    }

    return true;
}
