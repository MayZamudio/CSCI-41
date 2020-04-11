//\g++ -O3 day10.cc
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

class Vec {
	size_t size = 0, cur = 0;
	int *arr = nullptr;
	public:
	void push_back(int x) {
		//Handle base condition
		if (!arr) {
			arr = new int[1];
			size = cur = 1;
			arr[0] = x;
		}
		else {
			//We have room
			if (cur < size) {
				arr[cur++] = x;
			}
			else {
				int *arr2 = new int[size * 2];
				for (size_t i = 0; i < size; i++) {
					arr2[i] = arr[i]; //This is the key line in a vector push_back
				}
				arr2[cur++] = x;
				delete[] arr;
				arr = arr2;
				size *= 2;
			}
		}
	}
};
int main() {
	/*
	Vec vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	*/

	vector<int> vec2;
	clock_t start_time = clock();
	for (size_t i = 0; i < 1'000'000; i++) 
		vec2.push_back(i);
	cout << "Time to push 1M ints without reserve: " << double(clock() - start_time) / CLOCKS_PER_SEC << endl;
	vec2.clear();
	start_time = clock();
	vec2.reserve(1'100'000);
	for (size_t i = 0; i < 1'000'000; i++) 
		vec2.push_back(i);
	cout << "Time to push 1M ints with reserve: " << double(clock() - start_time) / CLOCKS_PER_SEC << endl;
}


























