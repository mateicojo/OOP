//
// Created by mok_a on 4/2/2023.
//
#include "Tests.h"
#include "UI.h"
int main(){
    //runTests();

    UI ui;
//    ui.getService().getRepo().addTenEntities();
//    ui.getService().getRepo().updateFile(ui.getService().getRepo().getFilename());
    ui.getService().getRepo().readData(ui.getService().getRepo().getFilename());
    ui.printFirstMenu();
    return 0;
}