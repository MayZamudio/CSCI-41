#include <iostream>
#include <vector>
#include <cctype>
#include <sstream>
using namespace std;

int main() {
	cout << "Please enter a name:\n";
	string s;
	getline(cin,s);
	cout << "You entered: " << s << endl;
	stringstream ss(s);
	vector<string> sentence;
	while (ss) {
		string t;
		ss >> t;
		if (!ss) break;
		sentence.push_back(t);
	}
	for (string t : sentence) 
		cout << "Word: " << t << endl;
	string splitter = sentence.at(4);
	stringstream ssplitter(splitter);
	vector<string> vins;
	while (ssplitter) {
		string t;
		getline(ssplitter,t,',');
		if (!ssplitter) break;
		vins.push_back(t);
	}
	for (string t : vins) {
		cout << "Vetting: " << t;
		bool coolio = true;
		for (char c : t)
			if (islower(c)) coolio = false;
		if (coolio)
			cout << "...is cool.\n";
		else
			cout << "...is not cool.\n";
	}
}
