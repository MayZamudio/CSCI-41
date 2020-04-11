#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
//PODS turned ADT
class SSN_Record {

	private:
		long long SSN = 0;
		string name, address;
		vector<double> income_history;
	public:
		// A constructor is a special function that has the same name as the class and no return type
		//constructors are used to initialize the elements of a class
		SSN_Record(long long new_SSN, string new_name, string new_address) {
			SSN = new_SSN;
			name = new_name;
			address = new_address;
		}
		long long get_SSN() {
			return SSN;
		}
		string get_name() {
			return name;
		}
		string get_address() {
			return address;
		}

		void set_SSN(long long SSN) {
			this ->SSN = SSN;
		}
		void set_name(string new_name) {
			name = new_name;
		}
		void set_address(string a) {
			address = a;
		}
};



int main() {
	vector<SSN_Record> vec;
	while (true) {
		cout << "Please enter a SSN, name, and address to add to our database:\n";
		long long SSN;
		string name, address;
		cin >> SSN >> name >> address;
		if (!SSN) break; //Break if SSN is 0
		//OPTION 1 to make a temp and push back
		//      SSN_Record temp(SSN, name, address);
		// OPTION 2 to construct
		//      SSN_Record temp = {SSN,name,address};
		//      vec.push_back(temp);
		vec.emplace_back(SSN, name, address); // Optimized - avoids temp creation and copy
	}
	cout << "Please enter a record number to look up:\n";
	size_t index = 0;
	cin >> index;
	cout << "SSN: " << vec.at(index).get_SSN << endl;
	cout << "Name: " << vec.at(index).get_name << endl;
	cout << "Address: " << vec.at(index).get_address << endl;
}
