#include <iostream>
#include <cmath>

using namespace std;

struct LL {
	int data;
	LL *next;
	LL(int new_data, LL *new_next) {
		data = new_data, next = new_next;
	}
	/*	~LL() {
			delete next;
		}*/
};

int main() {
	LL *head = nullptr;
//Builds the list
	while (true) {
		cout << "Please enter an int (0 to quit):\n";
		int x = 0;
		cin >> x;
		if (!cin) exit(EXIT_FAILURE);
		if (x == 0) break;
		LL *temp = new LL{x, head};
		head = temp;

	}
	//Print linked list
	LL *temp = head;
	while (temp) {
		temp = temp -> next;
		cout << temp -> data << endl;
	}
	cout << "What element do you want to delete?\n";
	int x = 0;
	cin >> x;
	if (!cin) exit(1);
	//Trying to delete the head
	if (!head) {
		; //Do nothing
	}
	else if (x == head ->data) {
		LL* temp = head;
		head = head ->next;
		delete temp;
	}
	else {
		LL *prev = head;
		LL *temp = head->next;
		while(temp) {
			if (x == temp->data){
				prev->next = temp->next;
				delete temp;
				break;
			}
			prev = temp;
			temp = temp-> next;
		}

	}

// Destroy the linked li
	temp = head;
	while (temp) {
		LL *temp2 = temp -> next;
		delete temp;
		temp = temp2;
	}

//	delete head;
}
