#ifndef FORESTROOM_H
#define FORESTROOM_H

#include "Room.h"
#include <string>

class ForestRoom : public Room {
private:
    bool wolftamed;

public:
    ForestRoom();
    Room* go(string direction, Player& Player) override;
    void use(string item, Player& player) override;
};

#endif