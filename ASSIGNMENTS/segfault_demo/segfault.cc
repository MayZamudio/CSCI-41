#include <iostream>
#include <fstream>
using namespace std;

int main() {
	cout << "Type 'unlimit coredumpsize' to enable core dumping.\n";
	int x = 0, y = 5;
	for (int i = 0; i < y; i++) {
		cout << x << endl; //WHY U NO PRINT??
		x = x + y;
	}

	ofstream outfile("outfile.txt");
	for (int i = 0; i < y; i++) {
		outfile << x;
		x = x + y;
	}
	outfile.close();

	char *s = "Hello World!";
//	*s = "Goo\n";
	cout << s;
	return 0;
}
