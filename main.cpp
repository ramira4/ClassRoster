#include <iostream>
#include "roster.h"
#include "student.h"
#include "degree.h"
using namespace std;

int main() {


	// “studentData Table” 
	const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Ana,Ramirez,aram457@wgu.edu,23,15,20,25,SOFTWARE" };

	Roster* classRoster = new Roster(studentData, 5);
	 
	
	//
	classRoster->printAll();
	cout << endl;
	cout << "Printing invalid emails:"<< endl;
	classRoster->printInvalidEmails();
	cout << endl;

	//loop through classRosterArray and for each element:
	cout << "Printing student's average days in courses:" << endl;
	classRoster->printAverageDaysInCourse("A1");
	cout << endl;


	classRoster->printByDegreeProgram(SOFTWARE);
	cout << endl;
	classRoster->remove("A3");
	cout << endl;
	classRoster->printAll();
	cout << endl;
	classRoster->remove("A3");
	cout << endl;
	//expected: the above line should print a message saying such a student with this ID was not found.

};
