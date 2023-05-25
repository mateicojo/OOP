//
// Created by mok_a on 5/21/2023.
//

#ifndef TEST3_PRACTICE_CARGUI3_H
#define TEST3_PRACTICE_CARGUI3_H

#include <QWidget>
#include "Service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class cargui3; }
QT_END_NAMESPACE

class cargui3 : public QWidget {
Q_OBJECT

public:
    explicit cargui3(Service& s,QWidget *parent = nullptr);
    void populateList();
    void connectSignalsAndSlots();
    void firstButtonClicked();
    ~cargui3() override;

private:
    Ui::cargui3 *ui;
    Service service;

};


#endif //TEST3_PRACTICE_CARGUI3_H
