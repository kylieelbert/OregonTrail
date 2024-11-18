#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "events.h"
#include "supplies.h"
#include "players.h"
#include "milestones.h"

using namespace std;

int checkStatus(Event game){
    int num = 0;
     if (game.getFood() <= 0){
         num = -1;
         cout << "Oh no! You ran out of food.\n";
     }
     if (game.getOxen() <= 0){
         num = -1;
         cout << "Oh no! You ran out of oxen.\n";
     }
     if (game.getWagonParts() <= -1){
         num = -1;
         cout << "Oh no! You don't have any wagon parts to fix your wagon.\n";
     }
     if (game.getMonth() > 11 && game.getDay() > 30){
         return -1;
         cout << "Oh no!" << "It's " << game.getMonth() << "/" << game.getDay() << "/1847. You didn't make it to Oregon in time.\n";
     }
     if (game.getLeader() == false){
         num = -1;
     }
     if (game.getMilesTravelled() >= 2040){
         num = 1;
     }
     return num;
}

void exportStats(Event game){ 
    // intention is to use holder class 
    // export to results.txt
    // take Event class and put it in a format in file
    ofstream fileOut;
    string file = "results.txt";
    fileOut.open(file);
    fileOut << "Leader: " << game.getPlayerName(0) << endl;
    fileOut << "Miles travelled: " << game.getMilesTravelled() << " mi\n";
    fileOut << "Food remaining: " << game.getFood() << " lbs.\n";
    fileOut << "Cash remaining: $" <<  game.getMoney() << endl;
}

int main(){
    int input = 0;
    string name; 
    int num;
    // date 
    int day = 28;
    int month = 3;
    int year = 1847;

    Event game;

    // Milestone array;
    game.setMS("Kansas River Crossing","river", 102, 0);
    game.setMS("Big Blue River Crossing", "river", 185, 1);
    game.setMS("Fort Kearney", "fort", 304, 2);
    game.setMS("Chimney Rock", "landmark", 554, 3);
    game.setMS("Fort Laramie", "fort", 640, 4);
    game.setMS("Independence Rock", "landmark", 830, 5);
    game.setMS("South Pass", "landmark", 932, 6);
    game.setMS("Fort Bridger", "fort", 989, 7);
    game.setMS("Green River Crossing", "river", 1151, 8);
    game.setMS("Soda Springs", "landmark", 1295, 9);
    game.setMS("Fort Hall", "fort", 1395, 10);
    game.setMS("Snake River Crossing", "river", 1534, 11);
    game.setMS("Fort Boise", "fort", 1648, 12);
    game.setMS("Blue Mountains", "landmark", 1808, 13);
    game.setMS("Fort Walla Walla", "fort", 1863, 14);
    

    cout << "THIS PROGRAM SIMULATES A TRIP OVER THE OREGON TRAIL FROM INDEPENDENCE, MISSOURI TO OREGON CITY, OREGON IN 1847. YOUR FAMILY OF FIVE WILL COVER THE 2040 MILE OREGON TRAIL IN 5-6 MONTHS --- IF YOU MAKE IT ALIVE." << endl;
    
    // take input for leader and other players 
    cout << "Leader's name:\n";
    getline(cin, name);
    game.setPlayerName(name);
    for (int i = 1; i < 5; i++){
        cout << "Enter teammate's name:\n";
        getline(cin, name);
        game.setPlayerName(name);
    }

    // ask start date
    cout << "You and your party are set to start your journey on 3/28/1847 and need to make it to Oregon by 11/30/1847. Would you like to change your start date? (1) yes (2) no\n";
    cin >> input;
    while (input < 1 || input > 2){
        cout << "Invalid input. Please enter 1 for yes or 2 for no.\n";
        cin >> input;
    }
    if (input == 1){
        cout << "You can start between 3/1/1847 & 5/1/1847\n";
        cout << "Please enter start month:\n";
        cin >> input;
        while (input < 3 || input > 5){
            cout << "Enter a valid month\n";
            cin >> input;
        }
        month = input;
        game.setMonth(month);
        cout << "Please enter start date:\n";
        cin >> input;
        if (month == 3 || month == 5){
            while (input < 1 || input > 31){
                cout << "Enter a valid date\n";
                cin >> input;
            }
            day = input;
        }
        else if (month == 4){
            while (input < 1 || input > 30){
                cout << "Enter a valid date\n";
                cin >> input;
            }
            day = input;
        }
        game.setDay(day);
        cout << "Start date is " << month << "/" << day << "/1847.\n";
    }
    else if (input == 2){
        cout << "Start date is 3/28/1847.\n";
    }
    
    cout << "YOU HAD SAVED $1600 TO SPEND FOR THE TRIP, AND YOU HAVE A WAGON. YOU WILL NEED TO SPEND THE REST OF YOUR MONEY ON THE FOLLOWING ITEMS:\n";
    cout << "- OXEN. YOU CAN SPEND $100-$200 ON YOUR TEAM. THE MORE YOU SPEND, THE FASTER YOU'LL GO BECAUSE YOU'LL HAVE BETTER ANIMALS.\n";         
    cout << "- FOOD. THE MORE YOU HAVE, THE LESS CHANCE THERE IS OF GETTING SICK.\n";        
    cout << "- AMMUNITION. YOU WILL NEED BULLETS FOR ATTACKS BY ANIMALS AND BANDITS, AND FOR HUNTING FOOD.\n";
    cout << "- MISCELLANEOUS SUPPLIES. THIS INCLUDES MEDICINE AND OTHER THINGS YOU WILL NEED FOR SICKNESS AND EMERGENCY REPAIRS.\n";
    cout << "YOU CAN SPEND ALL YOUR MONEY BEFORE YOU START YOUR TRIP, OR YOU CAN SAVE SOME OF YOUR CASH TO SPEND AT FORTS ALONG THE WAY WHEN YOU RUN LOW. HOWEVER, ITEMS COST MORE AT THE FORTS. YOU CAN ALSO GO HUNTING ALONG THE WAY TO GET MORE FOOD.\n";
    game.storeVisit();
    input = 0;

    while (input != 4){
        game.statusUpdate();
        game.landmark();
        cout << "It is a new turn. You can either: \n" << "(1) rest, (2) continue on trail, (3) hunt, (4) quit\n";
        cin >> input;
        game.turn(input);
        num = checkStatus(game); 
        if (num == -1){
            break;
        }
        if (num == 1){
            break;
        }
    }

    if (num == 1){
        cout << "YOU REACHED OREGON! CONGRATULATIONS, YOU WON!\n";
        exportStats(game);

    }
    if (input == 4){
        cout << "YOU QUIT\n";
        exportStats(game);
    }
    else if (num == -1){
        cout << "YOU LOST\n";
        exportStats(game);
    }

    return 0;
}