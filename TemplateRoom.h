#ifndef TEMPLATEROOM_H
#define TEMPLATEROOM_H

#include "Room.h"

class TemplateRoom : public Room {
private:
    bool doorUnlocked;

public:
    TemplateRoom();
    Room* go(string direction, Player& Player) override;
    void use(string item, Player& player) override;
};

#endif