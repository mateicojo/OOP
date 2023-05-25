//
// Created by mok_a on 5/24/2023.
//

#ifndef A8_A9_ADMINADDFORM_H
#define A8_A9_ADMINADDFORM_H

#include <QWidget>
#include "../Services/Service.h"
#include "admindisplayform.h"


QT_BEGIN_NAMESPACE
namespace Ui { class adminAddForm; }
QT_END_NAMESPACE

class adminAddForm : public QWidget {
Q_OBJECT

public:
    explicit adminAddForm(Services& ser,QWidget *parent = nullptr);
    void connectSignalsAndSlots();
    void addButtonClicked();
    ~adminAddForm() override;

private:
    Ui::adminAddForm *ui;
    Services& ser;
    admindisplayform admindisplayform;
};


#endif //A8_A9_ADMINADDFORM_H
