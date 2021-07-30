#include "../includes/Gameplay.h"
#include <string>
#include <iostream>

void Choose_attack (Player& dummy_player)
{
    // Menu options
    int menu_length = dummy_player.get_number_of_attacks() + 1;
    std::string menu_items[menu_length];
    Attack dummy_attack;

    for (int j = 0; j < menu_length - 1; ++j) {
        dummy_attack = dummy_player.get_attack(j);
        menu_items[j] = dummy_attack.get_name();
        menu_items[j] += " ";
        menu_items[j] += std::to_string(dummy_attack.get_power());
        menu_items[j] += " [";
        menu_items[j] += std::to_string(dummy_attack.get_cast_time());
        menu_items[j] += "]";
    }
    menu_items[menu_length - 1] = "Back";

    int i = 0;
    int selector_position = 0;

    do {
        clear_screen ();

        // Attack list options
        for (i = 0; i < selector_position; ++i) {
            std::cout << menu_items[i] << std::endl;
        }
        std::cout << menu_items[i] << " <" << std::endl;
        ++i;
        for (; i < menu_length; ++i) {
            std::cout << menu_items[i] << std::endl;
        }
    } while (!Selector(selector_position, menu_length));

}
