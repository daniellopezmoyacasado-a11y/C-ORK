#ifndef PLAYER_H
#define PLAYER_H

#include <set>
#include <string>
using namespace std;

class Player {
private:
    set<string> inventory;

public:
    void addItem(string item);
    bool hasItem(string item);
    void delItem(string item);
    void showInventory();
};

#endif