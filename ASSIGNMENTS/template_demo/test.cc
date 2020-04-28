#include <iostream>
#include <queue>
#include <vector>
#include <boost/lambda/lambda.hpp>
using namespace std;

template <class T>
void my_swap(T &a, T &b) {
	T c = a;
	a = b;
	b = c;
}

#define MAX_SIZE 100
#define old_lesser(a,b) ((a) < (b) ? (true) : (false))

class Bob {
  public:
	int data = 0;
	Bob(int new_data) : data(new_data) {}
	Bob(string s) : data(s.size()) {}
	bool operator< (Bob steve) {
		return data < steve.data;
	}
	Bob operator+ (Bob alice) {
		return Bob(data + alice.data);
	}
};

//< operator must be defined
template <typename T>
bool lesser(T a, T b) {
	if (a < b) return true;
	return false;
}

//Try templating this and see if it will still work!
Bob auto_add(Bob a, Bob b) {
	return a + b;
}

template <class T>
T auto_add(T a, T b) {
	return a + b;
}

template <class T>
class Node {
  public:
	T data;
	int bob(Node sally) {
		return sally.data;
	}

	Node *first_ptr; //Same as saying Node<T> *first_ptr
	Node<char> *second_ptr;
	Node<string> *third_ptr;
};


int main() {
	Bob x = 4, y = 4;
	int z, w;
	cout << auto_add<int> (z, w) << endl;
	Bob retval = auto_add<Bob> (z, w);
	cout << retval.data << endl;
	cout << lesser(x, y) << endl;

	cout << "---------------------------\n";
	int foo = 'F';
	int bar = 7;
	cout << "BEFORE SWAP Foo = " << foo << " Bar = " << bar << endl;
	my_swap(foo, bar);
	cout << " AFTER SWAP Foo = " << foo << " Bar = " << bar << endl;

	cout << "---------------------------\n";

	double apple = 5;
	double banana = 7;
	cout << "BEFORE SWAP APPLE: " << apple << " BANANA: " << banana << endl;
	//This works also! Try this - it's no different
	//my_swap<int>(apple,banana);
	my_swap(apple, banana);

	auto sum = auto_add(apple, banana);  //How do auto variables work?
	cout << " AFTER SWAP APPLE: " << apple << " BANANA: " << banana << endl;
	cout << "SUM: " << sum << endl;

	if (lesser<int> (apple, banana)) //Is the <int> necessary?
		cout << "APPLE is less than BANANA!\n";
	else
		cout << "APPLE is greater than BANANA!\n";

	if (old_lesser(apple, banana))
		cout << "APPLE is less than BANANA!\n";
	else
		cout << "APPLE is greater than BANANA!\n";

	cout << "---------------------------\n";

	Node<int> alice = { 42, NULL, NULL, NULL };
	Node<int> bob = { 17, NULL, NULL, NULL };
	Node<char> charlie = { 'c' };
	Node<string> diana = { "Hello World!", NULL, NULL, NULL };
	alice.first_ptr = &bob;
	alice.second_ptr = &charlie;
	alice.third_ptr = &diana;
	//COMPILER ERROR alice.first_ptr = &diana;
	cout << "ALICE: " << alice.data << endl << "BOB: " << bob.data << endl << "CHARLIE: " << charlie.data << endl << "DIANA: " << diana.data << endl;
	cout << "ALICE.first_ptr->data: " << alice.first_ptr->data << endl << "ALICE.second_ptr->data: " << alice.second_ptr->data << endl << "ALICE.third_ptr->data: " << alice.third_ptr->data << endl;

	cout << "---------------------------\n";

	//Look! Generic Queues!
	queue<long long> qu;
	cout << "PUSH 7\n";
	qu.push(7);
	cout << "PUSH 17\n";
	qu.push(17);
	cout << "PUSH 27\n";
	qu.push(27);
	cout << "PUSH 37\n";
	qu.push(37);
	cout << "POP\n";
	qu.pop(); //Pops off 7
	cout << "Head of the queue is: " << qu.front() << endl;
}
