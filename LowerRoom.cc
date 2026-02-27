#include <iostream>
#include "LowerRoom.h"
#include "Globals.h"


LowerRoom::LowerRoom() {
    description = "You are in a storage room, there are a few empty boxes lining the walls.\nOn the south side there is an archway that appears to be blocked by an troll.\nHe appears to be stuck.";

    NPC Troll("troll");
    Troll.addDialogue("Hello.");
    Troll.addDialogue("This is a Troll.");
    npcs.push_back(Troll);

    roomName = "LowerStorage";
}

Room* LowerRoom::go(string direction, Player& player) {
    if (direction == "north") {
                cout << "You go north." << endl;
        return northRoom;
    }

    return Room::go(direction, player);
}

void LowerRoom::use(string item, Player& player) {
    
    if (item == "Sword") {
        if (!player.hasItem("Sword")) {
        cout << "You don't have the " + item + ". "<< endl;
        return;
        }
        cout << "You swing your sword at the Troll, it's extremely heavy." << endl;
        return;
    }

    Room::use(item, player);
}