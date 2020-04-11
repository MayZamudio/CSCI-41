#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

class Animal {
	public:
		float x=0,y=0,z=0;
		virtual string speak() = 0; //Pure virtual function
		/* {
			return "Be cool, stay in school";
		}
		*/
		void move(float x, float y, float z) {
			this->x += x;
			this->y += y;
			this->z += z;
			cout << "My new location is: " << this->x << "," << this->y << "," << this->z << endl;
		}
};

class Winged : public Animal {
	public:
		//string speak() = delete;
		string speak() {
			return "Twitter is a great platform for sharing free speech";
		}
		void fly() {
			cout << "Flying up!\n";
			z = z + 10;
			cout << "Height now: " << z << endl;
		}
};

class Mammal : public Animal {
	public:
		int milk_units = 0;
		string speak() {
			return "Winners don't do drugs";
		}
		void milk() {
			cout << "Milk has been ordered on Amazon prime, will be delivered in 24 hours.\n";
			milk_units++;
			cout << milk_units << " units of milk have been ordered to date.\n";
		}
};

class Fish : public Animal {
	public:
		//string speak() = delete;
		void swim() { x += 5; }
};

class Fox : public Mammal {
	public:
		string speak() {
			if (rand() % 2) 
				return "Ring ding ding ding ding ding ding";
			else
				return "Whap pow pow pow pow pow pow";
		}
};

class Bat : public Winged {
	public:
		string speak() {
			return Winged::speak() + "... I am the night.";
		}
};

float distance(Animal *a) {
	return hypot(a->x,a->y,a->z);
}

string uppercaseify(string s) {
	for (char &c : s) c = toupper(c);
	return s;
}

string yell(Animal *a) {
	return uppercaseify(a->speak());
}

int main() {
	srand(time(0));
	Bat b;
	b.x = 10;
	b.y = 0;
	b.z = 0;
	cout << "Bat is: " << distance(&b) << " from the origin\n";
	cout << b.speak() << endl;
	b.fly();
	cout << "Bat is: " << distance(&b) << " from the origin\n";
	b.fly();
	cout << "Bat is: " << distance(&b) << " from the origin\n";
	b.fly();
	cout << "Bat is: " << distance(&b) << " from the origin\n";
	cout << "---------------------------------------------\n";

	/*
	Animal a;
	a.x = 1;
	a.y = 1;
	cout << a.speak() << endl;
	cout << "Animal is: " << distance(&a) << " from the origin\n";
	*/

	Fox f;
	f.x = 10;
	f.y = 10;
	f.z = 10;
	cout << f.speak() << endl;
	cout << "Fox is: " << distance(&f) << " from the origin\n";
	cout << f.speak() << endl;
	cout << f.speak() << endl;
	cout << f.speak() << endl;
	cout << f.speak() << endl;
	f.milk();
	f.milk();
	f.milk();

	Winged bird;
	cout << bird.speak() << endl;
	bird.fly();
	cout << "Bird is: " << distance(&bird) << " from the origin\n";

	Mammal m;
	cout << m.speak() << endl;
	m.milk();
	m.milk();
	m.milk();
	//cout << "ANIMAL YELL: " << yell(&a) << endl;
	cout << "MAMMAL YELL: " << yell(&m) << endl;
	cout << "FOX YELL: " << yell(&f) << endl;
	cout << "BIRD YELL: " << yell(&bird) << endl;
	cout << "BAT YELL: " << yell(&b) << endl;
}
