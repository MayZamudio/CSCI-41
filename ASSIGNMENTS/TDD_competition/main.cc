//GARCIA AND ZAMUDIO
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#ifndef SIZE
#define SIZE 10
#endif

//YOU: Write a function that will return true if the string passed
// in is a standard name: exactly two words, the first letter of each
// being capitalized. No digits, no other capitals, no special
// characters other than - and '
bool accept_name(string name) {
	stringstream ss(name);
	vector<string> vec;
	while (ss) {
		string s;
		ss >> s;
		if (!ss) break;
		char c = s.at(0);
		if(isupper(c)){
			for(size_t i=1; i< s.size();i++){
					if( isdigit(s.at(i)) || isupper(s.at(i)) ) return false;
						if((s.at(i)=='-') || (s.at(i)=='\''))continue;
						if(!isalpha(s.at(i))) return false;
			}

					  vec.push_back(s);
	}
	}
	if (vec.size() != 2) return false;

	return true;

}

// Google Test test cases are created using a C++ preprocessor macro
TEST(AcceptNameTest, GoodNames) {
	//Here are two simple demo tests...
	EXPECT_EQ(1+1, 2); //EXPECT will continue if a test fails
	ASSERT_EQ(1+1, 2); //ASSERT will stop testing if a test fails

	//Here are some real tests...
	EXPECT_EQ(accept_name("Marcus Aurelius"), true);
	EXPECT_EQ(accept_name("Bill Kerney"), true);
	EXPECT_EQ(accept_name("Jean-claude Van"), true);
	EXPECT_EQ(accept_name("Batz-castelmore D'artagnan"), true);
}

TEST(AcceptNameTest, BadNames) {
	//YOU: Write your own tests in addition to writing code to pass al  l of these tests
	EXPECT_EQ(accept_name("Marcus Aurelius Flint"), false);
	EXPECT_EQ(accept_name("B. Kerney"), false);
	EXPECT_EQ(accept_name("JCVD"), false);
	EXPECT_EQ(accept_name("👏  🍜 "), false);
}

struct Position {
	int x,y; //Holds a 2D coordinate
};

//YOU: Write this class
//Holds a 10x10 grid of elevations that hold numbers from 0 to 99
//They are initialized by a random number passed to the constructor
class Snow {
	public:
		static const int MAX_ELEVATION = 99;
		Snow() = delete; //No default constructor
		Snow(int seed) { //One parameter constructor
			srand(seed);
			//YOU: Initialize each element of elevation to a random number from 0 to MAX_ELEVATION
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++) {
					elevation[i][j] = rand() % (MAX_ELEVATION + 1); //YOU: Change this line to use rand() and modulus

				}
			}
		}

		//Lets the user access the elevation array at the given position
		//Returns throws on an error
		int get_elevation(Position pos) {
			if (pos.x < 0 || pos.x >= SIZE || pos.y < 0 || pos.y >= SIZE) {
				throw out_of_range("Bad Position");
			}
			return elevation[pos.x][pos.y];
		}

		//YOU: Given the x & y location, return the position of the
		// array element near it with the lowest elevation
		// For example if position (3,3) is surrounded on all sides
		// with elevation 99 tiles, but (3,1) is elevation 50, it
		// will return (3,1) by setting retval.x = 3, retval.y = 1
		//YOU: Throw an out_of_range exception if pos is out of bounds
		// (See the function above on how to do that.)
		//YOU: Throw a runtime_error("No way out!") if the position we are at is lower than all the neighbors
			Position fall_line(Position pos) {
				Position right={};
				Position left={};
				Position above={};
				Position below={};
				Position topLeft={};
				Position topRight={};
				Position bottomRight={};
				Position bottomLeft={};
				Position return_value={};
//				cerr<< " row "<<pos.x<<" column "<<pos.y<<"              position is: "<<get_elevation(pos)<<endl;

				if (pos.y <=SIZE-2)// ---->
				 right ={( pos.x), pos.y + 1};
				else
				 right ={ pos.x, pos.y};
//				cerr<< "right row : "<<right.x<<", right column: "<<right.y<<"         position is: "<<get_elevation(right)<<endl;

				if(pos.y >0)//<-------
				 left ={ pos.x, pos.y-1};
				else
				 left ={pos.x, pos.y};
//				cerr<< "left row "<<left.x<<" left column "<<left.y<<"             position is: "<<get_elevation(left)<<endl;

				if(pos.x >0)//^^^^^^^^^^^
			    above ={pos.x-1, pos.y};
				else
				 above ={pos.x, pos.y};
//				cerr<< "Above row"<<above.x<<", above column "<<above.y<<"         position is: "<<get_elevation(above)<<endl;

				if(pos.x <= SIZE-2)//downnnnnnnnnnn
				 below ={pos.x+1, pos.y};
				else
				 below ={pos.x, pos.y};

				if(pos.x >0 && pos.y>0)
					topLeft={ pos.x-1, pos.y-1};
				else
					topLeft={pos.x, pos.y};

				if(pos.x >0 && pos.y<= SIZE-2)
					topRight={ pos.x-1, pos.y+1};
				else
					topRight={pos.x, pos.y};

				if(pos.x <= SIZE-2 && pos.y<= SIZE-2)
					bottomRight={ pos.x+1, pos.y+1};
				else
					bottomRight={pos.x, pos.y};

				if(pos.x <= SIZE-2 && pos.y>0)
					bottomLeft={ pos.x+1, pos.y-1};
				else
					bottomLeft={pos.x, pos.y};
//
//				cerr<< "below row "<<below.x<<", Below column "<<below.y<<"            position is: "<<get_elevation(below)<<endl;

	//	if (pos.x < 0 || pos.x >= SIZE-1 || pos.y < 0 || pos.y >= SIZE-1) {
		//		throw out_of_range("Bad Position");}
		   			vector<Position> the8={};
			the8.push_back(right);
			the8.push_back(left);
			the8.push_back(topRight);
			the8.push_back(topLeft);
			the8.push_back(above);
			the8.push_back(below);
			the8.push_back(bottomRight);
			the8.push_back(bottomLeft);
				Position min=the8.at(0);
			for(size_t i=0; i< the8.size(); i++){
			//	cout<<"comparing new: "<<get_elevation(the8.at(i)) <<" with min : "<< get_elevation(min)<<endl;
				if(get_elevation(the8.at(i)) < get_elevation(min))
					min= the8.at(i);}
				//	else
						//min=the8.at(0);}
			//cout<<"Min is: "<<get_elevation(min);
			if(get_elevation(pos) <= get_elevation(min))
			throw runtime_error("No way out!"); //Put this in the code if the current position is lower than all neighbors
			else
				return_value=min;

			/*
			the8.push_back(get_elevation(right));
			the8.push_back(get_elevation(left));
			the8.push_back(get_elevation(above));
			the8.push_back(get_elevation(below));
			the8.push_back(get_elevation(topRight));
			the8.push_back(get_elevation(topLeft));
			the8.push_back(get_elevation(bottomRight));
			the8.push_back(get_elevation(bottomLeft));
			sort(the8.begin(), the8.end());
				return_value=the8.at(0);
				*/
		/*
			else if (get_elevation(left) < get_elevation(pos)) return_value= left;
			else if (get_elevation(above) < get_elevation(pos)) return_value= above;
			else if (get_elevation(below) < get_elevation(pos)) return_value= below;
			else if (get_elevation(topLeft) < get_elevation(pos)) return_value= topLeft;
			else if (get_elevation(topRight) < get_elevation(pos)) return_value= topRight;
			else if (get_elevation(bottomRight) < get_elevation(pos)) return_value= bottomRight;
			else if (get_elevation(bottomLeft) < get_elevation(pos)) return_value= bottomLeft;
			//else return_value=pos;
			//Position return_value =pos; //CHANGEME
			else throw runtime_error("No way out!"); //Put this in the code if the current position is lower than all neighbors
		*/
			return return_value;

			}
	private:
		int elevation[SIZE][SIZE];
};

//YOU: Write five more test cases for the Snow class's normal behavior...
// You can either put them inside here, or make a separate GoodTest2, GoodTest3, etc.
TEST(SnowTest,GoodTest1) {
	//You can put normal code inside these tests like this
	// They don't all have to be EXPECT or ASSERT macros...
	Snow bob(5); //5 is a random seed
	Position p = {7,2};
	//cout << bob.get_elevation(p) << endl;
	EXPECT_EQ(bob.get_elevation(p),87);
	EXPECT_EQ(bob.get_elevation({3,4}),99); //Shortcut


	Snow James(10); //5 is a random seed
	EXPECT_EQ(James.get_elevation({0,9}),7); //Shortcut

	Snow Mayra(8); //5 is a random seed
	EXPECT_EQ(Mayra.get_elevation({9,9}),4); //Shortcut

	Snow Tomas(8); //5 is a random seed
	EXPECT_EQ(Tomas.get_elevation({9,0}),1); //Shortcut
	Snow Scotty(8); //5 is a random seed
	EXPECT_EQ(Scotty.get_elevation({3,4}),1); //Shortcut
}

//YOU: Write five more test cases where the Snow class should fail
TEST(SnowTest,BadTest1) {
	Snow cindy(12);
	//Here's how you write a test for an exception
	try {
		Position p = cindy.fall_line({-1,-1}); //Should throw
		//But if not, this should throw:
		cout << cindy.get_elevation(p);
		FAIL() << "We shouldn't have gotten here - test should have thrown an exception in either fall_line or get_elevation!";
	}
	catch (const out_of_range &e) {
		//Testing strings is a bit weird - use one of these two options
		EXPECT_EQ(e.what(),string("Bad Position"));
//	EXPECT_STREQ(e.what(),"No way out!"); //FIXME: Figure out why this is failing
	}
	catch (...) {
		FAIL() << "We threw an exception that we didn't catch";
	}
}
TEST(SnowTest,BadTest2) {
	Snow cindy(12);
	//Here's how you write a test for an exception
	try {
		Position p = cindy.fall_line({3,11}); //Should throw
		//But if not, this should throw:
		cout << cindy.get_elevation(p);
		FAIL() << "We shouldn't have gotten here - test should have thrown an exception in either fall_line or get_elevation!";
	}
	catch (const out_of_range &e) {
		//Testing strings is a bit weird - use one of these two options
		EXPECT_EQ(e.what(),string("Bad Position"));
//	EXPECT_STREQ(e.what(),"No way out!"); //FIXME: Figure out why this is failing
	}
	catch (...) {
		FAIL() << "We threw an exception that we didn't catch";
	}
}
TEST(SnowTest,BadTest3) {
	Snow cindy(12);
	//Here's how you write a test for an exception
	try {
		Position p = cindy.fall_line({0,10}); //Should throw
		//But if not, this should throw:
		cout << cindy.get_elevation(p);
		FAIL() << "We shouldn't have gotten here - test should have thrown an exception in either fall_line or get_elevation!";
	}
	catch (const out_of_range &e) {
		//Testing strings is a bit weird - use one of these two options
		EXPECT_EQ(e.what(),string("Bad Position"));
//	EXPECT_STREQ(e.what(),"No way out!"); //FIXME: Figure out why this is failing
	}
	catch (...) {
		FAIL() << "We threw an exception that we didn't catch";
	}
}
TEST(SnowTest,BadTest4) {
	Snow Jimmothy(15);
	//Here's how you write a test for an exception
	try {
		Position p = Jimmothy.fall_line({10,8}); //Should throw
		//But if not, this should throw:
		cout << Jimmothy.get_elevation(p);
		FAIL() << "We shouldn't have gotten here - test should have thrown an exception in either fall_line or get_elevation!";
	}
	catch (const out_of_range &e) {
		//Testing strings is a bit weird - use one of these two options
		EXPECT_EQ(e.what(),string("Bad Position"));
//	EXPECT_STREQ(e.what(),"No way out!"); //FIXME: Figure out why this is failing
	}
	catch (...) {
		FAIL() << "We threw an exception that we didn't catch";
	}
}
TEST(SnowTest,BadTest5) {
	Snow Bobothy(15);
	//Here's how you write a test for an exception
	try {
		Position p = Bobothy.fall_line({3,'.'}); //Should throw
		//But if not, this should throw:
		cout << Bobothy.get_elevation(p);
		FAIL() << "We shouldn't have gotten here - test should have thrown an exception in either fall_line or get_elevation!";
	}
	catch (const out_of_range &e) {
		//Testing strings is a bit weird - use one of these two options
		EXPECT_EQ(e.what(),string("Bad Position"));
//	EXPECT_STREQ(e.what(),"No way out!"); //FIXME: Figure out why this is failing
	}
	catch (...) {
		FAIL() << "We threw an exception that we didn't catch";
	}
}
TEST(SnowTest,BadTest6) {
	Snow Felicia(15);
	//Here's how you write a test for an exception
	try {
		Position p = Felicia.fall_line({'A',3}); //Should throw
		//But if not, this should throw:
		cout << Felicia.get_elevation(p);
		FAIL() << "We shouldn't have gotten here - test should have thrown an exception in either fall_line or get_elevation!";
	}
	catch (const out_of_range &e) {
		//Testing strings is a bit weird - use one of these two options
		EXPECT_EQ(e.what(),string("Bad Position"));
//	EXPECT_STREQ(e.what(),"No way out!"); //FIXME: Figure out why this is failing
	}
	catch (...) {
		FAIL() << "We threw an exception that we didn't catch";
	}
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
#ifndef FOO
	//Stop people from compiling this code using 'compile'
	static_assert(false,"Type 'make' to build this, not 'compile'");
#endif
	cout << "Welcome to SNOW FAIL. Please enter your name (type \"test\" to run tests instead):\n";
	while (true) {
		string s;
		getline(cin,s);
		if (s == "test") return RUN_ALL_TESTS();
		if (accept_name(s)) {
			cout << "Welcome, " << s << "!\n";
			break;
		}
		else {
			cout << "Sorry, that name is not valid. Please re-enter:\n";
		}
	}
	cout << "You are on the Matterhorn map:\n";
	Snow matterhorn(10); //Random seed 10 for the Matterhorn
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << setw(3) << matterhorn.get_elevation({i,j});
		}
		cout << endl;
	}
	cout << "We will now compute what direction you will fall in. Please enter a coordinate as a pair of numbers:\n";
	Position p;
	cin >> p.x >> p.y;
	if (!cin) {
		cout << "Bad input.\n";
		exit(EXIT_FAILURE);
	}
	try {
		cout << "We'll now try skiing four spaces:\n";
		for (int i = 0; i < 4; i++) {
			cout << "You will ski to this point:\n";
			p = matterhorn.fall_line(p);
			cout << "(" << p.x << "," << p.y << ")\n";
		}
	} catch (runtime_error const &e) {
		if (e.what() == string("No way out!")) {
			cout << "You got stuck!\n";
			exit(EXIT_SUCCESS);
		}
	} catch (exception const &e) {
		cout << string("Big oof. Your code threw this exception: ") + e.what() << endl;
		exit(EXIT_FAILURE);
	}
	return 0;
}
