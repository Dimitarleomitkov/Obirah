#ifndef ENEMY_H
#define ENEMY_H

#include <stdint.h>
#include <string>

class Enemy
{
    public:
        Enemy();
        Enemy(uint16_t X,
                uint16_t Y,
                uint16_t level,
                uint64_t health,
                uint64_t max_health,
                uint64_t defense,
                uint64_t attack,
                uint64_t strength,
                uint64_t intelligence,
                uint64_t agility,
                uint16_t awareness,
                std::string name);

        Enemy (const Enemy& old_enemy);
        virtual ~Enemy();

        // Getters
        uint16_t position_X (void);
        uint16_t position_Y (void);
        uint16_t get_Level (void);
        uint64_t get_Health (void);
        uint64_t get_Max_Health (void);
        uint64_t get_Defense (void);
        uint64_t get_Attack (void);
        uint64_t get_Strength (void);
        uint64_t get_Intelligence (void);
        uint64_t get_Agility (void);
        uint16_t get_Awareness (void);
        std::string get_name (void);

        // Setters
        void set_positionX (uint16_t X);
        void set_positionY (uint16_t Y);
        void set_Level (uint16_t Level);
        void set_Health (uint64_t Health);
        void set_Max_Health (uint64_t Max_Health);
        void set_Defense (uint64_t Defense);
        void set_Attack (uint64_t Attack);
        void set_Strength (uint64_t Strength);
        void set_Intelligence (uint64_t Intelligence);
        void set_Agility (uint64_t Agility);
        void set_Awareness (uint16_t Awareness);
        void set_name (std::string Name);

    protected:
    private:
        uint16_t positionX;
        uint16_t positionY;

        uint16_t level;
        uint64_t health;
        uint64_t max_health;
        uint64_t defense;
        uint64_t attack;
        uint64_t strength;
        uint64_t intelligence;
        uint64_t agility;
        uint16_t awareness;
        std::string name;
};

#endif // ENEMY_H
