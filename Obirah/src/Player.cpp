#include "../include/Player.h"

// ctor
Player::Player()
{
    m_positionX = 6;
    m_positionY = 6;
    m_health = 1;
    m_agility = 1;
    m_strength = 1;
    m_intelligence = 1;
    m_awareness = 1;
}

// Getting functions for the position of the player
uint16_t Player::PositionX(void)
{
    return m_positionX;
}

uint16_t Player::PositionY(void)
{
    return m_positionY;
}

// Setting functions for the position of the player
void Player::MoveUp(uint8_t numberOfPositions)
{
    m_positionY -= numberOfPositions;
}

void Player::MoveLeft(uint8_t numberOfPositions)
{
    m_positionX -= numberOfPositions;
}

void Player::MoveDown(uint8_t numberOfPositions)
{
    m_positionY += numberOfPositions;
}

void Player::MoveRight(uint8_t numberOfPositions)
{
    m_positionX += numberOfPositions;
}

// Increase functions for the attributes of the player
void Player::IncreaseHealth (uint64_t amount)
{
    m_health += amount;
}

void Player::IncreaseAgility (uint64_t amount)
{
    m_agility += amount;
}

void Player::IncreaseStrength (uint64_t amount)
{
    m_strength += amount;
}

void Player::IncreaseIntelligence (uint64_t amount)
{
    m_intelligence += amount;
}

void Player::IncreaseAwareness (uint8_t amount)
{
    m_awareness += amount;
}


// Decrease functions for the attributes of the player
void Player::DecreaseHealth (uint64_t amount)
{
    m_health -= amount;
}

void Player::DecreaseAgility (uint64_t amount)
{
    m_agility -= amount;
}

void Player::DecreaseStrength (uint64_t amount)
{
    m_strength -= amount;
}

void Player::DecreaseIntelligence (uint64_t amount)
{
    m_intelligence -= amount;
}

void Player::DecreaseAwareness (uint8_t amount)
{
    m_awareness -= amount;
}


// Getting functions for the attributes of the player
uint64_t Player::Health (void)
{
    return m_health;
}

uint64_t Player::Agility (void)
{
    return m_agility;
}

uint64_t Player::Strength (void)
{
    return m_strength;
}

uint64_t Player::Intelligence (void)
{
    return m_intelligence;
}

uint8_t Player::Awareness (void)
{
    return m_awareness;
}


// dtor
Player::~Player()
{

}
