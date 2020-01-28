#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "Stats.h"
#include "Navigation.h"
#include "Fight.h"
#include "Enemies.h"
#include <string>
using namespace std;



//General manager class that runs the different functional parts of the game
//
class GameManager
{
    public:

    GameManager();

    void PlayerTurn();

    void fighting();

    int GetStateID();

    void SetStateID(int SID);

    int GetEnemyID();

    void SetEnemyID(int EID);

    private:

    //tracks game state
    int StateID;
    //tracks order of enemies encountered
    int EnemyID;

    //objects for other classes managed by this one to run the game
    Navigation nav;
    Fight fights;
    Stats stat;

    Enemies foes[7];

};


#endif
