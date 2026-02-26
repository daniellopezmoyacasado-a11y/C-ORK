#include "StorageRoom.h"
#include <iostream>

StorageRoom::StorageRoom(Room* west) { //old version
    description = "You are in a room full of barrels, most of them are emty though";
    items.push_back("meat");
}

StorageRoom::StorageRoom() {
    description = "You are in a room full of barrels, most of them are emty though";
    items.push_back("meat");
}

Room* StorageRoom::go(string direction, Player& player) {
    if (direction == "east") {
        cout << "You go east." << endl;
        return eastRoom;
    }

    return Room::go(direction, player);
}