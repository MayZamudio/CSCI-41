#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "menu.h"

using namespace std;

void Menu::showMenu() {
	cout << endl << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
    cout << endl;
   	system("figlet FARKLE | lolcat");
    cout << endl << "✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶✶\n";
	cout << "\n 1. View Rules" << endl;
	cout << "\n 2. Play" << endl;
	cout << "\n 3. Quit" << endl << endl;
	cout << "\n> ";
}

void Menu:: showRules() {
	    
	string lineInFile;
    ifstream inputfile;
    inputfile.open("rules.txt");
    while(getline(inputfile, lineInFile)) {
        cout << lineInFile << '\n';
    }
    inputfile.close();	
}
