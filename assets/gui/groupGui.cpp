#include <iostream>
#include "../groupController.cpp"
#pragma once
void drawGroupHelp(){
    cout<<"Dostepne akcje: s -> Sprawdz obenosci. z -> Zobacz listy. l -> Lista studentow. d -> Dodaj studenta  w-> Wroc."<<endl;
}

void checkPresenceList(string selected, studentList* studentList){

    string date;
    cout<<"Podaj date: (dd-mm-yyyy)"<<endl;
    cin>>date;

    if(!dateExist(date,selected)) {
        listRow *listRows = new listRow[studentList->size];
        for (int i = 0; i < studentList->size; i++) {
            fillRow(&listRows[i], studentList->students[i], 0);
        }

        List* list = createList(listRows,selected,date,studentList->size);
        fillPresenceList(list);
        saveListToFile(list);
        insertDate(date,selected);

        delete[] listRows;
    }

}

void addGroupGui(){
    string name, msg;
    cout<<"Podaj nazwe grupy: "<<endl;
    cin>>name;
    add_group(name,msg);
    cout<<msg<<endl;

}
void addStudentGui(string selected){
    int indexNumber;
    string name,surname;
    student s1;

    cout<<"Podaj nr indeksu, imie i nazwisko studenta (kazde zatwierdz ENTEREM)"<<endl;
    cin>>indexNumber>>name>>surname;
    fillStudent(s1,indexNumber,name,surname);
    if(!student_exist(s1,selected, true)){
        add_student(s1,selected);
        cout<<"Student zostal zapisany"<<endl;
    }else{
        cout<<"Student o podanych danych juz istnieje"<<endl;
    }
}

void ShowList(string selected, groupDates* dates){
    if(dates->size == 0){
        cout<<"Nie zostaly jeszcze utworzone listy obecnosci."<<endl;
        return;
    }
    draw_dates(dates);
    cout<<"wybierz liste do zobaczenia"<<endl;
    int select;
    cin>>select;
    if(!cin.fail()){
        if(select >0 and select <= dates->size){
            system("cls");
            string date = dates->groupDates[select-1];
            List* list = readListFromFile(selected,date);
            cout<<"Lista obecnosci grupy: "<<list->name<<" z dnia:"<<list->date<<endl;
            drawList(list);
            delete list;
            cin.clear();
            cout<<endl;
            return;
        }
    }
    cin.clear();
    cout<<"Prosze wybrac istniejaca liste"<<endl;
}




void GroupGui(string selected){
    system("cls");
    cout<<"Wybrana grupa: "<<selected<<endl;
    studentList* studentList;
    groupDates* dates;
    drawGroupHelp();
    bool back = false;
    char input;
    while (!back){

        studentList= get_students(selected);
        dates = get_dates(selected);
        cin>>input;

        switch (input) {
            case 's':
                system("cls");
                checkPresenceList(selected,studentList);
                drawGroupHelp();
            break;
            case 'd':
                system("cls");
                addStudentGui(selected);
                drawGroupHelp();
            break;
            case 'l':
                system("cls");
                drawStudentList(*studentList);
                drawGroupHelp();
            break;
            case 'z':
                system("cls");
                ShowList(selected,dates);
                drawGroupHelp();
            break;
            case 'h':
                drawGroupHelp();
            break;
            case 'w':
                system("cls");
                back = true;
            break;

            default:
                cout<<"Nieznane polecenie!"<<endl;
                cout<<"h-> Lista dostepnych akcji"<<endl;
            break;
        }
        cin.clear();

    }
    delete studentList;
    delete dates;
}


