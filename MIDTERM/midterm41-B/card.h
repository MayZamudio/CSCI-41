#pragma once
#include <iostream>
#include <cassert>
//Avoid using using namespace std in a header file

//Simple class. Write a constructor to set the suit and face, and it should never change after that
//Write getters (but no setters)
//Assert that the suit and face are within the legal range (inclusive) defined by the consts.
class Card {
		int suit, face;
	public:
		static const int MIN_SUIT = 0, MAX_SUIT = 3; //0 is clubs, 1 is diamonds, 2 is hearts, 3 is spades
		static const int MIN_FACE = 1, MAX_FACE = 13; //1 is an ace, 2-10 are face cards, 11 is a jack, 12 is a queen, 13 is a king
		Card(int new_suit, int new_face);
		int get_suit();
		int get_face();
		friend std::ostream& operator<< (std::ostream &outs, Card c);
};
