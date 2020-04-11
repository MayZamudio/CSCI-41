#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

class Bob {
	int x;
	public:
	explicit Bob(int new_x) : x(new_x) {} 
	int get_x() const { return x; }
	void set_x(int new_x) { x = new_x; }
};

//C++ says... hmm, I am supposed to be returning a Bob.
//But I'm getting an int!
//Do I know how to make a Bob from an int???
//YES! Constructors can be used to convert a value implicitly
//C++ will do one free implicit conversion for you!
//ctrl left arrow works!
Bob makea42bob() {
	return 42; //The return value has no name
}

int main() {
	Bob temp = makea42bob();
	cout << temp.get_x() << endl;
}
