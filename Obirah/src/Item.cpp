#include "../includes/Item.h"

//ctors
Item::Item()
{

}

Item::Item (std::string Name, int Quantity, int Max_Qantity)
{
    name = Name;
    quantity = Quantity;
    max_quantity = Max_Qantity;
}

// Copy ctor
Item::Item (const Item& old_item)
{
    name = old_item.name;
    quantity = old_item.quantity;
    max_quantity = old_item.max_quantity;
}

Item::~Item()
{
    //dtor
}

// Getters
std::string Item::get_name (void)
{
    return name;
}

uint64_t Item::get_quantity (void)
{
    return quantity;
}

uint64_t Item::get_max_quantity (void)
{
    return max_quantity;
}

// Setters
void Item::set_name (std::string Name)
{
    name = Name;
}

void Item::set_quantity (uint64_t Quantity)
{
    quantity = Quantity;
}

void Item::set_max_quantity (uint64_t Max_Quantity)
{
    max_quantity = Max_Quantity;
}

// Other functions
void Item::increase_quantity (uint64_t amount)
{
    quantity += amount;
}

void Item::decrease_quantity (uint64_t amount)
{
    quantity -= amount;
}
