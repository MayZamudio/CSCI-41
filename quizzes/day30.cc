#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>
#include <chrono>
using namespace std;
using namespace std::chrono;
using hrc = std::chrono::high_resolution_clock; //HRC is an alias

template <class T>
class Tree {
	struct BST {
		T data = {};
		BST *left = nullptr, *right = nullptr;
		BST(T new_data) : data(new_data) {}
	} *root = nullptr;

	public:
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

	void insert(T new_data) {
		if (!root) { //If root is empty
			//Make a new node in root with the data and null kids
			root = new BST(new_data);
			return;
		}
		BST *temp = root;
		while (temp) {
			if (new_data == temp->data) { //Duplicate
				return;
			}
			else if (new_data < temp->data) {
				//Check to see if the spot is available, and if it is insert
				if (temp->left == nullptr) {
					temp->left = new BST(new_data);
					return;
				}
				//If not, we move temp down to the left and repeat
				temp = temp->left;
			}
			else {
				//Check to see if the spot is available, and if it is insert
				if (temp->right == nullptr) {
					temp->right = new BST(new_data);
					return;
				}
				//If not, we move temp down to the left and repeat
				temp = temp->right;
			}
		}
	}
};

int main() {
	Tree<string> bst;
	cout << "Who do you want to invite to your wedding reception? (\"DONE\" to be done)\n";
	while (true) {
		string s;
		cin >> s;
		if (!cin) exit(1);
		if (s == "DONE") break;
		bst.insert(s); //STD uses a balancing BST, so all operations are O(logN)
	}
	cout << "Check the list:\n";
	string s;
	cin >> s;
	cout << boolalpha << bst.search(s) << endl;


	/*
	//Any time a doubling of work results in just one more step, it is O(logN)
	//With O(2^N) code, every extra element you add to vec doubles the work you do
	vector<int> vec(800);
	iota(vec.begin(),vec.end(),0);
	for (int x : vec) cout << x << endl; //O(N)

	for (size_t i = 1; i < vec.size(); i *= 2) cout << vec.at(i) << endl; //O(logN)

	//What is the Big O for the whole loop now? 
	for (size_t j = 1; j < vec.size(); j++) //O(N)
		for (size_t i = 1; i < vec.size(); i++) //O(N)
			sort(vec.begin(),vec.end()); //O(NlogN)

	set<string> bst; //Discard duplicates
	//multiset<string> bst; //Allow duplicates
	cout << "Who do you want to invite to your wedding reception? (\"DONE\" to be done)\n";
	while (true) {
		string s;
		cin >> s;
		if (!cin) exit(1);
		if (s == "DONE") break;
		bst.insert(s); //STD uses a balancing BST, so all operations are O(logN)
	}
	//Print everything in the binary search tree - O()?????
	for (string s : bst) cout << s << endl; //Either O(N) or it is O(NlogN)

	//How long does it take to sort a BST? O(0)
	//sort(bst.begin(),bst.end()); 

	cout << "Remove someone from the list:\n";
	string s;
	cin >> s;
	hrc::time_point start = hrc::now(); //This saves the starting time (start a stopwatch)
	auto it = find(bst.begin(),bst.end(),s);
	hrc::time_point stop = hrc::now(); //This saves the ending time
	cerr << "Running time for std::find: " << fixed << duration_cast<duration<double>>(stop - start).count() << endl;

	start = hrc::now();
	it = bst.find(s);
	stop = hrc::now();
	cerr << "Running time for set.find: " << fixed << duration_cast<duration<double>>(stop - start).count() << endl;

	if (it != bst.end()) {
		cout << *it << " is on the invite list!\n";
		bst.erase(it);
	}
	else cout << s << " is not on the list!\n";

	//Print everything in the binary search tree - O()?????
	cout << "New list:\n";
	for (string s : bst) cout << s << endl; //Either O(N) or it is O(NlogN)


	//lvalues are anything that can appear on the left side of an assignment (=) operation
	//rvalues are things that appear on the right side of an =
	//rvalues include things like literals, but also temps that are the result of an expression
	*/
}
