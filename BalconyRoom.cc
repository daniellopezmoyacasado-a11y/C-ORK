#include <iostream>
#include "BalconyRoom.h"
#include "Globals.h"
#include "Player.h"


BalconyRoom::BalconyRoom() {
    description = "You are in a long hall that is open on the east. You can see a forest extending far into mountains that loom like giant shadows in the night. \nThere is only an exit north, there is a knight guarding the way.\n He looks seriously skilled\n";

    NPC knight("knight");
    knight.addDialogue("...");
    npcs.push_back(knight);

    knightDead = false;
    roomName = "Balcony";
    attacked = false;
    defended = false;
}

Room* BalconyRoom::go(string direction, Player& player) {
    if (attacked && !knightDead) {
        cout << "The knight hits your side. He was faster than you. You feel the blade go through you. Everything goes dark..." << endl;
        cout << "YOU DIED"<< endl;
        game_end = true;
        return this;
    }
    if (direction == "north") {
        if (!knightDead) {
            cout << "The north door is blocked by the knight." << endl;
            return this;
        }
        cout << "You go north." << endl;
        return northRoom;
    }
    if (direction == "west") {
        cout << "You go west." << endl;
        return westRoom;
    }

    return Room::go(direction, player);
}

void BalconyRoom::use(string item, Player& player) {
    
    if (item == "sword") {
        if (!player.hasItem("sword")) {
            cout << "You don't have the " + item + ". "<< endl;
            return;
        }
        if (!attacked && !knightDead) {
            cout << "You swing your sword. It's extremely heavy." << endl;
            cout << "The knight dodges you with ease. Your left bodyside is left unguarded." << endl;
            attacked = true;
            return;
        } else if (attacked && !defended && !knightDead) {
            cout << "The knight hits your side. He was faster than you. You feel the blade go through you. Everything goes dark..." << endl;
            cout << "YOU DIED"<< endl;
            game_end = true;
            return;
        } else if (attacked && defended && !knightDead) {
            cout << "You put all of your strength into a final swing." << endl;
            cout << "The knight's head makes a satisfying thud as it hits the ground"<< endl;
            knightDead = true;
            return;
        }
    }

    if (item == "shield") {
        if (!player.hasItem("shield")) { //this is so redundant... I just keep copying it, i need to delete them all when I can.
            cout << "You don't have the " + item + ". "<< endl;
            return;
        }
        if (attacked && !knightDead) {
            cout << "You barely manage to block the incoming attack. You notice there's an opening to hit the knights head." << endl;
            defended = true;
            return;
        } else if (!knightDead){
            cout << "The knight stares at you. He tilts his head as if confused by your actions." << endl;
            return;
        }
    }

    Room::use(item, player);
}

void BalconyRoom::talk(string npcName) {
    if (attacked && !knightDead) {
        cout << "The knight hits your side. He was faster than you. You feel the blade go through you. Everything goes dark..." << endl;
        cout << "YOU DIED"<< endl;
        game_end = true;
        
    } else
        Room::talk(npcName);
}