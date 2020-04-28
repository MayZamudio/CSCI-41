#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <stack>
#include "stack.h"
using namespace std;

void die(int x = 0) {
	cout << "BAD INPUT " << x << "\n";
	//	cout << "BAD INPUT\n";
	exit(EXIT_FAILURE);
}

int main() {
	int operand;
	char operat;
	bool seen_an_e = false; //The user must enter at least one E in the input or die
	//This will only work for the specializations of stack in stack.cc...
	Stack<int,100> my_stack; //You can replace this with stack<int> my_stack to use the STL instead
	while (cin) {
		cin >> ws; //Eat whitespace
		int c = cin.peek();
		//Peek at next letter to read
		if (c == EOF) break; 
/*		if (c == '-') {
			int n;
			cin >> operat;
			if (cin.peek() != ' '){
				cin >> n;
				my_stack.push(n*-1);
				continue;
				//				c = cin.peek();
					if (isdigit(c)){
					isNeg = true;
				//cerr << "negative subtraction\n";
				} else {
				cin.putback(n);
				}
			}
		}*/
	//Type ctrl-d to send an EOF
		if (!isdigit(c)) { //Should be +,-,*,/,%,^,E
			cin >> operat;
			if (operat != 'E' && my_stack.size() < 2) die(5);
			//	if (my_stack.size() < 2) die(9);
			if (operat == '+'){
				int x = my_stack.top();
				my_stack.pop();
				int y = my_stack.top();
				my_stack.pop();
				my_stack.push(y + x);
			}
			else if (operat == '-'){
//				if (c == '-') {
					int n; 
//					cin >> operat; 
					if (cin.peek() != ' '){
						cin >> n;
						my_stack.push(n*-1);
						continue;
						//              c = cin.peek();
						/*  if (isdigit(c)){
							isNeg = true;
						//cerr << "negative subtraction\n";
						} else {
						cin.putback(n);
						}*/
					} else{

					//operat = '-';
					int x = my_stack.top();
					my_stack.pop();
					int y = my_stack.top();
					my_stack.pop();
					my_stack.push(y-x);
					}
				}
				else if (operat == '*'){
					int y = my_stack.top();
					my_stack.pop();
					int x = my_stack.top();
					my_stack.pop();
					my_stack.push(y*x);
				}
				else if (operat == '/'){
					int x = my_stack.top();
					my_stack.pop();
					int y = my_stack.top();
					my_stack.pop();
					if (x == 0) die(6);
					my_stack.push(y/x);
				}
				else if (operat == '%'){
					int x = my_stack.top();
					my_stack.pop();
					int y = my_stack.top();
					my_stack.pop();
					if (x == 0) die(7);
					my_stack.push(y%x);
				}
				else if (operat== '^'){
					int x = my_stack.top();
					my_stack.pop();
					int y = my_stack.top();
					if (x == 0 && y == 0) die(8);
					my_stack.pop();
					my_stack.push(pow(y,x));
				}
				else if (operat == 'E') {
					seen_an_e = true;
					cout << "stack size:" << my_stack.size();
					if (my_stack.size() == 1) cout << my_stack.top();
					else die(1);
				} else die(2);//YOU: Code this section
			}
			else { //isdigit(c)

				cin >> operand;
				/*	if (isNeg){
					operand *= -1;
					isNeg = false;
					}*/
				my_stack.push(operand);
			}
		} if (!seen_an_e) die(3);
		//Once we get here, we're at the end of the file
		//Do some final checks
		//YOU: Code this section
	}

