#ifndef SUPPLIES_H
#define SUPPLIES_H

#include <iostream>
#include <string>
using namespace std;

class Supply{

    private:
    double cost;
    string name;
    int amtBought;
    
    public:
    // default & param
    Supply();
    Supply(string name1, double cost1, int amt);
    // mutators
    void setCost(double cost1);
    void setName(string name1);
    void setAmtBought(int amt);
    // accessors
    double getCost();
    string getName();
    int getAmtBought();
    
    // functions
    void storeVisit();
};
#endif

