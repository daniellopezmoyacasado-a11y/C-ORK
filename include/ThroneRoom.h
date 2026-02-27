#ifndef THRONEROOM_H
#define THRONEROOM_H

#include "Room.h"

class Player;

class ThroneRoom : public Room {
private:
    bool jesterBribed;
    bool jesterBeat;

public:
    ThroneRoom();
    Room* go(string direction, Player& Player) override;
    void use(string item, Player& player) override;
    void talk(string npcName) override;
};

#endif