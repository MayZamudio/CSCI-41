#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<string> vec = {"PINTO", "AVOCADO", "TOURIST"};
	cout << "Enter a word to search for:\n";
	string s;
	cin >> s;
	auto it = find(vec.begin(),vec.end(),s);
	if (it == vec.end()) cout << "NOT FOUND\n";
	else cout << "FOUND\n";
}
