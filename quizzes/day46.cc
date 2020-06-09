//For the quiz today message your TA a program that inserts 10 random numbers into a BST using the STL BST class
#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
	int key_value;
	struct node *left, *right;
};

int CountLeaf(struct node* root) {
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	else
		return CountLeaf(root->left) + CountLeaf(root->right);
}
struct node *newNode(int item) {
	struct node *curr = (struct node *)malloc(sizeof(struct node));
	curr->key_value = item;
	curr->left = curr->right = NULL;
	return curr;
}

struct node* AddNode(struct node* node, int key) {
	if (node == NULL) return newNode(key);
	if (key < node->key_value)
		node->left = AddNode(node->left, key);
	else if (key > node->key_value)
		node->right = AddNode(node->right, key);

	return node;
}

int main() {

	struct node *root = NULL;
	srand(time(NULL));

	root = AddNode(root, rand() % 100);
	for (int i = 0; i < 9; ++i)
		AddNode(root, rand() % 100);

	cout << "The number of leaf is: " << CountLeaf(root) << endl;

	return 0;
}
