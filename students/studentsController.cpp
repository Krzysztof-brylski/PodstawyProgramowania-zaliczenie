#include <fstream>
#include "studentList.cpp"
#include "../db/dbTools.cpp"
#pragma once

const string dir = "../";
/**
 *  Add student to the group
 * @param s1 student data structure
 * @param groupName group name
 */

void add_student(student &s1,string groupName){
    fstream file;
    string path=dir+"db/groups/"+groupName+".txt";
    file.open(path,ios::in);
    int size = countLines(file);
    file.close();
    file.open(path,ios::app);
    if(file.is_open()){
        if(size>0){
            file<<"\n";
        }
        file<<s1.indexNumber<<" ";
        file<<s1.name<<" ";
        file<<s1.surname;
    }
    file.close();
}
/**
 *  check if given student exist in group,
 *  if bool validation is true, check only for same index numbers
 * @param s1
 * @param groupName
 * @param validation
 * @param validation
 * @return true if exist | false if not exist
 */
bool student_exist(student &s1,string groupName, bool validation = false){
    fstream file;
    file.open(dir+"db/groups/"+groupName+".txt");
    int TempIndex;
    string TempName,TempSurname;
    int size=countLines(file);
    for(int i=0;i<size;i++){
        file>>TempIndex;
        file>>TempName;
        file>>TempSurname;

        if(!validation){
            if(TempIndex == s1.indexNumber and TempName == s1.name and TempSurname == s1.surname){
                return true;
            }
        }
        if(TempIndex == s1.indexNumber){
            return true;
        }
    }
    file.close();
    return false;
}
/**
 * load all students in specified list in to the memory
 * @param groupName
 * @return studentList data structure
 */

studentList* get_students(string groupName){
    fstream file;
    file.open(dir+"db/groups/"+groupName+".txt",ios::in);
    if(file.is_open()){
        //counting lines in file
        int size= countLines(file);
        //allocate student list
        student* studentArr = new student[size];
        //allocate tem variables
        int* TempIndex = new int;
        string* TempName = new string;
        string* TempSurname = new string;
        for(int i=0;i<size;i++){
            // writing from file to temp vars
            file>>*TempIndex;
            file>>*TempName;
            file>>*TempSurname;
            //adding student to student list
            fillStudent(studentArr[i],*TempIndex,*TempName,*TempSurname);

        }
        file.close();
        //cleaning up
        delete TempIndex;
        delete TempName;
        delete TempSurname;
        //return student list
        return createStudentList(studentArr,size);
    }
    //if found nothing return null ptr
    file.close();
    return new studentList;
}
/**
 * return selected user from group
 * @param groupName
 * @param id
 * @return student data structure
 */
student get_student(string groupName, int id){
    fstream file;
    file.open(dir+"db/groups/"+groupName+".txt",ios::in);
    student s1;
    if(file.is_open()) {
        //counting lines in file
        int size = countLines(file);
        //tem variables
        int* TempIndex = new int;
        string* TempName=new  string;
        string* TempSurname=new string;
        string* TempLine = new string;
        for(int i=0;i<size;i++){
            if(i == id){
                // writing from file to temp vars
                file>>*TempIndex;
                file>>*TempName;
                file>>*TempSurname;
                fillStudent(s1,*TempIndex,*TempName,*TempSurname);
            }
            getline(file,*TempLine);
            continue;
        }
        //cleaning up
        delete TempLine;
        delete TempIndex;
        delete TempName;
        delete TempSurname;
    }
    return s1;
}

void dell_Student(string groupName, int id){

}