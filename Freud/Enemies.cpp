#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Enemies.h"
using namespace std;


//returns the enemy's accuracy
double Enemies::EGetHitChance() 
{
    return eHit;
}

//changes the enemy's accuracy as a result of rage state changes or enemy changes
void Enemies::ESetHitChance(double newEHit) 
{
    eHit = newEHit;
}

//returns current enemy's damage
int Enemies::EGetDamage() 
{
    return eDamage;
}

//changes enemy's damage
void Enemies::ESetDamage(int newEDamage) 
{
    eDamage = newEDamage;
}

//returns current enemy's health
int Enemies::EGetHealth() 
{
    return eHealth;
}

//changes enemy's health
void Enemies::ESetHealth(int newEHealth) 
{
    eHealth = newEHealth;
}

//returns current enemy's rage state
int Enemies::getRage() 
{
    return Rage;
}

//changes current enemy's rage state
void Enemies::setRage(int RageSet) 
{
    Rage = RageSet;
    
    if(RageSet == 1)
    {
        eHit = eHit - 0.05;
        eDamage = eDamage + 1;
        cout << "Enemy is now annoyed, attack increases by 1, accuracy decreases by 5%" << endl;
    }
    else if(RageSet == 2)
    {
        eHit = eHit - 0.05;
        eDamage = eDamage + 3;
        eHealth = eHealth + 3;
        cout << "Enemy is now enraged, attack and health increases by 3, accuracy decreases by 5%" << endl;
    }
    else if(RageSet == 3)
    {
        eHit = eHit - 0.2;
        eDamage = eDamage - 3;
        eHealth = eHealth -3;
        cout << "The enemy has become depressed! Attack and health decrease by 3, accuracy decreases by 20%" << endl;
    }
}

//prints enemy name and introduction
void Enemies::getIntro() 
{
    cout << name << endl;
    cout << intro << endl;
}

//returns which mental attack choice annoys the enemy
int Enemies::getAnnoying()
{
    return annoying;
}

//returns which mental attack enrages the enemy
int Enemies::getEnraging()
{
    return enraging;
}

//returns which mental attack depresses the enemy
int Enemies::getDepressing()
{
    return depressing;
}

//prints all mental attack options
void Enemies::getMind() 
{
    cout << mind[1] << endl;
    cout << mind[2] << endl;
    cout << mind[3] << endl;
}

//get enemy dialogue response to mental attack based on rage state
void Enemies::getMindRage(int ragePick)
{
    if(ragePick != 0)
    {
        cout << mindRage[ragePick] << endl;
    }
}

//get enemy attack dialogue
void Enemies::getAttacks()
{
    cout << attacks << endl;
}

//gets victory or defeat dialogue
void Enemies::getEnd(int outcome)
{
    cout << fightEnd[outcome] << endl;
}



//For setting up enemies array:

void Enemies::setName(string givenName)
{
    name = givenName;
}

void Enemies::setIntro(string givenIntro)
{
    intro = givenIntro;
}

void Enemies::setAnnoying(int givenAnnoy)
{
    annoying = givenAnnoy;
}

void Enemies::setEnraging(int givenEnrage)
{
    enraging = givenEnrage;
}

void Enemies::setDepressing(int givenDepress)
{
    depressing = givenDepress;
}

void Enemies::setMind(string mind1, string mind2, string mind3)
{
    mind[0] = "blankTest";
    mind[1] = mind1;
    mind[2] = mind2;
    mind[3] = mind3;
}

void Enemies::setMindRage(string mR1, string mR2, string mR3)
{
    mindRage[0] = "testBlank";
    mindRage[1] = mR1;
    mindRage[2] = mR2;
    mindRage[3] = mR3;
}

void Enemies::setAttack(string givenAttack)
{
    attacks = givenAttack;
}

void Enemies::setFightEnds(string defeat, string victory)
{
    fightEnd[0] = defeat; //enemy is defeated
    fightEnd[1] = victory; //enemy wins 
}