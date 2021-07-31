#ifndef ENEMYLUT_H
#define ENEMYLUT_H

// Enemy LUT
Enemy enemy_LUT[6] = {
//  {X, Y, level, health, max_health, defense, attack, strength, intelligence, agility, awareness, name}
    {0, 0, 1, 1000000, 1000000, 0, 0, 0, 0, 0, 0, "Target Dummy"},
    {0, 0, 1, 10000000, 10000000, 1000000, 5, 1 /* times yours */, 1 /* times yours */, 1 /* times yours */, 0, "Evil Target Dummy"},
    {0, 0, 2, 2, 2, 0, 1, 0, 0, 10, 15, "Rabbit"},
    {0, 0, 2, 15, 15, 0, 2, 1, 1, 7, 17, "Deer"},
    {0, 0, 3, 15, 15, 3, 6, 5, 1, 6, 13, "Wolf"},
    {0, 0, 4, 30, 30, 15, 13, 15, 1, 4, 13, "Bear"},
};

#endif // ENEMYLUT_H
