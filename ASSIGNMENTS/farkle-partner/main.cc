//Garcia , Zamudio
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
//FOR TIMER
#include <unistd.h>
#include "die.h"
#include "player.h"
#include "table.h"
#include "/public/colors.h"

using namespace std;

void die() {
	cout << "Invalid Input!\n";
	exit(EXIT_FAILURE);
	//return;
}

int howManyOnes, howManyTwos, howManyThrees, howManyFours, howManyFives, howManySixes;

void resetCounters() {
	howManyOnes = 0, howManyTwos = 0, howManyThrees = 0, howManyFours = 0, howManyFives = 0, howManySixes = 0;
}


int getScore(int roll, vector<Die> hand) { //SCORING FUNCTION
	bool farkle = false;
	int onesCheck = 0, twosCheck = 0, threesCheck = 0, foursCheck = 0, fivesCheck = 0, sixesCheck = 0;
	for (size_t i = 0; i < hand.size(); i++) { ///Farkle check
		if (hand.at(i).get_roll() == 1)onesCheck++;
		else if (hand.at(i).get_roll() == 2)twosCheck++;
		else if (hand.at(i).get_roll() == 3)threesCheck++;
		else if (hand.at(i).get_roll() == 4)foursCheck++;
		else if (hand.at(i).get_roll() == 5)fivesCheck++;
		else if (hand.at(i).get_roll() == 6)sixesCheck++;

	}

	if (onesCheck == 0 && fivesCheck == 0 && twosCheck < 3 && threesCheck < 3 && foursCheck < 3 && sixesCheck < 3) {
		farkle = true;
		return -1;
	}

	int score = 0;
	if (roll == 1) {
		score = 100;
		howManyOnes++;
		if (farkle == true && howManyOnes < 3)return -1;
		else if (howManyOnes == 3) score = 800; //adds up to 1000
		else if (howManyOnes == 4) score = 1000; //adds up to 2000
		else if (howManyOnes == 5) score = 2000;}//adds up to 4000

	else if (roll == 5) {
		howManyFives++;
		score = 50;
		if (farkle == true && howManyFives < 3)return -1;
		else if (howManyFives == 3) score = 400; //100 +400 =500
		else if (howManyFives == 4) score = 500; //500+500=1000
		else if (howManyFives == 5) score = 1000;}//1000+1000=2000
	else if (roll == 2) {
		howManyTwos++;
		if (farkle == true && howManyTwos < 3)return -1;
		else if (howManyTwos == 3)score = 200; //200
		else if (howManyTwos == 4)score = 200; //400
		else if (howManyTwos == 5)score = 400;}//800
	else if (roll == 3) {
		howManyThrees++;
		if (farkle == true && howManyThrees < 3)return -1;
		else if (howManyThrees == 3)score = 300;
		else if (howManyThrees == 4)score = 300; //600
		else if (howManyThrees == 5)score = 600;}//1200

	else if (roll == 4) {
		howManyFours++;
		if (farkle == true && howManyFours < 3)return -1;
		else if (howManyFours == 3)score = 400;
		else if (howManyFours == 4)score = 400; //800
		else if (howManyFours == 5)score = 800;}//1600
	else if (roll == 6) {
		howManySixes++;
		if (farkle == true && howManySixes < 3)return -1;
		else if (howManySixes == 3)score = 600;
		else if (howManySixes == 4)score = 600; //1200
		else if (howManySixes == 5)score = 1200;}//2400

		return score;

}
void gameFunction(Table table, Player &currPlayer) {

	vector<int> iterator ;// made of vector so user cant add the same Dice multiple times to score more points
	bool choosen = false;
	int diceChoosen = 0;
	const int DICE_REMAINING = 6;
	int currScore = 0;
	bool playerTurnOver = false;	
	int hotDice = 0;	
	bool hottDice = false;
	char diceType;
	bool cheater = true;

	cout << "\n 🎲  Does " << currPlayer.getName() << " want to user cheater dice? (y or n)  🎲 " << RESET << endl << endl;
	cout << "\n 〉 ";
	cin >> diceType;
	if (diceType == 'n' || diceType == 'N') {
		table.loadTableHand(DICE_REMAINING);//load table dice
		cheater = false;
	}
	else if (diceType == 'y' || diceType == 'Y') {
		cout << YELLOW << "\n ===== 🎲  Enter the Die # " << currPlayer.getName() << " wishes to use?  🎲  =====" << RESET << endl << endl;
		if (!cin) die();
		Die d1;
		d1.displayDie();
		d1.setDie(d1);
		table.loadTableHand(DICE_REMAINING);//load table dice
		cheater = true;	
	}
	else die();
	cout << "\n Rolling Dice...  " << endl;
	cout << endl;
	cout << " +------------+" << endl;
	cout << " | Dice Rolls |" << endl;
	cout << " +------------+" << endl;
	table.setRoll();
	cout << " +------------+" << endl << endl;

	if (getScore(0, table.getTableHand()) == -1) {
		cout << RED << " YOU FARKLED\n" << RESET;
		playerTurnOver = true;
		table.setScore(-5);//IF THEY FARKLE THEY LOSE ALL CURRENT POINTS
	}
	while (!playerTurnOver) {
/*		cout << "\n Rolling Dice...  " << endl;
		cout << endl;
		cout << " +------------+" << endl;
		cout << " | Dice Rolls |" << endl;
		cout << " +------------+" << endl;
		table.setRoll();
		cout << " +------------+" << endl << endl;*/
		cout << " 🎲 Enter the die # you wish to keep " << BOLDBLACK << " R: To Reroll  P: To Pass" << RESET << endl;
		cout << "\n 〉 ";
		char keep;
		cin >> keep;
		//had to use a char for keep so user can type in both numbers or letters
		if (keep >= 48 && keep <= 53) {//TRYING TO GET 1-6
			for (size_t i = 0; i < iterator.size(); i++) {
				if (iterator.at(i) == int(keep) - 48) { 
					//dont load into player vector same dice 2x (same die not same die value)
					cout << RED << int(keep) - 48 << " has already been selected " << RESET << endl;
					choosen = true;
				}
			}
			if (!choosen) {
				if(int(keep-48) >= table.getTableHand().size()){
					//TO NOT SEGFAULT WHEN TRYING TO ACCESS DIE > VECTOR<DIE>
					cout << RED << "Invalid option, try again" << RESET << endl;
					continue;
				}
				cout << BOLDWHITE << " Dice chosen: [" << RESET << table.getTableHand().at(int(keep - 48)).get_roll() << "]" << endl;

				iterator.push_back(int(keep) - 48); // what dice was chosen, make sure same dice isnt chosen again
				//changed to be Dice 1-6
				for (size_t i = 0; i < iterator.size(); i++)
					//	cout<<"iterator choices are: "<<iterator.at(i)<<endl;
				currPlayer.add(table.getTableHand().at(int(keep - 48)));
				diceChoosen++;  //KEEPING TRACK OF HOW MANY DICE HAVE BEEN SELECTED

				int value = (table.getTableHand().at(int(keep - 48)).get_roll());
				table.setScore(getScore((value), table.getTableHand()));// set the current score (using table class)
				cout << BOLDWHITE << " Current score is: " << RESET << table.getScore() << endl;
				//	cout<<"Player added: \n";
				//				for (size_t i = 0; i < currPlayer.getHand().size(); i++)
				//		cout<< currPlayer.getHand().at(i).get_roll()<<endl;
				continue;
			}
			choosen = false; //reset boolean otherwise wont load any dice after 1st time they choose the same dice
			//}
	}
	else if (keep == 82 || keep == 114) { //IF THEY CHOOSE R(REROLL)
		if(iterator.size() < 1) cout << " You must choose at least 1 die to reroll\n";
		//	continue;
		else{
			resetCounters();//Reset the 3-of-a-kind, 4-of-a-kind counters
			cout << " Rerolling....\n # of dice chosen so far = " << diceChoosen << endl;
			table.clear();//new set of dice
			iterator.clear();// reset the vector that checks if they already chose a certain dice
			table.loadTableHand(DICE_REMAINING - diceChoosen);	//subtract # of dice chosen from new roll
			cout << "\n +------------+" << endl;
			cout << " | Dice Rolls |" << endl;
			cout << " +------------+" << endl;
			table.setRoll();
			cout << " +------------+" << endl << endl;

			if (getScore(0, table.getTableHand()) == -1) {
				cout << RED << " YOU FARKLED\n" << RESET;
				playerTurnOver = true;
				table.setScore(-5);//IF THEY FARKLE THEY LOSE ALL CURRENT POINTS RESET TABLE SCORE TO 0
			}
		}
		continue;
	}


	else if (keep == 80 || keep==112) { //if they want to finish and pass
		cout << YELLOW << "\n 》"	<< currPlayer.getName()<< " CHOOSES TO PASS." << RESET << endl;
		cout << endl;
		playerTurnOver = true;
	}

	else
		;
}
if (diceChoosen == hotDice && !playerTurnOver) {
	cout<< " Hot Dice!\n";
	hottDice = true;
}	
currPlayer.setScore(table.getScore());
cout << "======================" << endl;
cout << BOLDWHITE << " 🎲 " << currPlayer.getName() << "'s Score: " << RESET << currPlayer.getScore() << endl << RESET;
cout << "======================" << endl;
cout << endl;
resetCounters();//Reset the 3-of-a-kind, 4-of-a-kind counters
}

void displayRules() {
	string lineInFile;
	ifstream inputfile;
	inputfile.open("rules.txt");
	while(getline(inputfile, lineInFile)) {
		cout << lineInFile << '\n';
	}
	inputfile.close();
}

int main() {
	srand(time(0));
	int howManyOnes = 0, howManyTwos = 0, howManyThrees = 0, howManyFours = 0, howManyFives = 0, howManySixes = 0;
	Table t;
	Player PlyOne, PlyTwo;
	int pointLimit = 0;
	int wager = 0;
	
	
	displayRules();
	cout << endl;
	sleep(5);
	cout << endl;
	cout << endl << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
	cout << endl;
	system("figlet FARKLE | lolcat");
	cout << endl << "===== 🎲  Let the games begin! 🎲  =====" << endl << endl;
	sleep(1);
	while (true) {
		cout << " Please enter how many points you will be playing to: " << endl;
		cout << BOLDBLACK << " Choose between 1000-10000" << RESET << endl;
		cout << "\n 〉 ";
		cin >> pointLimit;
		if (!cin) die();
		if (pointLimit >= 1000 && pointLimit <= 10000) break;
		cout << RED << " Choose between 1000 - 10000! " << RESET << endl;
	}
    cout << "======================================" << endl;
    system("toilet -f future PLAYER ONE --filter gay");
    cout << "======================================" << endl;
    sleep(1);
	cout << " Please enter Player 1's name " << endl;
	cout << "\n 〉 ";
	string player1Name = "";
	cin >> player1Name;
	PlyOne.setName(player1Name);
	while (true){
		cout << " Please enter "<< player1Name << "'s starting money ($1 - $1000)" << endl;
		cout << "\n 〉 ";
		int player1StartMoney;
        cin >> player1StartMoney;
		if (!cin) die();
		if (player1StartMoney > 0 && player1StartMoney <= 1000){
			PlyOne.setMoolah(player1StartMoney);
			break;
		} cout << RED << "\n Has to be between $1 - $1000 " << RESET << endl;
	}
	cout << "======================================" << endl;
	system("toilet -f future PLAYER TWO --filter gay");
	cout << "======================================" << endl;
	sleep(1);
	cout << " Please enter Player 2's name " << endl;
	cout << "\n 〉 ";
	string player2Name = "";
	cin >> player2Name;
	if (!cin) die();
	PlyTwo.setName(player2Name);
	while (true){
		cout << " Please enter " << player2Name << "'s starting money ($1 - $1000)" << endl;
		cout << "\n 〉 ";
		int player2StartMoney;
		cin >> player2StartMoney;
		if (!cin) die();
		if (player2StartMoney > 0 && player2StartMoney <= 1000){
			PlyTwo.setMoolah(player2StartMoney);
			break;
			} cout << RED << "\n Choose between $1 - $1000 " << RESET << endl;
	}
	while (true) {
		cout << YELLOW << "\n ===== 🎲  Enter the Wager Amount  🎲  =====" << RESET << endl <<   endl;
		cout << "\n 〉 ";
		cin >> wager;
		if(!cin)die();
		if (wager >= 1 && wager <= PlyOne.getMoolah() && wager <= PlyTwo.getMoolah()){
			t.setWagerUp(wager);
			break;
		}
		cout << RED << " Enter wage amount within " << PlyOne.getName() << "'s starting amount of: $" <<PlyOne.getMoolah() << "   and " << PlyTwo.getName() << "'s starting amount of: $" << PlyTwo.getMoolah() << RESET << endl;
	}
	cout << "==================" << endl;
	system("toilet -f future   START --filter gay");
	cout << "==================" << endl;
	sleep(1);
	cout << "\n ⊱ Welcome " << PlyOne.getName() << " and " << PlyTwo.getName() << "! ⊰ " << endl << endl;
	sleep(1);
	while (PlyOne.getScore() <pointLimit || PlyTwo.getScore() < pointLimit) {
		cout << "=================" << endl;
		cout << BOLDCYAN << " ✳ " << PlyOne.getName() << "'s Turn!" << RESET << endl;
		cout << "=================" << endl;
		gameFunction(t, PlyOne);
		if(PlyOne.getScore() >= pointLimit){
			cout << "=====================================" << endl;
			system("toilet -f future   CONGRATULATIONS --filter gay");
			cout << "=====================================" << endl;

			cout << BOLDWHITE << "\n 🎲 " << PlyOne.getName() << " is the winner! 🎲  " << RESET << endl;
			PlyOne.setMoolah(PlyOne.getMoolah() + t.getWagerUp());
			PlyTwo.setMoolah(PlyTwo.getMoolah() - t.getWagerUp());
			cout << BOLDGREEN << "\n ⋯⊱⊰✶✳ Oooohh " << PlyOne.getName() << " has $"<< PlyOne.getMoolah() << " ⋯⊱⊰✶✳" << endl << RESET;
			cout << RED << "\n ⟼ " << PlyTwo.getName() << " has $ " << PlyTwo.getMoolah() << " ⟻ " << endl << RESET;
			sleep(5);
			break;
		}

        cout << "=================" << endl;
        cout << BOLDCYAN << " ✳ " << PlyTwo.getName() << "'s Turn!" << RESET << endl;
        cout << "=================" << endl;
		gameFunction(t, PlyTwo);
		if(PlyTwo.getScore() >= pointLimit) {
			cout << "=====================================" << endl;
			system("toilet -f future   CONGRATULATIONS --filter gay");
			cout << "=====================================" << endl;
			cout << BOLDWHITE << "\n 🎲 " << PlyTwo.getName() << " is the winner! 🎲 " << RESET << endl;
			PlyTwo.setMoolah(PlyTwo.getMoolah() + t.getWagerUp());
			PlyOne.setMoolah(PlyOne.getMoolah() - t.getWagerUp());
			cout << BOLDGREEN << "\n ⋯⊱⊰✶✳ Oooohh " << PlyTwo.getName() << " has $"<< PlyTwo.getMoolah() << " ⋯⊱⊰✶✳" << endl << RESET;
			cout << RED << "\n ⟼ " << PlyOne.getName() << " has $ " << PlyOne.getMoolah() << " ⟻ " << endl << RESET;
			sleep(5);
			break;
		}

	}
}
