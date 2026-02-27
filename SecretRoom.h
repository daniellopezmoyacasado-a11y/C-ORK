#ifndef SECRETROOM_H
#define SECRETROOM_H

#include "Room.h"

class SecretRoom : public Room {
private:
    bool premonition;

public:
    SecretRoom();
    Room* go(string direction, Player& Player) override;
    void use(string item, Player& player) override;
};

#endif