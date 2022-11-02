#include "student.cpp"
#pragma once
/**
 *  studentList data structure;
 *  student data structure pointer
 *  int size
 */
struct studentList{
    student* students= nullptr;
    int size=0;
};
/**
 * constructor for studentList data structure
 * @param students
 * @param size
 * @return studentList data structure
 */
studentList* createStudentList(student* students, int size){
    studentList* l1 = new studentList;
    l1->students=students;
    l1->size=size;
    return l1;
}
/**
 * drawing all all students saved in studentList
 * @param l1 studentList data structure
 */
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
