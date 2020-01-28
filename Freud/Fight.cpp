#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <random>
#include <ctime>
#include "Stats.h"
#include "Fight.h"
using namespace std;

//gives menu options for picking between physical or mental attacks
int Fight::fightOrMind(int checkR)
{
    //choice and pause variables
    string pickOne;
    string stop;
    
    
    while(pickOne != "1" && pickOne != "2") 
    {
        cout << "1: Physical Attacks" << endl;
        cout << "2: Mental Attacks" << endl;
        getline(cin, pickOne);
        if(pickOne.length() > 0)
        {
            switch(stoi(pickOne))
                {
                    case 1:
                        // call fight();
                        break;
                    case 2:
                        // call mind(checkR);
                        break;
                    default:
                        cout << "The Psychopath can't channel his chaotic thoughts into action, he tries again..." << endl;
                        getline(cin, stop);
                }
        }
    }
    //returns the choice which will then call the next appropriate function
    return stoi(pickOne);
}

//provides menu options for physical attacks
int Fight::fight()
{
    //choice and pause variables
    string pickFight;
    string fightStop;
    
    while(pickFight != "1" && pickFight != "2")
    {
        cout << "1: Rock Swing" << endl;
        cout << "2: Scissors Stab" << endl;
        getline(cin, pickFight);
        if(pickFight.length() > 0)
        {
            switch(stoi(pickFight))
            {
                case 1:
                    cout << "The Psychopath swings at the enemy with his rock!" << endl;
                    break;
                case 2:
                    cout << "The Psychopath stabs at the enemy with his scissors!" << endl;
                    break;
                default:
                    cout << "The Psychopath can't channel his chaotic thoughts into action, he tries again..." << endl;
            }
        }
    }
    //returns attack choice
    return stoi(pickFight);
}

//provides mental attack options
int Fight::mind(int rageS)
{
    //choice variable
    string pickMind;
    
    
    if(rageS == 0)
    {
        //mental attack has yet to be used
        while(pickMind != "1" && pickMind != "2" && pickMind != "3")//added last condition and matching if statement to handle an enpty user input
        {
            getline(cin, pickMind);
            if(pickMind.length() > 0)
            {
                switch(stoi(pickMind))
                {
                    case 1:
                        return 1;
                        break;
                    case 2:
                        return 2;
                        break;
                    case 3:
                        return 3;
                        break;
                    default:
                        cout << "The Psychopath can't properly formulate words into a sentence, he tries again..." << endl;
                }
            }
        }
    }
    else
    {
        return 0;
    }
}

//automatically runs hit checks based on given accuracy
bool Fight::hitCheck(double enHit)
{

    double eCheck = (double) rand() / RAND_MAX;
    
    
    return(eCheck <= enHit);
}


