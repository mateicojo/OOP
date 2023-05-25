//
// Created by mok_a on 5/21/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CarGUI.h" resolved

#include "cargui.h"
#include "ui_CarGUI.h"
#include <assert.h>
#include <iostream>
#include <algorithm>
using namespace std;


CarGUI::CarGUI(Service& s,QWidget *parent):
        QWidget(parent), ui(new Ui::CarGUI) {
    ui->setupUi(this);
    populateList();
}

CarGUI::~CarGUI() {
    delete ui;
}

void CarGUI::populateList() {
    ui->carslistWidget->clear();
    this->service.getRepo().readData();
    vector<Car> cars = this->service.getRepo().getCars();
    std::sort(cars.begin(), cars.end(), [=](const Car& a, const Car& b) {
        return a.getManufacturer() < b.getManufacturer();
    });
    for(auto c:cars){
        ui->carslistWidget->addItem(QString::fromStdString(c.getManufacturer()+" "+c.getModel()));
    }
}
