#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <stdint.h>

class Item
{
    public:
        // Ctors
        Item ();
        Item (std::string Name, int Quantity, int Max_Qantity);
        // Copy ctor
        Item (const Item& old_item);
        // Dtor
        virtual ~Item ();

        // Getters
        std::string get_name (void);
        uint64_t get_quantity (void);
        uint64_t get_max_quantity (void);

        // Setters
        void set_name (std::string Name);
        void set_quantity (uint64_t Quantity);
        void set_max_quantity (uint64_t Max_Quantity);

        // Other functions
        void increase_quantity (uint64_t amount);

        void decrease_quantity (uint64_t amount);
    protected:
        std::string name;
        uint64_t quantity;
        uint64_t max_quantity;
    private:
};

#endif // ITEM_H
