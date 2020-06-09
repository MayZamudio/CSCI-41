//NCURSES + ZMQ chat client
//by Kerney
#include <zmq.hpp>
#include <zhelpers.hpp>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
using namespace zmq;

//My cool color header
#include "/public/colors.h"

//NCURSES headers
#include <locale.h>
#include <curses.h>
#include <unistd.h>

const int DEFAULT_PORT = 2222; //Change this to any port above 1024
string username; //Our username on the server
socket_t *server; //I don't use this except here
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

//Run the program like this: "client hostname portname"
//Example "client 55.22.11.78 2001"
//Or "client 2001" to use localhost as the host
int main (int argc, char **argv)
{
	int my_ships_left = 14, enemy_ships_left = 14;
	int me_placing_ship = 2, enemy_placing_ship = 2;
	const int SIZE = 10;
	const char EMPTY = '.', HIT = 'X', MISS = 'O', SHIP = 'S';
	vector<vector<char>> my_board(SIZE,vector<char>(SIZE));
	vector<vector<char>> enemy_board(SIZE,vector<char>(SIZE));
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			my_board.at(i).at(j) = EMPTY;
			enemy_board.at(i).at(j) = EMPTY;
		}
	}

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
	int port = DEFAULT_PORT;
	//You can run it like this: client 2000 to bind it to a different port
	try {
		if (argc == 2) port = stoi(argv[1]);
		else if (argc > 2) port = stoi(argv[2]);
	} catch (...) { port = DEFAULT_PORT; }

	cout << "Connecting to chat server..." << endl;
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

	initscr(); //Turns on NCURSES
	noecho(); //Turns off echoing to the screen
	cbreak(); //Disable input buffering since I will do this myself
	curs_set(0); //Hide the cursor
	keypad(stdscr,TRUE); //Enable extended input from NCURSES
	//TODO: Decouple the client frame rate from the server update rate
	const int MAXFPS = 60; //Cap framerate 
	timeout(1'000'000 / MAXFPS); //Nonblocking IO - 1/60th of a second delay if they don't type
	mousemask(ALL_MOUSE_EVENTS,NULL); //Enable mouse support

	int ROWS = 40, COLS = 20;
 	getmaxyx(stdscr, ROWS, COLS); //Read the terminals ROWS and COLS. TODO: Check for KEY_REFRESH
	idlok(stdscr,true);
	scrollok(stdscr,true);
	const int TOPCHAT = ROWS - 7;
	const int BOTCHAT = ROWS - 1;
	setscrreg(TOPCHAT,ROWS-2);

	clear(); //Erase screen

	//DRAW BOARD
	const int MY_BOARD_X = 0, MY_BOARD_Y = 2;
	move(1,0); //Row 1 col 0
	printw("Friendly Board");
	move(2,0); //Row 2 col 0
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			addch(my_board.at(i).at(j));
		}
		move(MY_BOARD_Y+i,MY_BOARD_X);
		//addch('\n');
	}

	move(1,30); //Row 1 col 0
	printw("Enemy Board");
	move(2,30); //Row 2 col 0
	const int ENEMY_BOARD_X = 30, ENEMY_BOARD_Y = 2;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			addch(enemy_board.at(i).at(j));
		}
		move(ENEMY_BOARD_Y+i,ENEMY_BOARD_X);
	}

	move(0,0); //Move the cursor on the screen to the top left
	printw("BATTLESLOOP 41");
	//mvprintw(0,0,"CSCI4X Chat"); //Literally the same thing as the above two lines

	move(BOTCHAT,0); //Move to bottom of the screen
	printw("%s: CLICK TO MAKE YOUR MOVE",username.c_str());

	//Step 4. Receive data from the server
	move(TOPCHAT,0); //Move cursor to the top of the chat log
	string response = s_recv(socket);
	printw("%s",response.c_str()); //Print the chat log from before I connected
	refresh(); //Has NCURSES redraw the screen

	int x = 0, y = 0; //Location in the world
	int row = 0, col = 0; //Last place we shot at 
	string current_str; //What the user is currently typing
	while(1)
	{
		int ch = getch(); //Does NCURSES nonblocking I/O read one character
		int cursor_y = 0, cursor_x = 0;
		getyx(stdscr,cursor_y,cursor_x); //Gets current cursor location
		/*
		move(ROWS-1,0);
		printw("Cursor location: %i %i",cursor_y,cursor_x);
		move(cursor_y,cursor_x);
		refresh();
		*/

        if (ch == ERR) { //No keystroke
            ; //Do nothing
        }
		//TODO: Add mouse support, I'm commenting this out for now
		else if(ch == KEY_MOUSE) { //Handle mouse events
			MEVENT mouse; //Struct for holding mouse events
			getmouse(&mouse);
			string temp = username + ":MOVE:" + to_string(mouse.y) + ":" + to_string(mouse.x);
			s_send(socket,temp);

			//move(0,0);
			//clrtoeol();
			//printw("%d\t%d\n",mouse.y,mouse.x);
			//mvprintw(mouse.y,mouse.x,"🤣"); //Move + printw
			//refresh();
		}
		//Handle arrow keys
		//TODO: Have them scroll the chat buffer, they don't do anything right now
        else if (ch == KEY_RIGHT) {
            x++;
			if (x >= COLS) x = COLS-1;
        }
        else if (ch == KEY_LEFT) {
            x--;
            if (x < 0) x = 0;
        }
        else if (ch == KEY_UP) {
            y--;
            if (y < 0) y = 0;
        }
        else if (ch == KEY_DOWN) {
            y++;
			if (y >= ROWS) y = ROWS - 1;
        }
		//Handle special keys like delete and enter
		else if (ch == KEY_DC or ch == KEY_BACKSPACE or ch == '') { //Delete keys
			if (current_str.size())
				current_str.pop_back();
			move(BOTCHAT,0); //Move to bottom
			clrtoeol(); //Erase the whole line
			printw("%s: %s\n",username.c_str(),current_str.c_str());
			move(cursor_y,cursor_x); //Put cursor back where it was
			refresh();
		}
		//ctrl-u erases everything typed
		//TODO: Fix this so it works
		else if (ch == KEY_DL) { //Delete line
			current_str.clear(); //Erase everything we've typed
		}
		else {
			//TODO: Unicode support
			char c = (char) ch; //Convert ch to char
			if (isprint(c) and ch != KEY_ENTER and c != ':') { //Make sure it's a printable character before adding it
				current_str += c; //Add it to the string we're typing
				move(BOTCHAT,0); //Move to bottom
				printw("%s:%s\n",username.c_str(),current_str.c_str());
				move(cursor_y,cursor_x); //Put cursor back where it was
			}
		}

		//Send a line of chat if they hit enter
		if (ch == KEY_ENTER or ch == '\n') {
			if (current_str == "QUIT" or current_str == "quit") bail_out(0);
			s_send(socket,username + ":" + current_str);
			current_str.clear(); //Erase the current line
			move(BOTCHAT,0); //Move to bottom
			printw("%s: %s\n",username.c_str(),current_str.c_str());
			move(cursor_y,cursor_x); //Put cursor back where it was
		}
		else if (ch == KEY_MOUSE) {
		}
		else //Heartbeat the server to get updates
			s_send(socket,username + ":");
		string response = s_recv(socket); //Get update from server

		//Do battlesloop here
		if (response != "") { //Ignore empty heartbeat
			//Here is the heart of the code
			stringstream sts(response);
			string user;
			getline(sts,user,':');
			string command;
			getline(sts,command,':');
			bool is_us = false;
			if (user == username) is_us = true;
			if (command == "MISS") {
				//enemy_board.at(row-ENEMY_BOARD_Y).at(col-ENEMY_BOARD_X) = MISS;
				mvaddch(row,col,MISS);
				move(cursor_y,cursor_x); //Put cursor back where it was
			}
			else if (command == "HIT") {
				//enemy_board.at(row-ENEMY_BOARD_Y).at(col-ENEMY_BOARD_X) = MISS;
				enemy_ships_left--;
				mvaddch(row,col,HIT);
				move(cursor_y,cursor_x); //Put cursor back where it was
				if (enemy_ships_left <= 0) {
					system("figlet A WINNER IS YOU");
					exit(0);
				}
			}
			else if (command == "MOVE") {
				printw("%s",response.c_str());
				string first;
				getline(sts,first,':');
				string second;
				getline(sts,second,':');
				row = stoi(first);
				col = stoi(second);

				if (is_us) {
					if (me_placing_ship <= 5) {
						//MY_BOARD_X = 0, MY_BOARD_Y = 2;
						//This maps from the screen location to the vector
						for (int i = 0; i < me_placing_ship; i++) {
							my_board.at(row-MY_BOARD_Y+i).at(col-MY_BOARD_X) = SHIP;
							mvaddch(row+i,col,SHIP);
						}
						move(cursor_y,cursor_x); //Put cursor back where it was
						me_placing_ship++;
					}
				}
				else {
					if (enemy_placing_ship <= 5) {
						//MY_BOARD_X = 0, MY_BOARD_Y = 2;
						//This maps from the screen location to the vector
						for (int i = 0; i < enemy_placing_ship; i++) {
							//enemy_board.at(row-ENEMY_BOARD_Y+i).at(col-ENEMY_BOARD_X) = SHIP;
							mvaddch(row+i,col,SHIP);
						}
						move(cursor_y,cursor_x); //Put cursor back where it was
						enemy_placing_ship++;
					}
					else {
						//TODO: Bounds check the attack
						if (my_board.at(row-MY_BOARD_Y).at(col-MY_BOARD_X) == SHIP) {
							my_ships_left--;
							if (my_ships_left <= 0) {
								s_send(socket,username+":LOSE");
								system("figlet YOU LOSE");
								exit(0);
							}
							s_send(socket,username+":HIT");
							string temp = s_recv(socket); //Discard response DANGER
							my_board.at(row-MY_BOARD_Y).at(col-MY_BOARD_X) = HIT;
							mvaddch(row,col,HIT);
							move(cursor_y,cursor_x); //Put cursor back where it was
						}
						else {
							s_send(socket,username+":MISS");
							string temp = s_recv(socket); //Discard response DANGER
							my_board.at(row-MY_BOARD_Y).at(col-MY_BOARD_X) = MISS;
							mvaddch(row,col,MISS);
							move(cursor_y,cursor_x); //Put cursor back where it was
						}
					}
				}
			}
			else {
				printw("%s",response.c_str());
			}
		}


		if (ch == ERR and response == "") 
			; //Nothing happened, don't refresh
		else
			refresh();
		//usleep(1'000'000 / MAXFPS); //Cap frame rate at FPS
		usleep(1'000); //Cap frame rate at FPS
	}
	
	endwin(); //Turn off NCURSES
	return 0;
}
