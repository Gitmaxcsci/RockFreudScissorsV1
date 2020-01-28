#ifndef ENEMIES_H
#define ENEMIES_H
#include <string>
using namespace std;

//holds enemy info, read from a text file
class Enemies
{
    public:
    
    double EGetHitChance();
    
    void ESetHitChance(double newEHit);
    
    int EGetDamage();
    
    void ESetDamage(int newEDamage);
    
    int EGetHealth();
    
    void ESetHealth(int newEHealth);
    
    int getRage();
    
    void setRage(int RageSet);
    
    void getIntro(); 
    
    int getAnnoying();
    
    int getEnraging();
    
    int getDepressing();
    
    void getMind();
    
    void getMindRage(int ragePick);
    
    void getAttacks();
    
    void getEnd(int outcome);
    
    //Made specifically for initializing enemies array
    
    void setName(string givenName);
    
    void setIntro(string givenIntro);
    
    void setAnnoying(int givenAnnoy);
    
    void setEnraging(int givenEnrage);
    
    void setDepressing(int givenDepress);
    
    void setMind(string mind1, string mind2, string mind3);
    
    void setMindRage(string mR1, string mR2, string mR3);
    
    void setAttack(string givenAttack);
    
    void setFightEnds(string defeat, string victory);
    
    private:
    
    double eHit;
    
    int eDamage;
    
    int eHealth;

    //tracks the enemy state of rage in the fight
    //0: normal state, no variation in stats
    //1: annoyed state, 10% less accurate, 10% more damage
    //2: enraged state, 10% less accurate, 20% more damage
    //3: depressed state, 30% less accurate, 30% less damage
    int Rage = 0;
    
    //each enemy has specific backstories and traits that are manifested as psychological weaknesses in the fighting mechanics
    string name;
    string intro; 
    int annoying;
    int enraging;
    int depressing;
    string mind[4];
    string mindRage[4];
    string attacks;
    string fightEnd[2];
    
};



#endif


