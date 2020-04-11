#include <iostream>
#include <vector>
#include <set>
#include <cctype>
#include <algorithm>
using namespace std;

int main() {
	set<char> s; //Make an ordered set of integers
	vector<char> v; //Make a vector of characters

	cout << "Please enter letters or numbers to add to our data structures. (0 to quit):\n";
	while (cin) {
		char c = cin.peek();
		if (c == '0') break;
		if (isspace(c)) {
			cin.get(); //Discard the space
			continue;
		}
		if (!cin) break;
		if (isdigit(c)) {
			int x = 0;
			cin >> x;
			s.insert(x);
		} else {
			cin >> c;
			v.push_back(c);
			if (c == '0') break;
		}
	}
	cout << "The set contains:\n";
	for (int i : s) cout << i << endl;
	cout << "The vector contains:\n";
	for (char c : v) cout << c << endl;
	sort(v.begin(), v.end());
	cout << "The sorted vector contains:\n";
	for (char c : v) cout << c << endl;
}
