#ifndef STARTROOM_H
#define STARTROOM_H

#include "Room.h"

class GreatRoom : public Room {
private:

public:
    GreatRoom();
    Room* go(string direction, Player& Player) override;
 
};

#endif