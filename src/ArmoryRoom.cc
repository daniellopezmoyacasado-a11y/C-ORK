#include <iostream>
#include "ArmoryRoom.h"
#include "Player.h"

ArmoryRoom::ArmoryRoom() {
    description = "You are in the armory, there seems to be some useful equipment here.\nIt seems like you can go North and East from here";
    roomName = "Armory";
    items.push_back("sword");
    items.push_back("shield");
}

Room* ArmoryRoom::go(string direction, Player& player) {
    if (direction == "east") {
        cout << "You go out into what looks like a forest" << endl;
        return eastRoom;
    }
    if (direction == "north") {
        cout << "you go north" << endl;
        return northRoom;
    }

    if (direction == "south") {
        cout << "you go south" << endl;
        return southRoom;
    }


    return Room::go(direction, player);
}

void ArmoryRoom::use(string item, Player& player) {
    
    Room::use(item, player);
}