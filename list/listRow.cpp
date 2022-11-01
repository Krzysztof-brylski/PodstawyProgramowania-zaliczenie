#include <iostream>
#include <fstream>
#include "../students/studentsController.cpp"
#pragma once

using namespace std;

struct listRow{
    student student;
	bool present = 0;

};

void fillRow(listRow* l1, student &student,bool present){
    l1->student=student;
	l1->present = present;
}

void drawRow(listRow &l1){
    drawStudent(l1.student);
    string msg="";
    l1.present ? msg="Obecny" : msg="Nie obecny";
	cout<<msg<<endl;

}

bool rowToFile(string fileName, listRow &l1){
    /*
    fstream file;
    file.open(fileName,ios::app);
    if(!file.is_open()){
        return false;
    }
    file<<l1.student.indexNumber<<"  ";
    file<<l1.student.name<<"  ";
    file<<l1.student.surname<<"  ";
    file<<l1.date<<"  ";
    file<<l1.present<<"\n";
    file.close();
     */
    return true;

}