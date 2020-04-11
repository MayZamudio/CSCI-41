#pragma once
#include "card.h"
#include "deck.h"
#include <vector>
using namespace std;
class Hand {
	public:
		Hand(); // ~ Default constructor
		vector<Card> get_hand() {return player_hand;} // ~ Return a vector of cards in hand
		void add_card(Card temp) {player_hand.push_back(temp);} // ~ Functions like push_back for the hand
		int total(); // ~ Total value of cards in hand
		bool busted(); // ~ Returns true or false based if total is over 21
	private:
		vector<Card> player_hand;
		int hand_total = 0;
};
