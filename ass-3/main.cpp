#include <iostream>
#include <fstream>
#include <cstdlib>
#include "battleship.h"
using namespace std;

int main(){
//read-in
	string name;
	ifstream in;
	while(!in.is_open()){
		cout << "Enter filename: ";
		cin >> name;
		in.open(name);
	}
	battleship ship(in);
//main game loop
	while(ship.isOver() == 'C'){
		char x;
		int y;
		cout << "Enter coordinates: ";
		cin >> x; 
		cin >> y;
		x = toupper(x);
		
		char result = ship.fire(x,y);

		if(result == 'E'){
			cout << "Error" << endl << endl;
			cin.clear();
		}if(result == 'H'){
			cout << endl << "you hit son" << endl << endl;
			cout << "Current status:" << endl << ship.getGrid() << endl;
			cout << "Ammo remaining: " << ship.remaining() << endl;;
		}if(result == 'M'){
			cout << endl << "you missed son" << endl << endl;
			cout << "Current status:" << endl << ship.getGrid() << endl;
			cout << "Ammo remaining: " << ship.remaining() << endl;;
		}
	}
	if(ship.isOver() == 'W')
		cout << endl << "wow you won" << endl;
	if(ship.isOver() == 'L')
		cout << endl << "we lost u r garbage" << endl;
	return 0;
}