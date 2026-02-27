#ifndef STARTROOM_H
#define STARTROOM_H

#include "Room.h"

class CornerRoom : public Room {
private:

public:
    CornerRoom();
    Room* go(string direction, Player& Player) override;
    void use(string item, Player& player) override;
};

#endif