#include <iostream>
#include "LowerRoom.h"
#include "Globals.h"
#include "Player.h"


LowerRoom::LowerRoom() {
    description = "You are in a storage room, there are a few empty boxes lining the walls.\nOn the south side there is an archway that appears to be blocked by an troll.\nHe appears to be stuck.";

    NPC Troll("troll");
    Troll.addDialogue("Hello. Friend");
    Troll.addDialogue("I was looking for the lavatory when I got stuck in this here doorway.");
    Troll.addDialogue("I would be very thankful if you tried pushing me from that side. Friend");
    npcs.push_back(Troll);
    doorUnlocked = false;
    troll_talked = 0;

    roomName = "LowerStorage";
}

Room* LowerRoom::go(string direction, Player& player) {
    if (direction == "east") {
                cout << "You go back up the stairs." << endl;
        return eastRoom;
    }
    if (direction == "south") {
            if (!doorUnlocked) {
                cout << "The Troll stands in the way. You try to squeeze through." << endl;
                cout << "troll: You wish to join me? Friend?" <<endl;
                return this;
            }
        return southRoom;
    }

    return Room::go(direction, player);
}

void LowerRoom::use(string item, Player& player) {
    
    if (item == "sword") {
        if (!player.hasItem("sword")) {
        cout << "You don't have the " + item + ". "<< endl;
        return;
        }
        cout << "You swing your sword at the troll, it's extremely heavy and as such, you move extremely slowly." << endl;
        cout << "The troll sees your attack coming. He extends an arm and grabs your entire body. He crushes you with ease." << endl;
        cout << "troll: Sorry. Friend." << endl;
        cout << "YOU DIED" << endl;
        game_end = true;
        return;
    }

    Room::use(item, player);
}

void LowerRoom::talk(string npcName) {
    for (int i = 0; i < npcs.size(); i++) {
        if (npcs[i].getName() == npcName) {
            if(troll_talked == 0) {
                npcs[i].talk();
                troll_talked++;
                return;
            } else if (troll_talked > 3) {
                doorUnlocked = true;
                description = "You are in a storage room, there are a few empty boxes lining the walls.\nOn the south side there is an archway.\nThe troll stands to the side, he appears to be doing his bussines inside an empty barrel.";
                cout << "troll: Thank you. Friend." << endl;
                return;
            } else if (troll_talked == 2) {
                cout << "You give one final push to the troll, he finally breaks free."<< endl;
                doorUnlocked = true;
                troll_talked ++;
                return;
            }
            cout << "You push agains the troll, he moves a little" << endl;
            cout << "troll: Yes. Continue. Friend" << endl;
            troll_talked ++;
            return;
        }
    }
    cout << "No one by that name here." << endl;
}