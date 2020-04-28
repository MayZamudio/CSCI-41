#include <iostream>
#include <vector>
using namespace std;

//PODS
struct Pixel {
	int x,y;
};

void image_search(unsigned char *data, int width, int height) {
	vector<Pixel> blues; //YOU: Fill this vector with all the blue pixels, maybe

//	for (int c = 0; c < 3; c++){
	for (int y = 0; y < height; y++){
		for (int x = 0; x < width; x++){
			int red = (int)data[x + y*width];// red is th 0th index so multiple by 0 would remove height*width
			int green = (int)data[x + y*width + height*width];// green is the 1st index so multiple times itself
			int blue = (int)data[x + y*width + 2*height*width];//blue is the 2nd index so multiple by 2 activates this layer
			//cout << "Blue "<< blue << "Red:" << red << "Green: "<< green << endl;
			if (blue >= 236 && red <= 20 && green <= 20)
			blues.push_back({x,y});
		}
	}
//}
	//YOU: Average all the x values fr m blues together into an int x
//	for (auto x : blues) {
//	  cout << "Blues: " << x.x << " " << x.y<< endl;
//	  }

	size_t sumX = 0, sumY = 0;
	for (auto pix : blues) {
		sumX += pix.x;
		sumY += pix.y;
	}
	//YOU: Average all the y values from blues together into an int y

	//Then we print the result and are done

	if (!blues.size()) cout << "No blue found.\n";
	else
		cout << "The center point for blue in this image is: (" << sumX / blues.size() << "," << sumY / blues.size() << ")\n";
}

