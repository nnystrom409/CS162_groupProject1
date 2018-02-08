/*********************************************************************
 ** Program name: Group Project : Predator-Prey Simulation
 ** Authors: Xavier Hollingsworth, Hannah Moon, Nicholas Nystrom, Hidayet Abay
 ** Date: 02/07/2018
 ** Description:
 *********************************************************************/
#include "menu.hpp"
#include <iostream>
using namespace std;


//  Function to display extra-credit at beginning of program.
void extraCredit()
{
    cout << "*Extra-Credit: Ask user to enter the number of time steps, the size of ";
    cout << "grid in rows and columns, the number of ants, and the number of ";
    cout << "doodlebugs*" << endl << endl;
    cout << "******Welcome to the Prey-Predator Simulation Game******" << endl;
}



int main() {
    //  Create variables
    int timeSteps, rows, columns, ants, doodlebugs;
    bool runAgain = false;
    
    extraCredit();
    
    do {
    timeSteps = 0; rows = 20; columns = 20; ants = 100; doodlebugs = 55;
    getValues(&timeSteps, &rows, &columns, &ants, &doodlebugs);
    
    } while (playAgain(runAgain));  //  Runs game until user decides to quit.
    return 0;
}

