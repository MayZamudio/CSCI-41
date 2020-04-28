//#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <unordered_map>
#include <set>
#include <array>
using namespace std;

//Custom hash function that just hashes strings based on their size
class SakanaHash {
	public:
		size_t operator() (string s) {
			return s.size();
		}
} smh;

template <class T, size_t size>
class HashTable {
	array<set<T>,size> arr;
	public:
	void insert(const T& new_data) {
		hash<T> hasher; //Uses the built in hash function from the STL
		//If you wanted to use your own hash function, it'd be done like this...
		//size_t bucket = smh(new_data) % size; //Uses SakanaHash
		size_t bucket = hasher(new_data) % size;
		cout << "Inserting " << new_data << " into bucket " << bucket << endl;
		arr.at(bucket).insert(new_data);
	}
	bool search(const T& new_data) {
		hash<T> hasher;
		size_t bucket = hasher(new_data) % size;
		cout << "Searching for " << new_data << " in bucket " << bucket << endl;
		auto it = arr.at(bucket).find(new_data);
		if (it == arr.at(bucket).end()) return false;
		return true;
	}
	bool remove(const T& new_data) {
		hash<T> hasher;
		size_t bucket = hasher(new_data) % size;
		cout << "Deleting " << new_data << " from bucket " << bucket << endl;
		auto it = arr.at(bucket).find(new_data);
		if (it == arr.at(bucket).end()) return false;
		arr.at(bucket).erase(it);
		return true;
	}
};

auto foo(auto x) {
	cout << x.size() << endl;
	//cout << x << endl;
	return x;
}

//Auto Anywhere (AA)
//Auto Almost Anywhere (AAA)
int main() {
	//auto y = foo(0b11011011);
	auto v = foo(vector{1,2,3,4,5});
	auto s = foo("Hello World"s);
	cout << s.length();
	vector vec = {1,2,3,4,5};
	HashTable<string,100> ht;
	ht.insert(s);
	s = "Rocky Mountain Oysters";
	ht.insert(s);
	ht.insert("Hello World!");
	ht.insert("Hello Applesauce!");
	ht.insert("B");
	cout << boolalpha;
	cout << ht.search("Hello World!") << endl;
	cout << ht.search("Hello Applesauce!") << endl;
	cout << ht.search("👏") << endl;
	cout << ht.remove("Hello Applesauce!") << endl;
	cout << ht.remove("👏") << endl;
	cout << ht.search("Hello World!") << endl;
	cout << ht.search("Hello Applesauce!") << endl;
	cout << ht.search("👏") << endl;
}
