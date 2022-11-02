#include "assets/gui/groupGui.cpp"
#include "assets/gui/welcomeGui.cpp"
#include "assets/gui/clear.cpp"
#include <iostream>
#include <fstream>
using namespace std;


char input;
bool endProgram= false;


//draw help
void drawHelp(){
    cout<<"Dostepne akcje: d -> Dodaj grupe. l -> Lista grup. z -> Wybierz grupe. w-> Wyjdz z programu."<<endl;
}

// main loop
int main() {
    cout<<"Potezny sprawdzacz obecnosci"<<endl;
    cout<<"Autor: Krzysztof Brylski (272490) ISA sem1"<<endl;
    cout<<"________________________________________________"<<endl;
    groupNames* group =get_all_groups();
    if(group->size == 0){
        welcome();
    }
    drawHelp();
    while (!endProgram){
        group =get_all_groups();
        string selectedGroup;
        cin>>input;
        switch (input) {
            case 'h':

                drawHelp();
            break;
            case 'd':
                clear();
                addGroupGui();
            break;
            case 'l':
                clear();
                draw_groups(group);
                drawHelp();
            break;
            case 'z':
                clear();
                selectedGroup = select_group(group);
                cout<<selectedGroup;
                if(selectedGroup != "!!!"){
                    GroupGui(selectedGroup);
                }
                drawHelp();
            break;
            case 'w':
                endProgram= true;
            break;
            default:
                cout<<"polecenie nieznane!"<<endl;
                cout<<"h-> Lista dostepnych akcji"<<endl;
            break;
        }
        cin.clear();
    }
    delete group;
}
