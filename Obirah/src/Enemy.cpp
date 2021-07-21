#include "../includes/Enemy.h"

//ctors
Enemy::Enemy()
{
    level = 0;
    health = 1;
    max_health = 1;
    defense = 0;
    attack = 0;
    strength = 0;
    intelligence = 0;
    agility = 0;
    awareness = 0;
    name = "???";
}

Enemy::Enemy(uint16_t X = 0,
                uint16_t Y = 0,
                uint16_t Level = 0,
                uint64_t Health = 1,
                uint64_t Max_Health = 1,
                uint64_t Defense = 0,
                uint64_t Attack = 0,
                uint64_t Strength = 0,
                uint64_t Intelligence = 0,
                uint64_t Agility = 0,
                uint16_t Awareness = 0,
                std::string Name = "???")
{
    positionX = X;
    positionY = Y;
    level = Level;
    health = Health;
    max_health = Max_Health;
    defense = Defense;
    attack = Attack;
    strength = Strength;
    intelligence = Intelligence;
    agility = Agility;
    awareness = Awareness;
    name = Name;
}

// Copy ctor
Enemy::Enemy (const Enemy& old_enemy)
{
    positionX = old_enemy.positionX;
    positionY = old_enemy.positionY;
    level = old_enemy.level;
    health = old_enemy.health;
    max_health = old_enemy.max_health;
    defense = old_enemy.defense;
    attack = old_enemy.attack;
    strength = old_enemy.strength;
    intelligence = old_enemy.intelligence;
    agility = old_enemy.agility;
    awareness = old_enemy.awareness;
    name = old_enemy.name;
}

Enemy::~Enemy()
{
    //dtor
}

// Getters
uint16_t Enemy::position_X (void)
{
    return positionX;
}

uint16_t Enemy::position_Y (void)
{
    return positionY;
}

uint16_t Enemy::get_Level (void)
{
    return level;
}

uint64_t Enemy::get_Health (void)
{
    return health;
}

uint64_t Enemy::get_Max_Health (void)
{
    return max_health;
}

uint64_t Enemy::get_Defense (void)
{
    return defense;
}

uint64_t Enemy::get_Attack (void)
{
    return attack;
}

uint64_t Enemy::get_Strength (void)
{
    return strength;
}

uint64_t Enemy::get_Intelligence (void)
{
    return intelligence;
}

uint64_t Enemy::get_Agility (void)
{
    return agility;
}

uint16_t Enemy::get_Awareness (void)
{
    return awareness;
}

std::string Enemy::get_name (void)
{
    return name;
}

// Setters
void Enemy::set_positionX (uint16_t X)
{
    positionX = X;
}

void Enemy::set_positionY (uint16_t Y)
{
    positionY = Y;
}

void Enemy::set_Level (uint16_t Level)
{
    level = Level;
}

void Enemy::set_Health (uint64_t Health)
{
    health = Health;
}

void Enemy::set_Max_Health (uint64_t Max_Health)
{
    max_health = Max_Health;
}

void Enemy::set_Defense (uint64_t Defense)
{
    defense = Defense;
}

void Enemy::set_Attack (uint64_t Attack)
{
    attack = Attack;
}

void Enemy::set_Strength (uint64_t Strength)
{
    strength = Strength;
}

void Enemy::set_Intelligence (uint64_t Intelligence)
{
    intelligence = Intelligence;
}

void Enemy::set_Agility (uint64_t Agility)
{
    agility = Agility;
}

void Enemy::set_Awareness (uint16_t Awareness)
{
    awareness = Awareness;
}

void Enemy::set_name (std::string Name)
{
    name = Name;
}
