#include <iostream>
using namespace std;

class complexType
{
public :
	complexType ();
	complexType ( double );
	complexType ( double , double );
	complexType operator*( const complexType&) const ;
	complexType operator*( double ) const ;
	complexType operator/( const complexType&) const ;
	complexType operator/( double ) const ;
	complexType operator+( const complexType&) const ;
	complexType operator+( double ) const ;
	complexType operator-( const complexType&) const ;
	complexType operator-( double ) const ;
	bool operator==( const complexType&) const ;
	bool operator==( double ) const ;
	bool operator!=( const complexType&) const ;
	bool operator!=( double ) const ;
	friend complexType operator*( double , const complexType&);
	friend complexType operator/( double , const complexType&);
	friend complexType operator+( double , const complexType&);
	friend complexType operator-( double , const complexType&);
	friend bool operator==( double , const complexType&);
	friend bool operator!=( double , const complexType&);
	friend istream& operator>>( istream& , complexType&);
	friend ostream& operator<<( ostream& , const complexType&);
private :
	double rpart ;
	double ipart ;
};