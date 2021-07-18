#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "Item.h"

class Equipment: public Item
{
    public:
        Equipment ();
        Equipment (std::string Name);
        virtual ~Equipment ();
    protected:
    private:
};

// Table of all the available equipment in the game

#endif // EQUIPMENT_H
