#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstdlib>
#include <cmath>
using namespace std;

void die() {
	cout << "BAD INPUT!\n";
	exit(EXIT_FAILURE);
}

//These structs are all done for you. They're all PODS, so you can convert them to ADTs if you like
//But... if you're coding under a time crunch, you can leave them this way

//Holds an x and y location. 
struct Location {
	long long x = 0, y = 0;
};

//Allows you to cin a Location, like this:
//cin >> loc; 
istream &operator>>(istream &ins, Location &l) {
	ins >> l.x >> l.y;
	if (!ins) die();
	return ins;
}

//Outputs the distance between a and b, rounded to the nearest int
//Example: a = (1,1) b = (4,5) would return 5
long long distance(const Location &a, const Location &b) {
	long long dist_x = b.x - a.x;
	long long dist_y = b.y - a.y;
	long long result = hypot(dist_x*100, dist_y*100);
	return round((result + 50) / 100 * 100); //YOU: Have it compute the distance between a and be using hypot and rounding to the nearest int
}

//Customer record
struct Customer {
	string name;
	Location loc;
	long long balance;
};

//Converts from cents to a string representation of dollars and cents
string cents_to_string(long long cents) {
	string cash = to_string(cents);
	if (cents == 0) {
		return "$0.00";
	}
    if (cents < 10) { 
        return "$0.0" + cash;
    }     
	if (cents < 100) {
		return "$0." + cash;
	}
	cash.insert(0, "$");
	cash.insert(cash.size() - 2, ".");
	return cash;
	//YOU: Write a function that will take a long long (in cents) and returns a string with dollars and cents
	//Example 1234 as the input would return a string "$12.34", and 500000 would return "$5000.00"
	//return "I haven't implemented cents_to_string yet! 😂";
}

//Tells C++ how to output a Customer
ostream &operator<<(ostream &outs, const Customer &c) {
	outs << "Name: " << left << setw(15) << c.name << "Balance: " << cents_to_string(c.balance);
	return outs;
}

//Tells C++ how to compare and sort Customers
bool operator<(const Customer &c1, const Customer &c2) {
	return c1.balance < c2.balance;
}

//YOU: Write a function that finds the richest customer from the data structure passed in
template <class T>
Customer max_element(const T &customers) {
	//T customers might be a vector, a set, a hash table... I'd use a range-based for loop here to find the richest guy
	Customer richest = customers.at(0);
	long long temp = richest.balance;
	for (auto x : customers) {
		if (x.balance > temp) richest = x;
	}
	return {richest}; //This doesn't work yet
}

//holds one of the items for sale in a store
struct Item {
	string name;
	long long price; //All prices are in cents
};

//Tells C++ how to print an Item to the screen
//I probably could have formatted this better but whatever
ostream &operator<<(ostream &outs, const Item &i) {
	outs << "Name: " << left << setw(15) << i.name << "Price: " << cents_to_string(i.price);
	return outs;
}

//The : public Customer here means that Business inherits from Customer
//I used inheritance here to avoid having to copy/paste the name, location, and balance.
//It doesn't make a lot of conceptual sense, but it means all those functions we have to compare Customers
//Will work with businesses as well, for free!
struct Business : public Customer {
	//A business has all the member variables of a customer, plus a data structure holding what items it sells
//	unordered_map<string,Item> items; //If you are confused by unordered maps, you can change this to a vector or set
	vector<pair<string,Item>> items; //If you are confused by unordered maps, you can change this to a vector or set
};
