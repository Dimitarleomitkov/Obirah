#include "../includes/Inventory.h"

Inventory::Inventory()
{
    //ctor
}

Inventory::~Inventory()
{
    //dtor
}

// Getters
Consumable Inventory::get_consumable (uint64_t index)
{
    return consumables[index];
}

Craftable Inventory::get_craftable (uint64_t index)
{
    return craftables[index];
}

Equipment Inventory::get_equipment (uint64_t index)
{
    return equipment[index];
}

uint64_t Inventory::get_number_of_consumables (void)
{
    return consumables.size ();
}

uint64_t Inventory::get_number_of_craftables (void)
{
    return craftables.size ();
}

uint64_t Inventory::get_number_of_equipment (void)
{
    return equipment.size ();
}

// Setters


// Other functions
void Inventory::add_consumable (Consumable& new_consumable)
{
    for (unsigned int i = 0; i < get_number_of_consumables(); ++i) {
        if (consumables[i].get_name() == new_consumable.get_name()) {
            if (consumables[i].get_quantity() < consumables[i].get_max_quantity()) {
                consumables[i].increase_quantity (1);
            }
            return;
        }
    }

    consumables.push_back (new_consumable);
}

void Inventory::add_craftable (Craftable& new_craftable)
{
    for (unsigned int i = 0; i < get_number_of_craftables(); ++i) {
        if (craftables[i].get_name() == new_craftable.get_name()) {
            if (craftables[i].get_quantity() < craftables[i].get_max_quantity()) {
                craftables[i].increase_quantity (1);
            }
            return;
        }
    }

    craftables.push_back (new_craftable);
}

void Inventory::add_equipment (Equipment& new_equipment)
{
    for (unsigned int i = 0; i < get_number_of_equipment(); ++i) {
        if (equipment[i].get_name() == new_equipment.get_name()) {
            return;
        }
    }
    equipment.push_back (new_equipment);
}
