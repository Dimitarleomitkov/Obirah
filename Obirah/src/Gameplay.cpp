#include "../include/Gameplay.h"
#include "../include/Terrain.h"
#include "../include/Player.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void Input(char* buff, const uint16_t inputLength)
{
    using namespace std;
    uint16_t inputCounter = 0;

    do {
        buff[inputCounter] = tolower(getch());
        if (buff[inputCounter] != 8) {
            cout << buff[inputCounter];
            ++inputCounter;
        } else if (buff[inputCounter] == 8 && inputCounter > 0) {
            --inputCounter;
            buff[inputCounter] = ' ';
            cout << '\b' << ' ' << '\b';
            continue;
        }
    } while (buff[inputCounter - 1] != ' ' && buff[inputCounter - 1] != 13 && inputCounter < inputLength - 1);
    if (buff[inputCounter - 1] != ' ' || buff[inputCounter - 1] != 13) {
        --inputCounter;
    }
    buff[inputCounter] = '\0';
}

e_Commands PlayerInput(Player* character, Terrain* gamespace)
{
    const uint16_t inputLength = 30;
    char input[inputLength];
    e_Commands command;

    do {
        Input(input, inputLength);
        command = ParseInput(input);
        if (command != INVALID) {
            // Clear the console (ON WINDOWS MACHINES)
            system("cls");
        }
        HandleInput(command, character, gamespace);
    } while (command == INVALID);

    if (command == EXIT) {
        return command;
    }

    gamespace->Draw(character);

    return command;
}

void HandleInput(e_Commands command, Player* character, Terrain* gamespace)
{
    using namespace std;

    switch (command) {
        case INVALID:
            cout << endl << "INVALID COMMAND" << endl;
            break;
        case UP:
            {
                if (!CheckValidUpMove(character, gamespace)) {
                    break;
                }
                uint32_t tilePosition = character->PositionY() * gamespace->Width() + character->PositionX();
                gamespace->ChangeTile(tilePosition, Terrain::EMPTY);
                character->MoveUp();
                break;
            }
        case LEFT:
            {
                if (!CheckValidLeftMove(character, gamespace)) {
                    break;
                }
                uint32_t tilePosition = character->PositionY() * gamespace->Width() + character->PositionX();
                gamespace->ChangeTile(tilePosition, Terrain::EMPTY);
                character->MoveLeft();
                break;
            }
        case DOWN:
            {
                if (!CheckValidDownMove(character, gamespace)) {
                    break;
                }
                uint32_t tilePosition = character->PositionY() * gamespace->Width() + character->PositionX();
                gamespace->ChangeTile(tilePosition, Terrain::EMPTY);
                character->MoveDown();
                break;
            }
        case RIGHT:
            {
                if (!CheckValidRightMove(character, gamespace)) {
                    break;
                }
                uint32_t tilePosition = character->PositionY() * gamespace->Width() + character->PositionX();
                gamespace->ChangeTile(tilePosition, Terrain::EMPTY);
                character->MoveRight();
                break;
            }
        case EXIT:
            break;
    }
    // TODO: Handle player status (is he dead or what?)
}

e_Commands ParseInput (char* input)
{
    if (!strcmp(input, "w")) {
        return UP;
    } else if (!strcmp(input, "a")) {
        return LEFT;
    } else if (!strcmp(input, "s")) {
        return DOWN;
    } else if (!strcmp(input, "d")) {
        return RIGHT;
    } else if (!strcmp(input, "exit")) {
        return EXIT;
    } else {
        return INVALID;
    }
}

bool CheckValidUpMove (Player* character, Terrain* gamespace)
{
    uint16_t tilePosition = (character->PositionY() - 1) * gamespace->Width() + character->PositionX();

    return CheckMove(gamespace, tilePosition);
}

bool CheckValidLeftMove (Player* character, Terrain* gamespace)
{
    uint16_t tilePosition = character->PositionY() * gamespace->Width() + character->PositionX() - 1;

    return CheckMove(gamespace, tilePosition);
}

bool CheckValidDownMove (Player* character, Terrain* gamespace)
{
    uint16_t tilePosition = (character->PositionY() + 1) * gamespace->Width() + character->PositionX();

    return CheckMove(gamespace, tilePosition);
}

bool CheckValidRightMove (Player* character, Terrain* gamespace)
{
    uint16_t tilePosition = character->PositionY() * gamespace->Width() + character->PositionX() + 1;

    return CheckMove(gamespace, tilePosition);
}

bool CheckMove (Terrain* gamespace, uint16_t tilePosition)
{
    using namespace std;
    switch (gamespace->Tile(tilePosition)){
        case Terrain::NPC:
            cout << "NPC is in the way." << endl;
            return false;
            break;
        case Terrain::DOOR:
            cout << "A door is in the way." << endl;
            return false;
            break;
        case Terrain::GATE:
            cout << "A gate is in the way." << endl;
            return false;
            break;
        case Terrain::TREE:
            cout << "A tree is in the way." << endl;
            return false;
            break;
        case Terrain::BUSH:
            cout << "A lovely flowery bush is in the way." << endl;
            return false;
            break;
        case Terrain::WALL:
            cout << "A wall is in the way." << endl;
            return false;
            break;
        case Terrain::DOWNWALL:
            cout << "A wall is in the way." << endl;
            return false;
            break;
    }
    return true;
}
