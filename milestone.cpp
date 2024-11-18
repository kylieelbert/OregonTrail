#include <iostream>
#include <string>
#include <cmath>
#include "milestones.h"
using namespace std;

Milestone::Milestone(){
    name = "";
    type = "";
    distance = 0;
}

Milestone::Milestone(string name1, string type1, int miles){
    name = name1;
    type = type1;
    distance = miles;
}

void Milestone::setName(string name1){
    name = name1;
}

void Milestone::setType(string type1){
    type = type1;
}

void Milestone::setDistance(int miles){
    distance = miles;
}

string Milestone::getName(){
    return name;
}

string Milestone::getType(){
    return type;
}

int Milestone::getDistance(){
    return distance;
}
