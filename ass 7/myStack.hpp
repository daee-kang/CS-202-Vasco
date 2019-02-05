#include <iostream>
using namespace std;

class myStack
{
public :
    myStack ();
    myStack ( const myStack &);
    const myStack & operator =( const myStack &);
    ~ myStack ();
    void push (int );
    void pop ();
    void pop ( int &);
    int top () const ;
    bool isEmpty () const ;
private :
    size_t length ;
    int * stk ;
};
