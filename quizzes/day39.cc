#include <iostream>
#include <vector>
#include <set>
using namespace std;

template <class T, size_t SIZE = 100>
class HashTable {
	//Code will go here
	//Hold at most 100 integers or whatever
	T arr[SIZE] = {}; //Our code won't handle 0's properly
	size_t hash(size_t key) { return key % SIZE; }
	size_t count = 0; //How many people are inserted
	public:
		//Key concept for today - the spot in the arr we insert the T into is the value % size
		//Example: we are inserting the value 1234 into a hash table of size 100, it will be inserted into spot 1234 % 100 = 34
		//Let's say you try inserting -1 which becomes 324432423432423243243423 % 100 = 23;
		//There are things called COLLISIONS in hash_tables, and how you handle them is the sticking point
		void insert(T new_t) { //You want more speed? USE MORE RAM
			if (search(new_t)) return; //Discard duplicates
			if (count >= SIZE) return; //Array is full, no room at the inn
			size_t address = hash(new_t);
			//Linear probing - check the next door
			while (arr[address]) { //We got a collision on room 34, try room 35
				address = (address + 1) % SIZE;
			}
			arr[address] = new_t;
			count++;
		}
		//Is the number 1234 in our hash table?? We check spot 34 (because 1234 % 100 = 34) 
		//So if 1234 is inside spot 34, then this code returns true, otherwise false
		bool search(T other_t) {
			size_t address = hash(other_t);
			//Linear probing - check the next door
			while (arr[address]) { //We got a collision on room 34, try room 35
				if (arr[address] == other_t) return true;
				address = (address+1) % SIZE;
				//Handle a full hash table
				if (address == hash(other_t)) //We've wrapped around back to the starting spot
					return false;
			}
			return false;
		}
		void delet(T other_t) {
			return;
			if (search(other_t)) {
				arr[hash(other_t)] = 0;
				count--;
			}
		}
};

int main() {
	vector<int> vec; //O(1) insert at end, O(N) insert anywhere else, O(N) search, O(1 or N) delete from the end or anywhere else
	set<int> s; //O(logN) insert, search, delete
	//HashTables trade off increased RAM usage for faster running time
	//RULE OF THUMB for LINEAR PROBING = use 10x the RAM that you'll need
	//Questions? Do you understand the tradeoffs for hash tables??
	HashTable<int,100> table; //O(1) insert, search, delete... at first. Slows down to O(N) as the load goes up. Load is the % full the hash table is.
	while (true) {
		cout << "Do you want to 1) insert, 2) search or 3) delete?\n";
		int choice = 0;
		cin >> choice;
		cout << "What int?\n";
		int x = 0;
		cin >> x;
		if (!cin) exit(1);
		if (choice == 1) {
			table.insert(x); //O(1)
		}
		else if (choice == 2) {
			cout << boolalpha << table.search(x) << endl; //O(1)
		}
		else if (choice == 3) {
			table.delet(x); //O(1)
		}
		else exit(0);
	}
}
