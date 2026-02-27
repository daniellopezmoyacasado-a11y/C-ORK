#include <iostream>
#include "GateRoom.h"
#include "Globals.h"
#include "Player.h"


GateRoom::GateRoom() {
    description = "You stand in front of a great gate, outside, you can hear the sound of the wind whistling past trees, water rushing down a nearby river, and a distant owl.\nThere is a large Key hole with the seal of the key.";
    doorUnlocked = false;
}

Room* GateRoom::go(string direction, Player& player) {
    if (direction == "north") {
        if (!doorUnlocked) {
            cout << "The north door is locked." << endl;
            return this;
        }
        if (!drawbridge_down) {
            cout << "You go outside. Its a warm night.\nYou don't know where to go, but the full moon will light your way" << endl;
            cout << "As you take your first step you fall into water, you look up, to see a bridge held on chains above the gate." << endl;
            cout << "You search for a way to climb out of the moat, as something swims past your leg. You hope it was only a fish." << endl;
            cout << "YOU DIED" <<endl;
            game_end = true;
            return this;
        }
        cout << "You go outside. Its a warm night.\nYou don't know where to go, but the full moon will light your way" << endl;
        cout << "YOU WON" <<endl;
        game_end = true;
        return this;
    }

    return Room::go(direction, player);
}

void GateRoom::use(string item, Player& player) {
    
    if (item == "KingsKey") {
        if (!player.hasItem("KingsKey")) {
            cout << "You don't have the " + item + ". "<< endl;
            return;
        }
        cout << "You turn the key inside the lock, the gates slowly open. A rush of cold air lifts your hair as it enters the room." << endl;
        doorUnlocked = true;
        return;
    }

    Room::use(item, player);
}