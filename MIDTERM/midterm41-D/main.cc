#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

//This holds a single node of a binary search tree
template <class T>
class Tree {
	class Node {
		T data = {};
		Node *left = nullptr, *right = nullptr;
	  public:
		Node() = delete; //Remove default cstor
		Node(T new_data) : data(new_data) {}
		~Node() {
			if (left) delete left;
			if (right) delete right;
		}
		T get_data() const {
			return data;
		}
		Node* get_right() const {
			return right;
		}
		Node* get_left() const {
			return left;
		}
		void set_right(Node *right) {
			this->right = right;
		}
		void set_left(Node *left) {
			this->left = left;
		}
	};

	Node *root = nullptr;
	size_t size = 0; //Basically it's an unsigned int
	void print_recursive(Node *ptr) {
		assert(ptr);
		if (ptr->get_left()) print_recursive(ptr->get_left());
		cout << ptr->get_data() << endl;
		if (ptr->get_right()) print_recursive(ptr->get_right());
//		cout << ptr->get_data() << endl;
	}

	void insert_recursive(Node *ptr, T new_data) {
		assert(ptr);
		//CASE 2 - The value here is a match for new_data
		if (ptr->get_data() == new_data) return;

		//CASE 3 - new_data is less than the value here
		else if (new_data < ptr->get_data()) {
			if (ptr->get_left() == nullptr) {
				ptr->set_left(new Node(new_data));
				size++;
				return;
			}
			insert_recursive(ptr->get_left(), new_data);
		}

		//CASE 4 - new_data is greater than the value here
		else {
			if (ptr->get_right() == nullptr) {
				ptr->set_right(new Node(new_data));
				size++;
				return;
			}
			insert_recursive(ptr->get_right(), new_data);
		}
	}
  public:
	Tree() {}
	~Tree() {
		if (root) delete root;
	}
	void insert(T new_data) {
		//CASE 1 - Empty Tree
		if (!root) {
			root = new Node(new_data);
			size = 1;
			return;
		}
		insert_recursive(root, new_data);
	}
	void print() {
		//Base condition
		if (!root) {
			cout << "Tree Empty.\n";
			return;
		}
		//Inductive step
		print_recursive(root);
	}
};

int main() {
	Tree<int> tree;
	cout << "Please type in ints to sort (0 to quit):\n";
	while (cin) {
		int x = 0;
		cin >> x;
		if (!cin or !x) break;
		tree.insert(x);
	}
	tree.print();

	Tree<string> trees;
	cout << "Please type in names to sort (\"DONE\" to quit):\n";
	while (cin) {
		string x;
		cin >> x;
		if (!cin or x == "DONE") break;
		trees.insert(x);
	}
	trees.print();
}
