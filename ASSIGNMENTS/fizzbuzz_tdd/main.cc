#include <gtest/gtest.h>
#include <iostream>
using namespace std;

//YOU: Write fizzbuzz
//Return "Fizz" if x is divisible by 3
//Return "Buzz" if x is divisible by 5
//Return "Fizzbuzz" if x is divisible by both 3 and 5
//Return a string containing the number otherwise
//Return "Error" if x is less than 1 or greater than 100
string fizzbuzz(int x) {
	if (x < 1 || x > 100) return "Error";

	else if (x % 15 == 0) {
		return "Fizzbuzz";
	} else if (x % 5 == 0) {
		return "Buzz";
	} else if (x % 3 == 0) {
		return "Fizz";
	} else return to_string(x);
	return "";
}

//YOU: Write tests to test your fizzbuzz implementation
TEST(Fizzbuzz, GoodTests) {
	EXPECT_EQ(fizzbuzz(33), "Fizz");// Good tests are good behavior --- I expect the output to equal ""
	EXPECT_EQ(fizzbuzz(5), "Buzz");
	EXPECT_EQ(fizzbuzz(30), "Fizzbuzz");
	EXPECT_EQ(fizzbuzz(41), "41");
	EXPECT_EQ(fizzbuzz(52), "52");
}

//YOU: Write your own tests to check bad inputs here
TEST(Fizzbuzz, BadTests) {
	EXPECT_EQ(fizzbuzz(-33), "Error");
	EXPECT_EQ(fizzbuzz(110), "Error");
	EXPECT_EQ(fizzbuzz(-110), "Error");
	EXPECT_EQ(fizzbuzz(110345), "Error");
}

//YOU: Write your own tests to check edge inputs here
TEST(Fizzbuzz, EdgeTests) {
	EXPECT_EQ(fizzbuzz(1), "1");
	EXPECT_EQ(fizzbuzz(100), "Buzz");
	EXPECT_EQ(fizzbuzz(0), "Error");
	EXPECT_EQ(fizzbuzz(99), "Fizz");
	EXPECT_EQ(fizzbuzz(101), "Error");
}

//YOU: Now write a function called fizzbuzz2, that is exactly the same as fizzbuzz, but with one important change.
//Before returning a number, add the digits of the number together, and use the result from that sum with the same
// rules. For example, 23 would return "Buzz" because 2+3 = 5.
string fizzbuzz2(int x) {
	int num = (x / 10) + (x % 10);
	if (x < 1 || x > 100) return "Error";
	if (x % 15 == 0) return "Fizzbuzz";
	if (x % 5 == 0) return "Buzz";
	if (x % 3 == 0) return "Fizz";
	if (num % 15 == 0) return "Fizzbuzz";
	if (num % 5 == 0) return "Buzz";
	if (num % 3 == 0) return "Fizz";
	return to_string(x);
}

//YOU: Now write good, bad, and edge cases for fizzbuzz2 as well.
TEST(Fizzbuzz2, GoodTests) {
	EXPECT_EQ(fizzbuzz(3), "Fizz");
	EXPECT_EQ(fizzbuzz(5), "Buzz");
	EXPECT_EQ(fizzbuzz(30), "Fizzbuzz");
	EXPECT_EQ(fizzbuzz(45), "Fizzbuzz");
	EXPECT_EQ(fizzbuzz(68), "68");
}

TEST(Fizzbuzz2, BadTests) {
	EXPECT_EQ(fizzbuzz(-33), "Error");
	EXPECT_EQ(fizzbuzz(110), "Error");
	EXPECT_EQ(fizzbuzz(-110), "Error");
	EXPECT_EQ(fizzbuzz(110345), "Error");
}

TEST(Fizzbuzz2, EdgeTests) {
	EXPECT_EQ(fizzbuzz(1), "1");
	EXPECT_EQ(fizzbuzz(100), "Buzz");
	EXPECT_EQ(fizzbuzz(0), "Error");
	EXPECT_EQ(fizzbuzz(99), "Fizz");
	EXPECT_EQ(fizzbuzz(101), "Error");
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
#ifndef FOO
	//Stop people from compiling this code using 'compile'
	static_assert(false, "Type 'make' to build this, not 'compile'");
#endif
	cout << "Welcome to Fizzbuzz 2000(tm). Choose one of the following options:\n";
	cout << "fizzbuzz   - will run fizzbuzz from 1 to 100.\n";
	cout << "fizzbuzz2  - will run fizzbuzz2 from 1 to 100.\n";
	cout << "(a number) - will run fizzbuzz and fizzbuzz2 on just that number.\n";
	cout << "test       - will run the test suite you've created.\n";
	string s;
	getline(cin, s);
	if (s == "test") return RUN_ALL_TESTS();
	else if (s == "fizzbuzz") {
		for (int i = 0; i < 100; i++) {
			cout << fizzbuzz(i + 1) << endl;
		}//YOU: Write code that will output the result of the fizzbuzz function from 1 to 100 here:
	} else if (s == "fizzbuzz2") {
		for (int i = 0; i < 100; i++) {
			cout << fizzbuzz2(i + 1) << endl;
		}//YOU: Write c de that will output the result of the fizzbuzz2 function from 1 to 100 here:
	} else { //Just a number, so feed it to each function and output the result
		int x = stoi(s);
		cout << "Fizzbuzz (" << x << ") = " << fizzbuzz(x) << endl;
		cout << "Fizzbuzz2(" << x << ") = " << fizzbuzz2(x) << endl;
	}

}
