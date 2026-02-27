#ifndef BALCONYROOM_H
#define BALCONYROOM_H

#include "Room.h"

class BalconyRoom : public Room {
private:
    bool knightDead;
    bool attacked;
    bool defended;

public:
    BalconyRoom();
    Room* go(string direction, Player& Player) override;
    void use(string item, Player& player) override;
    void talk(string npcName) override;
};

#endif