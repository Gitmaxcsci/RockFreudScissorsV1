#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <random>
#include <ctime>
#include <string>
#include "GameManager.h"
using namespace std;







int main()
{
    GameManager game; //relies only on this class for running the game
    
    //used for random chance checks in the game
    srand(time(NULL));
    
    //game start screen with user pauses
    string pause;
    cout << "Rock, Freud Scissors \n" << endl;
    cout << "Welcome, press enter to start the game" << endl;
    getline(cin, pause);
    cout << "A deranged lunatic, a disturbed criminal, the MANIAC, has escaped from the mental institution where he is kept.";
    getline(cin, pause);
    cout << "\n";
    cout << "Through the haze of his own insanity he managed to find a way out, and arm himself with some shiny scissors, a rock he liked, and a Freudian textbook he found in an office.";
    getline(cin, pause);
    cout << "\n";
    cout << "Though his thoughts aren't clear, he has faint memories of a friend, someone who can help him escape, his only hope for freedom.";
    getline(cin, pause);
    cout << "He is 30 days from freedom." << endl;
    
    //instigates player turn that continuously runs until an end game condition has been reached
    game.PlayerTurn(); 
}










