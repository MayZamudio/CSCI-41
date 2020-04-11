//1. Write a program that will ask the user if they want to compute the area of
// 1) a square
// 2) a rectangle
// 3) a triangle
// 4) a parallelogram
//EXTRA CREDIT (double the points (2 x 0 = 0))
// 5) SAS triangle
// 6) circle
// 7) trapezoid
//2. Vet the input to make sure it is 1 through 4
// (Remember, to quit, you type exit(0); )
//3. Input the necessary dimensions
//4. Vet the dimensions
//5. Output the area.
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cout << "1) Square, 2) Rectangle, 3) Triangle, 4) Parallelogram\n";
	int choice = 0;
	cin >> choice;
	if (!cin or choice < 1 or choice > 4) {
		cout << "Bad input! Try again.\n";
		exit(1);
	}
	if (choice == 1 or choice == 2 or choice == 4) {
		cout << "Please enter length and width:\n";
		int length = 0, width = 0;
		cin >> length >> width;
		if (!cin || length <= 0 || width <= 0) {
			cout << "Bad input! Try again.\n";
			exit(1);
		}
		cout << "The area is: " << length*width << endl;
	} else {
		cout << "Please enter base and height:\n";
		int base = 0, height = 0;
		cin >> base >> height;
		if (!cin || base <= 0 || height <= 0) {
			cout << "Bad input! Try again.\n";
			exit(1);
		}
		cout << "The area is: " << (base * height) / 2 << endl;
	}
}
