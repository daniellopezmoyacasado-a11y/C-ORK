#include <iostream>
#include "Room.h"
#include "Player.h"

class Player; //if i didn't add this for some reason throne room didn't work...

void Room::look() {
    cout << description << endl;

    if (items.size() > 0) {
        cout << "Items here: ";
        for (size_t i = 0; i < items.size(); i++) {
            if(i != 0) cout << ", ";
            cout << items[i];
        }
        cout << endl;
    }

    if (npcs.size() > 0) {
        cout << "NPCs here: ";
        for (size_t i = 0; i < npcs.size(); i++) {
            if(i != 0) cout << ", ";
            cout << npcs[i].getName();
        }
        cout << endl;
    }
}

Room::Room() {
    northRoom = NULL;
    southRoom = NULL;
    eastRoom = NULL;
    westRoom = NULL;
}

void Room::setNorth(Room* r) { northRoom = r; }
void Room::setSouth(Room* r) { southRoom = r; }
void Room::setEast(Room* r)  { eastRoom = r; }
void Room::setWest(Room* r)  { westRoom = r; }


void Room::take(string item, Player& player) {
    for (size_t i = 0; i < items.size(); i++) {
        if (items[i] == item) {
            player.addItem(item);
            items.erase(items.begin() + i);
            cout << "Taken." << endl;
            return;
        }
    }
    cout << "No such item here." << endl;
}

void Room::talk(string npcName) {
    for (size_t i = 0; i < npcs.size(); i++) {
        if (npcs[i].getName() == npcName) {
            npcs[i].talk();
            return;
        }
    }
    cout << "No one by that name here." << endl;
}

Room* Room::go(string direction, Player& player) {
    (void)player;

    if (direction == "north" && northRoom != NULL)
        return northRoom;

    if (direction == "south" && southRoom != NULL)
        return southRoom;

    if (direction == "east" && eastRoom != NULL)
        return eastRoom;

    if (direction == "west" && westRoom != NULL)
        return westRoom;

    cout << "You can't go that way." << endl;
    return this;
}

void Room::use(string item, Player& player) {
    if (player.hasItem(item)) {
        cout << "You use the " << item << ", but nothing happens." << endl;
    } else {
        cout << "You don't have that item." << endl;
    }
}

string Room::getName() {
    return roomName;
}
