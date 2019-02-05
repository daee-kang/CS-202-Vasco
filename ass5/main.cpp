#include "StudentTypes.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int SIZE = 5;

int main(){
    undergrad undergradStudents[SIZE];
    grad gradStudents[SIZE];
    phd doctoralStudents[SIZE];
    
    ifstream in;
    string name;
    cout << "Enter file name: ";
    cin >> name;
    in.open(name);
    if(!in.is_open())
        cout <<"fucking sucks";
    
    string first, last, id, type, thesis;
    int uCount = 0, gCount = 0, dCount = 0;
    
    in >> first;
    
    while(in){
        in >> last;
        in >> id;
        in >> type;
        if(type == "U"){
            undergradStudents[uCount] = undergrad(first, last, id);
            uCount++;
        }
        else if(type == "G"){
            in >> thesis;
            gradStudents[gCount] = grad(first, last, id, thesis);
            gCount++;
        }
        else if(type == "P"){
            in >> thesis;
            doctoralStudents[dCount] = phd(first, last, id, thesis);
        }
        cout << "cock";
        first = last = id = type = thesis = "";
        in >> first;
    }
    
    
    
};

