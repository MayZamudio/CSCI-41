#pragma once
#include "card.h"
#include <vector>
#include <utility>
using namespace std;
class Deck {
  public:
    Deck(); // ~ Default constructor
    void Shuffle(); // ~ Shuffle the deck
    Card Deal(); // ~ Deal from the deck
	void Generate(); // ~ Generate the deck
	vector<Card> get_deck() { // ~ Return the deck as a vector of Card class
        return class_deck;
    }
  private:
	vector<Card> class_deck; // ~ The deck
};
