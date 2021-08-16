#include <iostream>
#include <string>
#pragma once
#include "degree.h"
using namespace std;

class Student {
private:
    //D1 CREATE CLASS STUDENT
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysToComplete[3] = {};
    DegreeProgram degreeProgram;

public:
    //Constructor
    Student(string =" ", string = " ", string = " ", string = " ", int = 0, int daystoComplete[] = 0, DegreeProgram = INVALIDPROGRAM);
    ~Student();
    //D2a. create an accessor for each variable
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getDaysToComplete();
    DegreeProgram getDegreeProgram();
    // D2b. create a mutator  for each  variable
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string emailAddress);
    void setAge(int age);
    void setDaysToComplete(int daysToComplete[]);
    void setDegreeProgram(DegreeProgram degreeProgram);

    //D2e.
    void print();

};