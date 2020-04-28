#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
struct BST {
    T data = {};
    BST *left = nullptr, *right = nullptr;
    BST(T new_data) : data(new_data) {}
};

template <class T>
struct Tree {
    BST<T> *root = nullptr;
    bool search(T data) {
         if (!root) return false;
         BST<T> *temp = root;
         while (temp) {
             if (data == temp->data) { 
				 cout << "Found " << temp->data << ". Retrace your steps to the entrance. \n" << endl;
				 return true;
			 }
             else if (data < temp->data) { 
				cout << "Take the left door at the " << temp->data << ".\n";
				//Take the left door at the B.
				temp = temp->left;
				continue;
			 }
             else 
				 cout << "Take the right door at the " << temp->data << ".\n";
				 temp = temp->right;
				 continue;
         }
         return false;
    }

    void insert(T new_data) {
        if (!root) { //If root is empty
            //Make a new node in root with the data and null kids
            root = new BST<T>(new_data);
            return;
        }
        BST<T> *temp = root;
        while (true) {
            if (new_data == temp->data) { //Duplicate
                return;
            }
            else if (new_data < temp->data) {
                //Check to see if the spot is available, and if it is insert
                if (temp->left == nullptr) {
                    temp->left = new BST<T>(new_data);
                    return;
                }
                //If not, we move temp down to the left and repeat
                temp = temp->left;
            }
            else {
                //Check to see if the spot is available, and if it is insert
                if (temp->right == nullptr) {
                    temp->right = new BST<T>(new_data);
                    return;
                }
                //If not, we move temp down to the left and repeat
                temp = temp->right;
            }
        }
    }
	




};

