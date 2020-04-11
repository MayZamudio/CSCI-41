#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
	cout << "Shorts range from " << SHRT_MIN << " to " << SHRT_MAX << endl;
	cout << "Unsigned Shorts range from " << 0 << " to " << USHRT_MAX << endl;
	cout << "Ints range from " << INT_MIN << " to " << INT_MAX << endl;
	cout << "Unsigned Ints range from " << 0 << " to " << UINT_MAX << endl;
	cout << "Longs range from " << LONG_MIN << " to " << LONG_MAX << endl;
	cout << "Unsigned Longs range from " << LONG_MIN << " to " << LONG_MAX << endl;
	cout << "Long Longs range from " << LLONG_MIN << " to " << LLONG_MAX << endl;
	cout << "Unsigned Long Longs range from " << 0 << " to " << ULLONG_MAX << endl;
	unsigned short stop = -10; //16 bit number.... usually
	unsigned long long x = 5;
	int w = 5; //Ints pick the fastest type for the system you're on
	int32_t w2 = 5; //This will always be 32 bits
	long y = 12345;
	double z = -0.0001;


	//size_t is of whatever size is needed to address all of memory on your system
	//It will change from platform to platform

	vector<int> vec(1000,42);
	//As long as your array is of size smaller than 2 billion, you'll be okay using an int
	//for (size_t i = 0; i < vec.size(); i++) cout << vec[i] << endl;

	double account = 10.1111111111111111111; //Losing precision makes banks very nervous
	long long account2 = 100000; //These are millicents - this is a dollar
	//Fixed point math - that's how banks do
	cout << setprecision(20) << account << endl;
	cout << account2 << endl;
}


