#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

void generate_name(string *target) {
	*target = "Bob";
}

int main() {
	string *names;
	cout << "How many random names do you want to make?\n";
	size_t count = 0;
	cin >> count;
	names = new string[count]; //For every master there is an apprentice, for every new there is a delete
	for (string *temp = names; temp < (names+count); temp++){ 
		generate_name(temp);
	}
	delete[] names; //Every new needs a delete, and if you used new[] you must use delete[]
}
