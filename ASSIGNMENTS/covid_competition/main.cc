//Joshua Vargas & Mayra Zamudio
#include "classes.h"

long long gross = 0; //Total money made by Covid Connect
const long long MIN_ORDER = 5; //Minimum Delivery Fee (in dollars)

int main() {
#ifndef FROM_MAKEFILE
	//static_assert(false,"Use make to build this program, please.");
#endif
	//YOU: Make some data structures here to track customers and businesses
	//You can use vectors or hash tables or BSTs... your choice.
	//Option 1: Vectors
	vector<Customer> customers;
	vector<Business> businesses;
	//Option 2: Hash Tables
	//unordered_map<string,Customer> customers;
	//unordered_map<string,Business> businesses;
	//Option 3: BSTs
	//set<Customer> customers;
	//set<Business> businesses;
	//static_assert(false,"Pick an option above and delete this line.");
	system("figlet Covid Connect");
	while (true) {
		cout << "Pick a number:\n";
		enum Choice { ADDUSER = 1, ADDBUSINESS, ADDITEM, BUY, QUIT };
		cout << "1. ADD a user\n2. ADD a business\n3. ADD items for sale\n4. BUY an item\n5. QUIT\n";
		int choice = 0;
		cin >> choice;
		if (!cin or choice < ADDUSER or choice > QUIT) die();
		if (choice == QUIT) break;
		string trash;
		getline(cin,trash); //Eat the training newline
		if (choice == ADDUSER) {
			cout << "Please enter the name of the user to add:\n";
			string name;
			getline(cin,name);
			//YOU: Die if there is a duplicate entry
			if (!customers.empty()) {
                  for (size_t i = 0; i < customers.size(); i++) {
                      if (customers.at(i).name == name) die();
                  }
              }
			cout << "Please enter " << name << "'s location:\n";
			Location loc;
			cin >> loc; //This will error checks for us already
			cout << "Please enter " << name << "'s balance in cents:\n";
			long long balance;
			cin >> balance;
			//YOU: Vet balance, can't be < 0 or !cin
			if (!cin || balance < 0) die();
			//YOU: Add customer to the data structure
			Customer temp;
			temp.name = name;
			temp.loc = loc;
			temp.balance = balance;
			customers.push_back(temp);
//			for (auto x : customers) cout << x.name << " " << x.balance << endl;
			//customers.insert(temp);
		}
		else if (choice == ADDBUSINESS) {
			cout << "Please enter the name of the business to add:\n";
			string name;
			getline(cin,name);		
			//YOU: Check for duplicates
			if (!businesses.empty()) {
                  for (size_t i = 0; i < businesses.size(); i++) {
                      if (businesses.at(i).name == name) die();
                  }
              }
			vector<string> names;
			cout << "Please enter " << name << "'s location:\n";
			Location loc;
			cin >> loc; 
			cout << "Please enter " << name << "'s balance in cents:\n";
			long long balance;
			cin >> balance;
			//YOU: Vet balance
			if (!cin || balance < 0) die();

			//YOU: Add business to the data structure
			Business temp;
			temp.name = name;
			temp.loc = loc;
			temp.balance = balance;
			businesses.push_back(temp);
			//businesses.insert(temp);
		}
		else if (choice == ADDITEM) {
			cout << "Please enter the name of the business to add an item to:\n";
			string name;
			getline(cin,name);
			int it = 0;
			//YOU: Make sure this business exists, or die
			bool found = false;
			for (size_t i = 0; i < businesses.size(); i++) {
                  if (businesses.at(i).name == name) found = true;
            }
			if (!found) {
				cerr << "BROKEN AT 100" << endl;
				die();
			}
			cout << "Please enter the name of the item to add:\n";
			string item;
			getline(cin,item);
			cout << "Please enter the price of one " << item << " in cents" << endl;
			long long price;
			cin >> price;
			//YOU: Vet price, must be >= 0 and not a squirrel
			if (!cin || price < 0) {
				cerr << "BROKEN AT 108" << endl;
				die();
			}
			//YOU: Make sure this item doesn't exist already, each business can only have this item once
			//YOU: Add the item to the business
			Item temp;
			temp.name = item;
			temp.price = price;
			Business search;
			for (size_t i = 0; i < businesses.size(); i++) {
				if (businesses.at(i).name == name) {
					it = i;
					for (size_t j = 0; j < businesses.at(it).items.size(); j++) {
						if (businesses.at(it).items.at(j).first == item) {
							die();
						}
					}
					businesses.at(i).items.emplace_back(item, temp);
					}
				}
			reverse(businesses.at(it).items.begin(), businesses.at(it).items.end());
		//	cout << ".first: " << businesses.at(0).items.at(0).first << endl;
		//	cout << ".second: " << businesses.at(0).items.at(0).second << endl;
		}
		else if (choice == BUY) {
			string cust,biz;
			Location c;
			Location b;
			int itc = 0;
			int itb = 0;
			int itt = 0;
			cout << "Please enter the name of the person who wants to buy an item:\n";
			getline(cin,cust); 
			//YOU: Die if this customer doesn't exist
			bool foundcust = false;
			for (size_t i = 0; i < customers.size(); i++) {
                if (customers.at(i).name == cust) foundcust = true;
            }
			if (!foundcust) die();
			cout << "Please enter the name of the business who wants to sell an item:\n";
			getline(cin,biz); 
			//YOU: Die if this business doesn't exist
			bool foundbiz = false;
			for (size_t i = 0; i < businesses.size(); i++) {
                if (businesses.at(i).name == biz) foundbiz = true;
            }
			if (!foundbiz) die();
			//Compute delivery fee
			cout << "Delivery fee will be: ";
			int delivery_fee = 500;
			for (size_t i = 0; i < customers.size(); i++) {
				if (customers.at(i).name == cust) {
				itc = i;
				}
			}
			for (size_t i = 0; i < businesses.size(); i++) {
				if (businesses.at(i).name == biz) {
				itb = i;
				}
			}
			if ((distance(customers.at(itc).loc,businesses.at(itb).loc)) > delivery_fee) {
				delivery_fee = (distance(customers.at(itc).loc,businesses.at(itb).loc));
				if (delivery_fee > 10000) die();
			}
			//cout << delivery_fee << endl;
			//YOU: Make sure cents_to_string exists... or this won't work
			cout << cents_to_string(delivery_fee) << endl;
			cout << "These items are available for purchase:\n";
			//YOU: Print a list of items for sale at this business
			for (int i = 0; i < businesses.at(itb).items.size(); i++) {
			cout <<	businesses.at(itb).items.at(i).second << endl;	
			}
			cout << "Which item would you like to buy?\n";
			string tobuy;
			getline(cin,tobuy);
			//YOU: Die if the item doesn't exist in the business
			bool found = false;
			for (int i = 0; i < businesses.at(itb).items.size(); i++) {
				//cerr << "before if: " << businesses.at(itb).items.at(i).first << endl;
				if (businesses.at(itb).items.at(i).first == tobuy) {
					itt = i;
					found = true;
					break;
				} //Sets iterator to item customer wants to buy	
			}
			if (!found) die();
			//cerr << "AFTER ITEM SEARCH" << endl;
			//YOU: Die if the customer doesn't have enough money to pay both for the item's cost and the delivery fee
			if (customers.at(itc).balance < (businesses.at(itb).items.at(itt).second.price + delivery_fee)) die();
			//YOU: Subtract the delivery fee + cost of the item from the customer's bank account
			if (customers.at(itc).balance > (businesses.at(itb).items.at(itt).second.price + delivery_fee)) { //Subtract and equal our customer's balance by the item's price and delivery fee
				customers.at(itc).balance -= (businesses.at(itb).items.at(itt).second.price + delivery_fee);
			}
			//YOU: Add the cost of the item to the business's bank account
			businesses.at(itb).balance += businesses.at(itb).items.at(itt).second.price;
			//YOU: Add the delivery fee to gross (our global variable tracking profit
			gross += delivery_fee;
			//YOU: Print the remaining balance of the customer like this...
			cout << "Purchased. " << customers.at(itc).name << " has " << cents_to_string(customers.at(itc).balance) << " remaining.\n";
			//cout << "Purchased. " << cust << " has " << cents_to_string(customers[cust].balance) << " remaining.\n";
		}
	}
	cout << "Richest Customer and Business:\n";
	if (customers.size() < 1) cout << "No customers.\n";
	else cout << max_element(customers) << endl; //YOU: Make sure max_element works
	if (businesses.size() < 1) cout << "No businesses.\n";
	else cout << max_element(businesses) << endl; //YOU: Make sure max_element works
	cout << "Total gross income for Covid Connect: " << cents_to_string(gross) << endl; //YOU: Make sure cents_to_string works
}

