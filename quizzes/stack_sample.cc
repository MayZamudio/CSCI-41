#include <stack>
#include <queue>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string str) {
//for loop way
	for (size_t i = 0; i < str.size() / 2; i++)
		if (str.at(i) != str.at(str.size() - (i + 1))) return false;
	return true;

//short way
	string str2 = str;
	reverse(str2.begin(), str.end());
	return (str == str2);
//This is the queue and stack way
	queue <char> q;
	stack <char> s;
	for (char c : str) q.push(c);
	for (char c : str) s.push(c);
	while (q.size()) {
		char c1 = toupper(q.front());
		q.pop();
		char c2 = toupper(s.top());
		s.pop();
		if (c1 != c2)return false;
	}
}

int main() {
//	auto int x = 8;
	cout << "Please enter a string\n";
	string temp;
	cin >> temp;
	if (isPalindrome(temp)) cout << temp << " is Palindrome\n";
	else cout << temp << " is not Palindrome\n";
}
