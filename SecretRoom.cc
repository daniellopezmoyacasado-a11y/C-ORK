#include <iostream>
#include "SecretRoom.h"
#include "Globals.h"
#include "Player.h"


SecretRoom::SecretRoom() {
    description = "This is the kings hidden chamber, the walls are filled with bookcases.\nIn the room there is a large wooden desk, you can see something shiny on it, right beside an open book.\n Behind the desk there's a lever, and there's also a chain hanging from the west wall, it seems to be attached to some mechanism. \nAs you approach the desk, you notice a trap dor is hidden right in the center of the room, it feels like it can be opened remotely.";
    items.push_back("kingskey");
    premonition = false;
    roomName = "Secret Chamber";
}

Room* SecretRoom::go(string direction, Player& player) {
    if (direction == "south") {
        cout << "You go back to the throne room." << endl;
        return southRoom;
    }

    return Room::go(direction, player);
}

void SecretRoom::use(string item, Player& player) {
   if (item == "chain") {
        if (!drawbridge_down) {
            cout << "You pull hard on the chain. You hear the sound of water and of a heavy object moving in the distance" << endl;
            drawbridge_down = true;
            return;
        } else {
            cout << "You try to pull again. But it doesn't budge" << endl;
            return;
        }
    }

    if (item == "lever") {
        if (!premonition) {
            cout << "Something in your gut tells you not to go through with this..." << endl;
            premonition = true;
            return;
        } else {
            cout << "You reach over the desk, and pull the lever.\n You were standing on the wrong side...\nA loud crack is the last sound you hear before you fall down a dark well\nYOU DIED" << endl;
            game_end = true;
            return;
        }
    }

    if (item ==  "book") { //I still have to write the lore.
        cout << "You grab the open book laying on the desk. It appears to be the kings personal diary" << endl;
        //lore dump goes here
    }

    Room::use(item, player);
}