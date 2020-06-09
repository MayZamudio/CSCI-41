//Blocking chat client. It doesn't send or receive any data except when the user hits enter
// Then it updates all the missing chat from the server at once
#include <zmq.hpp>
#include <zhelpers.hpp>
#include <string>
#include <iostream>
using namespace std;
using namespace zmq;

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
	context_t context (1);
	socket_t socket (context, ZMQ_REQ);
	socket.setsockopt(ZMQ_IPV6,1);
	string hostname = "localhost";
	if (argc > 2) hostname = argv[1];
	const int DEFAULT_PORT = 2020; //Change this to any port above 1024
	int port = DEFAULT_PORT;
	//You can run it like this: client 2000 to bind it to a different port
	try {
		if (argc == 2) port = stoi(argv[1]);
		else if (argc > 2) port = stoi(argv[2]);
	} catch (...) { port = DEFAULT_PORT; }

	cout << "Connecting to chat server..." << endl;
	socket.connect ("tcp://"s + hostname + ":" + to_string(port));
	string username;
	while (true) {
		cout << "Username:\n";
		cin >> username;
		if (hascolon(username)) {
			cout << "No username can have colons.\n";
			continue;
		}
		break;
	}
	string str = username + ":LOGIN";
	s_send(socket,str);
	string response = s_recv(socket);
	cout << "Back chat log:\n";
	cout << response << endl;
	getline(cin,response);

	while (true) {
		cout << "Enter a string to send:\n";
		string message;
		getline(cin,message);
		s_send(socket,username+":"+message);
		string response = s_recv(socket);
		cout << response << endl;
	}
}
