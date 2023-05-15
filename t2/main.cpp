//
// Created by mok_a on 5/8/2023.
//
#include "UI.h"
int main(){
    Service ser;
    UI ui(ser);
    ui.addBuildings();
    ui.start();
    return 0;
}