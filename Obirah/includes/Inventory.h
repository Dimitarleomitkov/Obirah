#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"
#include "Consumable.h"
#include "Craftable.h"
#include "Equipment.h"

class Inventory
{
    public:
        Inventory ();
        virtual ~Inventory ();

        // Getters
        Consumable get_consumable (uint64_t index);
        Craftable get_craftable (uint64_t index);
        Equipment get_equipment (uint64_t index);
        uint64_t get_number_of_consumables (void);
        uint64_t get_number_of_craftables (void);
        uint64_t get_number_of_equipment (void);

        // Setters


        // Other functions
        void add_consumable (Consumable& new_consumable);
        void add_craftable (Craftable& new_craftable);
        void add_equipment (Equipment& new_equipment);

    protected:
    private:
    std::vector<Consumable> consumables;
    std::vector<Craftable> craftables;
    std::vector<Equipment> equipment;
};

#endif // INVENTORY_H
