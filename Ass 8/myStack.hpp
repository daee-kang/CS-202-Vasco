#include <iostream>

using namespace std;

class myStack {
public:
    struct node
    {
        int value;
        node * link;
    };
    myStack ();
    myStack(const myStack&);
    const myStack& operator=(const myStack&); ~myStack();
    void push(int);
    void pop ();
    void pop(int&);
    int top() const;
    bool isEmpty() const;
private:
    void destroyStack ();
    void copyStack(const myStack&);
    node * head;
    node * tail;
};
