#include <iostream>
#include <vector>
using namespace std;

//Inheritance describes an IS-A relationship between classes
//Animal is a super class, or a parent class
class Animal {
	public:
		int legs = 0;
		string color = "";
		bool lays_eggs = true;
		bool has_hair = false;
		string sciname = "";
		//Magic word for today is VIRTUAL
		//Add a secret member variable to the class saying what type I am
		//Adds a secret if statement, saying, "If I am an animal, print "default animal words", if I am a mammal
		// print "default mammal words", "If I am a dog, print borf", etc.
		virtual void speak() { cout << "Default animal words.\n"; }
};

//Mutate works with mammals, animals, dogs, cats... anything that inherits from Animal will work
void mutate(Animal &a) {
	a.legs += rand() % 4 + 1; //Grow 1d4 new legs
}

//HOWEVER, YOU CAN TELL C++... maybe it's not just an animal. Maybe it's a subclass? You should check.
void speak_twice(Animal &a) {
	a.speak(); //Because speak is a virtual function, it will see if it's really an animal
	a.speak(); // or a dog ro a cat or whatever
}

//Mammal IS A animal
//It copies all of the members from Animal into Mammal, so it has a color, legs, etc.
//Is Mammal a parent class or a child class? YES.
class Mammal : public Animal {
	public:
		int sweat_production = 5;
	Mammal() : Animal() { lays_eggs = false; has_hair = true; }
	void speak() { cout << "Default mammal words.\n"; }
	int sweat() { return sweat_production; }
};

//Dog IS A Mammal
class Dog : public Mammal {
	public:
		Dog() : Mammal() { sweat_production = 3; legs = 4; sciname = "Canis lupus familiaris"; }
		void speak() { cout << "Borf.\n"; }
};

//Class hierarchy
//You'll graph this stuff using what are called UML diagrams
//Animal -> Mammal -> Dog
//				   -> Cat


//Cat IS A Mammal
class Cat : public Mammal {
	public:
		Cat() : Mammal() { sweat_production = 1; legs = 4; }
		//Parent functions still exist, and you can call them using the scope resolution operator (::)
		void speak() { Mammal::speak(); cout << "Miao!\n"; }
};

int main() {
	cout << "BOB:\n";
	Animal bob;
	cout << boolalpha << bob.lays_eggs << endl;
	bob.speak();
	speak_twice(bob);

	Mammal cindy;
	cout << "CINDY:\n";
	cout << boolalpha << cindy.lays_eggs << endl;
	cindy.speak();
	cout << cindy.sweat() << endl;
	cout << cindy.legs << endl;

	Dog fido;
	cout << "FIDO:\n";
	cout << fido.lays_eggs << endl;
	fido.speak();
	cout << fido.sweat() << endl;
	cout << fido.legs << endl;

	Cat chairman_mao; 
	cout << "毛:\n";
	cout << chairman_mao.lays_eggs << endl;
	chairman_mao.speak();
	cout << chairman_mao.sweat() << endl;
	cout << "LEGS BEFORE: " << chairman_mao.legs << endl;
	mutate(chairman_mao);
	cout << "LEGS AFTER: " << chairman_mao.legs << endl;
	speak_twice(chairman_mao);

	//Trucating conversion - it throws away everything in mammal and cat, and 
	// keeps all of Mao's member variables in animal
	Animal zhou_enlai = chairman_mao; //Copy all of the animal variables fr mao to enlai
	cout << zhou_enlai.legs << endl;
	//cout << zhou_enlai.sweat() << endl;

	//Push_back will do a truncating conversion with a vector<Animal>
	//HOWEVER WITH POINTERS IT DOES NOT TRUNCATE!!@!@@@@@@@@@!@!!!!!
	vector<Animal *> vec;
	vec.push_back(&bob);
	vec.push_back(&cindy);
	vec.push_back(&fido);
	vec.push_back(&chairman_mao); //What happens to mao's sweat?
	//SEG FAULT vec.push_back((Animal *)1000); //In C you can freely convert between ints and *'s
	speak_twice(*vec.at(4)); //Works, but bleh

	//Polymporphism is when you have type flexibility
	//1. Function overloading 
	//2. Templates
	//3. Inheritance

	//Lessons for today:
	//1. You can do class hierarchies
}




