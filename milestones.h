#ifndef MILESTONES_H
#define MILESTONES_H

#include <iostream>
#include <string>
using namespace std;

class Milestone{
    private:
    string name;
    string type;
    int distance;

    public:
    // default & param
    Milestone();
    Milestone(string name1, string type1, int miles);
    // mutators
    void setName(string name1);
    void setType(string type1);
    void setDistance(int miles);
    // accessors
    string getName();
    string getType();
    int getDistance();
};
#endif
