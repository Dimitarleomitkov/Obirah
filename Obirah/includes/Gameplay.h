#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Gamespace.h"

enum e_Commands {
    INVALID = 0,
    GAME_MENU = 1,
    UP = 2,
    LEFT = 3,
    DOWN = 4,
    RIGHT = 5,
    CHARACTER_WINDOW = 6,
    // DEBUG commands
    NEXT_LEVEL = 7,
    PREVIOUS_LEVEL = 8
};

enum e_Directions {
    D_UP = 0,
    D_LEFT = 1,
    D_DOWN = 2,
    D_RIGHT = 3
};

void clear_screen (void);
void worldFrame (Gamespace& gamespace);
void npc_move (Gamespace& gamespace);

e_Commands PlayerInput (Gamespace& gamespace);
e_Commands ParseInput (char input);

void Player_move_up (Gamespace& the_player);
void Player_move_left (Gamespace& the_player);
void Player_move_down (Gamespace& the_player);
void Player_move_right (Gamespace& the_player);

bool check_collision (e_Directions direction, Gamespace& gamespace);
bool Empty_collide (Gamespace& gamespace);
bool Gate_collide (e_Directions direction, Gamespace& gamespace);
bool Door_collide (e_Directions direction, Gamespace& gamespace);
bool find_key (Gamespace& gamespace);
bool Road_collide (e_Directions direction, Gamespace& gamespace);
bool NPC_collide (e_Directions direction, Gamespace& gamespace);

void Nira_1_window (NPChar& dummy_NPC, Gamespace& gamespace);
void Jack_1_window (NPChar& dummy_NPC, Gamespace& gamespace);
void Rick_1_window (NPChar& dummy_NPC, Gamespace& gamespace);

std::string set_player_name_event ();
void initial_Rick_RP_window (NPChar& dummy_NPC, Gamespace& gamespace);

bool Selector (int& selector_position, int n_menu_items);

void Character_window (Gamespace& gamespace);
void Inventory_window (Player& dummy_player);
void Consumables_window (Player& dummy_player);
void Craftables_window (Player& dummy_player);
void Equipment_window (Player& dummy_player);

e_Commands restart_game (Gamespace& gamespace);

#endif // GAMEPLAY_H
