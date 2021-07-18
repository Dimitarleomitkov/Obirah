#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "Item.h"

class Consumable: public Item
{
    public:
        // Ctors
        Consumable ();
        Consumable (std::string Name, int Quantity, int Max_Quantity);
        virtual ~Consumable ();
    protected:
    private:
};

// Table of all the available consumables in the game

#endif // CONSUMABLE_H
