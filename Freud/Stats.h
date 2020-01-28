#ifndef STATS_H
#define STATS_H
#include <string>
using namespace std;

//player stats object

class Stats
{
    public:
    
    Stats();
    
    double GetRockH();
    
    void SetRockH(double newRH);
    
    double GetScissorsH();
    
    void SetScissorsH(double newSH);
    
    int GetRock();
    
    void SetRock(int newRock);
    
    int GetScissors();
    
    void SetScissors(int newScissors);
    
    int PGetHealth();
    
    void PSetHealth(int newHealth);
    
    
    
    private:
    
    //attack accuracies
    double RockH;
    
    double ScissorH;
    
    //attack damages
    int RockD;
    
    int ScissorD;
    
    //player health maintained across the whole game
    int pHealth;
    
    
    
};


#endif

