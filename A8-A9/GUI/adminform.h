//
// Created by mok_a on 5/24/2023.
//

#ifndef A8_A9_ADMINFORM_H
#define A8_A9_ADMINFORM_H

#include <QWidget>
#include "../Services/Service.h"
#include "admindisplayform.h"
#include "adminaddform.h"
#include "adminremoveform.h"
#include "adminupdateform.h"


QT_BEGIN_NAMESPACE
namespace Ui { class adminForm; }
QT_END_NAMESPACE

class adminForm : public QWidget {
Q_OBJECT

public:
    explicit adminForm(Services& ser,QWidget *parent = nullptr);
    void connectSignalsAndSlots();
    void addButtonClicked();
    void removeButtonClicked();
    void updateButtonClicked();
    void exitButtonClicked();
    void displayButtonClicked();
    ~adminForm() override;

private:
    Ui::adminForm *ui;
    Services& ser;
    admindisplayform admindisplayform;
    adminAddForm adminAddForm;
    adminRemoveForm adminRemoveForm;
    adminUpdateForm adminUpdateForm;
};


#endif //A8_A9_ADMINFORM_H
