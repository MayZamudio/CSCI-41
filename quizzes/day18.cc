#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

void uppercaseify(string &s) {
	for (char &c : s) c = toupper(c);
}

int main() {
	char arr[3][3];
	//Initialize all spaces to... space
	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 3; j++)
			arr[i][j] = ' ';

	cout << "Please enter a row and column:\n";
	int row = 0, col = 0;
	cin >> row >> col;
	if (row < 0 or row > 2 or col < 0 or col > 2) //Always vet your input
		exit(1);
	arr[row][col] = 'X';

	//Print the board
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << arr[i][j] << " | ";
		}
		cout << endl; //This is key to good formatting
	}

	/*
	string name;
	cout << "Enter your name:\n";
	cin >> name;
	//reverse(name.begin(),name.end()); //Option 1
	for (int i = 0; i < name.size()/2; i++) swap(name.at(i),name.at(name.size()-1-i));  //Option 2
	cout << "Your name backwards is:\n";
	cout << name << endl;
	sort(name.begin(),name.end());
	cout << "Your name sorted is:\n";
	cout << name << endl;
	random_shuffle(name.begin(),name.end());
	cout << "Your name shuffled is:\n";
	cout << name << endl;

	//ctrl-v is the quote command in UNIX!!!! So ctrl-v followed by ctrl-g (which is beep)
	vector<string> 💩 = {"🦄","🍕","☺","🍆","🍑","🐱‍💻","👩‍🚀","👌",""};
	cout << "Unicode:\n";
	for (string s : 💩) cout << s << endl;
	sort(💩.begin(),💩.end()); //Sorts a vector
	reverse(💩.begin(),💩.end()); //Reverses a vector from front to back
	cout << "\nUnicode sorted:\n";
	for (string s : 💩) cout << s << endl;
	cout << endl;
	vector<string> cool_kids;
	//kawaii means cute, kowai means scary, Kuai is an island in Hawaii that I'll be livestreaming from
	vector<string> kowai_kids;
	while (true) {
		cout << "Please enter a name (type \"done\" to be done):\n";
		string s;
		cin >> s;
	//	uppercaseify(s);
		if (s == "DONE" or !cin) break;
		if (s == "GURDEV" or s == "DOLIO" or s == "JAI") {
			kowai_kids.push_back(s);
		}
		else
			cool_kids.push_back(s);
	}
	cout << "COOL KIDS LIST:\n";
	for (string s : cool_kids) cout << s << endl;
	cout << "KOWAI KIDS LIST:\n";
	for (string s : kowai_kids) cout << s << endl;

	sort(cool_kids.begin(),cool_kids.end());
	sort(kowai_kids.begin(),kowai_kids.end());

	cout << "COOL KIDS LIST:\n";
	for (string s : cool_kids) cout << s << endl;
	cout << "KOWAI KIDS LIST:\n";
	for (string s : kowai_kids) cout << s << endl;

	//VIP Check
	cout << "Who dat?\n";
	string s;
	cin >> s;
	bool on_good_list = false;
	for (string cool : cool_kids) {
		if (s == cool) {
			on_good_list = true;
			break;
		}
	}
	bool on_bad_list = false;
	for (string bad : kowai_kids) {
		if (s == bad) {
			on_bad_list = true;
			break;
		}
	}
	if (on_good_list) {
		cout << "Welcome in, kind sir/ma'am, your butler awaits.\n";
	}
	else if (on_bad_list) {
		cout << "I'm Chris Hansen, why don't you take a seat over there.\n";
	}
	else {
		cout << "Never heard of you, GTFO.\n";
	}

	vector<int> vec = {1,1}; //Option 1
	//vector<int> vec(2,1); //Option 2
	//vector<int> vec(2); for (int i = 0; i < 2; i++) vec.at(i) = 1; //Option 3
	for (int i = 0; i < 100; i++) {
		int x = vec.back() + vec.at(vec.size()-2);
		vec.push_back(x);
	}
	for (int x : vec) cout << x << endl; //Option 1
	//for (int i = 0; i < vec.size(); i++) cout << vec.at(i) << endl; //Option 2
	*/
}
