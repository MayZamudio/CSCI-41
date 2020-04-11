#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
	srand(time(0)); //Initializes the random number generator
	int damage = 0;
	string weapon;
	cout << "What weapon do you want?\n";
	cin >> weapon;
	if (weapon == "dagger") damage = 4;
	//YOU:....
	else if (weapon == "shortsword") damage = 6;
	else if (weapon == "longsword" or weapon == "spear") damage = 8;
	else if (weapon == "halberd" or weapon == "glaive") damage = 10;
	else if (weapon == "greataxe" or weapon == "greatsword") damage = 12;
	else damage = 6;

	int attack_roll = rand()%20 + 1; //Rolls a random number from 1 to 20
	if (attack_roll == 20) {
		cout << "CRIT! Your attack does: " << 2 * (rand() % damage + 1) << " damage!\n";
	}
	else if (attack_roll > 9) {
		cout << "Hit! Your attack does: " << rand() % damage + 1 << " damage!\n";
	}
	else {
		cout << "You missed!\n";
	}

	/*
	int number = 0, number2 = 0;
	cin >> number >> number2;
	if (number > 10) cout << "Your number is over 10! Yay! Good for you!!!\n";
	if (number > number2) cout << "Number is bigger than number2!!\n";
	if (number > 10 and number < 20) cout << "Number is between 10 and 20!!\n";

	if (number % 2 == 0) cout << "Your number is divisible by two!\n";
	else cout << "Your number is not divisible by two!" << endl;

	int years_till_retirement = 0, income = 0;
	cout << "Please enter how many years you have until you retire and your annual income:\n";
	cin >> years_till_retirement >> income;
	cout << "Please enter how much money you want to have at retirement:\n";
	int target_money = 0;
	cin >> target_money;

	int retirement_money = years_till_retirement * income; //This is how much I'll have saved up

	if (retirement_money >= target_money) {
		cout << "You have enough for retirement! Yay!\n";
	}
	else {
		cout << "Sorry, I hope you like the taste of cat food.\n";
	}
	int x = 0, y = 0;
	cin >> x >> y;
	cout << static_cast<float>(x + y) / 2 << endl;
	cout << float(x + y) / 2 << endl;
	cout << (float)(x + y) / 2 << endl;
	*/
}
