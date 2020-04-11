#include <iostream>
#include <deque>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unistd.h>
#include "/public/colors.h"
using namespace std;

const int SIZE = 10;
const char START 	= 'S';
const char END 		= 'E';
const char OPEN 	= ' ';
const char WALL 	= '#';

void print_map(char map[SIZE][SIZE]) {
	system("clear");
	cout << BOLDRED;
	for (int i = 0; i < SIZE+2; i++) //Top border wall
		cout << WALL;
	cout << RESET << endl;
	for (int i = 0; i < SIZE; i++) {
		cout << BOLDRED << WALL << RESET; //Left border wall
		for (int j = 0; j < SIZE; j++) {
			cout << map[i][j];
		}
		cout << BOLDRED << WALL << RESET; //Right border wall
		cout << endl;
	}
	cout << BOLDRED;
	for (int i = 0; i < SIZE+2; i++) //Bottom border wall
		cout << WALL;
	cout << RESET << endl;
}

struct Tile {
	int x,y; //The location of the tile
	int from_x,from_y; //The location of the place we came from to get here
	double distance; //Our distance from the start
	Tile() = delete;
	Tile(int x, int y, int from_x, int from_y, double distance) {
		this->x = x;
		this->y = y;
		this->from_x = from_x; //-1 if the start tile
		this->from_y = from_y; //-1 if the start tile
		this->distance = distance;
	}
	bool operator==(const Tile &rhs) const {
		return (x == rhs.x and y == rhs.y);
	}
	bool operator<(Tile &rhs) const {
		return distance < rhs.distance;
	}
};

bool is_in(const Tile &t, const deque<Tile> &d) {
	auto iter = find(d.begin(),d.end(),t);
	return (iter != d.end());
}

//Takes in the location of the person to move, and will change it to be the location they need to move to
bool astar(char map[SIZE][SIZE],int &x, int &y,const int end_x, const int end_y) {
	//YOU
	deque<Tile> to_process; //deques are vectors with .push_front() and .pop_front()
	deque<Tile> processed;
	Tile start(x,y,-1,-1,0);
	to_process.push_back(start);
	while (to_process.size()) {
		sort(to_process.begin(),to_process.end()); //Find the tile with shortest distance to the start node
		Tile current = to_process.front(); //Get the shortest distance tile
		to_process.pop_front(); //Delete it from the to_process list
		if (is_in(current,processed)) continue;
		processed.push_back(current); //Add current to the processed list
		//YOU: Add all of the kids of current that are not in processed

		//YOU: If end is found, then handle that - backtrack and set x and y to the next move the user should make
	}
	return false; //No route found
}

int main() {
	int seed;
	cout << "Enter seed:\n";
	cin >> seed;
	srand(seed);
	char map[SIZE][SIZE] = {};
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			int roll = rand() % 10;
			if (roll < 3) //30% chance
				map[i][j] = WALL;
			else
				map[i][j] = OPEN;
		}
	}
	int start_x = rand() % SIZE;
	int start_y = rand() % SIZE;
	int end_x = rand() % SIZE;
	int end_y = rand() % SIZE;
	while (hypot(start_x-end_x,start_y-end_y) < SIZE/3) {
		end_x = rand() % SIZE;
		end_y = rand() % SIZE;
	}
	map[start_x][start_y] = START;
	map[end_x][end_y] = END;
	print_map(map);
	while (hypot(start_x-end_x,start_y-end_y) > 1) {
		int new_x = start_x;
		int new_y = start_y;
		bool solvable = astar(map,new_x,new_y,end_x,end_y);
		if (!solvable) {
			cout << "No route found!\n";
			exit(EXIT_SUCCESS);
		}
		map[start_x][start_y] = OPEN;
		map[new_x][new_y] = START;
		start_x = new_x;
		start_y = new_y;
		print_map(map);
		usleep(500'000);
	}
}
