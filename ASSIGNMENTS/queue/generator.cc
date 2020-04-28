#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char **argv) {
	//cout << argc << endl;
	if (argc != 3) {
		cout << "USAGE: Run the generator program with a command line parameter for how many entries it should make, and the filename to write to.\n";
		cout << "Example: " << argv[0] << " 10000 pushsearch10k\n";
		exit(1);
	}
	int count = atoi(argv[1]);
	if (count < 1) {
		cout << "Bad count, ah hah hah.\n";
		exit(1);
	}

	ofstream output_file(argv[2]);
	if (!output_file) {
		cout << "Output_file couldn't be opened!\n";
		exit(1);
	}

	srand(time(NULL));
	vector<int> saved;
	//Modify the below for the commands you want to test - this will do count PUSHes followed by count SEARCHes with the name numbers
	for (int i = 0; i < count; i++) {
		saved.push_back(rand());
		output_file << "PUSH " << saved.back() << endl;
	}
	random_shuffle ( saved.begin(), saved.end() ); //RIP random_shuffle, compile with -std=c++14 if you have to
	// COMBO
	for (int i = 0; i < count; i++) {
    output_file << "SEARCH " << saved.at(i) << endl;
    }
	for (int i = 0; i < count; i++) {
//		output_file << "SEARCH " << saved.at(i) << endl;
//		output_file << "REMOVE " << saved.at(i) << endl;
		output_file << "POP " << endl;
	}
}
