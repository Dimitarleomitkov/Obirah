#ifndef PLAYER_H
#define PLAYER_H

#include <stdint.h>

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
        uint64_t Health (void);
        uint64_t Agility (void);
        uint64_t Strength (void);
        uint64_t Intelligence (void);
        uint8_t Awareness (void);
    protected:
    private:
        // Members for the position of the players
        uint16_t m_positionX;
        uint16_t m_positionY;

        // Members for the attributes of the player
        uint64_t m_health;
        uint64_t m_agility;
        uint64_t m_strength;
        uint64_t m_intelligence;
        uint8_t m_awareness;
};

#endif // PLAYER_H
