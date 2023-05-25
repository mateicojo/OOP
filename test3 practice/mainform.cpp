//
// Created by mok_a on 5/21/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainForm.h" resolved

#include "mainform.h"
#include "ui_mainForm.h"
#include "cargui.h"
#include <iostream>
using namespace std;


mainForm::mainForm(Service& s,QWidget *parent) :
        QWidget(parent), ui(new Ui::mainForm), w(s), w2(s) , w3(s) {
    ui->setupUi(this);
    this->connectSignalsAndSlots();
}

void mainForm::connectSignalsAndSlots() {
        QObject::connect(ui->firstButton, &QPushButton::clicked, [&]() {
        this->firstButtonClicked();
    });
        QObject::connect(ui->secondButton, &QPushButton::clicked, [&]() {
        this->secondButtonClicked();
        }
    );
        QObject::connect(ui->thirdButton, &QPushButton::clicked, [&]() {
            this->w3.show();
        });
}

void mainForm::firstButtonClicked() {
    w.show();
}

void mainForm::secondButtonClicked() {
    w2.show();
}



mainForm::~mainForm() {
    delete ui;
}


