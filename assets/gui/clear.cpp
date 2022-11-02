#include <iostream>
#pragma once
using namespace std;
string platform="win";

void clear(){
    if(platform=="win"){
        system("cls");
        return;
    }
    system("clear");
    return;
}