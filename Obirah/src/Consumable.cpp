#include "../includes/Consumable.h"

Consumable::Consumable()
{
    //ctor
    name = "Unknown";
    quantity = 0;
    max_quantity = 1;
}

Consumable::Consumable (std::string Name, int Quantity, int Max_Quantity)
{
    name = Name;
    quantity = Quantity;
    max_quantity = Max_Quantity;
}

Consumable::~Consumable()
{
    //dtor
}
