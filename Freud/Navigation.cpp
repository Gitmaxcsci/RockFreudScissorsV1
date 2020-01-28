#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <random>
#include <ctime>
#include "Navigation.h"
using namespace std;


//constructor that sets initial position stats
Navigation::Navigation()
{
    LocID = 0;
    TurnId = 0;
    turnNum = 0;
    
    SearchChance = 0.7;
    
    Searched = 0;
}

//increments the number of turns that has passed
int Navigation::addTurnNum()
{
    turnNum++;
}


//runs players search of an area 
bool Navigation::Search() 
{
    //perform random call based on search chance
    double sCheck = (double) rand() / RAND_MAX;
    
    
    
    TurnId = 1;
    addTurnNum();
    
    //if random number is less than the search chance it is successful
    return(sCheck <= SearchChance);
}

//performs actual act of movement through the games positions
int Navigation::Move() 
{
    //called if player selects move
    LocID++;
    turnNum++;
    TurnId = 1;
    
}

//returns search chance
double Navigation::GetSearchChance() 
{
    return SearchChance;
}

//changes the search chance
void Navigation::SetSearchChance(int SSC) 
{
    SearchChance = SSC;
}

//returns the players current location
int Navigation::GetLocID() 
{
    return LocID;
}

//changes current location; could be used for shortcuts
void Navigation::SetLocID(int LID) 
{
    LocID = LID;
}

//increments location after each movement 
void Navigation::addLocID()
{
    LocID++;
}

//returns the turn state
int Navigation::GetTurnID() 
{
    return TurnId;
}

//changes the turn state 
int Navigation::SetTurnID(int TID) 
{
    TurnId = TID;
}

//returns number of turns that have passed
int Navigation::getTurnNum()
{
    return turnNum;
}



