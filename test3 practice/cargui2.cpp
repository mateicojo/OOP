//
// Created by mok_a on 5/21/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_cargui2.h" resolved

#include "cargui2.h"
#include "ui_cargui2.h"


cargui2::cargui2(Service& s,QWidget *parent) :
        QWidget(parent), ui(new Ui::cargui2) {
    ui->setupUi(this);
    this->loadList();
}

cargui2::~cargui2() {
    delete ui;
}

void cargui2::loadList() {
    ui->cars2ListWidget->clear();
    this->s.getRepo().readData();
    vector<Car> cars = this->s.getRepo().getCars();
    for(auto c:cars){
        ui->cars2ListWidget->addItem(QString::fromStdString(c.getManufacturer()+" "+c.getModel()));
                if(c.getColor()=="red")
            ui->cars2ListWidget->item(ui->cars2ListWidget->count()-1)->setForeground(Qt::red);
        if(c.getColor()=="blue")
            ui->cars2ListWidget->item(ui->cars2ListWidget->count()-1)->setForeground(Qt::blue);
        if(c.getColor()=="black")
            ui->cars2ListWidget->item(ui->cars2ListWidget->count()-1)->setForeground(Qt::black);
        if(c.getColor()=="green")
            ui->cars2ListWidget->item(ui->cars2ListWidget->count()-1)->setForeground(Qt::green);
    }
}
