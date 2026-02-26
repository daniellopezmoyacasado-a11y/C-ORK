#ifndef STARTROOM_H
#define STARTROOM_H

#include "Room.h"

class StartRoom : public Room {
private:
    bool doorUnlocked;

public:
    StartRoom(Room* north, Room* west);
    StartRoom();
    Room* go(string direction, Player& Player) override;
    void use(string item, Player& player) override;
};

#endif