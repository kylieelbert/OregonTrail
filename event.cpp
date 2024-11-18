#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include "events.h"
#include "players.h"
#include "supplies.h"
#include "milestones.h"
using namespace std;

Event::Event(){
    day = 28;
    month = 3;
    year = 1847;
    milesTravelled = 0;
    money = 1600;
    food = 0;
    bullets = 0;
    oxen = 0;
    wagonParts = 0;
    medKit = 0;
    MStracker = 0;
    teamSize = 5;
    leaderAlive = true;
    n = 0;
}

void Event::setDay(int day1){
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (day1 > 31){
                setMonth(month + 1);
                day = day1 - 31;
            }
            else{
                day = day1;
            }
            break;
        case 2:
        case 4:
        case 6:
        case 9: 
        case 11:
            if (day1 > 30){
                setMonth(month + 1);
                day = day1 - 30;
            }
            else{
                day = day1;
            }
            break;
        default:
            break;
    }
}

void Event::checkDay(int day1){
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (day1 > 31){
                setMonth(month + 1);
                day = day1 - 31;
            }
            else{
                day = day1;
            }
            break;
        case 2:
        case 4:
        case 6:
        case 9: 
        case 11:
            if (day1 > 30){
                setMonth(month + 1);
                day = day1 - 30;
            }
            else{
                day = day1;
            }
            break;
        default:
            break;
    }
}

void Event::setMonth(int month1){
    month = month1;
    if (month1 > 12){
        setYear(year + 1);
    }
}

void Event::setYear(int year1){
    year = year1;
}

void Event::setMilesTravelled(int miles){
    miles = milesTravelled;
}

void Event::setNextMilestone(int nextMilestone1, int miles){
    nextMilestone = nextMilestone1 - miles;
}

void Event::setBullets(int bullets1){
    bullets = bullets1;
}

void Event::setFood(int food1){
    food = food1;
}

void Event::setMoney(double money1){
    money = money1;
}

void Event::setOxen(int ox){
    oxen = ox;
}

void Event::setWagonParts(int parts){
    wagonParts = parts;
}

void Event::setMedKit(int med){
    medKit = med;
}

void Event::setPlayerName(string n){
    team.push_back(n);
}

void Event::setMS(string n, string t, int m, int i){
    if (i >= 15 || i < 0){
        cout << "Can't add milestone\n";
    }
    else{
        allMS[i].setDistance(m);
        allMS[i].setName(n);
        allMS[i].setType(t);
    }
}

int Event::getDay(){
    return day;
} 

int Event::getMonth(){
    return month;
}

int Event::getYear(){
    return year;
}

int Event::getMilesTravelled(){
    return milesTravelled;
}

int Event::getNextMilestone(){
    return nextMilestone;
}

int Event::getFood(){
    return food;
}

int Event::getBullets(){
    return bullets;
}

double Event::getMoney(){
    return money;
}

int Event::getOxen(){
    return oxen;
}

int Event::getWagonParts(){
    return wagonParts;
}

int Event::getMedKits(){
    return medKit;
}

bool Event::getLeader(){
    return leaderAlive;
}

string Event::getPlayerName(int input){
    return team[input].getName();
}

int Event::getNext(){
    int untilNext = allMS[MStracker].getDistance() - milesTravelled;
    return untilNext;
}

int Event::huntOption(int input){
    int num = 0;
    while (input < 1 || input > 2){
        cout << "INVALID INPUT. TRY AGAIN! 1 = YES & 2 = NO\n";
        cin >> input;
    }
    if (input == 1){
        srand(time(0));
        int r = rand() % 5 + 1;
        int guess;
        cout << "Guess a number between 1 & 5. If you guess right you have a successful hunt! You have 3 tries. Good luck!\n";
        for (int i = 0; i < 3; i++){
            cin >> guess;
            if (guess == r){
                cout << "Successful hunt!\n";
                num = 1;
                break;

            }
            else if(i == 2 && guess != r){
                cout << "Sorry! Better luck next time!\n";
                num = 2;
            }
            else{
                cout << "Try again!\n";
            }
        }
    }
    else if (input == 2){
        num = 2;
    }
    return num;
}

void Event::hunt(){
    day++;
    checkDay(day);
    int result = 0;
    int input = 0;
    bool success = false;
    srand(time(0));
    int r = rand() % 100 + 1;
    if (r > 50 && r <= 100){
        cout << "You didn't find anything. Better luck next time!\n";
    }
    if (r >= 1 && r <= 50){
        cout << "YOU GOT LUCKY! YOU ENCOUNTERED A RABBIT! DO YOU WANT TO HUNT?\n" << "(1) yes, (2) no (enter 1/2)\n";
        cin >> input;
        if (bullets >= 10){
            result = huntOption(input);
        }
        else{
            cout << "Sorry! You don't have enough bullets to hunt this animal.\n";
        }
        if (result == 1){
            success = true;
            food += 5;
            bullets -= 10;
        }
    }
    if (r >= 1 && r<= 25){
        cout << "YOU GOT LUCKY! YOU ENCOUNTERED A FOX! DO YOU WANT TO HUNT?\n" << "(1) yes, (2) no (enter 1/2)\n";
        cin >> input;
        if (bullets >= 8){
            result = huntOption(input);
        }
        else{
            cout << "Sorry! You don't have enough bullets to hunt this animal.\n";
        }
        if (result == 1){
            success = true;
            food += 10;
            bullets -= 8;
        }
    }
    if (r >=1 && r <= 15){
        cout << "YOU GOT LUCKY! YOU ENCOUNTERED A DEER! DO YOU WANT TO HUNT?\n" << "(1) yes, (2) no (enter 1/2)\n";
        cin >> input;
        if (bullets >= 5){
            result = huntOption(input);
        }
        else{
            cout << "Sorry! You don't have enough bullets to hunt this animal.\n";
        }
        if (result == 1){
            success = true;
            food += 60;
            bullets -= 5;
        }
    }
    if (r >= 1 && r <= 7){
        cout << "YOU GOT LUCKY! YOU ENCOUNTERED A BEAR! DO YOU WANT TO HUNT?\n" << "(1) yes, (2) no (enter 1/2)\n";
        cin >> input;
        if (bullets >= 10){
            result = huntOption(input);
        }
        else{
            cout << "Sorry! You don't have enough bullets to hunt this animal.\n";
        }
        if (result == 1){
            success = true;
            food += 200;
            bullets -= 10;
        }
    }
    if (r >= 1 && r <= 5){
        cout << "YOU GOT LUCKY! YOU ENCOUNTERED A MOOSE! DO YOU WANT TO HUNT?\n" << "(1) yes, (2) no (enter 1/2)\n";
        cin >> input;
        if (bullets >= 12){
            result = huntOption(input);
        }
        else{
            cout << "Sorry! You don't have enough bullets to hunt this animal.\n";
        }
        if (result == 1){
            success = true;
            food += 500;
            bullets -= 12;
        }
    }
    if (success == true){
        cout << "How well do you want to eat?\n";
        cout << "(1) Poorly: 2 lbs of food, per person\n";
        cout << "(2) Moderately: 3 lbs of food, per person\n";
        cout << "(3) Well: 5 lbs of food, per person\n";
        cin >> input;
        while (input < 1 || input > 3){
            cout << "INVALID INPUT. TRY AGAIN! (1, 2, or 3)\n";
            cin >> input;
        }
        if (input == 1){
            food -= (2 * teamSize);
        }
        else if (input == 2){
            food -= (3 * teamSize);
        }
        else if (input == 3){
            food -= (5 * teamSize);
        }
    }
    else{
        food -= (3 * teamSize);
    }
}

void Event::rest(){
    srand(time(0));
    int daysPast = rand() % 3 + 1;
    day += daysPast;
    checkDay(day);
    food -= (3 * daysPast * teamSize);
}

void Event::contTrail(){
    day += 14;
    checkDay(day);
    food -= (3 * 14 * teamSize); 
    srand(time(0));
    int m = rand() % 70 + 70;
    milesTravelled += m;
    if (milesTravelled > allMS[MStracker].getDistance()){
        milesTravelled = allMS[MStracker].getDistance();
    }
}

void Event::misfortune(int r){
    string illnesses[6] = {"typhoid", "cholera", "diarrhea", "measles", "dysentary", "fever"};
    string disease;
    int d = 0;
    int input = 0;
    int random = 0;
    string name;

    srand(time(0));
    random = rand() % 3 + 1;
    
    switch(random){
        case 1: 
            random = rand() % teamSize;
            name = team[random].getName();
            d = rand() % 6;
            disease = illnesses[d];
            cout << "Oh no! " << name << " has " << disease << " .\n";
            d = rand() % 100 + 1; 
            if (medKit >= 1){
                medKit--;
                if (d >= 1 && d <= 50){
                    cout << name << " has died of " << disease << "! \n";
                    if (random == 0){
                        cout << "The leader has died and you cannot continue.\n";
                        leaderAlive = false;
                    }
                    else{
                        team.erase(team.begin() + random);
                        teamSize--;
                    }
                }
                else{
                    cout << name << " didn't die of " << disease << "! \n";
                }
            }
            else{
                cout << "Would your party like to (1)rest or (2)press on?\n";
                cin >> input;
                while (input < 1 || input > 2){
                    cout << "Invalid option. Try again. 1 or 2?\n";
                    cin >> input;
                }
                if (input == 1){
                    day += 3;
                    checkDay(day);
                    food -= 3 * 3 * teamSize; 
                    if (d >= 1 && d <= 30){
                        cout << name << " has died of " << disease << "! \n";
                        if (random == 0){
                            cout << "The leader has died and you cannot continue.\n";
                            leaderAlive = false;
                        }
                        else{
                            teamSize--;
                            team.erase(team.begin() + random);
                        }
                    }
                    else{
                        cout << name << " didn't die of " << disease << "! \n";
                    }
                }
                else if (input == 2){
                    if (d >= 1 && d <= 70){
                        cout << name << " has died of " << disease << "! \n";
                        if (random == 0){
                            cout << "The leader has died and you cannot continue.\n";
                            leaderAlive = false;
                        }
                        else{
                            teamSize--;
                            team.erase(team.begin() + random);
                        }
                    }
                    else{
                        cout << name << " didn't die of " << disease << "! \n";
                    }
                }
            }
            break;
        case 2: 
            cout << "Oh no! One of your oxen wandered off!\n";
            oxen--;
            if (oxen <= 0){
                cout << "Your party is unable to continue because you don't have any more oxen.\n";
            }
            
            break;
        case 3: 
            cout << "Oh no! One of your wheels is broken.\n";
            wagonParts--;
            if (wagonParts < 0){
                cout << "Your party is unable to continue because you don't have any spare parts left to fix your wagon.\n";
            }
            else{
                cout << "You used one of your wagon parts to fix it.\n";
            }
            break;
        default: break;
    }
    
    int m = milesTravelled;
    double raiders = ((pow((m/100 - 4), 2) + 72) / (pow((m/100 - 4), 2) + 12) - 1) / 0.1;
    r = rand() % 100 + 1;
    if (r >= 1 && r <= raiders){
        cout << "RAIDERS AHEAD! THEY LOOK HOSTILE!\n";
        cout << "You have 3 options:\n";
        cout << "(1) Run, (2) Attack, (3) Surrender\n";
        cin >> input;
        while (input < 1 || input > 3){
            cout << "Ivalid input. Try again!\n";
            cin >> input;
        }
        switch(input){
            case 1: 
                cout << "Your party escapes, but you left behind one ox, 10 lbs. of food, and 1 wagon part.\n";
                oxen--;
                food -= 10;
                if (wagonParts > 0){
                    wagonParts--;
                }
                break;
            case 2:
                random = rand() % 7 + 1;
                cout << "Guess the correct number between 1 & 7 to beat the raiders. You get 3 tries!\n";
                int guess;
                for (int i = 0; i < 3; i++){
                    cin >> guess;
                    if (guess == r){
                        cout << "You won! Your party gets 50 lbs. of food and 50 bullets!\n";
                        food += 50;
                        bullets += 50;
                        break;
                    }
                    else if (guess != r && i == 2){
                        cout << "You lost! Your party will lose a quarter of your cash reserves and 50 bullets.\n";
                        money = money * 0.75;
                        if (bullets >= 50){
                            bullets -= 50;
                        }
                        else{
                            bullets = 0;
                        }
                    }
                    else{
                        cout << "Try again!\n";
                    }
                }
                break;
            case 3:
                cout << "Your party will lose a quarter of your cash reserves.\n";
                money = money * 0.75;
                break;
            default: break;
        }
    }
}

void Event::landmark(){
    if (milesTravelled == allMS[MStracker].getDistance()){
        string name = allMS[MStracker].getName();
        string type = allMS[MStracker].getType();
        int input = 0;
        if (type == "fort"){
            cout << "You have reached the fort: " << name << endl;
            while (input != 3){
            cout << "You can stay as long as you want. You can either (1) rest, (2) visit the store, or (3) continue journey.\n";    
            cin >> input;
                while (input < 1 || input > 3){
                    cout << "Invalid option! Choose 1-3.\n";
                    cin >> input;
                }
                switch(input){
                    case 1: rest(); statusUpdate(); break;
                    case 2: storeVisit(); statusUpdate(); break;
                    case 3: contTrail(); statusUpdate(); break;
                    default: break;
                }
            }
        }
        else if (type == "river"){
            cout << "You have reached the river crossing: " << name << endl;
            srand(time(0));
            int x = rand() % 100 + 1;
            if (x >= 1 && x <= 10){
                cout << "You got lucky! You found $1000!\n";
                money += 1000;
            }
            else if (x >= 1 && x <= 20){
                cout << "You got lucky! You found 20 bullets!\n";
                bullets += 20;
            }
        }
        else if (type == "landmark"){
            cout << "You have reached the landmark: " << name << endl;
            srand(time(0));
            int y = rand() % 100 + 1;
            if (y >= 1 && y <= 5){
                cout << "You got lucky! You found $2000!\n";
                money += 2000;
            }
            else if (y >= 1 && y <= 30){
                cout << "You got lucky! You found an extra wagon part!\n";
                wagonParts++;
            }
        }
        MStracker++;
    }
    else{
        cout << "";
    }
}

void Event::turn(int input){
    switch(input){
        case 1: 
            rest();
            break;
        case 2:
            contTrail();
            break;
        case 3:
            hunt();
            break;
        default: break;
    }
    srand(time(0));
    int r = rand() % 100 + 1;
    if (r >= 1 && r <= 40){
        misfortune(r);
    }
}

void Event::statusUpdate(){
    int n = getNext();
    cout << endl;
    cout << "Date: " << month << "/" << day << "/" << year << endl;
    cout << "Miles travelled: " << milesTravelled << " mi\n";
    cout << "Distance until next milestone: " << n << " mi\n";
    cout << "Food: " << food << " lbs.\n";
    cout << "Bullets: " << bullets << endl;
    cout << "Money: $" << fixed << setprecision(2) << money << endl;
    cout << endl;
}

void Event::storeVisit(){
    Supply Oxen("oxen", 40 * pow(1.25, n), 0);
    Supply Food("food", 0.5 * pow(1.25, n), 0);
    Supply Bullets("bullets", 2 * pow(1.25, n), 0);
    Supply WagonParts("wagon parts", 40 * pow(1.25, n), 0);
    Supply MedKit("medical kit", 25 * pow(1.25, n), 0);
    int input = -1;
    double total = 0.0;
    int amount = 0;
    while (input != 0){
        cout << "Choose what to buy:\n";
        cout << "(1) oxen, (2) food, (3) bullets, (4) wagon parts, (5) medical kits, (0) finish & pay\n";
        cout << "** Enter a number 0-5 **\n";
        cin >> input;
        switch(input){
            case 0:
                cout << "Total: $" << fixed << setprecision(2) << total << endl;
                money -= total;
                cout << "Money left: $" << money << endl;
                oxen += Oxen.getAmtBought();
                food += Food.getAmtBought();
                bullets += Bullets.getAmtBought();
                wagonParts += WagonParts.getAmtBought();
                medKit += MedKit.getAmtBought();
                break;
            case 1:
                cout << "You must spend $100-200 on oxen. There are 2 oxen in a yoke and the price of each yoke is $" << fixed << setprecision(2) << Oxen.getCost() << ". (Must buy 3-5 yokes) How many yokes would you like to purchase?\n";
                cin >> amount;
                while (amount < 3 || amount > 5){
                    cout << "Invalid amount. Try again!\n";
                    cin >> amount;
                }
                total += amount * Oxen.getCost();
                if (money >= total){
                    cout << "Total: $" << fixed << setprecision(2) << total << endl;
                    Oxen.setAmtBought(amount * 2);
                }
                else{
                    cout << "Sorry! You don't have enough money to buy this.\n";
                    total -= (amount * Oxen.getCost());
                }
                break;
            case 2:
                cout << "The store owner recommends that you purchase at least 200 lbs. of food per person at $" << fixed << setprecision(2) << Food.getCost() << " per pound. How many pounds of food would you like to purchase?\n";
                cin >> amount;
                total += amount * Food.getCost();
                if (money >= total){
                    cout << "Total: $" << fixed << setprecision(2) << total << endl;
                    Food.setAmtBought(amount);
                }
                else{
                    cout << "Sorry! You don't have enough money to buy this.\n";
                    total -= (amount * Food.getCost());
                }
                break;
            case 3:
                cout << "A box of 20 bullets costs $" << fixed << setprecision(2) << Bullets.getCost() << ". You will need the bullets for hunting along the way. How many boxes do you wish to purchase?\n";
                cin >> amount;
                total += amount * Bullets.getCost();
                if (money >= total){
                    cout << "Total: $" << fixed << setprecision(2) << total << endl;
                    Bullets.setAmtBought(amount * 20);
                }
                else{
                    cout << "Sorry! You don't have enough money to buy this.\n";
                    total -= (amount * Bullets.getCost());
                }
                break;
            case 4:
                cout << "A wagon part (wheels, axles, tongues) costs $" << fixed << setprecision(2) << WagonParts.getCost() << ". If the wagon breaks along the way, any wagon parts will be used to fix it. How many wagon parts do you wish to purchase?\n";
                cin >> amount;
                total += amount * WagonParts.getCost();
                if (money >= total){
                    cout << "Total: $" << fixed << setprecision(2) << total << endl;
                    WagonParts.setAmtBought(amount);
                }
                else{
                    cout << "Sorry! You don't have enough money to buy this.\n";
                    total -= (amount * WagonParts.getCost());
                }
                break;
            case 5:
                cout << "A medical aid kit costs $" << fixed << setprecision(2) << MedKit.getCost() << " and can be used to treat someone if they are sick. How many medical kits do you wish to purchase?\n";
                cin >> amount;
                total += amount * MedKit.getCost();
                if (money >= total){
                    cout << "Total: $" << fixed << setprecision(2) << total << endl;
                    MedKit.setAmtBought(amount);
                }
                else{
                    cout << "Sorry! You don't have enough money to buy this.\n";
                    total -= (amount * MedKit.getCost());
                }
                break;
            default: 
                cout << "INVALID INPUT. TRY AGAIN!\n";
                break;
        }
    }
    n++;
}

