#include "listRow.cpp"
#pragma once

/**
 *  build new return array of listRow's
 * @param int size
 * @return listRow*
 */

struct List{
    listRow* listRow= nullptr;
    string date="00-00-0000";
    string name="";
    int size=0;
};

List* createList(listRow* listRow,string groupName, string date,int size){
    List* list = new List;
    list->listRow=listRow;
    list->name=groupName;
    list->date=date;
    list->size=size;
    return list;
}
void fillPresenceList(List* l1){

    for(int i=0;i<l1->size;i++){
        bool status;
        cout<<"Podaj status obecnosci studenta: "<<endl;
        cout<<l1->listRow[i].student.indexNumber<<"  ";
        cout<<l1->listRow[i].student.name<<"  ";
        cout<<l1->listRow[i].student.surname<<"   ";

        cin>>status;
        l1->listRow[i].present = status;
        cout<<"obecnosci studenta zapisana"<<endl;
        cout<<  l1->listRow->present<<endl;
    }
}

List* readListFromFile(string group,string date){
    string fileName=group+"_"+date;
    fstream file;
    file.open("../db/lists/"+fileName+".txt",ios::in);
    int size = countLines(file);
    int tempIndex;
    string tempName,tempSurname,tempDate;
    bool status;
    listRow *listRows = new listRow[size];
    for(int i=0;i<size;i++){
            file>>tempIndex;
            file>>tempName;
            file>>tempSurname;
            file>>tempDate;
            file>>status;
            student s1;
            fillStudent(s1,tempIndex,tempName,tempSurname);
            fillRow(&listRows[i],s1,status);
    }
    file.close();
    return createList(listRows,group,date,size);
}

void saveListToFile(List* l1){
    string fileName=l1->name+"_"+l1->date;
    fstream file;
    file.open("../db/lists/"+fileName+".txt",ios::out);
    for(int i=0;i<l1->size;i++){

        file<<"\n"<<l1->listRow[i].student.indexNumber<<"  ";
        file<<l1->listRow[i].student.name<<"  ";
        file<<l1->listRow[i].student.surname<<"  ";
        file<<l1->date<<"  ";
        file<<l1->listRow[i].present;
    }
    file.close();
}

void drawList(List *l1){
    for(int i=0;i<l1->size;i++) {
        drawRow(l1->listRow[i]);
    }
}
void destroyList(List *list){
    delete list->listRow;
    delete list;
}


