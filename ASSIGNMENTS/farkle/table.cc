#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <array>
//FOR TIMER
#include <unistd.h>
#include "/public/colors.h"
#include "menu.h"
#include "die.h"
#include "table.h"
#include "player.h"

using namespace std;

void Table::ClearInput() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int Table::GetInput() {
	unsigned int sel;
	while (!(cin >> sel)) {
		ClearInput();
		cout << RED << "Invalid selection. Try again: "<< RESET;
	}
	ClearInput();
	return sel;
}

// Welcome screen, at this poinbt we have a vector with 2 players
void Table::PromptNumPlayers() {
	cout << endl;
	cout << endl << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
	cout << endl;
	system("figlet FARKLE | lolcat");
	cout << endl << "===== 🎲  Let the games begin! 🎲  =====" << endl << endl;
	sleep(1);
}

void Table::SetupPlayerNames(vector<Player>& players) {
	cout << "======================================" << endl;
	system("toilet -f future PLAYER NAMES --filter gay");
	cout << "======================================" << endl;

	for (unsigned int i = 0; i < players.size(); i++) {
		string name;
		cout << " Enter name for Player " << (i + 1) << " (no spaces): ";
		cin >> name;
		ClearInput();

		players[i] = Player(name);
	}
    for (unsigned int i = 0; i < players.size(); i++) {
          Die d1;
          Die d2;
          cout << YELLOW << "\n ===== 🎲  Enter the Die # Player " << (i + 1) << " wishes to use?  🎲  =====" << RESET << endl << endl;
          d1.displayDieChoices();
		  if (!cin){
			  cout << RED << "Invalid selection."<< RESET;
			  exit (1);
		  }
		  d1.setDie(d1);
      } 
}
//Ask players what die they want to use
/*void Table::SetupPlayerDie(Die &d1, Die &d2) {
	//Asking players what die they want to use
	cout << "What die does " << playerNames() << " wish to use?" << endl;
	d1.displayDieChoices();
	d1.setDie(d1);
}*/

void Table::WelcomePlayers(vector<Player>& players) {
	string playerNames;
	cout << "==================" << endl;
	system("toilet -f future   START --filter gay");
	cout << "==================" << endl;
	for (unsigned int i = 0; i < players.size(); i++) {
		if (i == players.size() - 1) {
			playerNames += "and " + players[i].Name();
		} else {
			playerNames += players[i].Name() + " ";
		}
	}

	cout << "\n ⊱ Welcome " << playerNames << "! ⊰ " << endl << endl;

	sleep(2);

}

array<int, 6> Table::CountDice(vector<int>& dicePool) {
	array<int, 6> counter = { };
	for (unsigned int i = 0; i < dicePool.size(); i++) {
		counter[dicePool[i] - 1]++;
	}
	return counter;
}

bool Table::CheckFor5k(int score) {
	bool isOver5k = score >= 5000 ? true : false;
	return isOver5k;
}

bool Table::ScoringDice(array<int, 6>& diceCount) {
	if (diceCount[0] >= 1 || diceCount[4] >= 1) {
		return true;
	}

	for (unsigned int i = 1; i < diceCount.size(); i++) {
		if (i == 4) { i = 5; }
		if (diceCount[i] >= 3) { return true; }
	}
	return false;
}

bool Table::IsValid(unsigned int& selection, vector<int>& dicePool) {
	if (selection > 0 && selection <= dicePool.size()) {
		return true;
	}
	return false;
}

int Table::ScoreDice(vector<int>& dicePool, int die, array<int, 6>& dieCount, array<int, 6>& keptDice) {
	die -= 1;
	int score = 0;
	int dieValue = dicePool[die];

	if (dieCount[dieValue - 1] == 3) {
		int i = 0;
		while (i < 3) {
			for (unsigned int j = 0; j < dicePool.size(); j++) {
				if (dicePool[j] == dieValue) {
					dicePool.erase(dicePool.begin() + j); 
					keptDice[dieValue - 1]++; 
					i++;
				}
			}
		}

		score = dieValue == 1 ? 1000 : dieValue * 100;
		//Four or more of a kind is worth double the points of three of a kind, so four 4s are worth 800 points,
	} 	else if (dieCount[dieValue - 1] == 4) {
		int i = 0;
		while (i < 4) {
			for (unsigned int j = 0; j < dicePool.size(); j++) {
				if (dicePool[j] == dieValue) {
					dicePool.erase(dicePool.begin() + j);
					keptDice[dieValue - 1]++; 
					i++;
				}
			}
		}
		score = dieValue == 1 ? 1000 : (dieValue * 100) * 2;
		//Five 4s are worth 1,600 points 
	}	else if (dieCount[dieValue - 1] == 5) {
		int i = 0;
		while (i < 4) {
			for (unsigned int j = 0; j < dicePool.size(); j++) {
				if (dicePool[j] == dieValue) {
					cout << "You have 5 of a kind!\n";
					dicePool.erase(dicePool.begin() + j); 
					keptDice[dieValue - 1]++; 
					i++;
				}
			}
		}
		score = dieValue == 1 ? 1000 : ((dieValue * 100) * 2) * 2;
	}

	else if (dieValue == 1 || dieValue == 5) {
		dicePool.erase(dicePool.begin() + die); 
		keptDice[dieValue - 1]++;

		// If die is 1, the score is 100, otherwise it's 50
		score = dieValue == 1 ? 100 : 50;
	}
	return score;
}
//PLACEHOLDER DIE TIL WE FIGURE OUT THE DIE CLASS
void Table::RollDice(vector<int>& dicePool) {
	random_device rng;

	for (unsigned int i = 0; i < dicePool.size(); i++) {
		dicePool[i] = rng() % 6 + 1;
	}
}

Player Table::GetWinner(vector<Player> players) {
	Player winner = players[0];

	for (unsigned int i = 1; i < players.size(); i++) {
		if (players[i].Score() > players[i - 1].Score()) {
			winner = players[i];
		}
	}

	return winner;
}

void Table::Congratulate(Player& player) {
	cout << "=====================================" << endl;
	system("toilet -f future   CONGRATULATIONS --filter gay");
	cout << "=====================================" << endl;
	cout << "\n 🎲 " << player.Name() << " is the winner with a score of " << player.Score() << "! 🎲 " << endl;
	cout << GREEN << "\n ⋯⊱⊰✶✳ Oooohh " << player.Name() << ", YOU RICH!!! You made $" << player.Money() << " ⋯⊱⊰✶✳" << RESET <<endl << endl;
	sleep(5);
}

void Table::FinalRound(Player& player) {
	cout << "========================" << endl;
	system("toilet -f future   FINAL ROUND --filter gay");
	cout << "========================" << endl;
	cout << " " << player.Name() << " has a score of " << player.Score() << "!" << endl;
	cout << " ✶ The final round of play has begun! Good luck! ✶ " << endl << endl;
	sleep(1);
}

void Table::ShowKeptDice(array<int, 6>& keptDice) {
	cout << "+------------+" << endl;
	cout << "| Kept Dice  |" << endl;
	cout << "+------------+" << endl;
//SHOWS KEPT DICE
	for (unsigned int i = 0; i < keptDice.size(); i++) {
		cout << "[" << (i + 1) << "]: " << keptDice[i];
		if (i != keptDice.size() - 1) {
			cout << ", ";
		}
	}

	cout << endl << endl;
}


void Table::ShowRolls(vector<int>& dicePool) {
	cout << "+------------+" << endl;
	cout << "| Dice Rolls |" << endl;
	cout << "+------------+" << endl;

	for (unsigned int i = 0; i < dicePool.size(); i++) {
		cout << "| Die " << (i + 1) << ": [" << dicePool[i] << "] |" << endl;
	}
	cout << "+------------+" << endl << endl;
}

Player Table::Play() {
	Player winner; // Game continues to loop while this string is empty
	int numOfPlayers = 2; // Sets game to 2 players
	int playerTurn = 0; // Keeps track of player turns based on order in vector
	int firstTo5k = -1; 
	int turnScore = 0; // Points for current turn
	int turnAmount = 100; // The value the player has scored this turn
	PromptNumPlayers();

	vector<Player> players(numOfPlayers); // generate a vector to hold Player objects
	SetupPlayerNames(players);
	WelcomePlayers(players);

	// Continue looping until a winner is declared
	while (winner.Name() == "") {
		// Return to first players turn if necessary
		if (playerTurn == players.size()) {
			playerTurn = 0;
		}
		// The game is over if all players have had a turn after a player reaches 2k
		if (firstTo5k >= 0 && playerTurn == firstTo5k) {
			winner = GetWinner(players);
			continue;
		}
		// Run a turn for a player and put their score into the turnScore variable
		turnScore = Turn(players[playerTurn]);
		// If the player has not entered the game and they score more than 1000 points total
		if (!players[playerTurn].InGame() && turnScore >= 1000) {
			players[playerTurn].SetInGame(); // put player in the game
		}
		// add turnscore and money to current player
		if (turnScore > 0 && turnAmount > 0) {
			players[playerTurn].AddScore(turnScore);
			if (turnScore >= 1000) {
				turnAmount = 200;
				players[playerTurn].AddMoney(turnAmount);
			} else players[playerTurn].AddMoney(turnAmount);
		}
		// Check if players score is over 10k
		if (firstTo5k == -1 && CheckFor5k(players[playerTurn].Score())) {
			FinalRound(players[playerTurn]);

			firstTo5k = playerTurn;
		}

		playerTurn++; // Send to next players turn
	}

	return winner;
}
// Turn loop
int Table::Turn(Player& player) {
	//TO DO: ADD DIE CLASS 
	//PLACEHOLDER DIE WHILE TOMAS FINISHES 
	Die d1;
	Die d2;
	vector<int> dicePool(6); // New dice pool of 6 dice
	array<int, 6> keptDice = {}; // Set all kept dice values to 0
	array<int, 6> diceCount = {}; // Variable to count die values
	int turnScore = 0; // Running score for this turn
	int turnAmount = 100; // Running score for this turn
	bool farkle = false; // Determines if player has Farkled
	bool canPass = player.InGame(); // Determines if player can pass their turn
	bool canReroll = false; // Determines if player can reroll the dice
	bool hasPassed = false; // Determines when the player has passed their turn

	unsigned int selection = 1;

	while (!hasPassed) {
		// if player has set aside all dice
		if (dicePool.size() == 0) {
			// populate dicePool back to 6 dice
			for (int i = 0; i < 6; i++) {
				dicePool.push_back(1);
			}
		}

		RollDice(dicePool);
		canReroll = false;
		canPass = false;
		// Allow player to set aside the rolled dice until they pass or reroll
		do {
			cout << "=================" << endl;
			cout << BOLDCYAN << " ✳ " << player.Name() << "'s Turn!" << RESET << endl;
			cout << "=================" << endl;
			cout << BOLDWHITE << " " << player.Name() << "'s Score: " << RESET << player.Score() << endl;
			cout << BOLDWHITE << " Money: " << RESET << GREEN << "$" << player.Money() << RESET << endl << endl;
			cout << BOLDWHITE << " Current Score: " << RESET << turnScore << endl;
			cout << BOLDWHITE << " Wager Amount: $" << RESET << turnAmount << endl << endl;

			ShowRolls(dicePool);
			ShowKeptDice(keptDice);

			diceCount = CountDice(dicePool);

			// If the player has no scoring dice and they can't reroll
			if (!ScoringDice(diceCount) && !canReroll) {
				farkle = true; // The player has farkled
				selection = 0; // Automatically select to end their turn
				continue; // Skip the rest of the code in this loop
			}

			cout << " 🎲 Enter the die # you wish to keep " << endl;
			cout << BOLDBLACK << " (Anything higher than triple values will be kept automatically)" << RESET << endl;
			cout << "\n Enter ⑨. To reroll dice" << endl;
			cout << " Enter ⓪: To end your turn (Must have a minimum of 500 points) " << endl;
			cout << "\n Selection: ";

			// If the dice pool is empty, automatically reroll to generate 6 new dice, otherwise get the player's selection
			selection = dicePool.size() == 0 ? 9 : GetInput();
			if (IsValid(selection, dicePool)) {
				// Add the dice value to turn score
				turnScore += ScoreDice(dicePool, selection, diceCount, keptDice);
				canReroll = true; // Player has kept a die and can now reroll the dice
				// If the player is in the game or they have over 500 points, the player can end their turn
				canPass = (player.InGame() || turnScore >= 500) ? true : false;
			}
			// check if the player has selected a valid move, ending turn or rerolling dice
			else if ((selection == 0 && !canPass) || (selection == 9 && !canReroll)) {
				string msg;

				cout << "=================" << endl;
				cout << " INVALID MOVE" << endl;
				cout << "=================" << endl;

				msg = selection == 0 ? + " " + player.Name() + " cannot score out at this time!" : + " " + player.Name() + " cannot reroll at this time!";

				cout << endl << RED << msg << RESET << endl << endl;

				selection = 7;
			}
		} while (selection > 0 && selection != 9);

		// Player selected to end their turn, then they have passed. Otherwise they're rolling dice
		hasPassed = selection == 0 ? true : false;
	}
	cout << "=================" << endl;
	cout << " " <<  player.Name() << "'s TURN ENDS!" << endl;
	cout << "=================" << endl;

	if (farkle) {
		cout << RED << " " << player.Name() << " has FARKLED!" << RESET << endl;
	}
	else {
		cout << " " << player.Name() << " has scored " << turnScore << " points this turn!" << endl;
		if (turnScore >= 1000){
			cout << BOLDBLACK << " You scored over 1000 points this round!" << endl;
			cout << " Bonus: $200" << RESET << endl;
			cout << GREEN << " " << player.Name() << " has earned $" << turnAmount + 100 << " this turn!" << RESET << endl;
		} else cout << GREEN << " " << player.Name() << " has earned $" << turnAmount << " this turn!" << RESET << endl;
	}
	// return 0 if player farkled or turnScore
	return turnScore = farkle ? 0 : turnScore;
}
/***********************
  END LOOPS
 ***********************/

void Table::GameLoop() {
	bool quit = false;
	unsigned int selection;
	Player winner;

	while (!quit) {
		Menu::showMenu();
		selection = GetInput();

		switch (selection) {
			case 1: 
				Menu::showRules();
				sleep(8);
				break;
			case 2: 
				winner =Play();
				Congratulate(winner);
				break;
			case 3:
				quit = true;
				break;
			default:
				break;
		}
	}
}
