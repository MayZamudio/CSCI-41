#define cimg_display 0
#include "CImg.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace cimg_library;
using namespace std;

void image_search(unsigned char *data, int width, int height);

int main() {
	//PHASE 1 - Load the image
	string filename;
	cout << "Please enter a URL or file name to load:\n";
	getline(cin,filename);
	//We will think it is an URL if it has http, .com, or www. in it. Hackish but w/e
	bool is_url = false;
	if (filename.find("http") != string::npos) is_url = true;
	else if (filename.find(".com") != string::npos) is_url = true;
	else if (filename.find("www.") != string::npos) is_url = true;
	if (is_url) {
		string command = "wget -O image_file "s + filename + " > /dev/null 2>&1"; //Grabs the image from the interwebs
		system(command.c_str());
		filename = "image_file";
	}
	try {
		CImg<unsigned char> image(filename.c_str());
		int width = image.width(); 
		int height = image.height();
		cout << "Loaded image of size " << width << "x" << height << endl;
		image_search(image, width, height); //Calls the student code
	} catch (CImgIOException e) {
		cout << "Error: Couldn't open that file. Quitting...\n";
		exit(1);
	}
}

