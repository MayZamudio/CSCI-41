#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <utility>
using namespace std;

//Inline is a hint to the compiler that it should copy the body of the function into the calling function
//This eliminates the overhead of a function call
//But the compiler can ignore it

inline size_t parent(size_t index) {
	return (index-1)/2;
}

inline size_t left_child(size_t index) {
	return index*2+1;
}

inline size_t right_child(size_t index) {
	return index*2+2;
}

int main() {
	//The cool thing about heaps is that they're basically always done using arrays
	//Heaps are binary trees, but they are not binary search trees.
	//The rule for a min heap is that your parent is smaller than you
	//	and your kids are bigger than you.
	vector<int> heap;
	while (true) {
		cout << "1. Push 2. Pop\n";
		int choice = 0;
		cin >> choice;
		if (!cin or choice < 1 or choice > 2) exit(1);
		if (choice == 1) {
			cout << "Give me a number to insert.\n";
			int number = 0;
			cin >> number;
			//Push number into the heap
			heap.push_back(number);
			//While the class invariant is broken, fix it
			size_t index = heap.size() - 1;
			while (true) {
				//If we hit root we're done
				if (index == 0) break;
				size_t p_index = parent(index);
				//Max heap
				if (heap.at(index) > heap.at(p_index)) {
					swap(heap.at(index),heap.at(p_index));
					index = p_index;
					continue;
				}
				break;
			}
		}
		else if (choice == 2) {
			if (heap.size() == 0) continue;
			auto topval = heap.at(0);
			cout << topval << endl;
			swap(heap.at(0),heap.at(heap.size()-1));
			heap.pop_back();
			//While the class invariant is broken, fix it
			size_t index = 0;
			while (true) {
				size_t l_index = left_child(index);
				size_t r_index = right_child(index);
				//If we ever hit a node with no left kid, we're done
				if (l_index >= heap.size()) break;
				//Special case - one kid
				if (r_index >= heap.size()) {
					if (heap.at(index) < heap.at(l_index)) 
						swap(heap.at(index),heap.at(l_index));
					break;
				}
				//Two kids
				//Find the bigger of the two kids
				size_t c_index = l_index;
				if (heap.at(l_index) < heap.at(r_index)) c_index = r_index;
				if (heap.at(index) < heap.at(c_index)) {
					swap(heap.at(index),heap.at(c_index));
					index = c_index;
				}
				else 
					break;
			}
		}
	}
}
