#include <iostream>
#include <string>
#include <cmath>
#include "supplies.h"
using namespace std;

Supply::Supply(){
    name = "";
    cost = 0;
}

Supply::Supply(string name1, double cost1, int amt){
    name = name1;
    cost = cost1;
    amtBought = amt;
}

void Supply::setCost(double cost1){
    cost = cost1;
}

void Supply::setName(string name1){
    name = name1;
}

void Supply::setAmtBought(int amt){
    amtBought = amt + this->getAmtBought();
}

double Supply::getCost(){
    return cost;
}

string Supply::getName(){
    return name;
}

int Supply::getAmtBought(){
    return amtBought;
}


