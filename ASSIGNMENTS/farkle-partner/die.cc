#include "die.h"
#include <cassert>
#include <time.h>
#include <iostream>
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
	int count = 0;
	vector<int> numbers;

	for (size_t i = 0; i < SIDES; i++) {
		int count = weight.at(i) * 10;
		while (count > 0) {
			numbers.push_back(i+1);
			count--;
		}
	} int selection = rand() % numbers.size();
	last_roll = numbers.at(selection);
}

void Die::setDie(Die d) {
	int x = 0;
	cin >> x;
	if (x == 1) Die d({ 0.4689, 0.0452, 0.0508, 0.0678, 0.1017, 0.2655 }, 6);
	if (x == 2) Die d({ 0.4444, 0.1111, 0.1111, 0.1111, 0.1111, 0.1111 }, 6);
	if (x == 3) Die d({ 0.2933, 0.08, 0.2133, 0.0667, 0.2933, 0.0533 }, 6);
}

void Die::displayDie() {
	cout << " 1.) Alfonse's Die\n";
	cout << " 2.) Biased Die\n";
	cout << " 3.) Odd Die\n";
	cout << "\n ☛ ";
}
/*	
	double rnd = rand() + 1;
for(int i=0; i<numbers.size(); i++) {
  if(rnd < weight.at(i))
    last_roll= i+1;
  rnd -= weight.at(i);
}
*/	//TODO: Implement weight system
/* double rando = (rand() % 100 / 100.0);
for (unsigned int i = 0; i < numbers.size(); i++) {
	//	std::cout<<"weight at "<<i<< "is: "<<weight.at(i)<< "and rando is: "<<rando<<endl;
		if (rando < weight.at(i)) {
			last_roll = numbers.at(i) ;
			break;
		}
		else
			rando -= weight.at(i);
	}
}*/
