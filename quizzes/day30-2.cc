#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>
#include <chrono>
using namespace std;
using namespace chrono;
using hrc = high_resolution_clock;

template <typename T>
class Tree {
	struct BST {
		T data;
		BST *left = nullptr, *right = nullptr;
		BST(int new_data) : data(new_data) {}
	} *root = nullptr;

	public:
	void insert(T new_data) {
		if (!root) { //If root is null
			root = new BST(new_data);
			return;
		}
		BST *temp = root;
		while (temp) { //Temp should never be null but never hurts to check
			if (new_data == temp->data) return; //Discard duplicates
			//Go to the left
			else if (new_data < temp->data) {
				//Option 1 - spot is available
				if (temp->left == nullptr) {
					temp->left = new BST(new_data);
					return;
				}
				else temp = temp->left; //Option 2 - spot is available
			}
			//Go to the right
			else {
				if (temp->right == nullptr) {
					temp->right = new BST(new_data);
					return;
				}
				else temp = temp->right; //Option 2 - spot is available
			}
		}
	}

	bool search(T data) {
		if (!root) return false;
		BST *temp = root;
		while (temp) {
			if (data == temp->data) return true;
			else if (data < temp->data) temp = temp->left;
			else temp = temp->right;
		}
		return false;
	}
};

int main() {
	Tree<int> bst;
	cout << "Enter some numbers (\"0\" for done)\n";
	while (cin) {
		int x = 0;
		cin >> x;
		if (!cin) exit(1);
		if (x == 0) break;
		bst.insert(x); //How much time does this take? O(logN)
	}

	cout << "Check to see if a number is in the set:\n";
	int x = 0;
	cin >> x;
	if (!cin) exit(1);
	cout << boolalpha << bst.search(x) << endl;

	//sort(bst.begin(),bst.end()); //O(0)
	/*
	set<int> bst; //Self-balancing BST, Discards duplicates
	//multiset<int> bst; //Keeps duplicates
	cout << "Enter some numbers (\"0\" for done)\n";
	while (cin) {
		int x = 0;
		cin >> x;
		if (!cin) exit(1);
		if (x == 0) break;
		bst.insert(x); //How much time does this take? O(logN)
	}
	//sort(bst.begin(),bst.end()); //O(0)
	for (int x : bst) cout << x << endl; //O(N) or O(NlogN)
	
	cout << "Check to see if a number is in the set:\n";
	int x = 0;
	cin >> x;
	if (!cin) exit(1);

	//Benchmark std::find for bsts
	int start = clock(); //Returns microseconds since program start
	hrc::time_point start2 = hrc::now();
	auto it = find(bst.begin(),bst.end(),x); //Generic find function in std
	hrc::time_point end2 = hrc::now();
	int end = clock();
	cerr << "Clock() time for std::find(): " << end - start << " microseconds\n";
	cerr << "HRC time for std::find(): " << fixed << duration_cast<duration<double>>(end2 - start2).count() << endl;


	//Benchmark set.find()
	start = clock();
	start2 = hrc::now();
	it = bst.find(x); //BST specially optimized find function
	end2 = hrc::now();
	end = clock();
	cerr << "Clock() time for set.find(): " << end - start << " microseconds\n";
	cerr << "HRC time for set.find(): " << fixed << duration_cast<duration<double>>(end2 - start2).count() << endl;

	if (it != bst.end()) {
		cout << "We found " << *it << endl;
	}
	else {
		cout << "We did not find " << x << endl; //This dereferences an iterator to the special end node, which is a guardian value, so it crashes your code, since you should never output it
	}

	//For every doubling of the program size, it does one more work
	//Logarithmic Complexity - the opposite of exponential growth
	//O(2^N) algorithm doubles the amount of work to be done for every one more in N
	//O(logN) algorithm it does one more work for every doubling of the problem size
	vector<int> vec(1'000'000);
	iota(vec.begin(),vec.end(),0); //O(N) - Sets element 0 to 0, 1 to 1, 2 to 2
	//What is the running time of this abomination???
	int count = 0;
	for (size_t i = 1; i < vec.size(); i++) //O(N)
		for (size_t j = 1; j < vec.size(); j *= 2) //O(logN)
			//count++; 
	cout << "Iterations: " << count << endl;
	*/
}
