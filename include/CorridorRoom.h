#ifndef CORRIDORROOM_H
#define CORRIDORROOM_H

#include "Room.h"
#include <string>

class CorridorRoom : public Room {
private:
    bool doorUnlocked;

public:
    CorridorRoom();
    Room* go(string direction, Player& Player) override;
 
};

#endif