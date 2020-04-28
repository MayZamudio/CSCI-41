#include "table.h"
#include <iostream>
#include "/public/colors.h"

using namespace std;

Table::Table(){
	vector<Die> sixFair{};
	vector<Die> sixWeighted{};
	currScore = 0;
	wagerUp = 0;
	Player tableOne {};
	Player tableTwo {};

}

Table::Table( Player one, Player two){
	Player tableOne = one;
	Player tableTwo = two;
}


void Table::setScore(int newScore){
	//IF FARKLE(USING -5 TO REPRESENT FARKLE) RESET TO 0 , OTHERWISE ADD TO PREVIOUS
	if(newScore == -5) currScore = 0;
	else
		currScore= currScore + newScore;
}

int Table:: getScore() {return currScore;}

void Table:: setWagerUp (int newWager) {
	wagerUp = newWager;
}

int Table::getWagerUp() {return wagerUp;}

vector<Die> Table::getTableHand() {return sixFair;}
vector<Die> Table::getCheater() {return sixWeighted;}

void Table:: setTableDice(vector<Die> Dice){
	for(size_t i = 0; i < Dice.size(); i++)
		sixFair.push_back(Dice.at(i));

}
void Table::loadTableHand(int howManyDice){
	for(int i = 0; i < howManyDice; i++){
		Die curr;
		sixFair.push_back(curr);
	}

}
void Table::loadCheater(int howManyDice){
	for(int i = 0; i < howManyDice; i++){
		Die curr;
		sixWeighted.push_back(curr);
	}

}
void Table::setRoll (){
	int count = 0;
	for (Die &d: sixFair){
		d.roll();
		cout << "  Dice "<< count <<":  [" << d.get_roll() << "] " << endl;
		count++;
	}
}


void Table::clear() {
	sixFair.clear();
}

void Table::update(int diceUsed) {
	for(int i = 0; i < diceUsed; i++) {
		Die curr;
		sixFair.push_back(curr);
	}
}
