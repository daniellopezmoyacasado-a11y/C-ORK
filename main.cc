#include <iostream>
#include "Player.h"
#include "StartRoom.h"
#include "ForestRoom.h"
#include "StorageRoom.h"
#include "Globals.h"

using namespace std;

bool game_end = false;

string toLowerCase(string text) { //almost forgot Uppercase cases
    for (int i = 0; i < text.length(); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = text[i] + 32;  //ASCII uppercase to lowercase
        }
    }
    return text;
}

int main() {
    Player player;


    ForestRoom forest;
    StorageRoom storage;
    StartRoom start;

    start.setNorth(&forest);
    start.setWest(&storage);

    forest.setSouth(&start);
    storage.setEast(&start);
    

    Room* currentRoom = &start;

    string command;
    string argument;

    cout << "You wake up in a dark room, only one memory remains in your head, escape..." << endl;
    

    while (!game_end) {
        cout << "> ";
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