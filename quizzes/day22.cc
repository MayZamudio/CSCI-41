#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

//C World code
bool fun(const char *arr, size_t SIZE) {
	for (size_t i = 0; i < SIZE-1; i++)
		if (arr[i] == arr[i+1]) return true;
	return false;
}
//C++ Version of the same code
bool fun(string s) {
	for (size_t i = 0; i < s.size()-1; i++) {
		if (s.at(i) == s.at(i+1)) return true;
	}
	return false;
}

//Given a string s, remove all letters that are not in order
//"ABCED" -> "ABCE"
//"GODAMIT" -> "GOT"
void stalin_sort(string &s) {
	for (size_t i = 0; i < s.size()-1; i++) {
		//If two letters not in order, then erase the one out of order
	}
	//This is an example, don't have it actually here...
	s.erase(0,1); //This erases 1 letter at index 0
}

int main() {
	cout << "Please enter a word and I will tell you if any two neighboring letters are the same:\n";
	string s;
	cin >> s;
	cout << "Before Stalin Sort: " << s << endl;
	stalin_sort(s);
	cout << "After Stalin Sort: " << s << endl;
}
