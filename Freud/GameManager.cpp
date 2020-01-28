#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "GameManager.h"
#include "Stats.h"
#include "Navigation.h"
#include "Fight.h"
#include "Enemies.h"
using namespace std;




//constructor that sets the necessary data members to 0
GameManager::GameManager()
{
    StateID = 0; //tracks players turn
    EnemyID = 0; //counts through enemies as they are encountered by the player
    
}

//split function used for splitting lines from enemy text file
int split (string str, char c, string array[], int size)
{
    if (str.length() == 0) {
         return 0;
     }
    string word = "";
    int count = 0;
    str = str + c;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            if (word.length() == 0)
                continue;
            array[count++] = word;
            word = "";
        } 
        else 
        {
            word = word + str[i];
        }
        
    }
    
    return count;
}

void GameManager::PlayerTurn()
{
    ifstream myFile;
    myFile.open("Enemies.txt");
    
    string line = "";
    string tempArr[102];
    int track = 0;
    
    if(myFile.is_open())
    {
        while(getline(myFile,line))
        {
            //reads all enemy data from text document and initializes enemy object array
            split(line, '|', tempArr, 102);
            foes[track].setName(tempArr[0]);
            foes[track].ESetHitChance(stod(tempArr[1]));
            foes[track].ESetHealth(stoi(tempArr[2]));
            foes[track].ESetDamage(stoi(tempArr[3]));
            foes[track].setIntro(tempArr[4]);
            foes[track].setAnnoying(stoi(tempArr[5]));
            foes[track].setEnraging(stoi(tempArr[6]));
            foes[track].setDepressing(stoi(tempArr[7]));
            foes[track].setMind(tempArr[8], tempArr[9], tempArr[10]);
            foes[track].setMindRage(tempArr[11], tempArr[12], tempArr[13]);
            foes[track].setAttack(tempArr[14]);
            foes[track].setFightEnds(tempArr[15], tempArr[16]);
            track++;
        }
    }
    
    
    
    //variables for player turn choice and natural dialogue pauses
    string choice1;
    string pause1;
    
    //runs game while the player is still alive and they have not reached the final space
    while(nav.GetLocID() < 31 && stat.PGetHealth() > 0)
    {
        //condition for positions in game where player encounters an enemy
        if(nav.GetLocID() == 1 || nav.GetLocID() == 4 || nav.GetLocID() == 9 || nav.GetLocID() == 15 || nav.GetLocID() == 23 || nav.GetLocID() == 30)
        {
            //instigates fight fight
            fighting();
            //prepares for next enemy encounter
            if(stat.PGetHealth() > 0)
            {
                foes[EnemyID].getEnd(0);
                EnemyID++;
            }
            else
            {
                //plays out defeat by specific enemy
                foes[EnemyID].getEnd(1);
            }
        }
        choice1 = "";
        if(stat.PGetHealth() > 0) //checks if the player is still alive as they could have died in a fight
        {
            cout << "The Wandering Madman is " << nav.GetLocID() << " days from the institution" << endl;
            cout << "He wonders at his health through the fog of his mind (" << stat.PGetHealth() << " health)" << endl;
            cout << "He dwells deeply on the prospect of violence (Rock: " << stat.GetRockH() << " accuracy / " << stat.GetRock() << " damage | Scissors: " << stat.GetScissorsH() << " accuracy / " << stat.GetScissors() << " damage)" << endl;
            cout << "The possibility of freedom grows ever closer (" << nav.GetLocID() << " days from a cell / " << (30 - nav.GetLocID()) << " days until sanctuary)" << endl;
            cout << "[PRESS ENTER TO CONTINUE]" << endl;
            //user pause here
            getline(cin, pause1);
            cout << "The Wandering Madman asks himself whether he should look around or move on..." << endl;
            cout << "1:Search Nearby" << endl;
            cout << "2:Move forward" << endl;
            
            while(choice1 != "1" && choice1 != "2")
            {
                getline(cin, choice1);
                if(choice1.length() > 0)
                {
                    switch(stoi(choice1))
                    {
                        case 1: //search result, positive or negative, depends on the players position in the game
                            cout << "He sets his mind to searching nearby for anything that can help him in his journey..." << endl;
                            
                            //successful search 
                            if(nav.Search() == true)
                            {
                                
                                if(((nav.GetLocID() + 2) % 3) == 0)
                                {
                                    //Accuracy Boost
                                    if(((nav.GetLocID() + 2) % 2) == 0)
                                    {
                                        double NewRA;
                                        if((stat.GetRockH() + 0.05) >= 1)
                                        {
                                            NewRA = 1.00;
                                        }
                                        else
                                        {
                                            NewRA = (stat.GetRockH() + 0.05);
                                        }
                                        
                                        stat.SetRockH(NewRA);
                                        cout << "The Maniac sees two hobos fighting, he learns from their form (+5% rock accuracy / Rock Hit Chance: " << stat.GetRockH() << ")" << endl; 
                                    }
                                    else
                                    {
                                        double NewSA;
                                        if((stat.GetScissorsH() + 0.05) >= 1)
                                        {
                                            NewSA = 1.00;
                                        }
                                        else
                                        {
                                            NewSA = (stat.GetScissorsH() + 0.05);
                                        }
                                        stat.SetScissorsH(NewSA);
                                        
                                        cout << "The Maniac finds what are probably carrots, after eating them he feels his sight is better (+5% scissors accuracy / Scissors Hit Chance " << stat.GetScissorsH() << ")" << endl; 
                                    }
                                }
                                else if(((nav.GetLocID() + 1) % 3) == 0) 
                                {
                                //Damage Boost
                                    if(((nav.GetLocID() + 1) % 2) == 0)
                                    {
                                        int NewR = (stat.GetRock() + 3);
                                        stat.SetRock(NewR);
                                        cout << "The Maniac finds a self help book, he feels stronger and more self-assured (+3 rock damage / Rock Damage: " << stat.GetRock() << ")" << endl;
                                    }
                                    else
                                    {
                                        int NewS = (stat.GetScissors() + 3);
                                        stat.SetScissors(NewS);
                                        cout << "The Maniac sees something shiny, it's new sharper scissors! (+3 scissors damage / Scissors Damage: " << stat.GetScissors() << ")" << endl;
                                    }
                               
                                    
                                }
                                else
                                {
                                    //Health Boost
                                    int NewH = (stat.PGetHealth() + 5);
                                    stat.PSetHealth(NewH);
                                    cout << "The Maniac finds an assortment of pills, after swallowing them all indiscriminantly he feels a little better (+5 health / Health: " << stat.PGetHealth() << ")" << endl;
                                }
                            }
                            //unsuccessful search
                            else
                            {
                                
                                if(((nav.GetLocID() + 2) % 3) == 0)
                                {
                                    //Accuracy loss
                                    if(((nav.GetLocID() + 2) % 2) == 0)
                                    {
                                        double badNewRA;
                                        if((stat.GetRockH() - 0.05) <= 0.05)
                                        {
                                            badNewRA = 0.05;
                                        }
                                        else
                                        {
                                            badNewRA = (stat.GetRockH() - 0.05);
                                        }
                                        
                                        stat.SetRockH(badNewRA);
                                        cout << "The Maniac finds a smaller rock, he likes this one more (-5% rock accuracy / Rock Hit Chance: " << stat.GetRockH() << ")" << endl; 
                                    }
                                    else
                                    {
                                        double badNewSA;
                                        if((stat.GetScissorsH() - 0.05) <= 0.05)
                                        {
                                            badNewSA = 0.05;
                                        }
                                        else
                                        {
                                            badNewSA = (stat.GetScissorsH() - 0.05);
                                        }
                                        stat.SetScissorsH(badNewSA);
                                        cout << "The Maniac finds a broken pair of glasses, he thinks these will help him see better (-5% scissors accuracy / Scissors Hit Chance " << stat.GetScissorsH() << ")" << endl; 
                                    }
                                }
                                else if(((nav.GetLocID() + 1) % 3) == 0) 
                                {
                                //Damage loss
                                    if(((nav.GetLocID() + 1) % 2) == 0)
                                    {
                                        int badNewR;
                                        if((stat.GetRock() - 3) <= 1)
                                        {
                                            badNewR = 1;
                                        }
                                        else
                                        {
                                            badNewR = (stat.GetRock() - 3);
                                        }
                                        stat.SetRock(badNewR);
                                        cout << "The Maniac finds a toy that reminds him of his childhood, he feels sick (-3 rock damage / Rock Damage: " << stat.GetRock() << ")" << endl;
                                    }
                                    else
                                    {
                                        int badNewS;
                                        if((stat.GetScissors() - 3) <= 1)
                                        {
                                            badNewS = 1;
                                        }
                                        else
                                        {
                                            badNewS = (stat.GetScissors() - 3);
                                        }
                                        stat.SetScissors(badNewS);
                                        cout << "The Maniac's schizophrenia acts up, he stabs wildly and blunts the scissors against the wall (-3 scissors damage / Scissors Damage: " << stat.GetScissors() << ")" << endl;
                                    }
                               
                                    
                                }
                                else
                                {
                                    //Health Loss
                                    int badNewH;
                                    if((stat.PGetHealth() - 5) <= 1)
                                    {
                                        badNewH = 1;
                                    }
                                    else
                                    {
                                        badNewH = (stat.PGetHealth() - 5);
                                    }
                                    stat.PSetHealth(badNewH);
                                    cout << "The Maniac finds an assortment of pills, after swallowing them all indiscriminantly he feels a little worse (-5 health / Health: " << stat.PGetHealth() << ")" << endl;
                                }
                            }
                            cout << "The Madman has found everything he can here, he will move on..." << endl;
                            nav.Move();
                            break;
                        case 2:
                            cout << "\"I should keep moving forward\" the madman mutters to himself" << endl;
                            nav.Move();
                            //*****************could include if statement for certain locations to say new areas have been reached
                            break;
                        default:
                            cout << "The Madman's thoughts are unintelligible gibberish, he needs better direction and tries again" << endl;
                    }
                }
            }
        }
        else
        {
            StateID = 2;
        }
    }
    //endgame check
    if(StateID == 2)
    {
        //loss condition
        cout << "It seems you've lost, enter your name to record how far you got:" << endl;
    }
    else
    {
        //win condition
        cout << "Congratulations on the daring escape from the Institution and your own mind, enter your name to save your success:" << endl;
    }
    //writes to file to save progress
    string nameSave;
    while(nameSave.length() == 0)
    {
        getline(cin, nameSave);
        if(nameSave.length() > 0)
        {
            ofstream myFileWrite;
            myFileWrite.open(nameSave);
            if(myFileWrite.is_open())
            {
                myFileWrite << "Name: " << nameSave << endl;
                myFileWrite << "Enemies Faced: " << EnemyID << endl;
                myFileWrite << "Final Health: " << stat.PGetHealth() << endl;
                myFileWrite << "Final Rock Accuracy / Damage: " << stat.GetRockH() << " / " << stat.GetRock() << endl;
                myFileWrite << "Final Scissors Accuracy / Damage: " << stat.GetScissorsH() << " / " << stat.GetScissors() << endl;
            }
            else
            {
                cout << "File Write Error" << endl;
            }
        }
    }
    
}


//runs in game fight mechanic through call to fight class
void GameManager::fighting()
{
    //used for user pauses
    string p1;
    
    
    cout << "The Psychopath has encountered an enemy. The voices urge him to fight." << endl;
    //gets name and opening lind
    foes[EnemyID].getIntro();
    //continuously runs while both are alive
    while(stat.PGetHealth() > 0 && foes[EnemyID].EGetHealth() > 0)
    {
        //offers player turn and the enemy turn
        while(StateID == 0) //keep track of turns with state ID; increment when player picks an attack option
        {
            //fight function menu options (larger fight/mental that leads to sub options) with switches in sub option functions that return the players input as an int which is then used in this function
            cout << "Psycho Health: " << stat.PGetHealth() << endl;
            cout << "Rock Damage: " << stat.GetRock() << "   Rock Accuracy: " << stat.GetRockH() << endl;
            cout << "Scissors Damage: " << stat.GetScissors() << "   Scissors Accuracy: " << stat.GetScissorsH() << endl;
            cout << "Enemy Health: " << foes[EnemyID].EGetHealth() << endl;
            cout << "Enemy Accuracy: " << foes[EnemyID].EGetHitChance() << endl;
            
            //physical attack choice
            if(fights.fightOrMind(foes[EnemyID].getRage()) == 1)
            {
                int attackHit = 0;
                if(fights.fight() == 1)
                {
                    //attack with rock (call hit check function and if it hits, subtract rock damage from enemy health)
                    if(fights.hitCheck(stat.GetRockH()) == true)
                    {
                        cout << "The rock cracks against the enemy's skull (-" << stat.GetRock() << " health)" << endl;
                        attackHit = (foes[EnemyID].EGetHealth() - stat.GetRock());
                        foes[EnemyID].ESetHealth(attackHit);
                    }
                    else
                    {
                        cout << "The rock hits empty air as the Psycho misses, the enemy moves to attack" << endl;
                    }
                    StateID++;
                }
                else
                {
                    //attack with scissors
                    if(fights.hitCheck(stat.GetScissorsH()) == true)
                    {
                        cout << "The scissors sink into the enemy drawing blood (-" << stat.GetScissors() << " health)" << endl;
                        attackHit = (foes[EnemyID].EGetHealth() - stat.GetScissors());
                        foes[EnemyID].ESetHealth(attackHit);
                    }
                    else
                    {
                        cout << "The scissors find nothing but air as the Psycho swings too wide, the enemy starts to retaliate" << endl;
                    }
                    StateID++;
                }
            }
            //mental attack option
            else
            {
                foes[EnemyID].getMind();
                int mindHold = fights.mind(foes[EnemyID].getRage());
                foes[EnemyID].getMindRage(mindHold);
                switch(mindHold)
                {
                    case 0: //doesn't let player perform more than one mental attack
                        cout << "The enemy is no longer responsive to mind attacks" << endl;
                        break;
                    case 1:
                        //check whether it was annoying, enraging, or depressing
                        //print the rage response
                        if(foes[EnemyID].getAnnoying() == 1)
                        {
                            foes[EnemyID].setRage(1);
                            
                        }
                        else if(foes[EnemyID].getEnraging() == 1)
                        {
                            foes[EnemyID].setRage(2);
                            
                        }
                        else
                        {
                            foes[EnemyID].setRage(3);
                            
                        }
                        
                        StateID++;
                        break;
                    case 2:
                        //same as 1
                        //same as 1
                        if(foes[EnemyID].getAnnoying() == 2)
                        {
                            foes[EnemyID].setRage(1);
                        }
                        else if(foes[EnemyID].getEnraging() == 2)
                        {
                            foes[EnemyID].setRage(2);
                        }
                        else
                        {
                            foes[EnemyID].setRage(3);
                        }
                        StateID++;
                        break;
                    case 3:
                        //same as 1
                        //same as 1
                        if(foes[EnemyID].getAnnoying() == 3)
                        {
                            foes[EnemyID].setRage(1);
                        }
                        else if(foes[EnemyID].getEnraging() == 3)
                        {
                            foes[EnemyID].setRage(2);
                        }
                        else
                        {
                            foes[EnemyID].setRage(3);
                        }
                        
                        StateID++;
                        break;
                    default:
                        cout << "something has gone terribly wrong my dear coder. . . ." << endl;
                }
            }
        }
        
        //resets the state id for the next turn
        StateID = 0;
        
        //user pause
        getline(cin, p1);
        
        //checks if the enemy was killed during the player turn before instigating the enemy turn
        if(foes[EnemyID].EGetHealth() > 0)
        {
            //plays out the type of enemy attack no matter what
            foes[EnemyID].getAttacks();
            
            //action for if the attack lands
            if(fights.hitCheck(foes[EnemyID].EGetHitChance()) == true)
            {
                cout << "The Psychopath feels pain as the attack connects (-" << foes[EnemyID].EGetDamage() << " damage)" << endl;
                int hurt = (stat.PGetHealth() - foes[EnemyID].EGetDamage());
                stat.PSetHealth(hurt);
            }
            //action for if the attack misses
            else
            {
                cout << "The attack misses, the Psychopath prepares to retaliate." << endl;
            }
        }
        //user pause
        getline(cin, p1);
    }
    
}

//returns the state that the game is currently in
int GameManager::GetStateID()
{
    return StateID;
}

//changes to a different game state
void GameManager::SetStateID(int SID)
{
    StateID = SID;
}

//returns the number of enemies that has been encountered
//each number is a different enemy with a different background
int GameManager::GetEnemyID()
{
    return EnemyID;
}

//changes to the next enemy
void GameManager::SetEnemyID(int EID)
{
    EnemyID = EID;
}
