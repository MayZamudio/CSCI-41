#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
	const string ball = "🍕";
	const string wall = "🧀";
	const int FPS = 100;
	const int MAX_X = 20, MAX_Y = 20; //20 columns and rows
	int x_pos = 0, y_pos = 0;
	int x_vel = 0, y_vel = 0;
	int x_acc = 0, y_acc = 0;
	cout << "Please enter x and y starting location:\n";
	cin >> x_pos >> y_pos;
	cout << "Please enter x and y starting velocity:\n";
	cin >> x_vel >> y_vel;
	cout << "Please enter x and y starting acceleration:\n";
	cin >> x_acc >> y_acc;

	while (true) {
		//Step 1 - Clear the screen
		cout << ''; //Type ctrl-v followed by ctrl-l

		//Step 2 - Run physics
		x_pos += x_vel;
		if(x_pos >= MAX_X) {
			x_vel *= -1;
			x_pos = MAX_X -1;
		} else if(x_pos <= 0) {
			x_vel *= -1;
			x_pos = 1;
		}
		y_pos += y_vel;
		if(y_pos >= MAX_Y-1) {
			y_vel *= -1;
			y_pos = MAX_Y -2;
		} else if(y_pos <= 0) {
			y_vel *= -1;
			y_pos = 1;
		}
		x_vel += x_acc;
		y_vel += y_acc;
		cout << x_pos << " " << y_pos << endl;
		

		//Step 3 - Draw the screen
		for(int i = 0; i < MAX_Y; i++) {
			cout << wall;
			for(int j = 0; j < MAX_X; j++) {
				if(j == 0) continue;
				if(i == 0) cout << wall;
				else if(i == y_pos && j == x_pos) cout << ball;
				else if(i == MAX_Y-1) cout << wall;
				else cout << " ";
			}
			cout << wall;
			cout << endl;
		}

		//Step 4 - Pause
		usleep(1000000/FPS);
	}
}
