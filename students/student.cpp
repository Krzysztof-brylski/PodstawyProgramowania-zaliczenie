#include <iostream>
#pragma once

using namespace std;
/**
 * student data structure
 * int indexNumber
 * string name
 * string surname
 */
struct student{
    int indexNumber;
    string name;
    string surname;
};
/**
 * constructor for studentList data structure
 * @param s1
 * @param index
 * @param name
 * @param surname
 * @return student data structure
 */

void fillStudent(student &s1,int index,string name, string surname){
    s1.indexNumber=index;
    s1.name=name;
    s1.surname=surname;
}
/**
 * draw data saved in student structure
 * @param s1
 */
void drawStudent(student s1){
    cout<<s1.indexNumber<<" "<<s1.name<<" "<<s1.surname<<endl;
}