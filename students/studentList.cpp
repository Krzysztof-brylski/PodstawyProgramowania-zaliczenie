#include "student.cpp"
#pragma once

struct studentList{
    student* students= nullptr;
    int size=0;
};

studentList* createStudentList(student* students, int size){
    studentList* l1 = new studentList;
    l1->students=students;
    l1->size=size;
    return l1;
}

void drawStudentList(studentList l1){
    if(l1.size == 0){
        cout<<"lista studentow jest pusta."<<endl;
        return;
    }
    cout<<"Lista osob:"<<endl;
    for(int i=0;i<l1.size;i++) {
        drawStudent(l1.students[i]);
    }
}
void destroyStudentList(studentList* list){
    delete list->students;
    delete list;
}