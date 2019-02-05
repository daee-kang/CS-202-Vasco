#include "myStack.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

void myStack::destroyStack(){
    node *temp =head;
    node *next;
    
    while(temp != nullptr){
        next = temp->link;
        delete temp;
        temp = next;
    }
    head = NULL;
}
void myStack::copyStack(const myStack &copy){
}
myStack::myStack(){
    head = tail = nullptr;
}
const myStack& myStack::operator=(const myStack& rhs){
    return *this;
}
myStack::~myStack(){
    destroyStack();
}
void myStack::push(int item){
    node *newNode;
    newNode = new node;
    newNode->value = item;
    newNode->link = nullptr;
    
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        if(head->link == nullptr){
            head->link = newNode;
        }
        tail->link = newNode;
        tail = newNode;
    }
}
void myStack::pop(){
    if(head == nullptr)
        cout << "Error" << endl;
    else{
        node* current;
        node* trailCurrent = nullptr;
        
        current = head;
        
        while(current->link != NULL){
            trailCurrent = current;
            current = current->link;
        }

        tail = trailCurrent;
        delete current;
        if(tail == nullptr)
            head = nullptr;
        else trailCurrent->link = nullptr;
    }
}
void myStack::pop(int& item){
    if(head == nullptr){
        cout << "Error Invalid expression" << endl;
        exit(0);
    }
    else {item = tail->value;
        pop();}
}
int myStack::top() const {
    return tail->value;
    
}
bool myStack::isEmpty() const {
    if(head == nullptr){
        return true;
    } else return false;
}
