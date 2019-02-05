#include <iostream>
#include <cstdlib>
#include "myStack.hpp"

using namespace std;

myStack::myStack(){
//default constructer, sets the pointer equal to zero and starts off the
//length at 0
    stk = NULL;
    length = 0;
}
myStack::myStack(const myStack& copy){
//copy constructer, if the copy array length is zero, the constructer
//will set mystack equal to null and 0.
//else it will deep copy the copy stack into a temp and set it equal to
//the original stack.
    if(copy.length == 0){
        length = 0;
        stk = NULL;
    } else {
//        if(stk != NULL)
//            delete[] stk;
        length = copy.length;
        stk = new int[length-1];
        for (int i = 0; i < length-1; i++)
            if(this->stk != NULL)
                stk[i] = copy.stk[i];
    }
}
const myStack& myStack::operator=(const myStack& rhs){
//equal operator, basically a copy constructer. I'm not really sure
//what this function is used for in this program. But it operates just
//like the above function returning itself.
    if(this != &rhs){
        if(stk != NULL)
            delete [] stk;
        length = rhs.length;
        stk = new int[length-1];
        
        if(rhs.stk != NULL){
            for(int i = 0; i < length-1; i++)
                stk[i] = rhs.stk[i];
        }
    }
    return *this;
}
myStack::~myStack(){
//deconstructor when out of scope
    if(stk != NULL)
        delete[] stk;
}
void myStack::push(int item){
//increments length by 1. If the stack is null, it will create a new array
//with a length of basically 1 and then set the last item equal to ITEM.
//else I call the copy constructer on itself with the new length and
//set the last item equal to ITEM.
    length++;
    if(stk == NULL){
        stk = new int[length-1];
        stk[length - 1] = item;
    }
    else {
        myStack(*this);
        stk[length - 1] = item;
    }
}
void myStack::pop(){
//pop function will decrement length by 1 and call the copy constructer
//with itself to resize the array.
//if the length is 0, it will output an error and exit the program
    if(length != 0){
        length--;
        myStack(*this);
    }
    else if(length == 0){
        cout << "Invalid postfix Expression" << endl;
        exit(0);
    }
}
void myStack::pop(int& item){
//used in main that copies back the last item into ITEM. then it uses
//the pop function to resize the array.
    item = stk[length-1];
    pop();
}
int myStack::top() const{
//returns tht top of the stack without resizing
    return stk[length - 1];
}
bool myStack::isEmpty() const{
//outputs true if stack points to null. else false
    if(stk == NULL)
        return true;
    else return false;
}
