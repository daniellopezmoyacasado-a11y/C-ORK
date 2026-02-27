#include <iostream>
#include "GreatRoom.h"


GreatRoom::GreatRoom() {
    description = "You are in a large room with two halls at each side. The room has been recently emptied out.\nThe hall left is made of stone and sligtly goes down, the hall to the right is enforced in wood.";

    roomName = "Great Hall";
}

Room* GreatRoom::go(string direction, Player& player) {
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
