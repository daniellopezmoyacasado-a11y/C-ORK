#include <iostream>
#include "PassageRoom.h"
#include "Player.h"


PassageRoom::PassageRoom() {
    description = "You are in a long hallway heading west";

    doorUnlocked = false;
}

Room* PassageRoom::go(string direction, Player& player) {
    if (direction == "west") {
        cout << "You go west." << endl;
        return westRoom;
    }
    if (direction == "east") {
        cout << "You go east." << endl;
        return eastRoom;
    }

    return Room::go(direction, player);
}
