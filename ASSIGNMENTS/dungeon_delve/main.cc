#include <iostream>
#include <vector>
#include <ctype.h>
#include <cstring>
#include "Bridges.h"
#include "BSTElement.h"
#include "tree.h"

using namespace std;
using namespace bridges;

BSTElement<char, char> *insert(BSTElement<char, char> *root, BSTElement<char, char> *new_element) {
	if (!root) return new_element;
	else if (new_element->getKey() < root->getKey())
		root->setLeft(insert(root->getLeft(), new_element));
	else root->setRight(insert(root->getRight(), new_element));
	return root;
}

int main() {
	Tree<char>DD;
	char c = {};
	char password = {};

	//Bridges stuff
	Bridges *bridges = new Bridges(3, "mzamudio", "499940957037");
	bridges->setTitle("Dungeon Delve");
	BSTElement<char, char> *root = NULL;
	//END OF BRIDGES

	vector<char>user_entry;
	vector<char>user_pw;
	bool solvable = false;
		while (true) {
			cin >> c;
			if (isalpha(c)) {
				BSTElement<char, char> *temp = new BSTElement<char, char> (c, c);
				root = insert(root, temp);
				user_entry.push_back(c);
				DD.insert(c);
			}
			if (!cin || !isalpha(c)) break;
		}
	
	while (true) {
		cin >> password;
		if (!cin || password == EOF) break;
		else
			user_pw.push_back(password);
	}
	cout << endl;

	for (size_t i = 0; i < user_pw.size(); i++) {
		solvable = false;
		for (size_t j = 0; j < user_entry.size(); j++) {
			if (user_pw.at(i) == user_entry.at(j)) {
				solvable = true;
				break;
			}
		}
		if (!solvable) {
			cout << "NOT SOLVABLE\n";
			return -1;
		}
	}
	for (char x : user_pw) DD.search(x);
	cout << "Exit the dungeon!\n";
	// set some visual attributes
	root->setColor("red");
	root->setShape(Shape::DIAMOND);
	//Bridges
	bridges->setDataStructure(root);
	bridges->visualize();
}
