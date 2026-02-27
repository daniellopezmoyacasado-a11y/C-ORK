#include <iostream>
#include "Player.h"
#include "StartRoom.h"
#include "ForestRoom.h"
#include "StorageRoom.h"
#include "ArmoryRoom.h"
#include "BalconyRoom.h"
#include "CornerRoom.h"
#include "CorridorRoom.h"
#include "GateRoom.h"
#include "GreatRoom.h"
#include "PassageRoom.h"
#include "SecretRoom.h"
#include "ThroneRoom.h"
#include "TreasureRoom.h"
#include "LowerRoom.h"
#include "Globals.h"

using namespace std;

bool game_end = false;
bool drawbridge_down = false; //necessary to beat the game

string toLowerCase(string text) { //almost forgot Uppercase cases
    for (int i = 0; i < text.length(); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = text[i] + 32;  //ASCII uppercase to lowercase
        }
    }
    return text;
}

StartRoom start; //I put them here since now making the map is a bit more complex I can put it in an auxiliary function.
ForestRoom forest;
StorageRoom storage;
ArmoryRoom armory;
BalconyRoom balcony;
CornerRoom corner;
CorridorRoom corridor;
GateRoom gate;
GreatRoom great;
PassageRoom passage;
SecretRoom secret;
ThroneRoom throne;
TreasureRoom treasure;
LowerRoom lower;


void setupMap() {
    start.setNorth(&great);
    
    great.setWest(&passage);
    great.setEast(&corridor);
    great.setNorth(&forest);
    great.setSouth(&start);

    forest.setNorth(&gate);
    forest.setSouth(&great);
    forest.setWest(&armory);
    forest.setEast(&throne);

    passage.setWest(&storage);
    passage.setEast(&great);

    storage.setEast(&passage);
    storage.setNorth(&armory);

    corridor.setWest(&great);
    corridor.setEast(&balcony);

    balcony.setWest(&corridor);
    balcony.setNorth(&throne);

    armory.setSouth(&storage);
    armory.setNorth(&corner);
    armory.setEast(&forest);

    throne.setWest(&forest);
    throne.setNorth(&secret);
    throne.setSouth(&balcony);

    lower.setEast(&corner);
    lower.setSouth(&treasure);

    treasure.setNorth(&lower);

    corner.setWest(&lower);
    corner.setEast(&gate);
    corner.setSouth(&armory);

    gate.setWest(&corner);
    gate.setSouth(&forest);

    secret.setSouth(&throne);


}

int main() {
    Player player;

    setupMap();

    Room* currentRoom = &start;

    string command;
    string argument;

    cout << "You wake up in a dark room, your head feels drowned in the darkness." << endl;
    

    while (!game_end) {
        //cout << "> ";

        cout << "[" 
        << currentRoom->getName() 
        << "] > ";

        cin >> command;
        command = toLowerCase(command);

        if (command == "look") {
            currentRoom->look();
        }

        else if (command == "take") {

            if (cin.peek() == '\n') {
                cout << "Take what?" << endl;
            } else {
                cin >> argument;
                argument = toLowerCase(argument);
                currentRoom->take(argument, player);
            }
        }

        else if (command == "talk") {
            if (cin.peek() == '\n') { //cin looks at the next char in the buffer, thid way it doesn't feel stuck due to lack of input.
                cout << "Talk to who?" << endl;
            } else {
                cin >> argument;
                argument = toLowerCase(argument);
                currentRoom->talk(argument);
            }
        }

        else if (command == "go") {
            if (cin.peek() == '\n') {
                cout << "Go where?" << endl;
            } else {
                cin >> argument;
                argument = toLowerCase(argument);
                currentRoom = currentRoom->go(argument, player);
            }
        }

        else if (command == "inventory") {
            player.showInventory();
        }
        else if (command == "use") {

            if (cin.peek() == '\n') {
                cout << "Use what?" << endl;
            } else {
                cin >> argument;
                argument = toLowerCase(argument);
                currentRoom->use(argument, player);
            }
        }

        else if (command == "quit") {
            game_end = true;
        }

        else {
            cout << "Unknown command." << endl;
        }
    }

    return 0;
}