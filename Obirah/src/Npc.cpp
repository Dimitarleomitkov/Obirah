#include "../includes/NPC.h"
#include <string.h>

//ctors
NPChar::NPChar ()
{
    position_x = 0;
    position_y = 0;
    name = "Mistake";
}

NPChar::NPChar (uint16_t x, uint16_t y, std::string Name)
{
    position_x = x;
    position_y = y;
    name = Name;
}

// Copy ctor
NPChar::NPChar (const NPChar& old_npc)
{
    position_x = old_npc.position_x;
    position_y = old_npc.position_y;
    name = old_npc.name;
}

//dtor
NPChar::~NPChar ()
{

}

// Getters

uint16_t NPChar::get_position_x (void)
{
    return position_x;
}

uint16_t NPChar::get_position_y (void)
{
    return position_y;
}

std::string NPChar::get_name (void)
{
    return name;
}

// Setters

void NPChar::set_position_x (uint16_t x)
{
    position_x = x;
}

void NPChar::set_position_y (uint16_t y)
{
    position_y = y;
}

void NPChar::set_name (std::string Name)
{
    name = Name;
}
