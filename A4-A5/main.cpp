//
// Created by mok_a on 4/2/2023.
//
#include "Tests.h"
#include "UI.h"
#include <windows.h>
int main(){
    //runTests();
    UI ui;
    ui.getService().getRepo().readData(ui.getService().getRepo().getFilename());
    ui.printFirstMenu();
    return 0;
}