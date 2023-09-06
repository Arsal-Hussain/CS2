/*
* Program Name: Roll Bones
* Date: 2022-09-16
* Author: Arsal Hussain
* Module Purpose: This program allows the user to play a dice game for certain stakes of their choice
*/
#include <iostream>
#include <string> // Needed to use strings
#include <stdio.h> //needed to throw the dice
using namespace std;
int stake; // hold player's balance amount
int bettingAmount; //how much the player is willing to place a bet on each try
int dice1, dice2; // computer generated number for each dice
int roll; //counts the amount of rolls
int diceTotal; //diceTotal is the "point"
int point; //to be used in the scenario that first roll isn't successful to compare

void stakes()
{
    do
    {
        cout << "What is your stake amount ? ";
        cin >> stake;
        if (stake < 0)
            cout << "You must enter a 0 or positive amount of money to bet with. Try again! \n";
    } while (stake < 0);
}

void rollDice()
{
    cout << "\nPress the enter key once or twice to continue..."; cin.ignore(); cin.get();
    srand(time(0));
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    diceTotal = dice1 + dice2;
    roll++;
}

void rollDicePoint()
{
    cout << "\nPress the enter key once or twice to continue..."; cin.ignore(); cin.get();
    srand(time(0));
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    point = dice1 + dice2;
    roll++;
    
}

void printResults()
{
    cout << "Dice 1 is " << dice1 << "\nDice 2 is " << dice2;
    cout << "\nThe dice throw results : " << diceTotal;
}

void printResultsPoint()
{
    cout << "Dice 1 is " << dice1 << "\nDice 2 is " << dice2;
    cout << "\nThe point is : " << diceTotal;
}

void pointSys()
{
    point = 0;
    do
    {
        cout << "\nThrow em again and hope that luck's on your side!";
        rollDicePoint();
        printResultsPoint();
        cout << "\nThe dice throw results is : " << point;
        if (point == 7)
        {
            cout << "\nUnfortunate, you lost!";
            stake -= bettingAmount;
            cout << "\nCurrent stake amount: " << stake;
            break;
        }
        else if (point == diceTotal)
        {
            cout << "\nWe have ourselves a winner!";
            stake += bettingAmount;
            cout << "\nCurrent stake amount: " << stake;
            break;
        }
    } while (point != diceTotal || point != 7 || stake != 0);
}

void betSetUp()
{
    
        cout << "Current stake amount: " << stake;
        if (stake > 0)
        {

            do
            {
                cout << "\nWhat will you bet? ";
                cin >> bettingAmount;
                if (bettingAmount > stake)
                {
                    cout << "Sorry! Bet should be larger than stake!";
                    continue;
                }
                if (bettingAmount == 0)
                {
                    cout << "Player Ends Game." << endl;
                    cout << "Roll Count: " << roll << endl;
                    cout << "Total Stake Amount: " << stake << endl;
                    break;
                }
                rollDice();
                printResults();
                if (diceTotal == 7 || diceTotal == 11)
                {
                    cout << "\nWe've got ourselves a winner!";
                    stake += bettingAmount;
                    cout << "\nCurrent stake amount: " << stake;
                }
                else if (diceTotal == 2 || diceTotal == 3 || diceTotal == 12)
                {
                    cout << "\nUnfortunate, you lost!";
                    stake -= bettingAmount;
                    cout << "\nCurrent stake amount: " << stake;
                }
                else
                {
                    pointSys();
                }
            } while (bettingAmount != 0 && stake > 0);


        }
   
}



int main()
{
    bettingAmount = 0;
    roll = 0;
    point = 0;
    stakes();
    betSetUp();

}
    


