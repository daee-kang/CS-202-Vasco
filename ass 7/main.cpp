#include <iostream>
#include "myStack.hpp"
#include <string>


using namespace std;

int main(){
//input for operation
    cout << "Enter postfix string: ";
    string input;
    getline(cin, input);
//creation of the stack
    myStack stack = myStack();
//variable declarations
    bool isFinished = false;//checks to see if the loop is finished running
    int count = 0;//count for array position
    int numberCount = 0, operatorCount = 0;//used at the end to see if numbercount-1 == operatorcount for proper notation
//main loop
    while(!isFinished){
        if(isdigit(input[count])){
            //reads in digit into the stack
            char temp = input[count];
            int i = temp - '0';//for proper char conversion to int
            stack.push(i);
            numberCount++;
        }
        
        else if(input[count] == '+'){
            //addition operator
            int temp1, temp2;
            stack.pop(temp1);
            stack.pop(temp2);
            stack.push(temp1 + temp2);
            operatorCount++;
        }
        else if(input[count] == '*'){
            //* operator
            int temp1, temp2;
            stack.pop(temp1);
            stack.pop(temp2);
            stack.push(temp1*temp2);
            operatorCount++;

        }
        else if(input[count] == '/'){
            //division operator
            int temp1, temp2;
            stack.pop(temp1);
            stack.pop(temp2);
            stack.push(temp2/temp1);
            operatorCount++;

        }
        else if(input[count] == '-'){
            //subtraction operator
            int temp1, temp2;
            stack.pop(temp1);
            stack.pop(temp2);
            stack.push(temp2-temp1);
            operatorCount++;

        }
        else if(input[count] == ' '){
            //does nothing if approaches space
        }
        else if(isalpha(input[count]) or input[count] != ('+' | '-' | '/' | '*')){
            //checks if array[count] equals to invalid character than breaks loop.
            cout << "Invalid character" << endl;
            break;
        }
        //if the count reaches the length of input, the loop is finished
        if(count != input.length()-1)
            count++;
        else isFinished = true;
    }
    //checks to see if the operation notation is correct with the amount of numbers and operators
    if((numberCount-1) != operatorCount){
        cout << "Invalid postfix Expression" << endl;
        return 0;
    }
    //if loop is finished, outputs the last on the stack
    else if(isFinished)
        cout << "The answer is: " << stack.top() << endl;
}
