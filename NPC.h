#ifndef NPC_H
#define NPC_H

#include <vector>
#include <string>
using namespace std;

class NPC {
private:
    string name;
    vector<string> dialogue;

public:
    NPC(string n);
    void addDialogue(string line);
    string getName();
    void talk();
};

#endif