#include "../includes/Gameplay.h"

#include <iostream>
#include <conio.h>

void Rick_1_window (NPChar& dummy_NPC, Gamespace& gamespace)
{
    // Message
    std::string NPC_speech;

    if (gamespace.get_player().get_name() == "Unknown") {
        NPC_speech = "Hello! How are you doing today?";
    } else {
        NPC_speech = "Hello, ";
        NPC_speech += gamespace.get_player().get_name();
        NPC_speech += "! How are you doing today?";
    }

    if (gamespace.get_story_stage() == 0) {
        // Reply options
        int menu_length = 4;
        std::string menu_items[menu_length] = {"\"Greetings.\"", "\"Who are you?\"", "\"...\"", "Back"};

        int i = 0;
        int selector_position = 0;

    NPC_Dialogue_1:
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
            // "Greetings."
            case 0:
                NPC_speech = "I would be grateful if you would make sure my family is doing well.";
                goto NPC_Dialogue_1;
            // "Who are you?"
            case 1:
                NPC_speech = "My name is Richard. My wife Nira, my son Jack and I have come to this camp to stay for the Summer."
                " Jack can usually be found running around the woodshed. Sometimes he even helps out... when one of us reminds him to... "
                " My wife, on the other hand, is always making herself useful inside the cabin."
                " Busy as a bee, I honestly would not know if I could manage without her."
                " Finally, my job here is to keep an eye for any threats which might come our way."
                " These woods are a home not only to us, but rabbits, squirrels, wolves, deer and even the occasional bear!";
                goto NPC_Dialogue_1;
            // "..."
            case 2:
                initial_Rick_RP_window (dummy_NPC, gamespace);
                gamespace.set_story_stage (1);
                break;
            // Back
            case 3:
                break;
            default:
                break;
        }
    } else {
        // Reply options
        int menu_length = 3;
        std::string menu_items[menu_length] = {"\"Greetings.\"", "\"Who are you?\"", "Back"};

        int i = 0;
        int selector_position = 0;

    NPC_Dialogue_2:
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
            // "Greetings."
            case 0:
                NPC_speech = "I would be grateful if you would make sure my family is doing well.";
                goto NPC_Dialogue_2;
            // "Who are you?"
            case 1:
                NPC_speech = "My name is Richard. My wife Nira, my son Jack and I have come to this camp to stay for the Summer."
                " Jack can usually be found running around the woodshed. Sometimes he even helps out... when one of us remind him to... "
                " My wife, on the other hand, is always busy inside the cabin."
                " Busy as a bee, I honestly would not know if I could manage without her."
                " Finally, my job here is to keep an eye for any threats which might come our way."
                " These woods are a home not only to us, but rabbits, squirrels, wolves, deer and even the occasional bear!";
                goto NPC_Dialogue_2;
            // Back
            case 2:
                break;
            default:
                break;
        }
    }
}

void initial_Rick_RP_window (NPChar& dummy_NPC, Gamespace& gamespace)
{
    // Message
    std::string NPC_speech = "I see you are finally awake. Do you know who you are? What are you doing wondering these lands?";
    // Reply options
    int menu_length = 3;
    std::string menu_items[menu_length] = {"\"I can't seem to remember anything...\"", "\"I am here to destroy you all!\"", "Back"};

    int i = 0;
    int selector_position = 0;

NPC_Dialogue_3:
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

    Equipment axe("Small Woodchipper's Axe");
    Player dummy_player = gamespace.get_player();
    switch (selector_position) {
        // "I can't seem to remember anything..."
        case 0:
            NPC_speech = "Well, you will not find your answers here for sure. Here, take this Axe to help you on your adventures."
            " Unfortunately, this is the only spare we have. Good luck!";
            dummy_player.inventory_add_equipment(axe);
            gamespace.set_player (dummy_player);
            goto NPC_Dialogue_3;
        // "I am here to destroy you all!"
        case 1:
            NPC_speech = "Shame...";
            goto NPC_Dialogue_3;
        // Back
        case 2:
            break;
        default:
            break;
    }
}
