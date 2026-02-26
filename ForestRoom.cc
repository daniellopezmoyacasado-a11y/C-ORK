#include <iostream>
#include "ForestRoom.h"
#include "Globals.h"

ForestRoom::ForestRoom(Room* south) { //old version, keeping it for continuity
    description = "You are in a dark forest. There is nothing to see past the thick dark trunks of the oaks";
    items.push_back("stick");

    NPC wolf("wolf");
    wolf.addDialogue("Grrrr...");
    npcs.push_back(wolf);
    wolftamed = false;
}

ForestRoom::ForestRoom() {
    description = "You are in a dark forest. There is nothing to see past the thick dark trunks of the oaks";
    items.push_back("stick");

    NPC wolf("wolf");
    wolf.addDialogue("Grrrr...");
    npcs.push_back(wolf);
    wolftamed = false;
}

Room* ForestRoom::go(string direction, Player& player) {
    if (direction != "south") {
        if (!wolftamed) {
            cout << "The Wolf blocks your way." << endl;
            return this;
        }
        cout << "You beat the game." << endl;
        game_end = true;
        return this;
    } else { //no behaviour currently
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
    }

    
    Room::use(item, player);// this way it goes to default fallback 
}