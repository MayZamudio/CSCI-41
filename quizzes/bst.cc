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
		Node() = delete;
		Node(T data) { this->data = data; }
		~Node() { if (left) delete left; if (right) delete right; }
		T get_data() { return data; }
		void set_data(T data) { this->data = data; }
		Node* get_right() { return right; }
		Node* get_left() { return left; }
		void set_right(Node *right) { this->right = right; }
		void set_left(Node *left) { this->left = left; }
	};

	Node *root = nullptr;
	size_t size = 0; //Basically it's an unsigned int
	void print_recursive(Node *ptr) {
		assert(ptr);
		if (ptr->get_left()) print_recursive(ptr->get_left());
		cout << ptr->get_data() << endl;
		if (ptr->get_right()) print_recursive(ptr->get_right());
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
			insert_recursive(ptr->get_left(),new_data);
		}

		//CASE 4 - new_data is greater than the value here
		else {
			if (ptr->get_right() == nullptr) {
				ptr->set_right(new Node(new_data));
				size++;
				return;
			}
			insert_recursive(ptr->get_right(),new_data);
		}
	}
	public:
	Tree() {}
	~Tree() { if (root) delete root; }
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
	tree.insert(5);
	tree.insert(2);
	tree.insert(1);
	tree.insert(3);
	tree.insert(10);
	tree.insert(8);
	tree.insert(16);
	tree.insert(12);
	tree.print();
}









