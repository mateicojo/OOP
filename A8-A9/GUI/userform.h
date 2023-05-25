//
// Created by mok_a on 5/24/2023.
//

#ifndef A8_A9_USERFORM_H
#define A8_A9_USERFORM_H

#include <QWidget>
#include "../Services/Service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class userForm; }
QT_END_NAMESPACE

class userForm : public QWidget {
Q_OBJECT

public:
    explicit userForm(Services& ser,QWidget *parent = nullptr);

    ~userForm() override;

private:
    Ui::userForm *ui;
    Services& ser;
};


#endif //A8_A9_USERFORM_H
