#ifndef PLAYER_H
#define PLAYER_H

#include <stdint.h>
#include <string>

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

        // Getting functions for the position of the player
        uint16_t PositionX (void);
        uint16_t PositionY (void);

        // Setting function for the name
        void set_name (std::string Name);

        // Increase functions for the attributes of the player
        void IncreaseHealth (uint64_t amount);
        void IncreaseAgility (uint64_t amount);
        void IncreaseStrength (uint64_t amount);
        void IncreaseIntelligence (uint64_t amount);
        void IncreaseAwareness (uint8_t amount);

        // Decrease functions for the attributes of the player
        void DecreaseHealth (uint64_t amount);
        void DecreaseAgility (uint64_t amount);
        void DecreaseStrength (uint64_t amount);
        void DecreaseIntelligence (uint64_t amount);
        void DecreaseAwareness (uint8_t amount);

        // Getting functions for the attributes of the player
        uint64_t get_Health (void);
        uint64_t get_Agility (void);
        uint64_t get_Strength (void);
        uint64_t get_Intelligence (void);
        uint8_t get_Awareness (void);
        std::string get_name (void);

    protected:
    private:
        // Members for the position of the players
        uint16_t positionX;
        uint16_t positionY;

        // Members for the attributes of the player
        uint64_t health;
        uint64_t agility;
        uint64_t strength;
        uint64_t intelligence;
        uint8_t awareness;

        // Name
        std::string name;
};

#endif // PLAYER_H
