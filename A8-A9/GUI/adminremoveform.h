//
// Created by mok_a on 5/25/2023.
//

#ifndef A8_A9_ADMINREMOVEFORM_H
#define A8_A9_ADMINREMOVEFORM_H

#include <QWidget>
#include "../Services/Service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class adminRemoveForm; }
QT_END_NAMESPACE

class adminRemoveForm : public QWidget {
Q_OBJECT

public:
    explicit adminRemoveForm(Services& ser,QWidget *parent = nullptr);
    void loadList();
    void connectSignalsAndSlots();
    ~adminRemoveForm() override;

private:
    Ui::adminRemoveForm *ui;
    Services& ser;
};


#endif //A8_A9_ADMINREMOVEFORM_H
