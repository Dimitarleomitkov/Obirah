#ifndef NPC_H
#define NPC_H

#include <stdint.h>
#include <string>

class NPChar
{
    public:
        NPChar ();
        NPChar (uint16_t x, uint16_t y, std::string Name);
        // Copy ctor
        NPChar (const NPChar& old_npc);
        virtual ~NPChar ();

        // Getters
        uint16_t get_position_x (void);
        uint16_t get_position_y (void);
        std::string get_name (void);
        // Setters
        void set_position_x (uint16_t x);
        void set_position_y (uint16_t y);
        void set_name (std::string Name);
    protected:
    private:
        // Location in the world
        uint16_t position_x;
        uint16_t position_y;
        // Name
        std::string name;
};

#endif // NPC_H
