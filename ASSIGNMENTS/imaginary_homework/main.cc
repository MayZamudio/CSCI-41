#include <iostream>
#include "imaginary.h"
#include "complex.h"
//YOU: include the header file for complex numbers

using namespace std;

void die() {
	cout << "-1" << endl;
	exit(1);
}

int main() {
	Complex i, j; 

	while (true) {
		string mathOp = "";
		int exponent = 0;
		cin >> i;
		//YOU: If it is 0 0, then break or exit
		if (i == Complex(0, 0)) {
			exit(EXIT_SUCCESS);
		}
		cin >> mathOp;
		if (mathOp == "^")
			cin >> exponent;
		else cin >> j;
		if(!cin) die();
		//YOU: Read in an operator (+,-,*,==,or ^)
        //YOU: Read in the second operand (another complex or an int)
        //YOU: Output the result
		if (mathOp == "==")
			cout << boolalpha << (i == j) << endl;
		else if (mathOp == "+")
			cout << (i + j) << endl;
		else if (mathOp == "-")
			cout << (i - j) << endl;
		else if (mathOp == "*")
			cout << (i * j) << endl;
		else if (mathOp == "^")
			cout << (i ^ exponent) << endl;
		else
			die();
	}
}
