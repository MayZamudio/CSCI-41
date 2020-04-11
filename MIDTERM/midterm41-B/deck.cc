#include "deck.h"
#include <algorithm>
using namespace std;

void Deck::shuffle(int seed) {
	if (seed == 0) srand(time(0));
	else srand(seed);
	//Build the deck
	for (int suit = Card::MIN_SUIT; suit <= Card::MAX_SUIT; suit++) 
		for (int face = Card::MIN_FACE; face <= Card::MAX_FACE; face++) 
			deck.emplace_back(suit,face);
	//cout << deck.size() << endl;
	std::random_shuffle(deck.begin(),deck.end(),[](int i) { return std::rand()%i; } );
	/*
	for (Card c : deck) {
		cout << c.get_suit() << " " << c.get_face() << endl;
		cout << c << endl;
	}
	*/
}

//Pulls a card off the top of the deck (use back() and pop_back())
//If the deck is empty, reshuffle then deal a card
Card Deck::deal() {
	if (!deck.size()) shuffle();
	Card temp = deck.back();
	deck.pop_back();
	return temp;
}
