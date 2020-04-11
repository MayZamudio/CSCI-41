#include <iostream>
#include <vector>
using namespace std;

int read_int(string prompt = "") {
	while (true) {
		int x = 0;
		cout << prompt;
		cin >> x;
		if (!cin) {
			cin.clear(); //Clear error code
			string s;
			cin >> s; //Remove the squirrel from your throat
			continue;
		}
		else
			return x;
	}
}

int main() {
	int blah = read_int();
	int age = read_int("Please enter your age:\n");
}
