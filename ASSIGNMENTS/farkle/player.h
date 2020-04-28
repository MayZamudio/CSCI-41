#pragma once
#include <string>

using namespace std;

class Player {
private:
    string name;
    int score;
    int money;
    bool inGame;

public:
    Player();
    // New player constructor
	Player(string name);
	//This is how you show the name
    string Name(); 
	//How to add value to score
    void AddScore(int value);
	//This is how to show the score
    int Score();
	//This adds amount to money
    void AddMoney(int amount);
	//Show the shmoney
    int Money();
	//This sets player in game
    void SetInGame();
	//Returns inGame status
    bool InGame();
};
