//
// Created by mok_a on 5/24/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_adminForm.h" resolved

#include "adminform.h"
#include "ui_adminForm.h"



adminForm::adminForm(Services& ser,QWidget *parent) :
        QWidget(parent), ui(new Ui::adminForm), ser(ser), admindisplayform(ser), adminAddForm(ser), adminRemoveForm(ser), adminUpdateForm(ser) {
    ui->setupUi(this);
    this->connectSignalsAndSlots();
}

adminForm::~adminForm() {
    delete ui;
}

void adminForm::connectSignalsAndSlots() {
    QObject::connect(ui->exitButton, &QPushButton::clicked, [&]() {
        this->exitButtonClicked();
    });
    QObject::connect(ui->addButton, &QPushButton::clicked, [&]() {
        this->addButtonClicked();
    });
    QObject::connect(ui->removeButton, &QPushButton::clicked, [&]() {
        this->removeButtonClicked();
    });
    QObject::connect(ui->updateButton, &QPushButton::clicked, [&]() {
        this->updateButtonClicked();
    });
    QObject::connect(ui->displayButton, &QPushButton::clicked, [&]() {
        this->displayButtonClicked();
    });
}

void adminForm::addButtonClicked() {
    this->adminAddForm.show();
}

void adminForm::removeButtonClicked() {
    this->adminRemoveForm.show();
}

void adminForm::updateButtonClicked() {
    this->adminUpdateForm.show();
}

void adminForm::displayButtonClicked() {
    this->admindisplayform.show();
}

void adminForm::exitButtonClicked() {
    this->close();
}
