#include <iostream>
#include "Player.h"

void Player::addItem(string item) {
    inventory.insert(item);
}

bool Player::hasItem(string item) {
    return inventory.find(item) != inventory.end();
}

void Player::showInventory() {
    cout << "Inventory: ";
     for (set<string>::iterator it = inventory.begin(); it != inventory.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void Player::delItem(string item) {
    inventory.erase(item);
}