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
class Grid{
//vector<vector<int>> grid(10); WHY DOESNT THIS WORK?
int ROWS= 10;
int COLUMNS=10;
vector<vector<char>> grid;
    public:
Grid(){
        grid.clear();
        grid.resize(COLUMNS); //100 rows tall
        for (auto &v : grid) v.resize(ROWS,'~'); //100 columns wide漀
}
void display(){
	for(vector v: grid){
			printw("\n");
		for (char c: v){
			printw("%c ", c);}
				printw("\n");}}
};
const int UP = 65; //Key code for up arrow
const int DOWN = 66;
const int LEFT = 68;
const int RIGHT = 67;
//Run the program like this: "client hostname portname"
//Example "client 55.22.11.78 2001"
//Or "client 2001" to use localhost as the host
int main (int argc, char **argv)
{
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

	initscr();
	noecho();
	cbreak(); //Disable input buffering since I will do this myself
	//curs_set(0); //Hide the cursor
	keypad(stdscr,TRUE); //Enable extended input from NCURSES
	timeout(0); //Nonblocking IO
	const int MAXFPS = 60; //Cap framerate at 30fps
	mousemask(ALL_MOUSE_EVENTS,NULL); //Enable mouse support

	int ROWS = 60, COLS = 20;
 	getmaxyx(stdscr, ROWS, COLS); //Read the terminals ROWS and COLS. TODO: Check for KEY_REFRESH
	idlok(stdscr,true);
	scrollok(stdscr,true);
	setscrreg(1,ROWS-3);

	clear(); //Erase screen

	move(0,0); //Move to top left
	printw("Battleslooop 41");
	Board.display();
	move(ROWS-1,0); //Move to bottom, two ros up
	printw("%s: (coordinates)",username.c_str());

	//Step 4. Receive data from the server
	move(1,0); //Move cursor to the second line
	string response = s_recv(socket);
		if(response=="Connection refused"){
			clear();
			endwin();
			cout<<"Connection refused\n";
			exit(0);
		}
	
	printw("%s",response.c_str());
	refresh();

	int x = 0, y = 0; //Location in the world
	string current_str; //What the user is currently typing
	while(1)
	{
		int ch = getch();
		int cursor_y = 0, cursor_x = 0;
		getyx(stdscr,cursor_y,cursor_x); //Gets current cursor location
		
		move(ROWS-1,0);
		printw("Cursor location: %i %i",cursor_y,cursor_x);
		refresh();
		
		move(cursor_y,cursor_x);

        if (ch == ERR) { //No keystroke
            ; //Do nothing
        }
		//TODO: Add mouse support, I'm commenting this out for now
		else if(ch == KEY_MOUSE) { //Handle mouse events
			MEVENT mouse; //Struct for holding mouse events
			getmouse(&mouse);

			//move(0,0);
			//clrtoeol();
			//printw("%d\t%d\n",mouse.y,mouse.x);
			//mvprintw(mouse.y,mouse.x,"🤣"); //Move + printw
			//refresh();
		}
		//Handle arrow keys
		//TODO: Have them scroll the chat buffer, they don't do anything right now
        else if (ch ==RIGHT) {
          // cursor_x++;
		   x++;
			if (x >= COLS) x = COLS-1;
        }
        else if (ch == LEFT) {
            x--;
		//	cursor_x--;
            if (x < 0) x = 0;
        }
        else if (ch == UP) {
            y--;
            if (y < 0) y = 0;
        }
        else if (ch == DOWN) {
            y++;
			if (y >= ROWS) y = ROWS - 1;
        }
		//Handle special keys like delete and enter
		else if (ch == KEY_DC or ch == KEY_BACKSPACE or ch == '') { //Delete keys
			if (current_str.size())
				current_str.pop_back();
			move(ROWS-1,0); //Move to bottom
			clrtoeol(); //Erase the whole line
			printw("%s: %s\n",username.c_str(),current_str.c_str());
			move(cursor_y,cursor_x); //Put cursor back where it was
			refresh();
		}
		//ctrl-u erases everything typed
		else if (ch == KEY_DL) { //Delete line
			current_str.clear(); //Erase everything we've typed
		}
		else {
			char c = (char) ch; //Convert ch to char
			if (isprint(c) and ch != KEY_ENTER and c != ':') { //Make sure it's a printable character before adding it
				current_str += c; //Add it to the string we're typing
				move(ROWS-1,0); //Move to bottom
				printw("%s: %s\n",username.c_str(),current_str.c_str());
				move(cursor_y,cursor_x); //Put cursor back where it was
			}
		}

		//Send a line of chat if they hit enter
		if (ch == KEY_ENTER or ch == '\n') {
			if (current_str == "QUIT" or current_str == "quit") exit(0);
			s_send(socket,username + ":" + current_str);
			current_str.clear(); //Erase the current line
			move(ROWS-1,0); //Move to bottom
			printw("%s: %s\n",username.c_str(),current_str.c_str());
			move(cursor_y,cursor_x); //Put cursor back where it was
		}
		else //Heartbeat the server to get updates
			s_send(socket,username + ":");
		string response = s_recv(socket); //Get update from server
		if (response != "") //Ignore empty heartbeat
			printw("%s",response.c_str());
				
		if (ch == ERR and response == "") 
			; //Nothing happened, don't refresh
		else
			refresh();
		usleep(1'000'000 / MAXFPS); //Cap frame rate at FPS
	}
	
	endwin(); //Turn off NCURSES
	return 0;
}
	//printw( "%s", s.c_str())i
/*  void draw(int x, int y) {
        int start_x = x - DISPLAY;
        int end_x = x + DISPLAY;
        int start_y = y - DISPLAY/2;
        int end_y = y + DISPLAY/2;
        //Bounds check to handle the edges
        if (start_x < 0) {
            end_x = end_x - start_x;
            start_x = 0;
        }
        if (end_x > SIZE-1) {
            start_x = start_x - (end_x - (SIZE-1));
            end_x = SIZE-1;
        }
        if (start_y < 0) {
            end_y = end_y - start_y;
            start_y = 0;
        }
        if (end_y > SIZE-1) {
            start_y = start_y - (end_y - (SIZE-1));
            end_y = SIZE-1;
        }
        //Now draw the grid using NCURSES
        for (size_t i = start_y; i <= end_y; i++) {
            for (size_t j = start_x; j <= end_x; j++) {
                //if (i == cursor_x && j == cursor_y)
                //  attron(A_UNDERLINE | A_BOLD);
                int color = 1;
                if (grid.at(i).at(j) == WALL)
                    color = 5;
                else if (grid.at(i).at(j) == LAND)
                    color = 2;
                else if (grid.at(i).at(j) == HERO)
                    color = 3;
                else if (grid.at(i).at(j) == TREASURE)
                    color = 4;
                else if (grid.at(i).at(j) == MONSTER)
                    color = 6;
                attron(COLOR_PAIR(color));
                mvaddch(i-start_y,j-start_x,grid.at(i).at(j));
                attroff(COLOR_PAIR(color));
                //attroff(A_UNDERLINE | A_BOLD);
            }
        }
    }
*/
