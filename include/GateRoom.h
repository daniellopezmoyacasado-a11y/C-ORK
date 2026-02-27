#ifndef GATEROOM_H
#define GATEROOM_H

#include "Room.h"
#include <string>

class GateRoom : public Room {
private:
    bool doorUnlocked;

public:
    GateRoom();
    Room* go(string direction, Player& Player) override;
    void use(string item, Player& player) override;
};

#endif