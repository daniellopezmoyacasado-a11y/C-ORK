#ifndef STARTROOM_H
#define STARTROOM_H

#include "Room.h"

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