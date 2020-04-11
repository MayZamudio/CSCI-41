#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

struct LL {
	int data;
	LL *next;
	LL(int new_data, LL *new_next) { data = new_data, next = new_next; }
	//~LL() { delete next; }
};

int main() {
	LL *head = nullptr;
	//Builds and grows a linked list
	while (true) {
		cout << "Please insert an int (0 to quit):\n";
		int x = 0;
		cin >> x;
		if (!cin) exit(EXIT_FAILURE);
		if (x == 0) break;
		LL *temp = new LL{x,head};
		head = temp;
	}

	//Print the linked list
	LL *temp = head;
	while (temp) {
		cout << temp -> data << endl;
		temp = temp -> next;
	}

	cout << "What element do you want to delete?\n";
	int x = 0;
	cin >> x;
	if (!cin) exit(1);
	//If list is empty do nothing
	if (!head) {
		; //Do nothing
	}
	//Trying to delete the head
	else if (x == head->data) {
		LL* temp = head;
		head = head->next;
		delete temp;
	}
	//Deleting from the middle of the list
	else {
		LL *prev = head;
		LL *temp = head->next;
		while (temp) {
			if (x == temp->data) {
				prev->next = temp->next; //$$$
				delete temp;
				break;
			}
			prev = temp;
			temp = temp->next;
		}
	}

	//Print the linked list
	temp = head;
	while (temp) {
		cout << temp -> data << endl;
		temp = temp -> next;
	}

	//Destroy the linked list
	while (true) {
		LL *temp = head->next;
		delete head;
		head = temp;
	}
}











