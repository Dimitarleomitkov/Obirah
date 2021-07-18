#include "../includes/Gameplay.h"

#include <iostream>
#include <string>

void Jack_1_window (NPChar& dummy_NPC, Gamespace& gamespace)
{
    // Message
    std::string NPC_speech = "Hi!";

    // Reply options
    int menu_length = 4;
    std::string menu_items[menu_length] = {"\"Hello. Who are you?\"", "\"What are you doing here?\"", "\"Where am I?\"", "Back"};

    int i = 0;
    int selector_position = 0;

NPC_Dialogue:
        do {
        system ("cls");

        // Name of the NPC
        std::cout << dummy_NPC.get_name() << ":" << std::endl;

        // NPC speech
        std::cout << NPC_speech << std::endl << std::endl;

        // Player options
        for (i = 0; i < selector_position; ++i) {
            std::cout << menu_items[i] << std::endl;
        }
        std::cout << menu_items[i] << " <" << std::endl;
        ++i;
        for (; i < menu_length; ++i) {
            std::cout << menu_items[i] << std::endl;
        }
    } while (!Selector(selector_position, menu_length));

    switch (selector_position) {
        // "Who are you?"
        case 0:
            NPC_speech = "My name is Jack. I am here with my family.";
            goto NPC_Dialogue;
        // "What are you doing here?"
        case 1:
            NPC_speech = "My family and I are here to collect wood. We are from Rowue,"
            " but during the Summers we stay in this settlement."
            " Helps us prepare for the Winter.";
            goto NPC_Dialogue;
        // "Where am I?"
        case 2:
            NPC_speech = "Father says, this settlement was built by the people of Rowue."
            " However, it has always felt like our own. We are the only family to ever utilize it."
            " It is called Mitsko.";
            goto NPC_Dialogue;
        // Back
        case 3:
            break;
        default:
            break;
    }
}
