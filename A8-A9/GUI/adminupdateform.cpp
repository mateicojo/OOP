//
// Created by mok_a on 5/25/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_adminUpdateForm.h" resolved

#include "adminupdateform.h"
#include "ui_adminUpdateForm.h"
#include <QMessageBox>


adminUpdateForm::adminUpdateForm(Services& ser,QWidget *parent) :
        QWidget(parent), ui(new Ui::adminUpdateForm), ser(ser) {
    ui->setupUi(this);
    this->connectSignalsAndSlots();
    this->loadList();
}

adminUpdateForm::~adminUpdateForm() {
    delete ui;
}

void adminUpdateForm::connectSignalsAndSlots() {
    //when a cell is clicked, the line edits will be filled with the data from the selected row
    QObject::connect(ui->tableWidget, &QTableWidget::cellClicked, [&]() {
        int row = ui->tableWidget->currentRow();
        ui->titleLineEdit->setText(ui->tableWidget->item(row, 0)->text());
        ui->presenterLineEdit->setText(ui->tableWidget->item(row, 1)->text());
        ui->durationLineEdit->setText(ui->tableWidget->item(row, 2)->text());
        ui->likesLineEdit->setText(ui->tableWidget->item(row, 3)->text());
        ui->linkLineEdit->setText(ui->tableWidget->item(row, 4)->text());
    });
    QObject::connect(ui->pushButton, &QPushButton::clicked, [&]() {
        this->updateButtonClicked();
    });

}

void adminUpdateForm::updateButtonClicked() {
    this->ser.updateTutorialSer(ui->titleLineEdit->text().toStdString(),ui->presenterLineEdit->text().toStdString(),ui->durationLineEdit->text().toInt(),ui->likesLineEdit->text().toInt(),ui->linkLineEdit->text().toStdString());
    if(ui->titleLineEdit->text().isEmpty() || ui->presenterLineEdit->text().isEmpty() || ui->durationLineEdit->text().isEmpty() || ui->likesLineEdit->text().isEmpty() || ui->linkLineEdit->text().isEmpty()){
        QMessageBox msgBox;
        msgBox.setText("Invalid input!");
        msgBox.exec();
        return;
    }
    QMessageBox msgBox;
    msgBox.setText("Tutorial updated successfully!");
    msgBox.exec();
    this->loadList();

}

void adminUpdateForm::loadList() {
    vector<Tutorial> data = this->ser.getRepo().getAll();
    ui->tableWidget->clear();
    int row = 0;
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Title" << "Presenter" << "Duration" << "Likes" << "Link");
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for (auto & i : data) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(i.getTitle())));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(i.getPresenter())));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(to_string(i.getDuration()))));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(to_string(i.getLikes()))));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(i.getLink())));
        row++;
    }
}
