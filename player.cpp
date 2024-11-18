#include <iostream>
#include <string>
#include <cmath>
#include "players.h"
using namespace std;

Player::Player(){
    name = "player";
}

Player::Player(string name1){
    if (name1 == ""){
        name = "player";
    }
    else{
        name = name1;
    }
}

void Player::setName(string name1){
    name = name1;
}

string Player::getName(){
    return name;
}

