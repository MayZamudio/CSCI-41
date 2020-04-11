#pragma once
#include <vector>
#include <cassert>
#include "card.h"

class Deck {
	std::vector<Card> deck;
	public:
		//Sets the random number generator's seed to the value passed in, or the current time if 0
		//This resets the deck of 52 cards back to a pristine state
		void shuffle(int seed = 0);
		//Pulls a card off the top of the deck (use back() and pop_back())
		//If the deck is empty, reshuffle then deal a card
		Card deal();
};
