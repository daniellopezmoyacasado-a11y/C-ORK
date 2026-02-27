#ifndef STORAGEROOM_H
#define STORAGEROOM_H

#include "Room.h"

class StorageRoom : public Room {
private:

public:
    StorageRoom(Room* west);
    StorageRoom();
    Room* go(string direction, Player& Player) override;
};

#endif