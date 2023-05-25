//
// Created by mok_a on 5/21/2023.
//

#ifndef TEST3_PRACTICE_CARGUI_H
#define TEST3_PRACTICE_CARGUI_H

#include <QWidget>
#include "Service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class CarGUI; }
QT_END_NAMESPACE

class CarGUI : public QWidget {
Q_OBJECT

public:
    explicit CarGUI(Service& s,QWidget *parent = nullptr);
    void populateList();
    ~CarGUI() override;

private:
    Ui::CarGUI *ui;
    Service service;
};


#endif //TEST3_PRACTICE_CARGUI_H
