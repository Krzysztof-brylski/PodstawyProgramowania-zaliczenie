#include <iostream>
#include <fstream>
#include "../db/dbTools.cpp"
#include "../list/List.cpp"
#pragma once

using namespace std;

struct groupNames{
    string* groups= nullptr;
    int size=0;
};
struct groupDates{
    string* groupDates= nullptr;
    int size=0;
};

void fillGroups(groupNames *groupNames,string* groups,int size){
    groupNames->groups=groups;
    groupNames->size=size;
}

/**
 * adding new group form
 * @param name
 * @param msg
 * @return
 */
bool add_group(string name,string &msg){
    if(lineExist("config/groupsNames.txt",name)){
        msg="grupa o podanej nazwie juz istnieje";
        return false;
    }

    fstream file;
    string path="../db/groups/"+name+".txt";
    file.open(path,ios::app);
    if(file.is_open()){
        if(registerGroup("groupsNames.txt",name)) {
            msg = "Grupa " + name + " zostala utworzona";
            file.close();
            return true;
        }
        msg="wystapil nieznany blad podczas tworzenia grupy2";
        file.close();
        return false;
    }
    msg="wystapil nieznany blad podczas tworzenia grupy";
    file.close();
    return false;
}
/**
 * get registered dates for specified group
 * @param groupName
 * @return groupDates data structure
 */
groupDates* get_dates(string groupName){
    fstream file;
    file.open("../db/config/dates/"+groupName+".txt");
    int size = countLines(file);
    if(size>0){
        string * dateList = new string[size];

        for(int i=0;i<size;i++){

            getline(file,dateList[i]);
        }
        file.close();
        groupDates* dates = new groupDates;
        dates->groupDates=dateList;
        dates->size=size;
        return dates;
    }
    groupDates* dates = new groupDates;
    dates->groupDates = nullptr;
    dates->size=0;
    return dates;

}
/**
 * draw all registered dates
 * @param dates
 */
void draw_dates(groupDates* dates){

    cout<<"Utworzone listy obecnosci:"<<endl;
    for(int i=0;i<dates->size;i++){
        cout<<(i+1)<<" -> "<<dates->groupDates[i]<<endl;
    }
}
/**
 * get all registered groups
 * @return groupNames data structure
 */
groupNames* get_all_groups(){
    fstream file;
    string path="../db/config/groupsNames.txt";
    file.open(path,ios::in);
    int count = countLines(file);
    string* lines = new string [count];
    for(int i=0;i<count;i++){
        getline(file,lines[i]);
    }
    file.close();
    groupNames* group = new groupNames;
    fillGroups(group,lines, count);
    return group;
}
/**
 * draw all registered groups
 * @param group
 */
void draw_groups(groupNames* group){
    cout<<"Lista utworzonych grup:"<<endl;

    for(int i=0;i<group->size;i++){
        cout<<(i+1)<<" -> "<<group->groups[i]<<endl;
    }
}
/**
 * select group form
 * @param group
 * @return selectet group name
 */
string select_group(groupNames* group){
    draw_groups(group);
    int select;
    cin>>select;
    if(cin.fail()){
        return "!!!";
    }
    if(select>0 and select<=group->size){
        return group->groups[select-1];
    }
    cout<<"Nie wybrano zadnej grupy"<<endl;
    return "!!!";
}
