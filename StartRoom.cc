#include <iostream>
#include "StartRoom.h"

StartRoom::StartRoom(Room* north, Room* west) { //old version, keep temporarily
    description = "You are in a stone chamber.";
    items.push_back("key");

    NPC guard("guard");
    guard.addDialogue("Hello traveler.");
    guard.addDialogue("The forest is dangerous.");
    npcs.push_back(guard);

    northRoom = north;
    doorUnlocked = false;
}

StartRoom::StartRoom() {
    description = "You are in a stone chamber.";
    items.push_back("key");

    NPC guard("guard");
    guard.addDialogue("Hello traveler.");
    guard.addDialogue("The forest is dangerous.");
    npcs.push_back(guard);

    doorUnlocked = false;
}

Room* StartRoom::go(string direction, Player& player) {
    if (direction == "north") {
        if (!doorUnlocked) {
            cout << "The north door is locked." << endl;
            return this;
        }
        cout << "You go north." << endl;
        return northRoom;
    }

    return Room::go(direction, player);
}

void StartRoom::use(string item, Player& player) {
    if (item == "key") {
        if (!player.hasItem("key")) {
            cout << "You don't have the key." << endl;
            return;
        }
        if (doorUnlocked) {
            cout << "The door is already unlocked." << endl;
            return;
        }

        doorUnlocked = true;
        cout << "You unlock the north door with the key." << endl;
        return;
    }

    
    Room::use(item, player);// this way it goes to default fallback 
}