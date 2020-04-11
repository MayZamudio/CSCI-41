//shift-2 m (@m)
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

class Point {
	public:
		float x,y,z;
		void print() {
			cout << x << " " << y << " " << z << endl;
		}
		float distance() {
			return sqrt(x*x + y*y + z*z);
		}
		Point operator+(Point other) {
			Point retval = {x+other.x,y+other.y,z+other.z};
			return retval;
		}
		Point operator*(float multiplier) {
			return {x * multiplier, y * multiplier, z * multiplier};
		}
};


int main() {
	//Make two points, one initialized to {3,10,100}, the other to {1,2,3}
	Point first;
	cin >> first.x >> first.y >> first.z;
	first.print();
	cout << "First is " << first.distance() << " from zero.\n";
	Point second = {3,4,0};
	second.print();
	cout << "Second is " << second.distance() << " from zero.\n";
	//Make a third variable equal to their sum (will be 4,12,103)
	Point third = first+second;
	third.print();
	cout << "Speeding up by 50%!\n";
	third = third * 1.5; //Speed up by 50%
	third.print();
}



