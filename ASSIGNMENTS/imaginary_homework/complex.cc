#include <iostream>
#include "complex.h"
using namespace std;

/*
Class definition file for Complex

YOU: Fill in all of these functions
There are stubs (fake functions) in there now so that it will compile
The stubs should be removed and replaced with your own code.
*/
Complex::Complex() {
	//Default cstor
	real = 0;
	imagine = 0;
}

Complex::Complex(int new_real, Imaginary new_imagine) {
	//Two-parameter cstor
	real = new_real;
	imagine = new_imagine;
}

Complex Complex::operator+(const Complex &rhs) {
//FIX: Test 17 "10 10 + 20 '\n'" BUT causes bugs for 0
/*	if (rhs.imagine == 0){
		cout << -1 << endl;
		exit(1);
	} else*/ return Complex(real + rhs.real, imagine + rhs.imagine);
}

Complex Complex::operator-(const Complex &rhs) {
	return Complex(real - rhs.real, imagine - rhs.imagine);
}
/* 
Multiplying imaginary numbers: (1+4i)(5+i) = (1)(5)+(1)(i)+(4i)(5)+(4i)(i)
*/
Complex Complex::operator*(const Complex &rhs) {
/*  https://pocketstudyblog.wordpress.com/2017/04/24/c-program-to-add-subtract-multiply-divide-two-complex-numbers/
 	complex complex::operator*(complex c1) {
		return complex(((r*c1.r)-(i*c1.i)),((r*c1.i)+(i*c1.r)));
	}
	return Complex((real * rhs.real) + (imagine * rhs.imagine), (real * rhs.imagine) + (imagine * rhs.real));
	CANT DO THIS: invalid operands to binary expression ('int' and 'const Imaginary')
	TO GET AN INT VALUE:
	//int Imaginary::get_coeff() const { //Get function */
	return Complex((real * rhs.real) + (imagine * rhs.imagine), (real * rhs.imagine.get_coeff()) + (imagine.get_coeff() * rhs.real));	
}
bool Complex::operator==(const Complex &rhs) {
	return (real == rhs.real && imagine == rhs.imagine);
}

Complex Complex::operator^(const int &exponent) {
	Complex num1(real, imagine), num2(real, imagine);
	for (int i = 1; i < exponent; i++)
		num1 = num1 * num2;
	return num1;
}
//This function should output 3+5i for Complex(3,5), etc.
ostream& operator<<(ostream &lhs,const Complex& rhs) {
	//Output a Complex here
	return lhs << rhs.real << rhs.imagine << noshowpos;
}

//This function should read in two ints, and construct a new Complex with those two ints
istream& operator>>(istream &lhs,Complex& rhs) {
/*	https://simplecplusplus.wordpress.com/tag/peek/
The peek() function looks into the input stream and tells us what the next
character is without removing it from the input stream. Moreover, the peek() 
function can store the character in a designated memory locatio without 
actually removing it from the stream.
The (ios::failbit) triggers the (!cin)
*/
	lhs >> rhs.real;
	char c = lhs.peek();
	if (c == '\n') lhs.setstate(ios::failbit);
	lhs >> rhs.imagine;
	return lhs;
/*  FIRST ATTEMPT AT TEST 17 but '\n' and 0x0a and 10 are all same so caused bugs on the int(10)
	lhs >> rhs.real;
	lhs >> rhs.imagine;
	
	if (rhs.real == 0x0a && rhs.imagine == 0x0a) {
		cout << -1 << endl; exit(1);
		} else {return lhs;}
*/	
//	return lhs >> rhs.real >> rhs.imagine;
}

