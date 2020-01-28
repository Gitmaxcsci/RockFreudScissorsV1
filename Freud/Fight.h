#ifndef FIGHT_H
#define FIGHT_H
#include <string>
#include "Stats.h"
using namespace std;

//handles the turn based fight mechanic of the game
class Fight
{
    public:
    
    int fightOrMind(int checkR);
    
    int fight();
    
    int mind(int rageS);
    
    bool hitCheck(double enHit);
    
    
    private:
    

};



#endif

