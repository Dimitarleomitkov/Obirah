#include "../includes/Craftable.h"

Craftable::Craftable()
{
    //ctor
    name = "Unknown";
    quantity = 0;
    max_quantity = 1;
}

Craftable::Craftable (std::string Name, int Quantity, int Max_Quantity)
{
    name = Name;
    quantity = Quantity;
    max_quantity = Max_Quantity;
}

Craftable::~Craftable()
{
    //dtor
}
