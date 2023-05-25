//
// Created by mok_a on 5/24/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainMenuForm.h" resolved

#include "mainmenuform.h"
#include "ui_mainMenuForm.h"



mainMenuForm::mainMenuForm(Services& ser,QWidget *parent) :
        QWidget(parent), ui(new Ui::mainMenuForm), ser(ser), adminform(ser), userform(ser) {
    ui->setupUi(this);
    this->connectSignalsAndSlots();
}

mainMenuForm::~mainMenuForm() {
    delete ui;
}

void mainMenuForm::connectSignalsAndSlots() {
    QObject::connect(ui->exitButton, &QPushButton::clicked, [&]() {
        this->exitButtonClicked();
    });
    QObject::connect(ui->userModeButton, &QPushButton::clicked, [&]() {
        this->userButtonClicked();
    });
    QObject::connect(ui->adminModeButton, &QPushButton::clicked, [&]() {
        this->adminButtonClicked();
    });
}

void mainMenuForm::userButtonClicked() {
    this->userform.show();
}

void mainMenuForm::adminButtonClicked() {
    this->adminform.show();
}

void mainMenuForm::exitButtonClicked() {
    this->close();
}

