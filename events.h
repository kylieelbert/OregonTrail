#ifndef EVENTS_H
#define EVENTS_H

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include "players.h"
#include "supplies.h"
#include "milestones.h"
using namespace std;

class Event{

    private:
    int milesTravelled;
    int nextMilestone;
    int month;
    int day;
    int year;
    int bullets;
    int food;
    double money;
    int oxen;
    int wagonParts;
    int medKit;
    vector<Player> team;
    int teamSize;
    bool leaderAlive;
    Milestone allMS[15];
    int MStracker;
    int n;

    public:
    // default 
    Event();

    // mutators
    void setDay(int day1);
    void setMonth(int month1);
    void setYear(int year1);
    void setMilesTravelled(int miles);
    void setNextMilestone(int nextMilestone1, int miles);
    void setBullets(int bullets1);
    void setFood(int food1);
    void setMoney(double money1);
    void setOxen(int ox);
    void setWagonParts(int parts);
    void setMedKit(int med);
    void setPlayerName(string n);
    void setMS(string n, string t, int m, int i);
    void checkDay(int day1);

    // accessors
    int getDay();
    int getMonth();
    int getYear();
    int getMilesTravelled();
    int getNextMilestone();
    int getBullets();
    int getFood();
    double getMoney();
    int getOxen();
    int getWagonParts();
    int getMedKits();
    bool getLeader();
    string getPlayerName(int input);
    int getNext();

    // functions
    int huntOption(int input);
    void hunt();
    void rest();
    void contTrail();
    void turn(int input);
    void misfortune(int r);
    void statusUpdate();
    void storeVisit();
    void landmark();

};
#endif
