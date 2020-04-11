#include <iostream>
#include <vector>

using namespace std;

void f() {
	static int count = 0;
	count++;
	cout << "Called: " << count << " times\n";
	//heap allocation
	int *arr = new int[100];
	//stack allocation

	int arr2[100];
	f();
}

int main() {

	f();
}
