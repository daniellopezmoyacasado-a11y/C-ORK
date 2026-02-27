#ifndef STARTROOM_H
#define STARTROOM_H

#include "Room.h"

class CorridorRoom : public Room {
private:
    bool doorUnlocked;

public:
    CorridorRoom();
    Room* go(string direction, Player& Player) override;
 
};

#endif