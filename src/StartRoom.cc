#include <iostream>
#include "StartRoom.h"
#include "Player.h"


StartRoom::StartRoom() {
    roomName = "Cell";
    description = "You are in a stone chamber. \nThere is someone here in the dark, he's laying wounded on the ground \nA foul smell is eminating from him.";
    items.push_back("key");

    NPC guard("guard");
    guard.addDialogue("You... Ugh");
    guard.addDialogue("Please take m-");
    guard.addDialogue("escape befo-...");
    npcs.push_back(guard);

    doorUnlocked = false;
    guardDead = false;
}

Room* StartRoom::go(string direction, Player& player) {
    if (direction == "north") {
        if (!doorUnlocked) {
            cout << "The north door is locked." << endl;
            return this;
        }
        cout << "You go past the door and make your way up a spiral staircase.\nyou put you hands on the walls to guide your way, the walls are icy cold and grimy with dirt." << endl;
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

void StartRoom::talk(string npcName) {
    for (size_t i = 0; i < npcs.size(); i++) {
        if (npcs[i].getName() == npcName) {
            if(!guardDead) {
                npcs[i].talk();
                guardDead = true;
                return;
            }
            cout << "The guard looks dead." << endl;
            return;
        }
    }
    cout << "No one by that name here." << endl;
}
