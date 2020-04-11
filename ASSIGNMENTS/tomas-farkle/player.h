#pragma once
#include <iostream>
#include "die.h"
#include <vector>

using namespace std;

class Player {
	string name;
	int score;
	int moolah;	
	int wager;
	vector<Die> hand;

	public:
	Player();
	void setName(string new_name);
	void setScore(int new_score);
	int getScore();
	std::string getName();
	void setMoolah(int newMoolah);
	int getMoolah();
	void setRoll();	
	vector<Die> getHand();
	void loadHand();
	void setPlayerDice(vector<Die> Dice);
	void add(Die);
};
