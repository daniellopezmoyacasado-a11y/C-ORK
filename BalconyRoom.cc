#include <iostream>
#include "BalconyRoom.h"


BalconyRoom::BalconyRoom() {
    description = "You are in a template chamber.";
    items.push_back("test");

    NPC test("test");
    test.addDialogue("Hello.");
    test.addDialogue("This is a test.");
    npcs.push_back(test);

    doorUnlocked = false;
        roomName = "Balcony";
}

Room* BalconyRoom::go(string direction, Player& player) {
    if (direction == "north") {
        if (!doorUnlocked) {
            cout << "The north door is locked." << endl;
            return this;
        }
        cout << "You go north." << endl;
        return northRoom;
    }

    return Room::go(direction, player);
}

void BalconyRoom::use(string item, Player& player) {
    if (!player.hasItem("test")) {
        cout << "You don't have the " + item + ". "<< endl;
        return;
    }
    if (item == "test") {
        cout << "You used the test item. It has no effect" << endl;
        return;
    }

    Room::use(item, player);
}