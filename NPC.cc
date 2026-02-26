#include <iostream>
#include "NPC.h"

NPC::NPC(string n) {
    name = n;
}

void NPC::addDialogue(string line) {
    dialogue.push_back(line);
}

string NPC::getName() {
    return name;
}

void NPC::talk() {
    for (int i = 0; i < dialogue.size(); i++) {
        cout << name << ": " << dialogue[i] << endl;
    }
}