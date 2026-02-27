#ifndef STARTROOM_H
#define STARTROOM_H

#include "Room.h"

class ArmoryRoom : public Room {
private:

public:
    ArmoryRoom();
    Room* go(string direction, Player& Player) override;
    void use(string item, Player& player) override;
};

#endif