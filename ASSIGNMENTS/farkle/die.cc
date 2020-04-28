#include "die.h"
#include "/public/colors.h"
#include <cassert>
using namespace std;

Die::Die() : SIDES(6), last_roll(0) {
	for (unsigned int i = 0; i < SIDES; i++)
		weight.push_back(1.0/SIDES);
}

Die::Die(vector<double> new_weights, const int new_sides) : SIDES(new_sides), last_roll(0) {
	assert(new_sides >= 4);
	assert(new_weights.size() == SIDES);
	double sum = 0;
	for (unsigned int i = 0; i < SIDES; i++) {
		assert(new_weights[i] >= 0 && new_weights[i] <= 1);
		sum += new_weights[i];
		weight.push_back(new_weights[i]);
	}
	assert(sum > .99 && sum < 1.01);
}

int Die::get_roll() {
	assert(last_roll >= 1 && last_roll <= SIDES);
	return last_roll;
}

void Die::roll() {
	
	vector<int> roll;
	int count = 0;
	for (size_t i = 0; i < SIDES; i++) {
		int count = weight.at(i) * 10;
		while (count > 0) {
			roll.push_back(i+1);
			count--;
		}
	}
	//TODO: Implement weight system 
	// 1 (40%), 2 (10%), 3 (10%), 4 (10%), 5 (20%),  6 (10%)
	int selection = rand() % roll.size();
	last_roll = rand() % SIDES + 1;
}

void Die::setDie(Die d) {
	int x = 0;
		cin >> x;
		if (x == 1) Die d();
		if (x == 2) Die d({ 0.4689, 0.0452, 0.0508, 0.0678, 0.1017, 0.2655 }, 6);
		if (x == 3) Die d({ 0.4444, 0.1111, 0.1111, 0.1111, 0.1111, 0.1111 }, 6);
		if (x == 4) Die d({ 0.2933, 0.08, 0.2133, 0.0667, 0.2933, 0.0533 }, 6);
		if (x == 5) Die d({ 0.10, 0.12, 0.26, 0.12, 0.32, 0.08 }, 6);
		if (x == 6) Die d({ 0.36, 0.16, 0.14, 0.08, 0.10, 0.16 }, 6);
}

void Die::displayDieChoices() {
	cout << " 1.) Normal\n";
	cout << " 2.) Alfonse's Die\n";
	cout << " 3.) Biased Die\n";
	cout << " 4.) Odd Die\n";
	cout << " 5.) Die of Misfortune\n";
	cout << " 6.) The Commonest Die\n";
	cout << "\n ☛ ";
}
