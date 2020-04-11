#include <iostream>
#include <algorithm>
#include <string>
#include <array>
using namespace std;

//T has to be a string class
template <class T, int size>
class Replacer {
	array<T, size> arr = {};
	size_t insert_index = 0;
	size_t replace_index = 0;
  public:
	Replacer() {}
	void insert(T data) {
		if (insert_index >= size) return;
		arr[insert_index++] = data;
	}
	void replace(T orig, T change) {
		if (replace_index > size) return;
		auto i = arr[replace_index].find(orig);
		if (i != string::npos)
			arr[replace_index].replace(i, orig.length(), change);
		replace_index++;
	}
	void dump() { //Print our array to cout
		for (size_t i = 0; i < insert_index; i++)
			cout << arr[i] << endl;
	}
};

int main() {
	string s, t;
	Replacer<string, 10> r;
	cout << "Please insert sentences. (Type 'quit' to quit.)\n";
	while (true) {
		getline(cin, s);
		if (s == "quit") break;
		r.insert(s);
	}
	cout << "Enter pairs of words to search and replace, which will apply to one sentence in a row. Type 'quit' to quit.\n";
	while (true) {
		cin >> s;
		if (!cin || s == "quit") break;
		cin >> t;
		if (!cin || t == "quit") break;
		r.replace(s, t);
	}
	cout << "The final set of strings is:\n";
	r.dump();
}
