#include "../includes/Gameplay.h"

#include <iostream>
#include <conio.h>

void Rick_1_window (NPChar& dummy_NPC, Gamespace& gamespace)
{
    system ("cls");

    // Name of the NPC
    std::cout << dummy_NPC.get_name() << ":" << std::endl;

    // Greeting message
    std::cout << "I am not implemented yet." << std::endl;
    getch ();
}
