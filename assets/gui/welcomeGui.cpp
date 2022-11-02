#include <iostream>
#include "groupGui.cpp"
#include "clear.cpp"
#pragma once

using namespace std;
/**
 * welcome gui
 */
void welcome(){
    string start, msg;
    string groupName;
    cout<<"Witamy w programie do sprawdzania obecnosci!"<<endl;
    cout<<"Aby zaczac prace z programem nalezy utworzyc grupe,"
          "\na nastepnie dodac do niej dane studentow takie jak: nr. indeksu, imie i nazwisko."<<endl;
    cout<<"Jestes gotowy/a aby zaczac (y/n)"<<endl;
    do{
        cin>>start;
        cout<<"Musisz wcisnac y aby zaczac!"<<endl;
    } while (start =="n" or start=="N");
    clear();
    cout<<"Swietnie a wiec zaczynamy!"<<endl;
    cout<<"Podaj nazwe twojej pierwszej grupy: "<<endl;
    do{
        cin>>groupName;
        cout<<msg<<endl;
    }while(!add_group(groupName,msg));
    clear();
    cout<<msg<<endl;
    cout<<"Teraz mozesz zaczac prace z programem."<<endl;
    cout<<"Powodzenia :)"<<endl;
}