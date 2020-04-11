#pragma once
#include <string>
using namespace std;
class Card { // ~ Example Card: Ace of Hearts
  public:
    Card(string set_suit, string set_face, int value); // ~ Default constructor
	string get_face() {
        return face; // ~ Returns the face of the card (Ace)
    }
	string get_suit() {
        return suit; // ~ Returns the suit of the card (Hearts)
    }
	int get_value() {
		return value; // ~ Returns the value of the card (1)
	}
  private:
	string suit;
	string face;
	int value;
};
