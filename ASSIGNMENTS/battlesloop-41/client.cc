//NCURSES + ZMQ chat client
//by Kerney
#include <zmq.hpp>
#include <zhelpers.hpp>
#include <string>
#include <iostream>
using namespace std;
using namespace zmq;

//My cool color header
#include "/public/colors.h"

//NCURSES headers
#include <locale.h>
#include <curses.h>
#include <unistd.h>
#include <ncurses.h>
#include <vector>
//string temp_name= s_recv(socket) ;
//#define WATER '#';
string username;
socket_t *server;
void bail_out(int s = 0) {
	s = s; //Disable warning
	clear();
	endwin(); //Turn off NCURSES

	cout << username << " has left the chat." << endl;
	if (server and username != "") {
		s_send(*server,username + ":LOGOUT");
		usleep(500'000); //Let the message time to go out
	}
	exit(EXIT_SUCCESS);
}
//Pair <type T, type Y)  name= s_recv(socket);
//make_pair (T first, T second)

//To make a client using ZMQ
//Step 1. Make a socket
//Step 2. Connect to server (hostname+port)
//In a loop:
//Step 3. Send to server
//Step 4. Receive from server
//I decided to use colons as field separators, so no colons can be used in strings
bool hascolon(const string &s) {
	for (auto &c : s) if (c == ':') return true;
	return false;
}
//#define
const int UP = 65;
const int DOWN = 66;
const int LEFT = 68;
const int RIGHT = 67;
const int ESCAPE = 27;
const int ENTER = 10;
int ROWS= 10;
int COLUMNS=10;

class Grid {
	//vector<vector<int>> grid(10); WHY DOESNT THIS WORK?

	vector<vector<char>> grid;

	public:
	static const char WATER = '~';
	static const char CURSOR = '*';
	static const char DESTROYER = 'D';
	static const char SUBMARINE = 'S';
	static const char BATTLESHIP = 'B';
	static const char AIRCRAFT_CARRIER = 'A';
	static const size_t SIZE = 10;

	void fill_grid() {
		grid.resize(SIZE); //10 rows tall
		for (auto &v : grid) v.resize(SIZE,'~'); //10 
		for (size_t i = 0; i < SIZE; i++) {
			for (size_t j= 0; j < SIZE; j++) {
				//Places cursor in middle of window - Coordinates (5,5)
				if (i == SIZE/2 && j == SIZE/2) grid.at(i).at(j) = CURSOR;
			}
		}

	}
	void init_grid_window(int y, int x, WINDOW* &grid) {
		grid = newwin(12, 22, y, x);
		box(grid, 0, 0);
	}
	void display(WINDOW *win) {
		for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
				mvwaddch(win, i + 1, j * 2 + 1, grid.at(i).at(j));
			}
		}
	}
	void move_cursor(int &x, int &y, int ch) {
		if (ch == UP) {
			y--;
			if (y < 0) y = 0;
			set(x,y,CURSOR);
			set(x, y+1, WATER);
		}
		else if (ch == DOWN) {
			y++;
			if (y >= ROWS) y = ROWS - 1;
			set(x,y,CURSOR);
			set(x, y-1, WATER);
		}
		else if (ch == LEFT) {
			x--;
			if (x < 0) x = 0;
			set(x,y,CURSOR);
		}
		else if (ch == RIGHT) {
			x++;
			if (x >= COLS) x = COLS-1;
			set(x,y,CURSOR);
			//if (grid.at(x-1).at(y) == BATTLESHIP) set(x-1, y, BATTLESHIP);
			set(x-1, y, WATER);
		}
		else if (ch == ERR) { //No keystroke
			; //Do nothing
		}
	}
    void place_ship(int &x, int &y, int ch) {
		set(x,y, BATTLESHIP);
	}
	void set(int x, int y, char c) {
		grid.at(y).at(x) = c;
	}
	char get(int x, int y) {
		return grid.at(y).at(x);
	}
	Grid() {
		fill_grid();
	}
};
int main (int argc, char **argv) {
	system("figlet BATTLESLOOP");
	Grid Board;
	//Step 1. Make a socket
	context_t context (1);
	socket_t socket (context, ZMQ_REQ);
	socket.setsockopt(ZMQ_IPV6,1);
	server = &socket; //Get pointer for signal handler
	signal(SIGINT,bail_out); //Disconnect nicely
	//atexit(bail_out); 

	//Step 2. Connect to server
	string hostname = "localhost";
	if (argc > 2) hostname = argv[1];
	const int DEFAULT_PORT = 2029; //Change this to any port above 1024
	int port = DEFAULT_PORT;
	//You can run it like this: client 2000 to bind it to a different port
	try {
		if (argc == 2) port = stoi(argv[1]);
		else if (argc > 2) port = stoi(argv[2]);
	} catch (...) { port = DEFAULT_PORT; }

	cout << "Setting up your battle..." << endl;
	socket.connect ("tcp://"s + hostname + ":" + to_string(port));
	cout << "Please enter your name:\n";
	getline(cin,username);
	if (hascolon(username)) {
		cout << "No username can have colons.\n";
		exit(EXIT_FAILURE);
	}

	//Step 3. Send data to the server - login
	string str = username + ":LOGIN";
	s_send(socket,str);
	//Set up NCURSES
	if (setlocale(LC_ALL, "") == NULL) {
		cout << "Couldn't set locale.\n";
		exit(EXIT_FAILURE);
	}
	//BEGIN NCURSES
	system("clear");
	initscr();
	noecho();
	clear();
	move(0,0);
	printw("Battleslooop 41");
	move(ROWS-1,0); //Move to bottom, two ros up
	printw("%s: (coordinates)",username.c_str());
	refresh();
	WINDOW* win = nullptr;
	Board.init_grid_window(1, 1, win);
	wrefresh(win);
	int x = Grid::SIZE/2, y = Grid::SIZE/2;
	int counter = 0;
	while (true) {
		counter++;
		int ch = getch();
		if (ch == UP || ch == DOWN || ch == LEFT || ch == RIGHT) Board.move_cursor(x, y, ch);
		if (ch == ENTER) Board.place_ship(x, y, ch);
		//display the borad
		Board.display(win);
		//
		mvprintw(14,2, "%s's Coordinates",username.c_str());
		mvprintw(15,2,"X - Location: %i", x);
		mvprintw(16,2,"Y - Location: %i", y);
		wrefresh(win);
		usleep(5000);
	}
}

