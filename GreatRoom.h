#ifndef GREATROOM_H
#define GREATROOM_H

#include "Room.h"

class GreatRoom : public Room {
private:

public:
    GreatRoom();
    Room* go(string direction, Player& Player) override;
 
};

#endif