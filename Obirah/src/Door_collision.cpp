#include "../includes/Gameplay.h"

bool Door_collide (e_Directions direction, Gamespace& gamespace)
{
    // TODO: Find out whether the player has a key
    if (!find_key(gamespace)) {
        gamespace.set_message ("The door is locked.");
        return true;
    }

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
