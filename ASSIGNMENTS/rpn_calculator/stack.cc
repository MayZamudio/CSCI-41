#include <iostream>
#include <string>
#include <cstdlib>
#include "stack.h"

//If you want to learn more about why it's hard to do separate compilation:
//http://isocpp.org/wiki/faq/templates#templates-defn-vs-decl

		//int top = 0; //Bottom is always index 0
		//T data[max_size];


template <class T,int max_size>
T& Stack<T,max_size>::top() {
	if (empty()) {
		//std::cout << "Stack empty!\n";
		data[0] = {};
		return data[0];
	}
	return data[index];
}

template <class T,int max_size>
void Stack<T,max_size>::push(const T& new_data) {
	if (size() >= max_size) {
		std::cout << "Stack overflow!\n";
		exit(EXIT_FAILURE);
	}
	data[++index] = new_data;
}

template <class T,int max_size>
void Stack<T,max_size>::pop() {
	if (index < 0) {
		std::cout << "Stack underflow!\n";
		exit(EXIT_FAILURE);
	}
	index--;
}
template class Stack<int,1000>;

//Wot.    Specify the types and now you can compile
template class Stack<int,100>;
template class Stack<char,100>;
template class Stack<std::string,100>;
