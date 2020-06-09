#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
using namespace std;

//Array of binary search trees
template <class T, size_t SIZE> 
class HashTable {
	set<T> arr[SIZE] = {}; //C style arrays must be compile time determinable (sorta)
	size_t hash(size_t key) { return key % SIZE; }
	public:
		void insert(T x) { //O(1) (linear probing is O(N) worst case
			size_t address = hash(x);
			arr[address].insert(x);
		}
		bool search(T x) { //O(1)... decreasing to O(N) as the hash table fills up
			size_t address = hash(x);
			return arr[address].find(x) != arr[address].end();
			//return find(arr[address].begin(), arr[address].end(),x) != arr[address].end();
		}
		void remove(T x) { //O(1)... decreasing to O(N) as the hash table fills up)
			size_t address = hash(x);
			auto it = arr[address].find(x);
			//auto it = find(arr[address].begin(), arr[address].end(),x);
			if (it == arr[address].end()) return;
			arr[address].erase(it);
		}
};

int main() {
	//OVERPROVISION BY A FACTOR OF 10
	//So if you want to hold 100 ints, use a hash table of size 1000
	//The standard library would use 110 ints
	HashTable<int,100> hash; //We could spend 16GB of RAM to guarantee O(1) performance
	cout << "Welcome to Hash Table 2000(tm)!\n";
	while (true) {
		cout << "Do you want to 1) insert, 2) search, 3) delete\n";
		int choice = 0;
		cin >> choice;
		if (!cin) exit(1);
		cout << "What number do you want to do this operation on?\n";
		int x = 0;
		cin >> x; //We have the best names, don't we people?
		if (!cin) exit(1);
		if (choice == 1) {
			hash.insert(x);
		}
		else if (choice == 2) {
			cout << boolalpha << hash.search(x) << endl;
		}
		else if (choice == 3) {
			hash.remove(x);
		}
	}
}
