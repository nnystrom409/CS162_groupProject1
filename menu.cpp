//  menu.cpp
//  groupProject
//  This is the file for the functions to run the menu.

#include "menu.hpp"
#include <iostream>
#include <unistd.h>
using namespace std;

/*********************************************************************
 ** 
 **
 **
 **
 *********************************************************************/
void getValues(int *timeSteps, int *rows, int *columns, int *ants, int *doodlebugs)
{
    int choice = 0;
    
    while(choice != 7 && choice != 1 && choice != 8)   {
        cout << "Please enter an option below: " << endl;
        cout << "1: Initialize game with variables automatically initialized." << endl;
        cout << "2: Enter the number of time steps to run the game for: " << *timeSteps << endl;
        cout << "3: Enter the number of rows for the board: " << *rows << endl;
        cout << "4: Enter the number of columns for the board: " << *columns << endl;
        cout << "5: Enter the number of ants to start game with: " << *ants << endl;
        cout << "6: Enter the number of doodlebugs to begin game with: " << *doodlebugs << endl;
        cout << "7: Start the game." << endl;
        cout << "8: Quit the game." << endl;
        cin >> choice;
        
        while (choice < 1 || choice > 8)    {
            cin.clear();
            cin.ignore();
            cout << "Selection not valid. Please try again." << endl;
            getValues(timeSteps, rows, columns, ants, doodlebugs);
        }
        switch(choice)  {
            case 1:
                *rows = 20; *columns = 20; *ants = 100; *doodlebugs = 5;
                cout << "Enter the number of time steps you would like the game to run for: ";
                cin >> *timeSteps;
                while (*timeSteps < 1)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "You must enter an integer greater than 0. Please try again:";
                    cin >> *timeSteps;
                }
                while (*timeSteps > 200)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "You must enter an integer less than 200. Please try again: ";
                    cin >> *timeSteps;
                }
                break;
            case 2:
                cout << "Enter the number of time steps you would like to run the game for: ";
                cin >> *timeSteps;
                while (*timeSteps < 1)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "You must enter an integer greater than 0. Please try again:";
                    cin >> *timeSteps;
                }
                while (*timeSteps > 200)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "You must enter an integer less than 200. Please try again: ";
                    cin >> *timeSteps;
                }
                break;
            case 3:
                cout << "Enter the number of rows for the board: ";
                cin >> *rows;
                while (*rows < 1)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "You must enter an integer greater than 0. Please try again: ";
                    cin >> *rows;
                }
                while ((*rows * *columns) < (*ants + *doodlebugs))
                {
                    cin.clear();
                    cin.ignore();
                    cout << "The number of rows you entered is too small to fit the current amount of ants and doodlebugs. Please try again: ";
                    cin >> *rows;
                }
                break;
            case 4:
                cout << "Enter the number of columns for the board: ";
                cin >> *columns;
                while (*columns < 1)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "You must enter an integer greater than 0. Please try again:";
                    cin >> *columns;
                }
                while ((*rows * *columns) < (*ants + *doodlebugs))
                {
                    cin.clear();
                    cin.ignore();
                    cout << "The number of columns you entered is too small to fit the current amount of ants and doodlebugs. Please try again: ";
                    cin >> *columns;
                }
                break;
            case 5:
                cout << "Enter the number of ants to begin game with: ";
                cin >> *ants;
                while (*ants < 1)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "You must enter an integer greater than 0. Please try again:";
                    cin >> *ants;
                }
                while (*ants > (*rows * *columns) - *doodlebugs)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "The number of ants you entered is too large to fit on the board. Please try again: ";
                    cin >> *ants;
                }
                break;
            case 6:
                cout << "Enter the number of doodlebugs to begin game with: ";
                cin >> *doodlebugs;
                while (*doodlebugs < 1)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "You must enter an integer greater than 0. Please try again:";
                    cin >> *doodlebugs;
                }
                while (*doodlebugs > (*rows * *columns) - *ants)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "The number of doodlebugs you entered is too large to fit on the board. Please try again: ";
                    cin >> *doodlebugs;
                }
                break;
            case 7:
                if (*timeSteps == 0)    {
                    cout << endl << endl << "WARNING:You must enter an integer greater than 0 for the time steps to begin the game." << endl << endl << endl;
                    usleep(2000000);
                    choice = 0;
                    break;
                }
                else{
                   break;
                }
                
            case 8:
                exit(0);
        }
    }
}



bool playAgain(bool again)
{
    int choice;

    cout << "***Please select an option below***" << endl;
    cout << "1: Play game again." << endl;
    cout << "2: Quit game." << endl;
    cin >> choice;
    while(choice != 1 && choice != 2)   {
        cin.clear();
        cin.ignore();
        cout << "Selection not valid." << endl;
        playAgain(again);
    }
    if (choice == 1)    {
        return again = 1;
    }else
        return again = 0;
}
