#include <vector>
#include <iostream>
using namespace std;

void die() {
	cout << "BAD INPUT!\n";
	exit(1);
}

int main() {
	cout << "Welcome to the Baseball Score Calculator.\n";
	cout << "How many games did your team play?\n";
	unsigned int x = 0;
	cin >> x;
	if (!cin || x < 1 || x > 100) die();
	vector<int> vec(x);
	cout << "Please enter the score your team got in each game.\n";
	for (auto &i : vec) {
		cin >> i;
		if (!cin || i > 100) die();
	}
	double accum = 0;
	for (auto x : vec) accum += x;
	cout << "Your average score was: " << accum / vec.size() << endl;
}
