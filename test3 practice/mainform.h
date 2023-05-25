//
// Created by mok_a on 5/21/2023.
//

#ifndef TEST3_PRACTICE_MAINFORM_H
#define TEST3_PRACTICE_MAINFORM_H

#include <QWidget>
#include "Service.h"
#include "cargui.h"
#include "cargui2.h"
#include "cargui3.h"


QT_BEGIN_NAMESPACE
namespace Ui { class mainForm; }
QT_END_NAMESPACE

class mainForm : public QWidget {
Q_OBJECT

public:
    explicit mainForm(Service& s,QWidget *parent = nullptr);
    void connectSignalsAndSlots();
    void firstButtonClicked();
    void secondButtonClicked();
    ~mainForm() override;

private:
    Ui::mainForm *ui;
    Service s;
    CarGUI w;
    cargui2 w2;
    cargui3 w3;
};


#endif //TEST3_PRACTICE_MAINFORM_H
