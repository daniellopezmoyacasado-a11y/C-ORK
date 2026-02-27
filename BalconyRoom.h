#ifndef STARTROOM_H
#define STARTROOM_H

#include "Room.h"

class BalconyRoom : public Room {
private:
    bool doorUnlocked;

public:
    BalconyRoom();
    Room* go(string direction, Player& Player) override;
    void use(string item, Player& player) override;
};

#endif