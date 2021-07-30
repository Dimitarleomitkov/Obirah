#include "../includes/Attack.h"

// ctors
Attack::Attack ()
{
    name = "Self Harm";
    power = 1000000;
    cast_time = 0;
}

Attack::Attack (std::string Name, uint64_t Power, uint16_t Cast_Time)
{
    name = Name;
    power = Power;
    cast_time = Cast_Time;
}

// dtor
Attack::~Attack ()
{

}

// Getters
std::string Attack::get_name (void)
{
    return name;
}

uint64_t Attack::get_power (void)
{
    return power;
}

uint16_t Attack::get_cast_time (void)
{
    return cast_time;
}

// Setters
void Attack::set_name (std::string Name)
{
    name = Name;
}

void Attack::set_power (uint64_t Power)
{
    power = Power;
}

void Attack::set_cast_time (uint16_t Cast_Time)
{
    cast_time = Cast_Time;
}
