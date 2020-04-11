#include "card.h"
#include "deck.h"
#include "hand.h"
#include <iostream>

Hand::Hand() {
	hand_total = 0;
}

int Hand::total() {
	int temp = 0;
	for (Card possessed_card : player_hand) {
		temp += possessed_card.get_value(); // ~ Finding the total value of all the cards in hand
	}
	hand_total = temp;
	return temp;
}

bool Hand::busted() {
	return (hand_total > 21 ? true : false); // ~ If hand_total > 21 return true, otherwise false
}
