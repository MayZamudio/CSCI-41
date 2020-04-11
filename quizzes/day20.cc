#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

void set_it_to_42(int *ptr) { //This is how C does call by reference
	*ptr = 42;
} 

int main() {
	//In our programs, we've got different chunks of memory
	//  Stack - which is where normal variables live, up near 0x7FFFF. Stack is usually 100MB
	//    Stack allocated variables go away when they go out of scope
	//  Heap  - gets used only with NEW operator. Used for BIG MEMORY OPERATIONS. Heap is about 2GB
	//    Heap allocated variables only go away with explicit calls to delete
	//    If you screw up and don't delete, the OS will clean up your mess for you
	//    SITH RULE - for every new there must be one (and only one) delete
	//new operator - allocate memory off the heap
	//delete operator - deallocate memory
	int* foo = new int[10]; //Foo holds the memory address of the FIRST element in the array
	foo[0] = -1;
	foo[5] = 20;
	cout << "Foo[5]: " << foo[5] << endl; //What will this print to the screen?
	//[] operator - "arr[i]" means access the ith element from array arr
	//It's actually syntactic sugar (meaning it doesn't do anything), it just rewrites itself as: *(arr+i)
	cout << "Foo[5]: " << foo[5] << endl; //What will this print to the screen?
	cout << "Foo[5]: " << *(foo+5) << endl; //What will this print to the screen?
	//If the universe was run by a loving god, this next line would not be possible
	cout << "Foo[5]: " << 5[foo] << endl; //Don't do this, this is horrible, but it's the same as foo[5]
	cout << "Foo[5]: " << *(5+foo) << endl; //What will this print to the screen?
	cout << 5*8 << endl; //Binary * operator = multiply
	cout << *foo << endl; //Unary * operator = dereference
	cout << *(foo+0) << endl; //Same
	cout << foo[0] << endl; //Same




	delete[] foo; //Reclaims the 40 bytes
	//Double delete is Undefined Behavior
	//delete[] foo; //Reclaims the 40 bytes
	//Using something after a delete is Undefined Behavior
	//cout << "Foo[5]: " << foo[5] << endl; //What will this print to the screen?



	//int sdfsdfsd[100'000'000]; //This is going to try to allocate 400MB off the stack
	int* image = new int[100'000'000]; //Each int is 4 bytes (32 bits) so this allocates 4 x 10000000 = 400MB of memory
	image[100] = 42;
	delete[] image; //Reclaim the memory here

	//& operator -- reference operator - "get the memory address of a variable" operator
	//* and & are opposites
	//* operator -- dereference operator - "give me the variable at that memory address" operator
	int x = 100;
	cout << x << endl;
	set_it_to_42(&x); //Pass the address of x to foo
	cout << x << endl;
	int y = 200;
	int z = 300;
	//An lvalue is anything that can appear on the left side of an =, hence left value
	//x, y, z, i.e. all variables are lvalues
	//A rvalue is anything that can appear on the right side of an =, hence right value
	//literals (i.e. 100) and the results of expressions are rvalues
	//You can also put lvalues on the right side as well
	cout << x << " " << y << " " << z << endl;
	cout << &x << " " << &y << " " << &z << endl;
	//This is undefined behavior that relies on y being 16 bytes after x
	//This is the equivalent of licking a door knob
	int* ptr = &x; //These guys only hold memory addresses
	cout << *ptr << endl;

	const int SIZE = 10;
	int arr2[SIZE] = {};
	cout << arr2 << endl;
	arr2[3] = 42; //If this was Java, it would be doing bounds checking
	arr2[2] = 80;
	arr2[6] = -1;
	cout << "ARR:\n";
	for (int i = 0; i < SIZE; i++) //How you print an array
		cout << i[arr2] << endl;

	cout << "RBFL:\n";
	for (int x : arr2) cout << x << endl;

	cout << "PTR:\n";
	//Lesson for today = arrays are pointers and pointers are arrays**
	// (**some exceptions apply)
	//Berkeley for loop
	for (int *ptr = arr2; ptr < arr2+SIZE; ptr++) //How you print an array
		cout << *ptr << endl;

	//Option 1 - 2D C Style Arrays ([] Arrays)
	int arr[SIZE][SIZE] = {}; //Using {} will default initialize it
	arr[3][5] = 42;
	arr[5][3] = -20; 
	for (int i = 0; i < SIZE; i++)
    	for (int j = 0; j < SIZE; j++)
        	cout << arr[i][j] << " ";

	//Option 2 - 2D Vectors
	vector<vector<int>> vec(SIZE,vector<int>(SIZE));
	vec[3][5] = 42; //Option 1 - No bounds checking 
	vec.at(3).at(5) = 42; //Option 2 - Bounds checking
	vec.at(5).at(3) = -20;
	cout << vec.at(5).at(3) << endl;
	//90G jumps to line 90
	//cout << "Foo[5]: " << foo[5] << endl; //What will this print to the screen?
}
