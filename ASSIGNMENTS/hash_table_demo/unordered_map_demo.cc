#include <iostream>
#include <unordered_map>
using namespace std;

struct SSN {
	string name, address;
	long long number;
};
ostream &operator<<(ostream &outs, const SSN &s) {
	outs << s.name << " lives at " << s.address << " with SSN = " << s.number;
	return outs;
}

int main() {
	//Lesson 1 - How do we make a hash table using the STL?
	//Lecture:
	//	Unordered maps use a "key" to search for something and a "value" which is the data to store
	//	So if you want to store SSN records by name, which is a string, you'd do this
	unordered_map<string,SSN> records;
	//	But if you wanted searchable by SSN number instead (number is a long long) you'd do it like this:
	//unordered_map<long long, SSN> records2;
	//	The first template parameter is the type of the key - that is the thing getting hashed. The second is the type of the data to store

	//Part 2 - Build a hash table
	//Lecture:
	//	We use the insert method to insert a pair of values - the key (which is what it will hash on) and the value to be stored
	//	We can either make a pair<string,SSN> to insert, or we can just use universal initialization syntax to do it for us
	while (true) {
		cout << "Please enter the name of the user to add:\n";
		string name;
		getline(cin,name);
		if (!cin or name == "") break;
		cout << "Please enter " << name << "'s address:\n";
		string address;
		getline(cin,address);
		cout << "Please enter " << name << "'s SSN number:\n";
		long long number;
		cin >> number;
		//Add person to the hash table
		//insert takes a pair<string,SSN>, so we use doubly-nested curly bois to do so, one for the pair, one for the SSN inside the pair
		records.insert({name,{name,address,number}});
		//Or we'd do this if we were using the SSN as the key
		//records2.insert({number,{name,loc,balance}});

		//When you switch from >> to getlines, you need to do this...
		string trash;
		getline(cin,trash); //Throw away the trailing newline
	}

	//Part 3 - Print everything in a hash table
	//Lecture:
	//	Now we will print everything in the hash table
	//	The key thing to note here is that it returns a PAIR
	//	A pair is a simple data structure with a .first and .second
	//	The .first is the key, the .second is the value stored
	
	cout << "Database:\n";

	//	We usually use auto here to cut down on the typing
	//	If you want to know what it'd look like without the auto...
	//	for (const pair<string,SSN> &x : records) {
	for (const auto &x : records) {
		//x is a pair, with x.first being the key
		//x.second being the data (an SSN entry)
		cout << "KEY: " << x.first << "\tVALUE: " << x.second << endl;
	}

	//Part 4 - Print one entry in a hash table
	//Lecture:
	//  To look up a record in a hash table, we use the [] operator
	//  BUT this is a really bad operator, because if there is nothing
	//  in the hash table with that name, IT WILL MAKE ONE UP
	//  So we always check to see if it exists before using [] to read
	cout << "Enter a name to look up:\n";
	string name;
	getline(cin,name);
	//First, we want to check if the name is in the database
	//.count is a method that says how many times the name is in the
	//database. It will be either 0 or 1 since this isn't a multimap
	//(If you want duplicates, use unordered_multimap instead.)
	//We do this to avoid [] creating an entry if it isn't there
	if (records.count(name) == 0) cout << name << " not found.\n";
	else cout << records[name] << endl; //[key] returns value
	//I like using [] since we don't need to worry about pairs that way
	//Just be careful to always check to see if it exists first

	//Part 5 - Modify a hash table
	//Lecture:
	//	We will now change the address to be "REDACTED"
	//	We do this with the [] operator again...
	//	And again we check to see it exists first
	if (records.count(name)) records[name].address = "REDACTED";

	//And lets print the database again...
	cout << "Final database:\n";
	for (const auto &x : records) cout << x.second << endl;
}

