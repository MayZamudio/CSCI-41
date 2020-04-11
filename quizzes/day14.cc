#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

void swop(int &x, int &y) {
	int z = x;
	x = y;
	y = z;
}

//Sometimes people write comments like this...
//IN: x
//OUT: first, second, third
void digits(int x, int &first, int &second, int &third) {
	third  =  x % 10; //534 % 10 = 4
	second = (x / 10) % 10; //534 / 10 = 53. 53 % 10 = 3
	first  = (x / 100) % 10; //534 / 100 = 5. 5 % 10 = 5
}

const int FIRE = 0;
const int GRASS = 1;
const int AGUA = 2;

//IN and OUT: health, lives
//OUT: damage
void damage(int &health, int damage, int &lives, int attacking_type, int defending_type) {
	//Any type to itself is half damage
	//Fire to water is half damage, Fire to grass is double damage
	//Grass to fire is half damage, Grass to agua is double damage
	//Agua to grass is half damage, Agua to fire is double damage
	health -= damage;
	if (health <= 0) {
		health = 100;
		lives--;
	}
}

int main() {
	/*
	int a = 5, b = 10;
	swop(a,b);
	cout << a << " " << b << endl;
	int bob = 421;
	int first,second,third;
	digits(bob, first, second, third);
	cout << bob << " " << first << " " << second << " " << third << endl;
	*/
	int health = 100;
	int lives = 3;
	while (lives) {
		cout << "Health: " << health << " Lives: " << lives << endl;
		int dam = rand() % 20 + 1;
		cout << "Doing " << dam << " damage.\n";
		cout << "What attacking type? (0 = Fire, 1 = Grass, 2 = Agua)\n";
		int attacking_type = 0, defending_type = 0;
		cin >> attacking_type;
		cout << "What defending type? (0 = Fire, 1 = Grass, 2 = Agua)\n";
		cin >> defending_type;
		damage(health, dam, lives,attacking_type, defending_type);
		cout << "Health is now: " << health << endl;
	}
	cout << "Ded.\n";
}












