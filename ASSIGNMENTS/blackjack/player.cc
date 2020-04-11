#include "player.h"
#include <iostream>
using namespace std;
//Implementation 
Player::Player(){
	name = "";
	money = 100;
}
Player::Player(int x, string s){//assigns values
	money = x;
	name = s;
}
void Player:: set_name(string s){
	name = s;
}
void Player:: set_money(int x){
	money = x;
}
void Player:: set_hand(Card temp){
	h.add_card(temp);
}
std::string Player:: get_name(){
	return name;
}
int Player::get_money() {
	return money;
}
