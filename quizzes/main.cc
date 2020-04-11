#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

//Will return a number from 1 to 13, representing the face of a card
int draw_card() { return rand() % 13 + 1; }


int main() {
	const int BET = 10;
	//This will allow you to control chance, to make testing easier
	cout << "Please choose a random seed, or 0 to use the current time:\n";
	int seed = 0;
	cin >> seed;
	if (seed == 0) srand(time(0));
	else srand(seed);

	cout << "Welcome to Blackjack-40!\n\n";

	//YOU: Create an integer named money and set it to 100

	//YOU: Do this (and all lines below) in an infinite loop...

		cout << "You currently have $" << money << " and are betting $" << BET << endl;

		//YOU: For each player...

			//YOU: Make an integer called total holding the total value of the players card and initialize it to 0
			//YOU: Using a for loop, deal 4 cards to the player
			int card = draw_card(); //This is how you deal a card
			//YOU: Handle face cards. I.e., if the card is >= 10 set the card to 10

			//YOU: Handle aces (a 1 is worth 11)
			cout << "You drew a " << card << endl;
			
			//YOU: Add the card's value to the total 

			//Then we print the total
			cout << "The total value of your cards is: " << total << endl;

			//YOU: Make an infinite loop for the players drawing cards until they bust or stay or quit
				cout << "Do you wish to 1) Hit or 2) Stay or 3) Quit?\n";

		//YOU: After the players are done, draw cards for the dealer until they get a 35 or higher, or bust
		cout << "Dealer drew a " << card << endl;

		//YOU: Check for loss. If the player has 0 dollars or less, they lose
		cout << "YOU LOSE! GAME OVER!\n";
		//YOU: Check for win. If the player has 200 dollars or more, they win
		cout << "A WINNER IS YOU! GAME OVER!\n";
}
