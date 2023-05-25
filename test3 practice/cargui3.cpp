//
// Created by mok_a on 5/21/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_cargui3.h" resolved

#include "cargui3.h"
#include "ui_cargui3.h"
#include <iostream>
using namespace std;


cargui3::cargui3(Service& s,QWidget *parent) :
        QWidget(parent), ui(new Ui::cargui3) {
    ui->setupUi(this);
    this->service.getRepo().readData();
    this->connectSignalsAndSlots();
}

void cargui3::connectSignalsAndSlots() {
    QObject::connect(ui->pushButton, &QPushButton::clicked, [&]() {
        this->firstButtonClicked();
//        string manufacturer = ui->lineEdit->text().toStdString();
    });
}

cargui3::~cargui3() {
    delete ui;
}

void cargui3::firstButtonClicked(){
    ui->listWidget->clear();
    string manufacturer = ui->lineEdit->text().toStdString();
    vector<Car> cars = this->service.getRepo().getCars();
    int count=0;
    for(auto c:cars){
        if(c.getManufacturer()==manufacturer){
            ui->listWidget->addItem(QString::fromStdString(c.getManufacturer()+" "+c.getModel()));
            count++;
        }
    }
    ui->label_2->setText(QString::fromStdString("There are "+to_string(count)+" cars from "+manufacturer));
}
