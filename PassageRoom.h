#ifndef PASSAGEROOM_H
#define PASSAGEROOM_H

#include "Room.h"

class PassageRoom : public Room {
private:
    bool doorUnlocked;

public:
    PassageRoom();
    Room* go(string direction, Player& Player) override;
};

#endif