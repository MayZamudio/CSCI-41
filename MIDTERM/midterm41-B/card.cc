#include <iostream>
#include <cassert>
#include "card.h"
using namespace std;

Card::Card(int new_suit, int new_face) {
	assert(new_suit >= MIN_SUIT and new_suit <= MAX_SUIT);
	assert(new_face >= MIN_FACE and new_face <= MAX_FACE);
	suit = new_suit;
	face = new_face;
}
int Card::get_suit() { return suit; }
int Card::get_face() { return face; }

//If you do a "cout << card;" it will call this function
std::ostream& operator<< (std::ostream &outs, Card c) {
	//Since this code has to hardcode in the translations, we check to make sure the class hasn't changed
	static_assert(Card::MIN_FACE == 1 and Card::MAX_FACE == 13);
	static_assert(Card::MIN_SUIT == 0 and Card::MAX_SUIT == 3);
	std::string s,f;
	int face = c.get_face();
	assert(face >= Card::MIN_FACE and face <= Card::MAX_FACE);
	if (face == 1) f = "Ace of ";
	else if (face == 2) f = "Two of ";
	else if (face == 3) f = "Three of ";
	else if (face == 4) f = "Four of ";
	else if (face == 5) f = "Five of ";
	else if (face == 6) f = "Six of ";
	else if (face == 7) f = "Seven of ";
	else if (face == 8) f = "Eight of ";
	else if (face == 9) f = "Nine of ";
	else if (face == 10) f = "Ten of ";
	else if (face == 11) f = "Jack of ";
	else if (face == 12) f = "Queen of ";
	else if (face == 13) f = "King of ";
	int suit = c.get_suit();
	assert(suit >= Card::MIN_SUIT and suit <= Card::MAX_SUIT);
	if (suit == 0) s = "Clubs";
	else if (suit == 1) s = "Diamonds";
	else if (suit == 2) s = "Hearts";
	else if (suit == 3) s = "Spades";
	outs << f + s;
	return outs;
}
