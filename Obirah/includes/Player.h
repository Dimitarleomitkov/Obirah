#ifndef PLAYER_H
#define PLAYER_H

#include <stdint.h>
#include <string>
#include "Inventory.h"

class Player
{
    public:
        // ctor
        Player ();
        // dtor
        virtual ~Player ();

        // Setting functions for the position of the player
        void MoveUp (uint8_t numberOfPositions = 1);
        void MoveLeft (uint8_t numberOfPositions = 1);
        void MoveDown (uint8_t numberOfPositions = 1);
        void MoveRight (uint8_t numberOfPositions = 1);
        void set_PositionX (uint16_t x);
        void set_PositionY (uint16_t y);

        // Getting functions for the position of the player
        uint16_t PositionX (void);
        uint16_t PositionY (void);

        // Setting function for the name
        void set_name (std::string Name);
        void set_level (uint16_t Level);
        void set_Health (uint64_t Health);
        void set_maxHealth (uint64_t Health);
        void set_Agility (uint64_t Agility);
        void set_Strength (uint64_t Strength);
        void set_Intelligence (uint64_t Intelligence);
        void set_Awareness (uint64_t Awareness);
        void set_xp (uint64_t XP);
        void set_xp_next_level (uint64_t XP);

        // Increase functions for the attributes of the player
        void IncreaseHealth (uint64_t amount);
        void IncreaseAgility (uint64_t amount);
        void IncreaseStrength (uint64_t amount);
        void IncreaseIntelligence (uint64_t amount);
        void IncreaseAwareness (uint8_t amount);
        void IncreaseXP (uint64_t amount);

        // Decrease functions for the attributes of the player
        void DecreaseHealth (uint64_t amount);
        void DecreaseAgility (uint64_t amount);
        void DecreaseStrength (uint64_t amount);
        void DecreaseIntelligence (uint64_t amount);
        void DecreaseAwareness (uint8_t amount);
        void DecreaseXP (uint64_t amount);

        // Getting functions for the attributes of the player
        uint16_t get_level (void);
        uint64_t get_Health (void);
        uint64_t get_maxHealth (void);
        uint64_t get_Agility (void);
        uint64_t get_Strength (void);
        uint64_t get_Intelligence (void);
        uint16_t get_Awareness (void);
        uint64_t get_xp (void);
        uint64_t get_xp_next_level (void);
        std::string get_name (void);
        Inventory get_inventory (void);

        void inventory_add_consumable (Consumable& item);
        void inventory_add_craftable (Craftable& item);
        void inventory_add_equipment (Equipment& item);

    protected:
    private:
        // Members for the position of the players
        uint16_t positionX;
        uint16_t positionY;

        // Members for the attributes of the player
        uint16_t level;
        uint64_t health;
        uint64_t max_health;
        uint64_t agility;
        uint64_t strength;
        uint64_t intelligence;
        uint16_t awareness;
        uint64_t xp;
        uint64_t xp_next_level;
        Inventory inventory;

        // Name
        std::string name;
};

#endif // PLAYER_H
