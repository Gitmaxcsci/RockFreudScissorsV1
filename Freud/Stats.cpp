#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Stats.h"
using namespace std;

//constructor that sets the default character stats
Stats::Stats() 
{
    //arbitrary non 0 values for now
    RockH = 0.85;
    
    RockD = 4;
    
    ScissorH = 0.6;
    
    ScissorD = 7;
    
    pHealth = 40;
    
}

//returns the rock's accuracy
double Stats::GetRockH() 
{
    return RockH;
}

//changes the rock's accuracy as a result of searches in the game
void Stats::SetRockH(double newRH) 
{
    RockH = newRH;
}

double Stats::GetScissorsH()
{
    return ScissorH;
}

void Stats::SetScissorsH(double newSH)
{
    ScissorH = newSH;
}

//returns the rock's damage
int Stats::GetRock() 
{
    return RockD;
}

//change's the rock's damage as a result of searches
void Stats::SetRock(int newRock) 
{
    RockD = newRock;
}

int Stats::GetScissors()
{
    return ScissorD;
}

void Stats::SetScissors(int newScissors)
{
    ScissorD = newScissors;
}

//returns the player's health
int Stats::PGetHealth() 
{
    return pHealth;
}

//changes the player's health
void Stats::PSetHealth(int newHealth) 
{
    pHealth = newHealth;
}




