#pragma once
#include <iostream>
#include <string>
#include "student.h"
using namespace std;

class Roster {
public:
    //CREATE CLASS ROSTER
    Roster(const string studentData[], int numStudents);
    ~Roster();

    //E3
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printByDegreeProgram(DegreeProgram degreeProgram);
    void printInvalidEmails();

private:
    Student** classRosterArray;
    int numStudents;

};