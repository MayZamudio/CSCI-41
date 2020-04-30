#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cctype>
#include <string>
#include <unordered_map>
#include "Bridges.h"
#include <Array1D.h>
#include <tuple>
using namespace std;
using namespace bridges;

struct Word {
	string str;
	int count = 1;
};

//Sort greatest to smallest by count
bool operator<(const Word &w1, const Word &w2) {
	//YOU - this was cool https://stackoverflow.com/questions/36056448/how-overload-operator-for-sort-method-for-objects
	return tie(w2.count, w1.str) < tie(w1.count, w2.str);
}

ostream &operator<<(ostream &outs, const Word &w) {
	outs << w.str << ": " << w.count;
	return outs;
}

int main() {
	const int TOP = 30; //Show top 30 words
	//Bridges visualization
	Bridges *bridges =  new Bridges(42, "mzamudio", "614923477058");

	//Use a hash table to count words
	unordered_map<string,Word> hist;
	//Use a vector to sort the words by count
	vector<Word> vec;
	while (true) {
		cout << "Enter the name of a file to open (DONE to be done):\n";
		string filename;
		cin >> filename;
		if (filename == "done" or filename == "DONE") break;
		ifstream ins(filename); 
		if (!ins) { 
			cout << "Error opening file.\n";
			continue;
		}
		while (ins) {
			string s;
			ins >> s;
			if (!ins) break;
			//cerr << "First string: " << s << endl;
			//YOU: Remove any non-letter characters from s. Use isalpha.
			//THIS WAS COOL - https://stackoverflow.com/questions/28491954/remove-non-alphabet-characters-from-string-c
			s.erase(remove_if(s.begin(), s.end(), [](char c) { return !isalpha(c); } ), s.end());
			//cerr << "After remove: " << s << endl;
			//YOU: If it has less than 4 characters remaining, continue;
			if (s.size() < 4) continue;
			//cerr << "After remove < 4: " << s << endl;
			//YOU: See if it has appeared in the histogram before by using hist.count(s)
			//  YOU: If it has, update its count. You can access the Word via hist[s]
			if (hist.count(s) >= 1) hist[s].count++;
				//  YOU: If not, add it to the histogram by setting hist[s] to s. The count will default to 1.
				else hist[s] = {s,1};
		}
	}
	//Convert the hash table into a vector of results and sort it by count
	//for (auto x : histogram) vec.push_back(x.second);
	for (auto x : hist) vec.push_back(x.second);
	Array1D<Word> arr(vec.size() < TOP ? vec.size() : TOP); //Array of 30 elements or vec.size, whatever is smaller
	sort(vec.begin(),vec.end()); //YOU: This won't work until you implement operator<

	//Print the top 30 and copy them into bridges array
	if (vec.size() > 30) cout << TOP << endl;
		else cout << vec.size() << endl;

	for (size_t i = 0; i < TOP and i < vec.size(); i++) {
		//YOU: cout the ith element of vec
		cout << vec.at(i) << endl;	
		//Copy from the vec into our BRIDGES array
		arr[i] = vec.at(i);
		string s = vec.at(i).str;
		int count = vec.at(i).count;
		arr.getElement(i).setLabel(s+"\n"+to_string(count));
		//YOU: Words with a count over 100 get colored red
		if (count >= 100) arr.getElement(i).setColor("red");
		//YOU: Words with a count over 10 get colored yellow
		else if (count >= 10) arr.getElement(i).setColor("yellow");
		//YOU: Words with a count over 1 get colored green
		else if (count >= 1) arr.getElement(i).setColor("green");
		//Else go with white
		else arr.getElement(i).setColor("white");
	}
	bridges->setDataStructure(arr);
	bridges->visualize(); //YOU: When done, put the hyperlink this prints into Canvas for me to view for 3 points
}
