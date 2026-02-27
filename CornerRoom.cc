#include <iostream>
#include "CornerRoom.h"
#include "Player.h"


CornerRoom::CornerRoom() {
    description = "You are in a windowless room. In the west corner there are a set of stairs taking you down, to your right,\na passage leading to a great room.";
    roomName = "Corner Room";
}

Room* CornerRoom::go(string direction, Player& player) {
    if (direction == "east") {
        cout << "the passage opens to a hall with no ceiling, there is a smell of rotting wood." << endl;
        return eastRoom;
    }
    if (direction == "west") {
        cout << "you go down the stairs. As you begin to reach the bottom, deep loud breaths reach your ears." << endl;
        return westRoom;
    }
    if (direction == "south") {
        cout << "you go south." << endl;
        return southRoom;
    }

    return Room::go(direction, player);
}

void CornerRoom::use(string item, Player& player) {
    
    Room::use(item, player);
}