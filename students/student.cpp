#include <iostream>
#pragma once

using namespace std;

struct student{
    int indexNumber;
    string name;
    string surname;
};

void fillStudent(student &s1,int index,string name, string surname){
    s1.indexNumber=index;
    s1.name=name;
    s1.surname=surname;
}

void drawStudent(student s1){
    cout<<s1.indexNumber<<" "<<s1.name<<" "<<s1.surname<<endl;
}