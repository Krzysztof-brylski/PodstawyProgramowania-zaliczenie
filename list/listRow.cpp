#include <iostream>
#include <fstream>
#include "../students/studentsController.cpp"
#pragma once

using namespace std;
/**
 *  presence list row data structure
 *  student data structure
 *  bool present
 */
struct listRow{
    student student;
	bool present = 0;

};
/**
 * constructor for presence list row
 * @param l1
 * @param student
 * @param present
 */
void fillRow(listRow* l1, student &student,bool present){
    l1->student=student;
	l1->present = present;
}
/**
 * draw data saved in presence list row
 * @param l1
 */
void drawRow(listRow &l1){
    drawStudent(l1.student);
    string msg="";
    l1.present ? msg="Obecny" : msg="Nie obecny";
	cout<<msg<<endl;

}
