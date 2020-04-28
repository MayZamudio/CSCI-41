#pragma once
#include <iostream>
using namespace std;

class Imaginary {
	private:
		int coeff; //If 5, then means 5i
	public:
		Imaginary();
		Imaginary(int new_coeff);
		int get_coeff() const;
		Imaginary operator+(const Imaginary& rhs) const; //This is a "constant method"
		Imaginary operator-(const Imaginary& rhs) const;
		int       operator*(const Imaginary& rhs) const;
		Imaginary operator*(const int& rhs) const;
		Imaginary operator=(const int& rhs); 
		Imaginary operator=(const Imaginary& rhs); 
		bool      operator==(const Imaginary& rhs) const; 
		friend ostream& operator<<(ostream& lhs, const Imaginary& rhs);
		friend istream& operator>>(istream& lhs, Imaginary& rhs);
};
