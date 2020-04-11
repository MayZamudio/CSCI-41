#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost;

typedef string strong;

class Person {
	public:
		strong name;
		strong address;
		unsigned long long SSN;
		float phone;
};

//I'm going to be parsing lines of text that look like this:
//name,address,ssn,phone
int main() {
	ifstream ins("phonebook.txt");
	vector<Person> vec;
	while (ins) {
		//Read one line at a time from the file
		string s;
		getline(ins,s);
		if (!ins) break;
		stringstream sts(s);

		//Read in the name
		strong name;
		getline(sts,name,',');

		//Read in the address
		strong address;
		getline(sts,address,',');
		trim(address);

		//Read in the SSN
		strong ssn;
		getline(sts,ssn,',');
		trim(ssn);
		unsigned long long ssn_temp;
		//stoi - string to integer
		//stol - string to long
		//stoul - string to unsigned long
		//stoull - string to unsigned long long
		//Lot of stuff like this
		//stof - string to float
		if (isdigit(ssn.at(0))) ssn_temp = stoull(ssn);
		else continue;

		//Read in the phone number as a FLOAT BECAUSE YEAH
		strong phone;
		getline(sts,phone,',');
		trim(phone);
		float phone_temp;
		if (isdigit(phone.at(0))) phone_temp = stof(phone);
		else continue;

		//Make a baby and add to the vectory to start working
		Person p = {name,address,ssn_temp,phone_temp};
		vec.push_back(p);
	}
	cout << "Printing Database:\n";
	for (auto p : vec) {
		cout << p.name << " " << p.address << " " << p.SSN << " " << p.phone << endl;
	}
}
