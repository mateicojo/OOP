//
// Created by mok_a on 5/24/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_userForm.h" resolved

#include "userform.h"
#include "ui_userForm.h"


userForm::userForm(Services& ser,QWidget *parent) :
        QWidget(parent), ui(new Ui::userForm), ser(ser) {
    ui->setupUi(this);
}

userForm::~userForm() {
    delete ui;
}
