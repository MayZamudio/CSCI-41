#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <climits>
#include <optional>
#include "/public/colors.h"
using namespace std;

//Pointer way
class Node {
	public:
		Node *left, *right; //64 bit pointers or 8 bytes
		int32_t data; //4 bytes
		//4 bytes of padding
};

int main() {
	//How much memory does it take to hold a vector of 1000 ints?
	//int *data, int arr[1000]; //The pointer is 8 bytes, and the array will be between 4000 and 8000 bytes
	//size_t size; //8 bytes
	//How much memory does it take to hold 1000 pointer based nodes in a BST?
	//24 bytes per node * 1000 nodes = 24000 bytes

	//When things are contiguous in memory, the memory system can access it faster
	//"Cache coherency" or "being memory friendly"

	//Pros of the array based method - less memory usage*, faster memory access, no need for pointers, you can access a child or parent just by using math
	//Cons??? If you have an unbalanced BST, to hold N elements requires O(2^N) memory!!@!!!!!
	//So here's the rule - If you have a balanced BST, use the array method. If you have an unbalanced or sparse tree use pointers.
	vector<int> vec(1024, INT_MIN); //We use INT_MIN as a magic number to mean nothing is there
	vec.at(0) = 5; //Root
	vec.at(1) = 3; //Left child of the root
	vec.at(2) = 10; //Right child of the root
	vec.at(5) = 7; //Left kid of index 2
	vec.at(6) = 20; //Right kid of index 2

	//Basically all the code is the same except your temp = temp->left becomes index = index*2 + 1 or whatever
	//Rather than checking for temp being null, you check to see if you have the MAGIC NUMBER (boo hiss) there

	//Do BST search using the array method here
	cout << "Please enter an int to search for:\n";
	int x = 0;
	cin >> x;
	size_t index = 0; //Start at the root
	while (index < vec.size()) {
		if (vec.at(index) == x) {
			cout << "It's in the tree!\n";
			break;
		}
		if (vec.at(index) == INT_MIN) {
			cout << "It's not in the tree!\n";
			break;
		}
		if (x < vec.at(index)) index = index*2 + 1; //This is the algebra for moving to the left kid in the tree
		else index = index*2 + 2; //This is the algebra for moving to the right kid in the tree
	}
}
