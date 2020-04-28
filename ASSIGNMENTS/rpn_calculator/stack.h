#pragma once
//If you want to learn more about why it's hard to do separate compilation:
//http://isocpp.org/wiki/faq/templates#templates-defn-vs-decl

template <class T,int max_size>
class Stack {
		int index = -1; //Empty is -1, otherwise is index of top element
		T data[max_size];
	public:
		Stack() {} //Note it's not Stack<T>
		bool empty() {return index == -1; }
		int size() { return index + 1; }
		T& top(); 
		void push(const T& new_data);
		void pop(); 
};
