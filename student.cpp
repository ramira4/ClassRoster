#include <iostream>
#include <string> 
#include <map>
#include "student.h"
#include "degree.h"
using namespace std;

//Constructor
Student::Student(string studentID, string firstName, string lastName, string emailAdress, int age, int daysToComplete[], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAdress;
    this->age = age;
    for (int i = 0; i < 3; i++) {
        this->daysToComplete[i] = daysToComplete[i];
    }
    this->degreeProgram = degreeProgram;
}
// Destructor
Student::~Student() {

}

//D2a. Getters
string Student::getStudentID() {
    return studentID;
}
string Student::getFirstName() {
    return firstName;
}
string Student::getLastName() {
    return lastName;
}
string Student::getEmail() {
    return emailAddress;
}
int Student::getAge() {
    return age;
}
int* Student::getDaysToComplete() {
    return daysToComplete;
}
DegreeProgram Student::getDegreeProgram() {
    return degreeProgram;
}

//D2b. Setters
void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}
void Student::setLastName(string lastName) {
    this->lastName = lastName;
}
void Student::setEmail(string emailAddress) {
    this->emailAddress = emailAddress;
}
void Student::setAge(int age) {
    this->age = age;
}
void Student::setDaysToComplete(int daysToComplete[]) {
    for (int i = 0; i < 3; i++) {
        this->daysToComplete[i] = daysToComplete[i];
    }
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

//2e.  print  student data
void Student::print() {
    std::cout << "Student ID: " << studentID << '\t';
    std::cout << " First Name: " << firstName << '\t';
    std::cout << " Last Name: " << lastName << '\t';
    std::cout << " Email Address: " << emailAddress << '\t';
    std::cout << " Age: " << age << '\t';
    std::cout << " Days in Course: " << daysToComplete[0] << ", " << daysToComplete[1] << ", " << daysToComplete[2] << '\t';

    std::map<DegreeProgram, string> program{ {SECURITY, "SECURITY"},{NETWORK, "NETWORK"},{SOFTWARE,"SOFTWARE"} };
    std::cout << " Degree Program: " << program[degreeProgram] << endl;

    std::cout << endl;

}