#ifndef PLAYERS_H
#define PLAYERS_H

#include <string>
using namespace std;

class Player{
    private:
    string name;

    public:
    // default & param
    Player();
    Player(string name1);
    // mutators
    void setName(string name1);
    // accessors
    string getName();

};
#endif
