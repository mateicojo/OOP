//
// Created by mok_a on 5/24/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_adminAddForm.h" resolved

#include "adminaddform.h"
#include "ui_adminAddForm.h"
#include <QMessageBox>


adminAddForm::adminAddForm(Services& ser,QWidget *parent) :
        QWidget(parent), ui(new Ui::adminAddForm), ser(ser), admindisplayform(ser) {
    ui->setupUi(this);
    this->connectSignalsAndSlots();
}

adminAddForm::~adminAddForm() {
    delete ui;
}

void adminAddForm::connectSignalsAndSlots() {
    QObject::connect(ui->pushButton, &QPushButton::clicked, [&]() {
        this->addButtonClicked();
    });
}

void adminAddForm::addButtonClicked() {
    string title = ui->titleLineEdit->text().toStdString();
    string presenter = ui->presenterLineEdit->text().toStdString();
    int duration = ui->durationLineEdit->text().toInt();
    int likes = ui->likesLineEdit->text().toInt();
    string link = ui->linkLineEdit->text().toStdString();
    if(title.empty() || presenter.empty() || duration == 0 || link.empty()){
        QMessageBox msgBox;
        msgBox.setText("Invalid input!");
        msgBox.exec();
        return;
    }
    this->ser.addTutorialSer(title,presenter,duration,likes,link);
    QMessageBox msgBox;
    msgBox.setText("Tutorial added successfully!");
    msgBox.exec();
    //update the list
    this->admindisplayform.loadList();
    this->close();

}
