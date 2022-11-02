#include <fstream>
#pragma once

using namespace std;

/**
 * counting not empty lines in a file
 * @param file
 * @return
 */
int countLines(fstream &file){
    int count=0;
    string* temp = new string;
    while (!file.eof()){
        getline(file,*temp);
        if(*temp != ""){
            count+=1;
        }
    }
    file.seekg(0);
    file.seekp(0);
    delete temp;
    return count;
}
/**
 * checking if line exist in specified file
 * @param where
 * @param value
 * @return
 */
bool lineExist(string where, string value){
    fstream file;
    file.open("../db/"+where,ios::in);
    file.seekg(0);
    string* temp = new string;
    while(!file.eof()){
        getline(file,*temp);
        if(*temp == value){
            delete temp;
            file.close();
            return true;
        }
    }
    file.close();
    delete temp;
    return false;
}
/**
 * register groupName in group db
 * @param type
 * @param name
 * @return
 */
bool registerGroup(string type,string name){
    fstream file;
    fstream file2;
    string path="../db/config/"+type;
    string datePath="../db/config/dates/"+name+".txt";
    file.open(path,ios::in);
    int size = countLines(file);
    file.close();
    file.open(path,ios::app);
    if(file.is_open()){
        bool check=lineExist(path, name);
        if(!check){
            if(size>0){
                file<<"\n";
            }
            file2.open(datePath,ios::app);
            file<<name;
            file.close();
            file2.close();
            return true;
        }
    }
    file.close();
    file2.close();
    return false;
}
/**
 * register date for specified  group
 * @param date
 * @param groupName
 * @return
 */
bool registerDate(string date,string groupName){
    string path="../db/config/dates/"+groupName+".txt";
    fstream file;
    file.open(path,ios::in);
    int size = countLines(file);
    file.close();
    file.open(path,ios::app);
    if(file.is_open()){
        if(!lineExist(path,date)){
            if(size>0){
                file<<"\n";
            }
            file<<date;
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}
/**
 * insert date into group-dates db for specified group
 * @param date
 * @param groupName
 */
void insertDate(string date,string groupName){
    string path="../db/config/dates/"+groupName+".txt";
    fstream file;
    file.open(path,ios::in);
    int size = countLines(file);
    file.close();
    file.open(path,ios::app);
    if(file.is_open()){
        if(size>0){
            file<<"\n";
        }
        file<<date;
    }
    file.close();
}
/**
 * check if date exist in specified group-dates db
 * @param date
 * @param groupName
 * @return
 */
bool dateExist(string date,string groupName){
    string fileName="../db/config/dates/"+groupName+".txt";
    fstream file;
    file.open(fileName,ios::in);
    file.seekg(0);
    string* temp = new string;
    while(!file.eof()){
        getline(file,*temp);
        if(*temp == date){
            delete temp;
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}