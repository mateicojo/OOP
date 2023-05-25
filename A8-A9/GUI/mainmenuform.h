//
// Created by mok_a on 5/24/2023.
//

#ifndef A8_A9_MAINMENUFORM_H
#define A8_A9_MAINMENUFORM_H

#include <QWidget>
#include "../Services/Service.h"
#include "userform.h"
#include "adminform.h"


QT_BEGIN_NAMESPACE
namespace Ui { class mainMenuForm; }
QT_END_NAMESPACE

class mainMenuForm : public QWidget {
Q_OBJECT

public:
    explicit mainMenuForm(Services& ser,QWidget *parent = nullptr);
    void connectSignalsAndSlots();
    void userButtonClicked();
    void adminButtonClicked();
    void exitButtonClicked();
    ~mainMenuForm() override;

private:
    Ui::mainMenuForm *ui;
    Services& ser;
    adminForm adminform;
    userForm userform;
};


#endif //A8_A9_MAINMENUFORM_H
