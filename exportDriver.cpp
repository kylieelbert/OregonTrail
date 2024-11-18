#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "events.h"
#include "supplies.h"
#include "players.h"

using namespace std;

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

// int main(){
//     return 0;
// }