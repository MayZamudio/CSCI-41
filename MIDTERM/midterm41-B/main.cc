#include <iostream>
#include <sstream>
#include "Bridges.h"
#include "SLelement.h"
#include "card.h"
#include "deck.h"
using namespace std;
using namespace bridges;

int main(int argc, char **argv) {
	cout << "Welcome to a contrived blackjack thing designed to show you how easy BRIDGES is to use.\n";
	cout << "Pick a random seed:\n";
	int seed = 0;
	cin >> seed;
	if (!cin) exit(1);
	cout << "How many cards do you want to draw and add up?\n";
	int draw = 0;
	cin >> draw;
	if (!cin or draw < 1) exit(1);
	Deck deck;
	deck.shuffle(seed);
	//Make a linked list of the first 10 cards dealt
	SLelement<Card> *head = nullptr;
	for (int i = 0; i < draw; i++) {
		Card c = deck.deal();
		cout << "Drew: " << c << endl;
		ostringstream sts;
		sts << "Draw " << to_string(i) << ": " << c;
		SLelement<Card> *temp = new SLelement<Card>(head, c, sts.str());
		head = temp;
	}
	//Now tally up their point value using Blackjack rules (1s are worth 11, 10-13s are worth 10), don't worry about soft aces here
	int total = 0;
	for (SLelement<Card> *temp = head; temp; temp = temp->getNext()) {
		//cerr << temp->getValue().get_face() << endl;
		int val = temp->getValue().get_face();
		if (val > 10) val = 10;
		if (val == 1) val = 11;
		total += val;
		if (temp->getNext()) temp = head; //This line is suspicious
	}
	cout << "Total value: " << total << endl;

	//Visualize it using BRIDGES
	Bridges *bridges =  new Bridges(40, "YOURNAMEHERE", "YOURIDHERE");
	bridges->setDataStructure(head);
	bridges->visualize();
}
