#include "../includes/Gameplay.h"
#include <string>
#include <iostream>
#include <conio.h>

bool Enemy_collide (e_Directions direction, Gamespace& gamespace)
{
    // Get the position of the player
    uint16_t x_pos = gamespace.get_player().PositionX();
    uint16_t y_pos = gamespace.get_player().PositionY();

    // Get the encountered enemy
    Enemy dummy_enemy;
    switch (direction) {
        case D_UP:
            dummy_enemy = gamespace.get_enemy (x_pos - 1, y_pos);
            break;
        case D_LEFT:
            dummy_enemy = gamespace.get_enemy (x_pos, y_pos - 1);
            break;
        case D_DOWN:
            dummy_enemy = gamespace.get_enemy (x_pos + 1, y_pos);
            break;
        case D_RIGHT:
            dummy_enemy = gamespace.get_enemy (x_pos, y_pos + 1);
            break;
    }

    combat_window (dummy_enemy, gamespace);

    return true;
}

void combat_window (Enemy& enemy, Gamespace& gamespace)
{
    Player dummy_player = gamespace.get_player();


    // Menu options
    int menu_length = 4;
    std::string menu_items[menu_length] = {"Attacks", "Buffs", "Defences", "Consumables"};

    int i = 0;
    int selector_position = 0;

Combat_Options:
    do {
        clear_screen ();
        // Battle print
        battle_setup (enemy, dummy_player);
        std::cout << std::endl;

        // Combat options
        for (i = 0; i < selector_position; ++i) {
            std::cout << menu_items[i] << std::endl;
        }
        std::cout << menu_items[i] << " <" << std::endl;
        ++i;
        for (; i < menu_length; ++i) {
            std::cout << menu_items[i] << std::endl;
        }
    } while (!Selector(selector_position, menu_length));

    switch (selector_position) {
        // Attacks
        case 0:
            Choose_attack (dummy_player);
            goto Combat_Options;
        // Buffs
        case 1:
            break;
            goto Combat_Options;
        // Defences
        case 2:
            break;
            goto Combat_Options;
        // Consumables
        case 3:
            break;
            goto Combat_Options;
        default:
            break;
    }
}

void battle_setup (Enemy& enemy, Player& dummy_player)
{
    std::string msg = "";
    msg += enemy.get_name();
    msg += " (lvl ";
    msg += std::to_string(enemy.get_Level());
    msg += ")\n";
    msg += "HP ";
    msg += std::to_string(enemy.get_Health());
    msg += " / ";
    msg += std::to_string(enemy.get_Max_Health());

    msg += "\n\n\n";

    msg += dummy_player.get_name();
    msg += " (lvl ";
    msg += std::to_string(dummy_player.get_level());
    msg += ")\n";
    msg += "HP ";
    msg += std::to_string(dummy_player.get_Health());
    msg += " / ";
    msg += std::to_string(dummy_player.get_maxHealth());

    std::cout << msg << std::endl;
}
