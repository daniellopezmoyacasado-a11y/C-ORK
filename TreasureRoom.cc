#include <iostream>
#include "TreasureRoom.h"
#include "Player.h"


TreasureRoom::TreasureRoom() {
    description = "You are in a room filled with chests.They're overflowing with coins, pearls and diamonds.\nYou try to fill your pockets only to have your entire pant leg be ripped.\nSeems like you're gonna have to take only what you can hold in your hands";
    items.push_back("gold");
}

Room* TreasureRoom::go(string direction, Player& player) {
    if (direction == "north") {
        cout << "You go north." << endl;
        return northRoom;
    }

    return Room::go(direction, player);
}

