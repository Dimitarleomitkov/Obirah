#ifndef ATTACK_H
#define ATTACK_H

#include <string>
#include <stdint.h>

class Attack
{
    public:
        // ctor
        Attack ();
        Attack (std::string Name, uint64_t Power, uint16_t Cast_Time);
        // dtor
        virtual ~Attack ();

        // Getters
        std::string get_name (void);
        uint64_t get_power (void);
        uint16_t get_cast_time (void);

        // Setters
        void set_name (std::string Name);
        void set_power (uint64_t Power);
        void set_cast_time (uint16_t Cast_Time);

    protected:
    private:
        std::string name;
        uint64_t power;
        // In game turns
        uint16_t cast_time;
};

#endif // ATTACK_H
