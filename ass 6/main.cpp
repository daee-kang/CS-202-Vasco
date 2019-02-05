#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

int * resize (int*, int&, int);
bool is_prime(int);

//variables for setw spacing
const int8_t w1 = 12;
const int8_t w2 = 8;

int main() {
//file stream read-in
    ifstream in;
    string name;
    while(!in.is_open()){
        cout << "Enter input file: ";
        cin >> name;
        in.open(name);
    }
//read-in for increase amount and variable declarations
    cout << "Please enter increase amount: ";
    unsigned int increaseAmount;
    cin >> increaseAmount;
    //checks for cin fail, if failed, prompts for reentry
    while(cin.fail()){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Please enter increase amount: ";
        cin >> increaseAmount;
    }
/*VARIABLE DECLARATIONS FOR ARRAY-READ IN
 capacity is the total size of the array, initialized to 0 from the start
 list is the array
 isEnd checks if the array is finished reading in
 remain and count are used to check how many unused variables there are */
    int capacity = 0;
    int * list = NULL;
    bool isEnd = false;
    int remain = 0, count = 0;
/* While loop used for array read in. First it checks ifEnd is false and then runs.
 It then automatically resizes the array using resize function and then checks
 if the file reaches the end while read in. If it does, isEnd is set to true and
 breaks out. otherwise, it will read into list by item keeping count, if it encounters
 a cin fail, it sets back a position and count back by 1 and reads in again. */
    while(!isEnd){
        list = resize (list, capacity, increaseAmount);
        for(int i = capacity - increaseAmount; i < capacity; i++){
            if(in.eof()){
                isEnd = true;
                remain = count;
                break;
            }
            in >> list[i];
            count++;
            if(in.fail()){
                in.clear();
                in.ignore(100,'\n');
                i--;
                count--;
            }
        }
    }
/* VARIABLE DECLARATIONS TO CALCULATE UNUSED, TOTAL, MEDIAN, AND MEAN
    unused calculates how many unused array spaces
    total calculates how many total used array spaces
    mtotal is used for finding mean, addition of all array spaces
    mean is mean */
    
    int unused = capacity - remain;
    int total = capacity - unused;
    double mtotal = 0;
    double mean = 0;
//sort function to sort array numerically
    sort(list, list + total);
//finding the mean
    for(int i = 0; i < count; i++)
        mtotal += list[i];
    mean = mtotal / total;
/* VARIABLE DECLARATIONS FOR FINDING MEDIAN
    median = the median
    odd = if the function is even, it has to get two numbers and divide by 2
          this is the output of that
    isEven = checks if the function is even */
    int median = 0;
    double odd = 0.0;
    bool isEven = false;
//gets median for odd numbered array
    if(total % 2 == 1)
        median = (total - 1) / 2;
    else{
//for even numbered array
        median = total / 2;
        odd = (list[median - 1]+list[median])/2.0;
        isEven = true;
    }
//cout statements
    cout << setw(w1) << left << "Num count: " << setw(w2) << right << total << endl;
    cout << setw(w1) << left <<  "Min: " <<  setw(w2) << right << list[0] << endl;
    cout << setw(w1) << left <<  "Max: " <<  setw(w2) << right << list[total-1] << endl;
    //cout median based on even or not
    if(!isEven) cout << setw(w1) << left <<  "Median: " << setw(w2) << right <<  list[median] << endl;
    else cout << setw(w1) << left <<  "Median: " << setw(w2) << right <<  odd << endl;
    cout << setw(w1) << left <<  "Mean: " << setw(w2) << right <<  mean << endl;
    //for loop to print out all prime number using the if_prime func
    cout << "List of sorted prime numbers: " << endl;
    int spacing = 0;
    for(int i = 0; i < total; i++)
        if(is_prime(list[i])){
            cout << setw(6) << right << list[i];
            spacing++;
            if(spacing == 10){
                spacing = 0;
                cout << endl;
            }
        }
    cout << endl << endl;
    cout << "Unused elements: " << unused << endl;
}
//resize function, creating a new array and deleting the old one and returning the new array.
int * resize (int * list, int& capacity, int increaseAmount){
    if(list == NULL){
        capacity = increaseAmount;
        list = new int[capacity];
        return list;
    }else{
        int * temp;
        temp = new int[capacity + increaseAmount];
        capacity += increaseAmount;
        for (int i = 0; i < capacity; i++)
            temp[i] = list[i];
        delete[] list;
        return temp;
    }
}
//function for finding prime numbers, outputs true if it is prime
bool is_prime(int num){
    bool is_prime = true;
    for(int i = 2; i <= num / 2; i++){
        if(num % i == 0){
            is_prime = false;
            break;
        }
    }
    if(num == 0 or num == 1) is_prime = false;
    return is_prime;
}

