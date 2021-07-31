#include "../includes/Enemy.h"
#include "../includes/EnemyLUT.h"

//ctors
Enemy::Enemy ()
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

Enemy::Enemy (uint16_t X = 0,
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

Enemy::~Enemy ()
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

Enemy enemy_rng_pos (e_TileType* dummy_tiles, uint8_t map_width, uint8_t map_height, uint16_t map_level)
{
    unsigned int number_of_tiles = map_width * map_height;
    unsigned int number_of_empty_tiles = 0;

    unsigned int i;
    for (i = 0; i < number_of_tiles; ++i) {
        if (dummy_tiles[i] == EMPTY) {
            ++number_of_empty_tiles;
        }
    }

    unsigned int empty_tiles[number_of_empty_tiles];

    unsigned int j = 0;
    for (i = 0; i < number_of_tiles; ++i) {
        if (dummy_tiles[i] == EMPTY) {
            empty_tiles[j] = i;
            ++j;
        }
    }

    uint16_t random_map_index = rand() % number_of_empty_tiles;
    uint16_t enemy_x = empty_tiles[random_map_index] / map_width;
    uint16_t enemy_y = empty_tiles[random_map_index] % map_width;


    Enemy enemy = choose_enemy (enemy_x, enemy_y, map_level);

    return enemy;
}

Enemy choose_enemy (uint16_t enemy_x, uint16_t enemy_y, uint16_t map_level)
{
    uint16_t enemy_type = 0;
    switch (map_level) {
        case 2:
            {
                if (rand () % 100 < 10) {
                    enemy_type = 5; // Bear
                } else if (rand () % 100 < 30) {
                    enemy_type = 4; // Wolf
                } else if (rand () % 100 < 50) {
                    enemy_type = 3; // Deer
                } else {
                    enemy_type = 2; // Rabbit
                }
                Enemy new_enemy(enemy_x, enemy_y, enemy_LUT[enemy_type].get_Level(), enemy_LUT[enemy_type].get_Health(), enemy_LUT[enemy_type].get_Max_Health(),
                                enemy_LUT[enemy_type].get_Defense(), enemy_LUT[enemy_type].get_Attack(), enemy_LUT[enemy_type].get_Strength(),
                                enemy_LUT[enemy_type].get_Intelligence(), enemy_LUT[enemy_type].get_Agility(), enemy_LUT[enemy_type].get_Awareness(),
                                enemy_LUT[enemy_type].get_name());
                return new_enemy;
            }
        default:
            {
                Enemy new_enemy(enemy_x, enemy_y, enemy_LUT[enemy_type].get_Level(), enemy_LUT[enemy_type].get_Health(), enemy_LUT[enemy_type].get_Max_Health(),
                                enemy_LUT[enemy_type].get_Defense(), enemy_LUT[enemy_type].get_Attack(), enemy_LUT[enemy_type].get_Strength(),
                                enemy_LUT[enemy_type].get_Intelligence(), enemy_LUT[enemy_type].get_Agility(), enemy_LUT[enemy_type].get_Awareness(),
                                enemy_LUT[enemy_type].get_name());
                return new_enemy;
            }
            break;
    }
}
