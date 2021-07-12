#include "Gameplay.h"

enum e_Commands_Menu {
    MENU_EXIT = 0,
    MENU_UP = 1,
    MENU_DOWN = 2,
    MENU_SELECT = 3,
    MENU_INVALID = 5,
};

void draw_menu (bool game_started);
bool Menu_Input (e_Commands& game_command, bool& game_started);
e_Commands_Menu ParseMenuInput (char input);