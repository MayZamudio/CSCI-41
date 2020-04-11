#pragma once
#include "hand.h"
#include "card.h"
#include <iostream>

class Player {
	public://default constructor and functions
		//declaration of variables
		Player();
		Player(int x, std::string s);
		void set_name(std::string s);
		void set_money(int x);
		void set_hand(Card temp);
		std::string get_name();
		int get_money();

	private://things you don't want seen
		string name;
		int money;
		Hand h;
};
