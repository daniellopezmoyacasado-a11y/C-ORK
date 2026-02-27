#ifndef CORNERROOM_H
#define CORNERROOM_H

#include "Room.h"
#include <string>

class CornerRoom : public Room {
private:

public:
    CornerRoom();
    Room* go(string direction, Player& Player) override;
    void use(string item, Player& player) override;
};

#endif