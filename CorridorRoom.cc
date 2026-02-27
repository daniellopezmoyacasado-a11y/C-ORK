#include <iostream>
#include "CorridorRoom.h"
#include "Player.h"


CorridorRoom::CorridorRoom() {
    description = "You are in a long corridor heading east.";

    doorUnlocked = false;
    roomName = "Corridor";
}

Room* CorridorRoom::go(string direction, Player& player) {
    if (direction == "east") {
        cout << "You go east." << endl;
        return eastRoom;
    }
    if (direction == "west") {
        cout << "You go west." << endl;
        return westRoom;
    }

    return Room::go(direction, player);
}
