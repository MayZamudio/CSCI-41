#include "player.h"
#include <iostream>

using namespace std;

Player::Player (){
	name="";
	score=0;
	moolah=0;
	vector<Die> hand{6};
}
void Player:: setName(string new_name){
	for(size_t i=0;i < new_name.size();i++)
		new_name.at(i)=toupper(new_name.at(i));
		name=new_name;
}
void Player:: setScore(int new_score){
	score=score+ new_score;
}
string Player::getName(){return name;}
int Player::getScore(){return score;}
void Player::setMoolah(int newMoolah){
	moolah=newMoolah;
}
int Player::getMoolah(){return moolah;}


void Player::setRoll (){

	for (Die &d: hand){
		d.roll();
			cout<<d.get_roll()<<endl;}
}

vector<Die> Player:: getHand() {return hand;}


void Player::loadHand(){
	for(int i=0; i < 6;i++){
		Die curr;
	hand.push_back(curr);}
}

//void Player::getRoll(){}

void Player:: setPlayerDice(vector<Die> Dice){
        for(size_t i=0; i< Dice.size();i++)
            hand.push_back(Dice.at(i));}

void Player::add(Die d){
	hand.push_back(d);
}
