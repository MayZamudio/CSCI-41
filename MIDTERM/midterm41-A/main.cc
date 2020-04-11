#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

struct Color {
	unsigned char R, G, B;
};

bool sort_by_red(const Color &x, const Color &y) {
	return x.R < y.R;
}
bool sort_by_green(const Color &x, const Color &y) {
	return x.G < y.G;
}
bool sort_by_blue(const Color &x, const Color &y) {
	return x.B < y.B;
}
//YOU: What operator should this be to get the code to work?
Color operator+(const Color &x, const Color &y) {
	return {(unsigned char)(x.R + y.R), (unsigned char)(x.G + y.G), (unsigned char)(x.B + y.B)};
}
ostream &operator <<(ostream &outs, const Color &x) {
	outs << "(" << (int)x.R << "," << (int)x.G << "," << (int)x.B << ")";
	return outs;
}

int main() {
	const int SWATCHES = 10;
	cout << "Welcome to the Color Swatch 2000(tm) color generation system\n";
	cout << "Testing the color mixing system now:\n";
	Color x = {30, 0, 50}, y = {50, 50, 50};
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	Color z = x + y;
	cout << "x+y: " << z << endl;

	cout << "Please enter a random seed:\n";
	int seed = 0;
	cin >> seed;
	if (!cin) exit(1);
	srand(seed);

	vector<Color> swatches;
	for (int i = 0; i < SWATCHES; i++) {
		Color temp = {(unsigned char)(rand() % 256), (unsigned char)(rand() % 256), (unsigned char)(rand() % 256)};
		cout << "Color Swatch " << i << ": " << temp << endl;
		swatches.push_back(temp);
	}
	sort(swatches.begin(), swatches.end(), sort_by_red);
	cout << "The least red swatch: " << swatches.front() << endl;
	cout << "The most red swatch: " << swatches.back() << endl;
	sort(swatches.begin(), swatches.end(), sort_by_green);
	cout << "The least green swatch: " << swatches.front() << endl;
	cout << "The most green swatch: " << swatches.back() << endl;
	sort(swatches.begin(), swatches.end(), sort_by_blue);
	cout << "The least blue swatch: " << swatches.front() << endl;
	cout << "The most blue swatch: " << swatches.back() << endl;
}
