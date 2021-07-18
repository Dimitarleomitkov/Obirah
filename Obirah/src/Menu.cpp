#include "../includes/Menu.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <unistd.h>
#include <dirent.h>


static int selector_position = 0;

void draw_menu (Gamespace& gamespace)
{
    int menu_length = 4;
    std::string menu_items[menu_length] = {"New Game", "Load Game", "Save Game", "Exit"};
    std::string menu_items2[menu_length] = {"Continue Game", "Load Game", "Save Game", "Exit"};
    int i = 0;

    // Clear the screen
    system ("cls");

    if (gamespace.get_game_started() == 0) {
        for (i = 0; i < selector_position; ++i) {
            std::cout << menu_items[i] << std::endl;
        }
        std::cout << ">>" << menu_items[i] << "<<" << std::endl;
        ++i;
        for (; i < menu_length; ++i) {
            std::cout << menu_items[i] << std::endl;
        }
    } else {
        for (i = 0; i < selector_position; ++i) {
            std::cout << menu_items2[i] << std::endl;
        }
        std::cout << ">>" << menu_items2[i] << "<<" << std::endl;
        ++i;
        for (; i < menu_length; ++i) {
            std::cout << menu_items2[i] << std::endl;
        }
    }
}

bool Menu_Input (e_Commands& game_command, Gamespace& gamespace)
{
    e_Commands_Menu command = MENU_INVALID;
    char input;

    // Get an input until it is a proper one
    do {
        input = tolower (getch());
        command = ParseMenuInput(input);
    } while (command == MENU_INVALID);

    bool return_value = false;

    switch (command) {
        case MENU_UP:
            if (selector_position == 0) {
                selector_position = 3;
            } else {
                --selector_position;
            }
            break;
        case MENU_DOWN:
            if (selector_position == 3) {
                selector_position = 0;
            } else {
                ++selector_position;
            }
            break;
        case MENU_SELECT:
            switch (selector_position) {
                // New/Continue Game
                case 0:
                    if (gamespace.get_game_started() == false) {
                        gamespace.set_game_started (true);
                        system ("cls");
                        std::cout << "The sun rises over the roofs of the nearby houses. Unfamiliar surroundings..." << std::endl;
                        getch();
                    }
                    game_command = INVALID;
                    break;
                // Load Game
                case 1:
                    load_game (gamespace);
                    game_command = INVALID;
                    break;
                // Save Game
                case 2:
                    save_game (gamespace);
                    break;
                // Exit
                case 3:
                    return_value = true;
                    break;
            }
            break;
        default:
            break;
    }
    return return_value;
}

e_Commands_Menu ParseMenuInput (char input)
{
    switch (input) {
        case 'w':
            return MENU_UP;
        case 's':
            return MENU_DOWN;
        case '\r':
            return MENU_SELECT;
        case '\n':
            return MENU_SELECT;
        default:
            return MENU_INVALID;
    }
}

void save_game (Gamespace& gamespace)
{
    // Clear the screen
    system ("cls");

    // Construct the file
    std::cout << "Enter a name of your save:" << std::endl;
    std::string file_name = "";
    mkdir ("saves");
    std::getline (std::cin, file_name);
    file_name.append (".txt");
    file_name.insert (0, "saves/");
    // Create a dummy player for the values
    Player dummy_player = gamespace.get_player ();
    // Open the file for writing
    std::ofstream SaveFile (file_name);


    // Write down all the needed data
    SaveFile << dummy_player.get_name () << ",";
    SaveFile << "\n";
    SaveFile << gamespace.get_game_started () << ",";
    SaveFile << gamespace.get_map_level () << ",";
    SaveFile << "\n";
    SaveFile << dummy_player.PositionX () << ",";
    SaveFile << dummy_player.PositionY () << ",";
    SaveFile << dummy_player.get_Agility () << ",";
    SaveFile << dummy_player.get_Awareness () << ",";
    SaveFile << dummy_player.get_Health () << ",";
    SaveFile << dummy_player.get_Intelligence () << ",";
    SaveFile << dummy_player.get_Strength () << ",";
    SaveFile << "\n";

    // Close the file
    SaveFile.close ();
}

void load_game (Gamespace& gamespace)
{
    // Clear the screen
    system ("cls");

    // Get the saves directory
    DIR* dir;
    struct dirent *ent;
    uint16_t files_counter = 0;

    if ((dir = opendir ("./saves/")) != NULL) {
        // Count the files in the directory
        while ((ent = readdir (dir)) != NULL) {
            ++files_counter;
        }
        closedir (dir);
    } else {
        /* could not open directory */
        std::cerr << "Could not open directory!";
    }


    // Create an array with all the available saves
    std::string saves[files_counter];

    if ((dir = opendir ("./saves/")) != NULL) {
        uint16_t i = 0;

        // Get rid of the first two files. They do not concern us
        readdir (dir);
        readdir (dir);

        // Populate the array
        while ((ent = readdir (dir)) != NULL) {
            saves[i] = ent->d_name;
            saves[i].erase (saves[i].length() - 4);
            ++i;
        }
        closedir (dir);
    } else {
        /* could not open directory */
        std::cerr << "Could not open directory!";
    }

    // Print the available saves
    std::cout << "Available saves:" << std::endl;
    for (int j = 0; j < files_counter - 2; ++j) {
        std::cout << saves[j] << std::endl;
    }

    // Get the user's choice
    std::cout << "Type the name of the save you want to load:" << std::endl;
    std::string save_name = "";
    std::getline (std::cin, save_name);
    save_name.append (".txt");
    save_name.insert (0, "saves/");

    // Open the file and load the parameters in
    std::ifstream LoadFile (save_name);

    char ch;
    std::string saved_data = "";
    while (LoadFile.get(ch)) {
        saved_data += ch;
    }

    // Load the name of the player
    std::string character_name = "";

    int j = 0;
    while (saved_data[j] != ',') {
        character_name += saved_data[j];
        ++j;
    }

    // Load the gamespace parameters
    std::string dummy_str = "";
    uint16_t gamespace_data[2];
    int k = 0;

    j += 2;
    while (saved_data[j] != '\n') {
        while (saved_data[j] != ',') {
            dummy_str += saved_data[j];
            ++j;
        }
        gamespace_data[k] = stoi(dummy_str);
        ++k;
        dummy_str = "";
        ++j;
    }

    // Load the player parameters
    dummy_str = "";
    uint16_t player_data[7];
    k = 0;

    ++j;
    while (saved_data[j] != '\n') {
        while (saved_data[j] != ',') {
            dummy_str += saved_data[j];
            ++j;
        }
        player_data[k] = stoi(dummy_str);
        ++k;
        dummy_str = "";
        ++j;
    }

    LoadFile.close ();

    // Load the data
    Player dummy_player;

    dummy_player.set_name (character_name);

    gamespace.set_game_started (gamespace_data[0]);
    gamespace.set_map_level (gamespace_data[1]);

    dummy_player.set_PositionX (player_data[0]);
    dummy_player.set_PositionY (player_data[1]);
    dummy_player.set_Agility (player_data[2]);
    dummy_player.set_Awareness (player_data[3]);
    dummy_player.set_Health (player_data[4]);
    dummy_player.set_Intelligence (player_data[5]);
    dummy_player.set_Strength (player_data[6]);

    gamespace.set_player (dummy_player);
    gamespace.generate_level ();
}
