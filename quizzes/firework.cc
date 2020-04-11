#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unistd.h>
#include "/public/colors.h"
using namespace std;

const char EMPTY = '.';
const char PLAYER1 = 'X', PLAYER2 = 'O', WALL = '#', FIREWORK = '*';
const int ROWS = 30, COLS = 30;
//int wall_trap = -1;

void print_array(char arr[ROWS][COLS]) {
	//Will draw a WALL above the world
	for (int i = 0; i < COLS+2; i++)
		cout << WALL;
	cout << endl;
	for (int i = 0; i < ROWS; i++) {
		/*
		if (i <= wall_trap) {
			for (int i = 0; i < COLS+2; i++)
				cout << WALL;
			cout << endl;
			continue;
		}
		*/
		for (int j = 0; j < COLS; j++) {
			if (j == 0) cout << WALL; //Left wall
			if (arr[i][j] == FIREWORK) {
				switch (rand() % 10) {
					case 0:
						cout << BLUE;
						break;
					case 1:
						cout << RED;
						break;
					case 2:
						cout << GREEN;
						break;
					case 3:
						cout << CYAN;
						break;
					case 4:
						cout << MAGENTA;
						break;
					case 5:
						cout << WHITE;
						break;
					case 6:
						cout << BOLDBLUE;
						break;
					case 7:
						cout << BOLDRED;
						break;
					case 8:
						cout << YELLOW;
						break;
					case 9:
						cout << BOLDGREEN;
						break;
				}
				cout << arr[i][j];
				cout << RESET;
			}
			else {
				cout << arr[i][j];
			}
			if (j == COLS-1) cout << WALL; //Right wall
		}
		cout << endl;
	}
	//Will draw a WALL below the world
	for (int i = 0; i < COLS+2; i++)
		cout << WALL;
	cout << endl;
}

void draw_circle(char arr[ROWS][COLS], int x, int y, int radius) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			//Compute the distance from (j,i) to (x,y)
			//Option 1
			float distance = hypot((j-x),(i-y));
			//Option 2
			//float distance = sqrt(pow((j-x),2)+pow((i-y),2));
			if (distance <= radius) 
				arr[i][j] = FIREWORK;
			else
				arr[i][j] = EMPTY; 
		}
	}
}

void refresh(char arr[ROWS][COLS]) {
		system("clear");
		print_array(arr);
		usleep(250'000); //250,000 - 4fps
}

int main() {
	char arr[ROWS][COLS]; //20 rows and 10 columns
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			arr[i][j] = EMPTY; //Characters use single quotes, strings use double quotes
		}
	}
	cout << "Please enter x,y starting location:\n";
	int x = 0, y = 0;
	cin >> x >> y;
	int radius = 0;
	while (true) {
		radius++;
		draw_circle(arr,x,y,radius);
		if (radius > ROWS) radius = 1;
		refresh(arr);
	}
	/*
	int x = 0, y = 0;
	int vel_x = 0, vel_y = 0;
	cout << "Please enter x,y starting location:\n";
	cin >> x >> y;
	cout << "Please enter vel_x,vel_y starting values:\n";
	cin >> vel_x >> vel_y;
	if (!cin) exit(0);
	while(true) {
		arr[y][x] = EMPTY;
		x += vel_x;
		y += vel_y;
		if (x >= COLS) {
			int overshoot = x - (COLS-1);
			x = COLS-1-overshoot;
			vel_x *= -1;
		}
		if (y >= ROWS) {
			int overshoot = y - (ROWS-1);
			y = ROWS-1-overshoot;
			vel_y *= -1;
		}
		if (x < 0 ) {
			x = -x;
			vel_x *= -1;
		}
		if (y <= wall_trap) {
			y = wall_trap+1;
			vel_y *= -1;
		}
		arr[y][x] = WALL;
		refresh();
		wall_trap++;
		if (wall_trap >= ROWS-1) wall_trap = -1;
	}
	*/
}
