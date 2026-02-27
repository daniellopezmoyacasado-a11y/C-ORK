#ifndef LOWERROOM_H
#define LOWERROOM_H

#include "Room.h"

class LowerRoom : public Room {
private:
    bool doorUnlocked;
    int troll_talked;

public:
    LowerRoom();
    Room* go(string direction, Player& Player) override;
    void use(string item, Player& player) override;
    void talk(string npcName) override;
};

#endif