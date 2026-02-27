#include <iostream>
#include "ForestRoom.h"
#include "Globals.h"


ForestRoom::ForestRoom() {
    description = "You are in a dark forest. There is nothing to see past the thick dark trunks of the oaks. \nTwo red eyes stare at you in the darkness...";
    items.push_back("stick");

    NPC wolf("wolf");
    wolf.addDialogue("Grrrr...");
    npcs.push_back(wolf);
    wolftamed = false;
    roomName = "forest";
}

Room* ForestRoom::go(string direction, Player& player) {
    if (direction != "south") {
        if (!wolftamed) {
            cout << "The Wolf blocks your way." << endl;
            return this;
        } else {
            cout << "You go though the trees, only to find walls of stone surrounding it. Seems like it was only an inner garden." << endl;
            roomName = "garden";
            return Room::go(direction, player);
        }
    } 

    return Room::go(direction, player);
}

void ForestRoom::use(string item, Player& player) {
    if (item == "meat") {
        if (!player.hasItem("meat")) {
            cout << "You don't have the meat." << endl;
            return;
        }
        if (wolftamed) {
            cout << "The wolf is already tamed." << endl;
            return;
        }

        wolftamed = true;
        cout << "The wolf seems happy with you." << endl;
        //player.
        return;
    }
    if (item == "stick") {
        cout << "You throw the stick." << endl;
        cout << "The wolf fetches it and brings it back to you." << endl;
        return;
    }

    
    Room::use(item, player);// this way it goes to default fallback 
}