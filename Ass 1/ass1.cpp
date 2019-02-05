#include <iostream>
using namespace std;

int main(){
//var declarations
	signed int decNum;
	int count = 0;
	int place = 31;
	bool biNum[31] = {false};
//input for number; also checks for input failure
	cout << "Enter a number:" << endl;
	cin >> decNum;

	while(cin.fail()){
    cin.clear();
    cin.ignore(100,'\n');
    cout << "Enter a number: ";
    cin >> decNum;
 	}
//if inputted number is negative, changes biNum[0] to be 1
 	if(decNum > 0)
 		biNum[0] = true;
//outputs inputted number before it is manipulated
	cout << decNum;
/* main algorithm as instructed, also added is a counter to check 
for digit places. Useful for printing out number without leading 0's */
 	while(decNum != 0){
 		int g;
		g = decNum % 2;
 		biNum[place] = g;
 		decNum = decNum / 2;
 		place--;
 		count++;
 	}
/*outputs negative sign if number is negative, also checks if output is 
 	just zero in which it then ends the program*/
 	cout << " in binary is ";
 	if(!count){
 		cout << "0" << endl;
 		return 0;
 	}
 	if(!biNum[0])
 		cout << "-";
//loop using the before mentioned counter to print out binary equivalent num
 	for(int i = 32 - count; i < 32; i++)
    cout << biNum[i];
	cout << endl;
}
