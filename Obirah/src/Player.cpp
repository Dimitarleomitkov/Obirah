#include "../includes/Player.h"

// ctor
Player::Player()
{
    positionX = 6;
    positionY = 6;
    health = 1;
    agility = 1;
    strength = 1;
    intelligence = 1;
    awareness = 1;
    name = "Unknown";
}

// dtor
Player::~Player()
{

}

// Getting functions for the position of the player
uint16_t Player::PositionX(void)
{
    return positionX;
}

uint16_t Player::PositionY(void)
{
    return positionY;
}

// Setting function for the name
void Player::set_name (std::string Name)
{
    name = Name;
}

void Player::set_PositionX (uint16_t x)
{
    positionX = x;
}

void Player::set_PositionY (uint16_t y)
{
    positionY = y;
}

void Player::set_Health (uint64_t Health)
{
    health = Health;
}

void Player::set_Agility (uint64_t Agility)
{
    agility = Agility;
}

void Player::set_Strength (uint64_t Strength)
{
    strength = Strength;
}

void Player::set_Intelligence (uint64_t Intelligence)
{
    intelligence = Intelligence;
}

void Player::set_Awareness (uint64_t Awareness)
{
    awareness = Awareness;
}

// Setting functions for the position of the player
void Player::MoveUp(uint8_t numberOfPositions)
{
    positionX -= numberOfPositions;
}

void Player::MoveLeft(uint8_t numberOfPositions)
{
    positionY -= numberOfPositions;
}

void Player::MoveDown(uint8_t numberOfPositions)
{
    positionX += numberOfPositions;
}

void Player::MoveRight(uint8_t numberOfPositions)
{
    positionY += numberOfPositions;
}

// Increase functions for the attributes of the player
void Player::IncreaseHealth (uint64_t amount)
{
    health += amount;
}

void Player::IncreaseAgility (uint64_t amount)
{
    agility += amount;
}

void Player::IncreaseStrength (uint64_t amount)
{
    strength += amount;
}

void Player::IncreaseIntelligence (uint64_t amount)
{
    intelligence += amount;
}

void Player::IncreaseAwareness (uint8_t amount)
{
    awareness += amount;
}


// Decrease functions for the attributes of the player
void Player::DecreaseHealth (uint64_t amount)
{
    health -= amount;
}

void Player::DecreaseAgility (uint64_t amount)
{
    agility -= amount;
}

void Player::DecreaseStrength (uint64_t amount)
{
    strength -= amount;
}

void Player::DecreaseIntelligence (uint64_t amount)
{
    intelligence -= amount;
}

void Player::DecreaseAwareness (uint8_t amount)
{
    awareness -= amount;
}


// Getting functions for the attributes of the player
uint64_t Player::get_Health (void)
{
    return health;
}

uint64_t Player::get_Agility (void)
{
    return agility;
}

uint64_t Player::get_Strength (void)
{
    return strength;
}

uint64_t Player::get_Intelligence (void)
{
    return intelligence;
}

uint16_t Player::get_Awareness (void)
{
    return awareness;
}

std::string Player::get_name (void)
{
    return name;
}
