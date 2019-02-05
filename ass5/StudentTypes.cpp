#include "StudentTypes.hpp"
#include <string>

using namespace std;

person::person(){
    first = last = id = "";
}
person::person(string f, string l, string ID){
    first = f;
    last = l;
    id = ID;
}
string person::getFirst() const{
    return first;
}
string person::getLast() const{
    return last;
}
string person::getId() const{
    return id;
}

student::student(){
    credits = gpa = 0;
    info = person();
}
student::student(string f, string l, string ID){
    info = person(f,l,ID);
}
person student::getPersonInfo () const {
    return info;
}
unsigned int student::getCredits () const {
    return credits;
}
double student::getGpa () const {
    return gpa;
}
bool student::graduated() const {
    if (credits >= CREDITS_NEEDED)
        return true;
    else return false;
}
void student::addCredits(unsigned int addCredits, double newGpa){
    credits += addCredits;
    gpa = newGpa;
}

undergrad::undergrad() :student(){
}
undergrad::undergrad(string f, string l, string ID)
:student(f,l,ID){
}
string undergrad::getFirst() const {
    person info = getPersonInfo();
    return info.getFirst();
}
string undergrad::getLast() const {
    person info = getPersonInfo();
    return info.getLast();
}
unsigned int undergrad::getCredits() const {
    return student::getCredits();
}
double undergrad::getGpa() const {
    return student::getGpa();
}
bool undergrad::searchById(string ID) const{
    person info = getPersonInfo();
    if(info.getId() == ID){
        return true;
    } else return false;
}
bool undergrad::searchByName(string searchedName) const{
    person info = getPersonInfo();
    string name = info.getFirst() + " " + info.getLast();
    for(int i = 0; i < name.length(); i++)
        name[i] = tolower(name[i]);
    for(int i = 0; i < searchedName.length(); i++)
        searchedName[i] = tolower(searchedName[i]);
    if(searchedName == name)
        return true;
    else return false;
}
void undergrad::completedClass(double num){
    addCredits(3, num);
}
bool undergrad::graduated() const {
    if(student::graduated())
        return true;
    else return false;
}
grad::grad() :student(){
    thesis = "";
    defended = false;
}
grad::grad(string f, string l, string id, string mthesis)
:student(f,l,id){
    thesis = mthesis;
    defended = false;
}
string grad::getFirst() const {
    person info = getPersonInfo();
    return info.getFirst();
}
string grad::getLast() const {
    person info = getPersonInfo();
    return info.getLast();
}
unsigned int grad::getCredits() const {
    return student::getCredits();
}
double grad::getGpa() const {
    return student::getGpa();
}
bool grad::searchById(string ID) const{
    person info = getPersonInfo();
    if(info.getId() == ID){
        return true;
    } else return false;
}
bool grad::searchByName(string searchedName) const{
    person info = getPersonInfo();
    string name = info.getFirst() + " " + info.getLast();
    for(int i = 0; i < name.length(); i++)
        name[i] = tolower(name[i]);
    for(int i = 0; i < searchedName.length(); i++)
        searchedName[i] = tolower(searchedName[i]);
    if(searchedName == name)
        return true;
    else return false;
}
void grad::completedClass(double num){
    addCredits(3, num);
}
bool grad::graduated() const {
    if(student::graduated() and defended)
        return true;
    else return false;
}
void grad::completedThesis(){
    if(thesis != "")
        defended = true;
}
bool grad::hasDefended() const {
    return defended;
}

phd::phd() :student(){
    dissertation = "";
    defended = false;
}
phd::phd(string f, string l, string id, string mthesis)
:student(f,l,id){
    dissertation = mthesis;
    defended = false;
}
string phd::getFirst() const {
    person info = getPersonInfo();
    return info.getFirst();
}
string phd::getLast() const {
    person info = getPersonInfo();
    return info.getLast();
}
unsigned int phd::getCredits() const {
    return student::getCredits();
}
double phd::getGpa() const {
    return student::getGpa();
}
bool phd::searchById(string ID) const{
    person info = getPersonInfo();
    if(info.getId() == ID){
        return true;
    } else return false;
}
bool phd::searchByName(string searchedName) const{
    person info = getPersonInfo();
    string name = info.getFirst() + " " + info.getLast();
    for(int i = 0; i < name.length(); i++)
        name[i] = tolower(name[i]);
    for(int i = 0; i < searchedName.length(); i++)
        searchedName[i] = tolower(searchedName[i]);
    if(searchedName == name)
        return true;
    else return false;
}
void phd::completedClass(double num){
    addCredits(3, num);
}
bool phd::graduated() const {
    if(student::graduated() and defended)
        return true;
    else return false;
}
void phd::completedDissertation(){
    if(dissertation != "")
        defended = true;
}
bool phd::hasDefended() const {
    return defended;
}














