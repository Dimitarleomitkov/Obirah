#ifndef CRAFTABLE_H
#define CRAFTABLE_H

#include "Item.h"

class Craftable: public Item
{
    public:
        Craftable ();
        Craftable (std::string Name, int Quantity, int Max_Quantity);
        virtual ~Craftable ();
    protected:
    private:
};

// Table of all the available craftables in the game

#endif // CRAFTABLE_H
