#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include "roster.h"
#include "student.h"

using namespace std;
//POPULATE ROSTER part E
Roster::Roster(const string studentData[], int numStudents) {
    this->numStudents = numStudents;
    this->classRosterArray = new Student * [numStudents];

    for (int i=0; i < 5; i++) {
        std::vector<string> attributes;
        std::stringstream input(studentData[i]);
        string data;
        while(getline(input, data, ',')) {
            attributes.push_back(data);
        }
        
        string tempID = attributes.at(0);
        string tempFirst = attributes.at(1);
        string tempLast = attributes.at(2);
        string tempEmail = attributes.at(3);
        int tempAge = stoi(attributes.at(4));
        int daysToComplete[3] = {stoi(attributes.at(5)), stoi(attributes.at(6)), stoi(attributes.at(7))};
 
        DegreeProgram degreeProgram = INVALIDPROGRAM;
        if (attributes.at(8).compare("NETWORK") == 0) {
            degreeProgram = NETWORK;
        }
        else if (attributes.at(8).compare("SECURITY") == 0) {
            degreeProgram = SECURITY;
        }
        else if (attributes.at(8).compare("SOFTWARE") == 0) {
            degreeProgram = SOFTWARE;
        }
        
        classRosterArray[i] = new Student(tempID, tempFirst, tempLast, tempEmail, tempAge, daysToComplete, degreeProgram);
    }
}
Roster::~Roster() {
    delete[] classRosterArray;
}

// METHODS PART E3

// ADD: 
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
    for (int i = 0; i < numStudents; i++) {
        int daysToComplete[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
        classRosterArray[i] = new Student{ studentID, firstName, lastName, emailAddress, age, daysToComplete, degreeprogram };
    }
}

// REMOVE: removes students 
void Roster::remove(string studentID) {
    bool find = false;
    for (int i = 0;  i< numStudents; i++){ 
        if (this->classRosterArray[i]->getStudentID() == studentID) {
            find = true;
            delete this->classRosterArray[i];
            this->classRosterArray[i] = this->classRosterArray[numStudents-1];
            numStudents--;
            cout << "Student " << studentID << " Deleted" << endl;
                    }
    if(!find) {
            cout << "Error removing student, student  "<< studentID << " not found" << endl;
       }
        }
       
    }


//PRINT ALL: 
void Roster::printAll() {
    cout << "Printing all students:" << endl;
    for (int i = 0; i < numStudents; i++) {
        classRosterArray[i]->print();
        cout << endl;
    }
    cout << endl;
};

//AVERAGE DAYS:   student’s average number of days in the three courses
void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << classRosterArray[i]->getStudentID() << " average number of days in courses: ";
        int* day = classRosterArray[i]->getDaysToComplete();
        cout << (day[0] + day[1] + day[2]) / 3;
        cout << endl;

    }
}

//PRINT BY DEGREE PROGRAM: 
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    map<DegreeProgram, string> program{ {SECURITY, "SECURITY"},{NETWORK, "NETWORK"},{SOFTWARE,"SOFTWARE"} };
    cout << "Printing students in " << program[degreeProgram] << endl;
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
            cout << endl;
        }
    }
};

//PRINT INVALID EMAILS: 
void Roster::printInvalidEmails() {
    for (int i = 0; i < numStudents; i++) {
        string emailAddress = classRosterArray[i]->getEmail();
        if (emailAddress.find("@") == string::npos) {
            cout << "Invalid email: " << emailAddress << " Error: email must contain @" << endl;
        }
        if (emailAddress.find(" ") != string::npos) {
            cout << "Invalid email: " << emailAddress << " Error: email may not contain any spaces" << endl;
        }
        if (emailAddress.find(".") == string::npos) {
            cout << "Invalid email: " << emailAddress << " Error: email must contain a period" << endl;
            
        }
        cout << endl;
    }
               
    }

 