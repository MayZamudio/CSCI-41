#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <tuple>
using namespace std;

int main() {
	pair<int,int> bob = {3,5};
	vector<tuple<unsigned char, unsigned char, unsigned char>> all_red_pixels, all_white_pixels;
	all_red_pixels.push_back({in[R(i,j)],in[B(i,j)],in[G(i,j)]});
	long long total_red = 0;
	long long total_blue = 0;
	long long total_gree = 0;
	for (auto pixel : all_red_pixels) {
		total_red += pixel[0];
		total_blue += pixel[1];
		total_gree += pixel[2];
	}
	total_red /= all_red_pixels.size();
	total_blue /= all_blue_pixels.size();
	total_green /= all_green_pixels.size();
}
