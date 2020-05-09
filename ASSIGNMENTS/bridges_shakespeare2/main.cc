#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cctype>
#include <string>
#include <unordered_map>
#include "Bridges.h"
#include <Array1D.h>
#include <tuple>

using namespace std;
using namespace bridges;

template <class T> 
// Data structure for Min Heap
class Heap {
	private:
		//vector to store heap elements
		vector<T> heap;
		//Return parent
		inline size_t parent(size_t index) {
			return (index-1)/2;
		}
		//Return left child
		inline size_t getLeftChild(size_t index) {
			return index*2+1;
		}
		//Return right child
		inline size_t getRightChild(size_t index) {
			return index*2+2;
		}
	public:
		size_t getSize() {
			return heap.size();
		}
		// insert key into the heap
		void push(T value) {
			heap.push_back(value);
			size_t index = heap.size() - 1;
            while (true) {
				//If we hit root we're done
                if (index == 0) break;
                size_t p_index = parent(index);
                if (heap.at(index) > heap.at(p_index)) {
                    swap(heap.at(index),heap.at(p_index));
                    index = p_index;
                    continue;
                }
                break;
            }

		}
		// function to remove element
		T pop() {
            T topval = heap.at(0);
            int root = 0;
			int last = heap.size() - 1;
            swap(heap.at(root),heap.at(last));
            heap.pop_back();
            size_t index2 = 0;
            while (true) {
                size_t l_index = getLeftChild(index2);
                size_t r_index = getRightChild(index2);
				//If we ever hit a node with no left kid, we're done
                if (l_index >= heap.size()) break;
				//Special case - one kid
                if (r_index >= heap.size()) {
                    if (heap.at(index2) < heap.at(l_index))
                        swap(heap.at(index2),heap.at(l_index));
                    break;
                }
				//Two kids
				//Find the bigger of the two kids
                size_t c_index = l_index;
                if (heap.at(l_index) < heap.at(r_index)) c_index = r_index;
                if (heap.at(index2) < heap.at(c_index)) {
                    swap(heap.at(index2),heap.at(c_index));
                    index2 = c_index;
                }
                else
                    break;
            }
			return topval;
		}
};

struct Word {
	string str;
	int count = 1;
};

//Sort greatest to smallest by count
bool operator<(const Word &w1, const Word &w2) {
	//YOU
	if (w2.count > w1.count) return true;
	if (w1.count == w2.count) {
		if (w1.str > w2.str) return true;
		else return false;
	}
	else return false;
	    if (w1.count == w2.count) return (w1.str < w2.str);
    return (w1.count > w2.count);
}
bool operator>(const Word &w1, const Word &w2) {
	//YOU
	if (w2.count < w1.count) return true;
	if (w1.count == w2.count) {
		if (w1.str < w2.str) return true;
		else return false;
	}
	else return false;
}

ostream &operator<<(ostream &outs, const Word &w) {
	outs << w.str << ": " << w.count;
	return outs;
}

int main() {
	const int TOP = 30; //Show top 30 words
	Bridges *bridges =  new Bridges(47, "mzamudio", "614923477058");
	//Use a hash table to count words
	unordered_map<string,Word> hist;
	//Use a vector to sort the words by count
	Heap<Word> heap;
	while (true) {
		cout << "Enter the name of a file to open (DONE to be done):\n";
		string filename;
		cin >> filename;
		if (filename == "done" or filename == "DONE") break;
		ifstream ins(filename); 
		if (!ins) { 
			cout << "Error opening file.\n";
			continue;
		}
		while (ins) {
			string s;
			string s2;
			ins >> s;
			if (!ins) break;
			s.erase(remove_if(s.begin(), s.end(), [](char c) { return !isalpha(c); } ), s.end());
			if (s.size() < 4) continue;
			if (hist.count(s) >= 1) hist[s].count++;
			else hist[s] = {s,1};
	}
}
	//Convert the hash table into a vector of results and sort it by count
	//for (auto x : hist) vec.push(x.second);
	for (auto x : hist) heap.push(x.second);
//	sort(vec.begin(),vec.end()); //YOU: This won't work until you implement operator<
	Array1D<Word> arr(heap.getSize() < TOP ? heap.getSize() : TOP);
	//Print the top 30 and copy them into bridges array
	if (TOP > heap.getSize()) cout << heap.getSize() << endl;
	else cout << TOP << endl;
	int heapsize = heap.getSize();
	for (int i = 0; i < TOP and i < heapsize; i++) {
	Word temp = heap.pop();
        cout << temp << endl;
        //Copy from the vec into our BRIDGES array
        arr[i] = temp;
        string s = temp.str;
        //string s = heap.pop().str;
        int count = temp.count;
        //int count = heap.pop().count;
        arr.getElement(i).setLabel(s+"\n"+to_string(count));
        //YOU: Words with a count over 100 get colored red
        if (count >= 100) arr.getElement(i).setColor("red");
        //YOU: Words with a count over 10 get colored yellow
        else if (count >= 10) arr.getElement(i).setColor("yellow");
        //YOU: Words with a count over 1 get colored green
        else if (count >= 1) arr.getElement(i).setColor("green");
        //Else go with white
        else arr.getElement(i).setColor("white");

	}
    bridges->setDataStructure(arr);
    //bridges->visualize(); //YOU: When done, put the hyperlink this prints into Canvas for me to view for 3 points
}

