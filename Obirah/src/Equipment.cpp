#include "../includes/Equipment.h"

Equipment::Equipment()
{
    //ctor
    name = "Unknown";
    quantity = 0;
    max_quantity = 1;
}

Equipment::Equipment (std::string Name)
{
    name = Name;
    quantity = 1;
}

Equipment::~Equipment()
{
    //dtor
}
