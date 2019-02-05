#include "complextype.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

complexType::complexType() {
	rpart = 0;
	ipart = 0;
}
complexType::complexType(double r) {
	rpart = r;
	ipart = 0; 
}
complexType::complexType(double r, double i) {
	rpart = r;
	ipart = i;
}
complexType complexType:: operator*(const complexType& complex) const {
	double r, i;
	r = (rpart * complex.rpart) - (ipart * complex.ipart);
	i = (rpart * complex.ipart) + (complex.rpart * ipart);
	return complexType(r,i);
}
complexType complexType:: operator*(double real) const {
	return complexType(rpart * real, ipart * real);
}
complexType complexType:: operator/(const complexType& complex) const {
	double r, i, denom;
	denom = complex.rpart*complex.rpart + complex.ipart*complex.ipart;
	r = rpart*complex.rpart + ipart*complex.ipart;
	i = ipart*complex.rpart - (rpart * complex.ipart);
	return complexType (r/denom, i/denom);
}
complexType complexType::operator/(double real) const {
	return complexType (rpart / real, ipart / real);
}
complexType complexType::operator+(const complexType& complex) const {
	return complexType(rpart + complex.rpart, ipart + complex.ipart);
}
complexType complexType::operator+(double real) const {
	return complexType(real + rpart, ipart);
}
complexType complexType::operator-(const complexType& complex) const {
	return complexType(rpart - complex.rpart, ipart - complex.ipart);
}
complexType complexType:: operator-(double real) const {
	return complexType(rpart - real, ipart);
}
bool complexType::operator==(const complexType& complex) const {
	if((rpart == complex.rpart) and (ipart == complex.ipart))
		return true;
	else return false;
}
bool complexType::operator==(double real) const {
	if((ipart == 0) and real == rpart)
		return true;
	else return false;
}
bool complexType::operator!=(const complexType& complex) const {
	if((rpart == complex.rpart) and (ipart == complex.ipart))
			return false;
	else return true;
}
bool complexType::operator!=(double real) const {
	if((ipart == 0) and real == rpart)
		return false;
	else return true;
}
complexType operator*(double real, const complexType& complex){
	return complexType (complex.rpart * real, complex.ipart * real);
}
complexType operator/(double real, const complexType& complex){
	double r, i, denom;
	denom = complex.rpart*complex.rpart + complex.ipart*complex.ipart;
	r = real*complex.rpart;
	i = -(real * complex.ipart);
	return complexType (r/denom, i/denom);
}
complexType operator+( double real, const complexType& complex){
	return complexType (real + complex.rpart, complex.ipart);
}
complexType operator-( double real, const complexType& complex){
	return complexType (real - complex.rpart, -complex.ipart);
}
bool operator==(double real , const complexType& complex){
	if((real == complex.rpart) and complex.ipart == 0)
		return true;
	else return false;
}
bool operator!=( double real , const complexType& complex){
	if((real == complex.rpart) and complex.ipart == 0)
		return false;
	else return true;
}

istream& operator>>( istream& in, complexType& complex){

	string input;
	getline(in,input);
	input.erase(remove(input.begin(), input.end(), ' '), input.end());

	string num1, num2;
	int psign[2] = {0,0};
	int c = 0;
	char sign[2];


	for(int i = 0; i < input.length(); i++)
	{
		if(input[i] == '-' or input[i] == '+'){
			psign[c] = i;
			sign[c] = input[i];
			c++;
		}
	}

	if(psign[0] != 0 and psign[1] == 0){

			num1 = input.substr(0, psign[0]);
			num2 = input.substr(psign[0]+1, input.length()-psign[0]-2);
			int num;
			stringstream number(num1);
			number >> num;
			complex.rpart = num;
			if(sign[0] == '-')
				if(input[psign[0]+1] == 'i')
					complex.ipart = -1;
				else {
					int num;
					stringstream number2(num2);
					number2 >> num;
					complex.ipart = -num;				}
			else {
			if(input[psign[0]+1] == 'i')
				complex.ipart = 1;
			else {
				int num;
				stringstream number2(num2);
				number2 >> num;
				complex.ipart = num;				}
			}
	}
	else if(psign[0] == 0 and psign[1] != 0){
	
			num1 = input.substr(1, psign[1]-1);
			num2 = input.substr(psign[1]+1, input.length()-psign[1]-2);
			int num;
			stringstream number1(num1);
			number1 >> num;
			complex.rpart = -num;
			if(sign[1] == '-')
				if(input[psign[1]+1] == 'i')
					complex.ipart = -1;
				else {
					int num;
					stringstream number(num2);
					number >> num;
					complex.ipart = -num;
				}
			else {
			if(input[psign[1]+1] == 'i')
				complex.ipart = 1;
			else {
				int num;
				stringstream number(num2);
				number >> num;
				complex.ipart = num;
				}
			}
	}
	else if(psign[0] == 0 and psign[1] == 0 and sign[0] == '-'){
		bool realOrImaginary = true;
			for(int i = 1; i < input.length(); i++)
				if(!isdigit(input[i]))
					realOrImaginary = false;
		if(!realOrImaginary){	
			if(input[1] == 'i')
				complex.ipart = -1;
			else {
				num1 = input.substr(1,input.length() - 2);
				int num;
				stringstream number2(num1);
				number2 >> num;
				complex.ipart = -num;
			}
			complex.rpart = 0;
		}else{
			int num;
			stringstream number(input);
			number >> num;
			complex.rpart = num;
			complex.ipart = 0;
			}

	}else{
		bool realOrImaginary = true;
		for(int i = 0; i < input.length(); i++)
			if(!isdigit(input[i]))
				realOrImaginary = false;
	if(!realOrImaginary){
		num1 = input.substr(0, input.length() -1);
		complex.rpart = 0;
		if(input[0] == 'i')
			complex.ipart = 1;
		else {
			stringstream number3(num1);
			int num;
			number3 >> num;
			complex.ipart = num;
		}
	}
	else {
		int num;
		stringstream number4(input);
		number4 >> num;
		complex.rpart = num;
		complex.ipart = 0;
		}
	}
	return in;
}
ostream& operator<<( ostream& out, const complexType& complex){
	if(complex.rpart == 0){
		if(abs(complex.ipart) != 1)
			out << complex.ipart << "i" << endl;
		else if(complex.ipart == 1)
			out << "i" << endl;
		else out << "-i" << endl;
		return out;
	}	
	out << complex.rpart;
	if(complex.ipart == 0){
		out << endl;
		return out;
	}
	if(complex.ipart > 0)
		if(abs(complex.ipart) != 1)
			out << " + " << complex.ipart << "i" << endl;
		else out << " + " << "i" << endl;
	else{
		if(abs(complex.ipart) != 1)
			out << " - " << abs(complex.ipart) << "i" << endl;
		else out << " - " << "i" << endl;
	}
	return out;
}

























