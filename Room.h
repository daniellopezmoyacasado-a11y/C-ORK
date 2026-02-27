#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <string>
#include "NPC.h"
#include "Player.h"

using namespace std;

class Room {
protected:
    string roomName;
    string description;
    vector<string> items;
    vector<NPC> npcs;
    Room* northRoom;
    Room* southRoom;
    Room* eastRoom;
    Room* westRoom;

public:
    Room(); 
    virtual void look(); 
    virtual void take(string item, Player& player);
    virtual void talk(string npcName);
    virtual Room* go(string direction, Player& player);
    virtual void use(string item, Player& player); //new, player has to use items to clear conditions to be able to leave the room.
    virtual ~Room() {}
    void setNorth(Room* r);
    void setSouth(Room* r);
    void setEast(Room* r);
    void setWest(Room* r);
    string getName();
    
    //I didn't remember these existed but
    //apparently virtual funcs allow 
    //for different objects to essentially 
    //have different behaviour while  being 
    //of the same class and having the same functions
};

#endif