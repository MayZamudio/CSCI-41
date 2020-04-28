#pragma once
#include "table.h"
#include <vector>
#include <cassert>
#include <cstdlib>

using namespace std;

class Die {

	const unsigned int SIDES;
	vector<double> weight;
	unsigned int last_roll;
	public:
	Die(); //Create a fair die
	Die(vector<double> new_weights, int new_sides); //Create a cheater die
	int get_roll(); //Return the last value rolled
	void roll(); //Set the die to a random value
	void setDie(Die d);
	void displayDieChoices();
};
