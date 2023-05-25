//
// Created by mok_a on 5/24/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_admindisplayform.h" resolved

#include "admindisplayform.h"
#include "ui_admindisplayform.h"


admindisplayform::admindisplayform(Services& ser,QWidget *parent) :
        QWidget(parent), ui(new Ui::admindisplayform), ser(ser) {
    ui->setupUi(this);
    if(this->ui->tableWidget->rowCount() > 0)
        this->ui->tableWidget->clear();
    this->ser.getRepo().readData(this->ser.getRepo().getFilename());
    this->loadList();
}

admindisplayform::~admindisplayform() {
    delete ui;
}

void admindisplayform::connectSignalsAndSlots() {
    //when a cell is clicked, the list is updated
    QObject::connect(ui->tableWidget, &QTableWidget::cellClicked, [&]() {
        this->loadList();
    });
}

void admindisplayform::loadList() {
    this->ser.getRepo().readData(this->ser.getRepo().getFilename());
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
