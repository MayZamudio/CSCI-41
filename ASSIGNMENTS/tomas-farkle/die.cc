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
	srand(rand());
	vector<int> numbers{1,2,3,4,5,6};
	/*	
		double rnd = rand() + 1;
		for(int i=0; i<numbers.size(); i++) {
		if(rnd < weight.at(i))
		last_roll= i+1;
		rnd -= weight.at(i);
		}
		*/	//TODO: Implement weight system
	double rando=(rand() % 100 / 100.0);
	for(unsigned int i=0;i < numbers.size();i++){
		//	std::cout<<"weight at "<<i<< "is: "<<weight.at(i)<< "and rando is: "<<rando<<endl;
		if(rando < weight.at(i)){
			last_roll =numbers.at(i) ;
			break;}
		else
			rando -= weight.at(i);
	}
}
