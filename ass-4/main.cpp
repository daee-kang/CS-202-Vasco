#include "complextype.h"
#include <iostream>


using namespace std;

int main(){
	complexType c1, c2, cResult;
	double num;
	cout << "Enter complex number 1: ";
	cin >> c1;
	cout << "Enter complex number 2: ";
	cin >> c2;
	cout << "Enter a real number: ";
	cin >> num;


	cout << " c1 = " << c1 << " c2 = " << c2 << " num = " << num << endl << endl;
		cout << endl << "Computations: " << endl << endl;
	cResult = c1 + c2 ;
	cout << " c1 + c2 = " << cResult ;
	cResult = c2 - c1 ;
	cout << " c2 - c1 = " << cResult ;
	cResult = c2 * c1 ;
	cout << " c2 * c1 = " << cResult ;
	cResult = c1 / c2 ;
	cout << " c1 / c2 = " << cResult ;
	if ( c1 == c2 )
	cout << " c1 equals c2 " << endl;
	else if ( c1 != c2 )
	cout << " c1 does not equal c2 " << endl;
	cResult = c2 * num ;
	cout << " c2 * num = " << cResult ;
	cResult = c1 + num ;
	cout << " c1 + num = " << cResult ;
	cResult = c2 / num ;
	cout << " c2 / num = " << cResult ;
	cResult = c2 - num ;
	cout << " c2 - num = " << cResult ;
	cResult = num * c2 ;
	cout << " num * c2 = " << cResult ;
	cResult = num / c2 ;
	cout << " num / c2 = " << cResult ;
	cResult = num + c1 ;
	cout << " num + c1 = " << cResult ;
	cResult = num - c2 ;
	cout << " num - c2 = " << cResult ;
	if ( c1 == num )
	cout << " c1 equals num " << endl ;
	else if ( c1 != num )
	cout << " c1 does not equal num " << endl ;
	if ( num == c2 )
	cout << " num equals c2 " << endl ;
	else if ( num != c2 )
	cout << " num does not equal c2 " << endl ;
	return 0;
}