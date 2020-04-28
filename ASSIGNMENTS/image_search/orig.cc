#include <iostream>
#include <vector>
using namespace std;

//PODS
struct Pixel {
	int x,y;
};

void image_search(unsigned char *data, int width, int height) {
	vector<Pixel> blues; //YOU: Fill this vector with all the blue pixels, maybe
	//YOU: Remove the couts here once you understand what is happening
	for (int c = 0; c < 3; c++) { //For each color...
		if (c == 0) cout << "RED:\n";
		else if (c == 1) cout << "GREEN:\n";
		else cout << "BLUE\n";
		for (int y = 0; y < height; y++) { //For each row...
			for (int x = 0; x < width; x++) { //For each column...
				//This is how you grab the brightness of color c at location (x,y):
				cout << (int)data[x + y*width + c*height*width] << " "; //Output the color value there
				if (isbluefsfsdfdfds)
					blues.push_back({x,y});
			}
			cout << endl;
		}
		cout << "====================================\n";
	}
	//YOU: Average all the x values from blues together into an int x
	//YOU: Average all the y values from blues together into an int y

	//Then we print the result and are done
	if (count == 0) cout << "No blue found.\n";
	else
		cout << "The center point for blue in this image is: (" << x << "," << y << ")\n";
}

