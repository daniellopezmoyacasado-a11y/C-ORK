#ifndef STARTROOM_H
#define STARTROOM_H

#include "Room.h"

class TreasureRoom : public Room {
private:

public:
    TreasureRoom();
    Room* go(string direction, Player& Player) override;
};

#endif