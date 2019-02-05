#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct automobile{
	string make;
	string model;
	unsigned int year;
	string color;
	unsigned int msrp;
};

void printOut(automobile[],int);
//prints out all entries of struct based on array pos
void bubbleSort(automobile[],string);
//sorts array numerically based on input high or low

int main(int args, char * argv[]){	
//variable declarations
	string entry,type;
	int i = 0;
	automobile car[20];
//opening file for read-in	
	ifstream in;
	in.open(argv[1]);
//reading file into struct; looped
	in >> car[i].make;	
	while(in){
		in >> car[i].model;
		in >> car[i].year;
		in >> car[i].color;
		in >> car[i].msrp;
		i++;
		in >> car[i].make;
	}
//loop to check if input is valid
	bool successful = false;
	while(!successful){
		successful = true;
//reads in first word(entry)	
		cout << "Enter search type or 'q' to quit: ";
		cin >> entry;
//lowercases first input word		
		for(int i = 0; i < entry.length(); i++){
			entry[i] = tolower(entry[i]);
		}
//checks for q before moving onto the second word inputed
		if(entry == "q"){
			cout << "ok no problem please come back" << endl;
			return 0;
		}
//checks first input to see if it is valid, if not it repeats 
		if(!(entry == "make" || entry == "model" || entry == "year" || entry == "color" || 
			entry == "list")){
			cin.ignore(100, '\n');
			cout << "please give me a real categorie man " << endl;
			successful = false;
		}
//second word (type) inputed		
		
		if(successful == true) cin >> type;
//lowercases entire word and uppercases the first letter
		for(int i = 0; i < type.length(); i++){
			type[i] = tolower(type[i]);
		}
		type[0] = toupper(type[0]);
//Search algorithm, if entry matches, outputs all entries that matches type
		if(entry == "make"){
			for(int i = 0; i < 20; i++){
				if(type == car[i].make){
					printOut(car, i);
				}
			}
		}if(entry == "model"){
			for(int i = 0; i < 20; i++){
				if(type == car[i].model){
					printOut(car, i);
				}
			}
		}if(entry == "year"){
			for(int i = 0; i < 20; i++){
				if(type == to_string(car[i].year)){
					printOut(car, i);
				}
			}
		}if(entry == "color"){
			for(int i = 0; i < 20; i++){
				if(type == car[i].color){
					printOut(car, i);
				}
			}
		}if(entry == "list"){
			if(type == "Low" || type == "High"){
				bubbleSort(car,type);
				for(int i = 0; i < 20; i++)
					printOut(car, i);
			}
		}
	}
}
void printOut(automobile car[], int i){
	cout << "Make: " << car[i].make << endl;
	cout << "Model: " << car[i].model << endl;
	cout << "Year: " << car[i].year << endl;
	cout << "Color: " << car[i].color << endl;
	cout << "MSRP: " << car[i].msrp << endl << endl;
}
void bubbleSort(automobile car[],string order){
   automobile temp;
   for (int i=0; i < 20-1; i++)
       for (int j=0; j < 20-(i+1); j++){
//If input is 'high', descends from low to high
       	if(order == "High"){
         	if (car[j].msrp > car[j+1].msrp){
            temp = car[j];
            car[j] = car[j+1];
            car[j+1] = temp;
         	}
     	}
//If input is 'low', descends from high to low
     	if(order =="Low"){
     		if (car[j].msrp < car[j+1].msrp){
            temp = car[j];
            car[j] = car[j+1];
            car[j+1] = temp;
         	}
     	}
	}
}