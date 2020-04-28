#pragma once
#include <list>
#include <algorithm>
#include "ll.h"
#include <vector>
#include <iostream>
using namespace std;

//This is a class to implement a queue
//You must implement it three different ways.
//You can use the standard library for two of them, but you have to write it yourself one of the ways
//You can't use the queue class or the deque class from the standard library
//Possibilities include:
//1) Using the list<> class from the STL (or forward_list)
//2) Using the vector<> class (what will this do to performance?)
//3) Writing a circular array
//4) Writing your own linked list class (you can borrow from an earlier assignment if you want) 
//5) Writing it yourself some other way
//Remember to #include whatever STL class you use
template <typename T>
class Queue {
	vector<T>vec;//Vec from STD Lib
	list<T>list_a;//List from STD Lib
	List<T>list_b;//List from EU4
	public:
	//Edit these if you like
	static const int STD_LIST_MODE = 0;
	static const int STD_VECTOR_MODE = 1;
//	static const int CIRCULAR_ARRAY_MODE = 2;
	static const int MY_LIST_MODE = 2;
//	static const int MY_MODE = 4;
//	int mode = CIRCULAR_ARRAY_MODE;
	int mode = MY_LIST_MODE;
	//The constructor will choose which mode you'll use on the back end
	Queue(int new_mode) : mode(new_mode) {}

	//You'll need to write these for all three methods
      size_t size() const {
          if (mode == STD_LIST_MODE) {
              if (list_a.size() <= 0) return 0;
			  return list_a.size();
          }
          if (mode == STD_VECTOR_MODE) {
			  if (vec.size() <= 0) return 0;
              return vec.size();
          }
          if (mode == MY_LIST_MODE) {
			  if (list_b.get_size() <= 0) return 0;
              return list_b.get_size();
          }
          return 0;
      }

	void print_queue() const {
		if (size() <= 0) {
			cout << "EMPTY QUEUE\n";
			return;
		}
		int counter = 0;
		counter++;
		//Node 0: 2
		if (mode == STD_LIST_MODE) {
			for (T x : list_a) {
			cout << "Node " << counter++ << ": " << x << endl;
			}
		}
		if (mode == STD_VECTOR_MODE) {
			for (T x : vec) {
			cout << "Node " << counter++ << ": " << x << endl;
			}
		}
        if (mode == MY_LIST_MODE)  {
			cout << list_b.print_list() << endl;
        }
	
	}
	T pop() {
	T x;
	if (mode == STD_LIST_MODE) {
		if (list_a.size() <= 0) return 0;
		else {
		x = list_a.front();
		list_a.pop_front();
		}
	}
	if (mode == STD_VECTOR_MODE) {
		if (vec.size() <= 0) return 0;
		else {
		reverse(vec.begin(), vec.end());
		x = vec.back();
		vec.pop_back();
		reverse(vec.begin(), vec.end());
		}
	}
	if (mode == MY_LIST_MODE) {
		if (list_b.get_size() <= 0) return 0;
		else {
		x = list_b.pop();	
		}
	}
		return {x};
	}
	void push(T new_data) {
		if (mode == STD_LIST_MODE){
			list_a.push_back(new_data);
		}
		if (mode == STD_VECTOR_MODE) {
			vec.push_back(new_data);
		}
		if (mode == MY_LIST_MODE) {
			list_b.push_back(new_data);
		}
	}
	bool search(const T test_data) {
          if (mode == STD_LIST_MODE){
             auto iter = find (list_a.begin(), list_a.end(), test_data);
			 if (iter != list_a.end()) return true; 
          }
		  if (mode == STD_VECTOR_MODE) {
		  	for (T x : vec) {
			if (x == test_data) return true;
			}
		  }
		  if (mode == MY_LIST_MODE) {
		  	return list_b.search(test_data);
		  }
		return false;
	}
	bool remove (T old_data) {
		bool return_value = search(old_data);
		if (mode == STD_LIST_MODE) {
			list_a.erase(find(list_a.begin(), list_a.end(), old_data));
		}
		if (mode == STD_VECTOR_MODE) {
			vec.erase(find(vec.begin(), vec.end(), old_data));
		}
		if (mode == MY_LIST_MODE) {
			list_b.remove(old_data);
		}
		return return_value;
	}

	//Don't worry about these - it just means not to allocate default
	// functions for the copy constructor or assignment operator
	//We do this to follow the rule of three 
	Queue(const Queue&) = delete;
	Queue operator=(const Queue&) = delete;
};
