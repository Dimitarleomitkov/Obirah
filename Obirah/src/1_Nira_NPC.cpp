#include "../includes/Gameplay.h"

#include <iostream>
#include <conio.h>
#include <algorithm>

void Nira_1_window (NPChar& dummy_NPC, Gamespace& gamespace)
{
    // Message
    std::string NPC_speech;

    if (gamespace.get_player().get_name() == "Unknown") {
        NPC_speech = "Hello, stranger! I hope you are feeling better!";
    } else {
        NPC_speech = "Hello, ";
        NPC_speech.append (gamespace.get_player().get_name());
        NPC_speech.append (". I hope your adventures have been fruitful.");
    }

    // Reply options
    int menu_length = 3;
    std::string menu_items[menu_length] = {"\"Greetings.\"", "\"What are you up to?\"", "Back"};

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
        // "Greetings."
        case 0:
            if (gamespace.get_player().get_name() == "Unknown"){
                std::string new_name = set_player_name_event ();

                Player dummy_player = gamespace.get_player();
                dummy_player.set_name(new_name);
                gamespace.set_player(dummy_player);
                break;
            } else {
                NPC_speech = "Hello again, ";
                NPC_speech.append (gamespace.get_player().get_name());
                NPC_speech.append (".");
            }
            goto NPC_Dialogue;
        // "What are you up to?"
        case 1:
            NPC_speech = "You are catching me in the middle of preparing a meal for my family."
            " They should be back shortly.\nJack is gathering up some wood nearby, while Rick is keeping watch since last night."
            " These woods are not as kind when the sun goes behind the mountains.";
            if (gamespace.get_story_stage() == 0) {
                NPC_speech.append ("\n\nYou should try and speak with Rick. He seemed to have a few questions for you.");
            }
            goto NPC_Dialogue;
        // Back
        case 2:
            break;
        default:
            break;
    }
}

std::string set_player_name_event ()
{
    std::string NPC_speech = "I was so glad when you finally woke up. We found you near the Mitsko bridge. What is your name?";

    system ("cls");
    // Name of the NPC
    std::cout << "Nira:" << std::endl;
    // NPC speech
    std::cout << NPC_speech << std::endl << std::endl;

    // Player options
    std::cout << "\"...I can't seem to remember...\" <" << std::endl;
    // Get input from user
    int selector = 0;
    while (!Selector(selector, 1));
    NPC_speech = "This is horrible!...\n...How about you choose how we can call you and we start from there?";

    system ("cls");
    // Name of the NPC
    std::cout << "Nira:" << std::endl;
    // NPC speech
    std::cout << NPC_speech << std::endl << std::endl;

    // Get input from user
    std::string new_name;
    std::getline (std::cin, new_name);

    std::string parsed_name = "";

    int i = 0;
    while (new_name[i] != '\0') {
        if (isalnum(new_name[i])) {
            parsed_name += new_name[i];
        }
        ++i;
    }

    return parsed_name;
}
