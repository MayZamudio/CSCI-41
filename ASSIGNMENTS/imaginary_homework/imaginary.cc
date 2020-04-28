#include "imaginary.h"

using namespace std;

Imaginary Imaginary::operator+(const Imaginary& rhs) const {
	return Imaginary(coeff+rhs.coeff); //My coeff is 3; rhs.coeff is 5. So construct a new one with a coeff of 8.
}

Imaginary::Imaginary() { //Default cstor
	coeff = 0;
}

Imaginary::Imaginary(int new_coeff) { //One parameter cstor
	coeff = new_coeff; 
}

int Imaginary::get_coeff() const { //Get function
// return what is in the class 
	return coeff;
}

Imaginary Imaginary::operator-(const Imaginary& rhs) const {
	return Imaginary(coeff-rhs.coeff); 
}

Imaginary Imaginary::operator*(const int& rhs) const {
	return Imaginary(coeff*rhs); //5i * 2 = 10i
}

int Imaginary::operator*(const Imaginary& rhs) const {
	return coeff * rhs.coeff * -1; ; //i * i = -1
}

//This function is functional
Imaginary Imaginary::operator=(const Imaginary& rhs) {
	coeff = rhs.coeff;
	return rhs; 
}

//This function is functional
Imaginary Imaginary::operator=(const int& rhs) {
	coeff = rhs;
	return Imaginary(rhs); 
}

bool Imaginary::operator==(const Imaginary& rhs) const {
	return (coeff == rhs.coeff); 
}

/*
This function is done for you. It will allow you to cout variables of type Imaginary.
For example, in main you could write:
  Imaginary foo(2);
  cout << foo << endl; 
And this would print out "2i"
*/
ostream& operator<<(ostream& lhs, const Imaginary& rhs) {
	lhs << showpos;
	lhs << rhs.coeff << "i"; //Will echo +4i or +0i or -3i or whatever
	lhs << noshowpos;
	return lhs;
}

istream& operator>>(istream& lhs, Imaginary& rhs) {
	int i;
	lhs >> i;
	rhs.coeff = i;
	return lhs;
}

