//Helpful tip: Write your code here
#include <iostream>

using namespace std;

int main() {
	for (int i = 0; i < 100; i++) {
		int num = i + 1;
		if (num % 15 == 0) {
			cout << "FizzBuzz\n";
		} else if (num % 5 == 0) {
			cout << "Buzz\n";
		} else if (num % 3 == 0) {
			cout << "Fizz\n";
		} else cout << num << endl;
	}
}

