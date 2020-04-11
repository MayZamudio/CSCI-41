#include <iostream>
using namespace std;

//PODS linked list node
struct LL {
	bool bit;
	LL * next;
	LL() : bit(false), next(nullptr) {}
	LL(bool new_bit, LL* new_next) : bit(new_bit), next(new_next) {}
};

int main() {
	LL *head = new LL;
	cout << "Insert a series of 1s and 0s (anything else to quit): ";
	while (true) {
		char ch;
		cin.get(ch);
		if (!cin) break;
		bool bit = false; // Converts from int to boolean, not buggy FYI
		if (ch == '0') bit = false;
		else if (ch == '1') bit = true;
		else break;
		LL *temp = new LL(bit, head);
		head = temp;
	}
	//Count how many 1s and 0s are in the list
	int one_count = 0, zero_count = 0;
	for (LL *p = head; p->next != NULL; p = p->next) {
		if (p->bit) one_count++;
		else zero_count++;
	}


	cout << "You entered " << one_count + zero_count << " bits, of which " << one_count << " were ones and ";
	cout << zero_count << " were zeroes.\n";

	//Free up list
	while (head) {
		LL *temp = head->next;
		delete head;
		head = temp;
	}
}
