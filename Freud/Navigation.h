#ifndef NAVIGATION_H
#define NAVIGATION_H
#include <string>
using namespace std;

//handles the motion through spaces in the game by the player's turn
class Navigation
{
    public:
    
    Navigation();
    
    bool Search();
    
    int Move();
    
    double GetSearchChance();
    
    void SetSearchChance(int SSC);
    
    int GetLocID();
    
    void SetLocID(int LID);
    
    void addLocID();
    
    int GetTurnID();
    
    int SetTurnID(int TID);
    
    int getTurnNum();
    
    int addTurnNum();
    
    private:
    
    //current location 
    int LocID = 0;
    
    //tracks whether it is still the player's turn
    int TurnId = 0;
    
    //tracks the number of turns that has passed; maybe use for periodic enemy attacks
    int turnNum = 0;
    
    //tracks the positive search chance value
    double SearchChance = 0.7;
    
    //tracks whether the player has already searched on a given turn
    int Searched;
    
};


#endif

