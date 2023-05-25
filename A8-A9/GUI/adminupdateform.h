//
// Created by mok_a on 5/25/2023.
//

#ifndef A8_A9_ADMINUPDATEFORM_H
#define A8_A9_ADMINUPDATEFORM_H

#include <QWidget>
#include "../Services/Service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class adminUpdateForm; }
QT_END_NAMESPACE

class adminUpdateForm : public QWidget {
Q_OBJECT

public:
    explicit adminUpdateForm(Services& ser,QWidget *parent = nullptr);
    void connectSignalsAndSlots();
    void updateButtonClicked();
    void loadList();
    ~adminUpdateForm() override;

private:
    Ui::adminUpdateForm *ui;
    Services& ser;
};


#endif //A8_A9_ADMINUPDATEFORM_H
