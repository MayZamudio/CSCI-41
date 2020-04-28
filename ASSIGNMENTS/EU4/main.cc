#include <iostream>
#include "ll.h"
using namespace std;

int main() {
	cout << "Welcome to the EU4 Simulator\n";
	cout << "1) Test your Linked List Node class\n";
	cout << "2) Test your List class\n";
	cout << "3) Simulate the AI\n";
	int choice = 0;
	cin >> choice;
	if (!cin || choice < 0 || choice > 3) die();
	if (choice == 1) {
		cout << "Checking your Linked List Node class...\n";
		LL_test();
		cout << "All tests passed.\n";
		return 0;
	}
	else if (choice == 2) {
		cout << "Checking your List class...\n";
		List_test();
		cout << "All tests passed.\n";
	}
	else {
		int soldiers = 0; //Manpower
		int points = 0; //Diplomacy Points
		List pti; //Provinces to Invade
		List pta; //Provinces to Annex
		while (true) {
			cout << "------------------------------------\n";
			cout << "Soldiers: " << soldiers << endl;
			cout << "Diplomacy Points: " << points << endl;
			cout << "Provinces Available to Invade: " << pti.get_size() << endl;
			cout << "Provinces Available to Annex: " << pta.get_size() << endl;
			cout << "1) Add Soldiers\n2) Add Diplomacy Points\n3) Add Province to Invade\n4) Add High Priority Province to Invade\n5) Invade Provinces\n";
			cout << "6) Add Province to Annex\n7) Add High Priority Province to Annex\n8) Annex Provinces\n9) Print all provinces\n";
			cout << "0) Quit\n";
			cout << "------------------------------------\n";
			int choice = 0;
			cin >> choice;
			if (!cin) die();
			if (choice == 0) return 0;
			if (choice < 1 || choice > 9) continue;
			if (choice == 1) { //Add Manpower
				cout << "How many soldiers would you like to recruit?\n";
				int recruits = 0;
				cin >> recruits;
				if (!cin || recruits < 0) die();
				soldiers += recruits;
			}
			else if (choice == 2) {
				cout << "How many diplomacy points would you like to gain?\n";
				int diplomacy = 0;
				cin >> diplomacy;
				if (!cin || diplomacy < 0) die();
				points += diplomacy;
			}
			else if (choice == 3) {
				cout << "Please enter the name of a province you can potentially invade:\n";
				string s;
				cin >> s;
				if (!cin) die();
				cout << "Please enter how many soldiers it will take to invade:\n";
				int soldiers;
				cin >> soldiers;
				if (!cin || soldiers < 0) die();
				//YOU: Write code here to insert at the end of pti a province that will cost soldiers to invade and has a name of s
				pti.insert_at_end(soldiers, s);
			}
			else if (choice == 4) {
				cout << "Please enter the name of a high priority province you can potentially invade:\n";
				string s;
				cin >> s;
				if (!cin) die();
				cout << "Please enter how many soldiers it will take to invade:\n";
				int soldiers;
				cin >> soldiers;
				if (!cin || soldiers < 0) die();
				//YOU: Write code here to insert at the beginning of pti a province that will cost soldiers to invade and has a name of s
				pti.insert_at_beginning(soldiers, s);
			}
			else if (choice == 5) {
				string temp = pti.delete_amount(soldiers, soldiers);
				cout << temp << endl;
				//Write code here that will delete from pti, and update soldiers based on how many were used in the invasion
			}
			else if (choice == 6) {
				cout << "Please enter the name of a province you can potentially annex:\n";
				string s;
				cin >> s;
				if (!cin) die();
				cout << "Please enter how many diplomacy points it will take to annex:\n";
				int diplomacy;
				cin >> diplomacy;
				if (!cin || diplomacy < 0) die();
				pta.insert_at_end(diplomacy, s);
				//YOU: Write code here to insert at the end of pta a province that will cost diplomancy to invade and has a name of s
			}
			else if (choice == 7) {
				cout << "Please enter the name of a high priority province you can potentially annex:\n";
				string s;
				cin >> s;
				if (!cin) die();
				cout << "Please enter how many diplomacy points it will take to annex:\n";
				int diplomacy;
				cin >> diplomacy;
				if (!cin || diplomacy < 0) die();
				pta.insert_at_beginning(diplomacy, s);
				//YOU: Write code here to insert at the beginning of pta a province that will cost diplomancy to invade and has a name of s
			}
			else if (choice == 8) {
				string s;
				string del = "";
				bool deleted = false;
				while (true) {
				//	if (points <= 0) break;
					s = pta.delete_amount(points, points);//Write code here to keep deleting provinces from pta until we fail to delete with our remaining diplo points
					if (s == "Nothing deleted") break;
					else {deleted = true;
					del = del + "\n" + s + "\n";
					}
				} 
				if (!deleted) {
					cout << "Nothing deleted\n";
				} else cout << del << endl;
			}
			else {
				cout << "List of all provinces it is possible to invade:\n";
				cout << pti.print_list();
				cout << "List of all provinces it is possible to annex:\n";
				cout << pta.print_list();
			}
		}
	}
}
