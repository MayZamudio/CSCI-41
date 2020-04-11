#include <iostream>
#include <vector>
#include <algorithm>
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
using namespace std;

void die() { // I claim copyright on this function lmao
	cout << "Invalid Input!\n";
	exit(1);
}

int main() {
	//srand(time(0));
	int number_of_players = 0, seed = 0;
	vector<Hand> players; // Rename to player maybe or some other name
	vector<pair<Player, Hand>> players_party;
	system("toilet -f smblock Welcome to BlackJack --filter border:metal");
	//cout << "Welcome to blackjack debug!\n";
	Deck deck;
	deck.Shuffle(); // ~ Shuffle the deck (Refills it as well)
	Hand dealer;
	int seed_choice; 
	cout << "\n Would you like to use your own seed?\n";
	cout << "\n 1.) Yes \n";
	cout << "\n 2.) No \n";
	cin >> seed_choice;
	if (seed_choice == 1){
	cout << "\n Please enter the seed:\n";
	cin >> seed;
	srand(seed); // ~ Setting the seed although I'm not sure if this is really random
	} else srand(time(0));
	
	cout << "\n Enter the number of players at \"The Table\" (Excluding the Dealer):\n";
	cin >> number_of_players;
	if (!cin || number_of_players < 1 || number_of_players > 6) die(); // ~ Will fix this later by replacing with assert
	for (int i = 0; i < number_of_players; i++) players.emplace_back(); // ~ Creating number of players based on input
	cout << "Generated " << players.size() << " players.\n";
	//Adding Names, Money, and Round
	for (int i = 0; i < number_of_players; i++) {
	cout << "Name of player #" << i + 1 << ": ";
	cin >> players_party.at(0).get_name;
}
	number_of_players++; // To deal cards to the dealer as well
	for (int i = 0; i < number_of_players; i++) { // ~ Drawing two cards to all players + dealer
		for (int j = 0; j < 2; j++) {
			if (!i) dealer.add_card(deck.Deal()); // ~ How to add a card to someone's hand
			else players.at(i - 1).add_card(deck.Deal());
		}
	}
	cout << "Dealer Total: " << dealer.total() << endl; // ~ Check dealer's total
	for (int i = 0; i < number_of_players - 1; i++) cout << "Player " << i + 1 << "'s Total: " << players.at(i).total() << endl; // ~ Check a player's total
	while (!players.at(0).busted()) { // ~ How to check if a player has busted
		players.at(0).add_card(deck.Deal());
		cout << "Player 1's Total: " << players.at(0).total() << endl;
	}
	cout << "Busted\n";
}
