//
// Created by mok_a on 5/25/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_adminRemoveForm.h" resolved

#include "adminremoveform.h"
#include "ui_adminRemoveForm.h"


adminRemoveForm::adminRemoveForm(Services& ser, QWidget *parent) :
        QWidget(parent), ui(new Ui::adminRemoveForm), ser(ser) {
    ui->setupUi(this);
    this->ser.getRepo().readData(this->ser.getRepo().getFilename());
    this->connectSignalsAndSlots();
    if(this->ui->tutorialsTableWidget->rowCount() > 0)
        this->ui->tutorialsTableWidget->clear();
    this->loadList();
}

adminRemoveForm::~adminRemoveForm() {
    delete ui;
}

void adminRemoveForm::loadList() {
    vector<Tutorial> data = this->ser.getRepo().getAll();
    ui->tutorialsTableWidget->clear();
    int row = 0;
    ui->tutorialsTableWidget->setRowCount(0);
    ui->tutorialsTableWidget->setColumnCount(5);
    ui->tutorialsTableWidget->setHorizontalHeaderLabels(QStringList() << "Title" << "Presenter" << "Duration" << "Likes" << "Link");
    ui->tutorialsTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for (auto & i : data) {
        ui->tutorialsTableWidget->insertRow(row);
        ui->tutorialsTableWidget->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
        ui->tutorialsTableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(i.getTitle())));
        ui->tutorialsTableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(i.getPresenter())));
        ui->tutorialsTableWidget->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(to_string(i.getDuration()))));
        ui->tutorialsTableWidget->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(to_string(i.getLikes()))));
        ui->tutorialsTableWidget->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(i.getLink())));
        row++;
    }
}

void adminRemoveForm::connectSignalsAndSlots() {
    QObject::connect(ui->tutorialsTableWidget, &QTableWidget::cellClicked, this, [this]() {
//        this->loadList(); no. bad idea
        ui->pushButton->setEnabled(true);
    });
    QObject::connect(ui->pushButton, &QPushButton::clicked, this, [this]() {
        int row = ui->tutorialsTableWidget->currentRow();
        QString title = ui->tutorialsTableWidget->item(row, 0)->text();
        this->ser.removeTutorialSer(title.toStdString());
        this->loadList();
    });
}
