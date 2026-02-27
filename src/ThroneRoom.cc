#include <iostream>
#include "ThroneRoom.h"
#include "Player.h"


ThroneRoom::ThroneRoom() {
    description = "A beautiful room stands all around you.\n Banners, torches, lamps, ornate structures are all organized leading to a stone chair on the north end of the room.\nThere is a Jester here, sitting on the steps just below the throne.";

    NPC jester("jester");
    jester.addDialogue("Ah a new customer I see");
    jester.addDialogue("Perhaps a riddle you'd like to solve for me");
    jester.addDialogue("Tell me what commands in such a room?");
    jester.addDialogue("Honor, coin, or the threat of a violent doom?");
    jester.addDialogue("I'll give you a clue for you seem slow I fear");
    jester.addDialogue("But take an interest in the Monarchs rear");
    npcs.push_back(jester);

    jesterBeat = false;
    jesterBribed = false;
    roomName = "Throne Room";
}

Room* ThroneRoom::go(string direction, Player& player) {
    if (direction == "north") {
        if (!jesterBeat && !jesterBribed ) {
            cout << "Why would you try to go north?" << endl;
            return this;
        } else {
            cout << "You go behind the throne to find a secret room" << endl;
            return northRoom;
        }
    }
    if (direction == "south") {
            cout << "You go east to the royal balcony" << endl;
            return southRoom;
    }

    if (direction == "west") {
            cout << "You go back to the inner garden." << endl;
            return westRoom;
    }

    return Room::go(direction, player);
}

void ThroneRoom::use(string item, Player& player) {
    
    if (item == "stick") {
        if (!player.hasItem("stick")) {
            cout << "You don't have the " + item + ". "<< endl;
            return;
        }
        if (!jesterBeat) {
            cout << "You beat the jester with the stick.\nSeveral loud Bangs echo across the room as you hit his back.\nHe throws himself at your feet." << endl;
            cout << "jester: 'ENOUGH ENOUGH'\njester: 'Please don't hurt me! I was talking about a secret chamber, behind the throne...'" << endl;
            description = "A beautiful room stands all around you.\n Banners, torches, lamps, ornate structures are all organized leading to a stone chair on the north end of the room.\n A humiliated jester lays on the floor, crying";
            jesterBeat = true;
        } else {
            cout << "You raise your arm to strike but don't find it in your heart to strike" << endl;;
        }
        return;
    }

    if (item == "gold") {
        if (!player.hasItem("gold")) {
            cout << "You don't have the " + item + ". "<< endl;
            return;
        }
        if (!jesterBribed && !jesterBeat) {
            cout << "You show the jester the gold bar, he stays quiet as he it of your hands" << endl;
            cout << "jester: I see... A payment for me from thee...\njester: Very well, there is a secret chamber behind the throne, that secret is for you alone" << endl;
            description = "A beautiful room stands all around you.\n Banners, torches, lamps, ornate structures are all organized leading to a stone chair on the north end of the room.\n The jester is admiring the gold bar";
            jesterBribed = true;
            player.delItem("gold");
        } else {
            cout << "The jester doesn't pay mutch attention to you";
        }
        return;
    }

    Room::use(item, player);
}

void ThroneRoom::talk(string npcName) {
    for (size_t i = 0; i < npcs.size(); i++) {
        if (npcs[i].getName() == npcName) {
            if (jesterBeat) {
                cout << "The jester is softly sobbing" << endl;
                return;
            }
            else if (jesterBribed) {
                cout << "The jester is too busy looking at his gold to pay any attention to you" << endl;
                return;
            }
            if(!jesterBeat && !jesterBribed) {
                npcs[i].talk();
                cout << "the jester lets out an unnerving laughter, it seems he's made you the butt of some joke" << endl;
                return;
            }
        }
    }
    cout << "No one by that name here." << endl;
}
