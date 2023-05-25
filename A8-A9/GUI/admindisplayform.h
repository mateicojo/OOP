//
// Created by mok_a on 5/24/2023.
//

#ifndef A8_A9_ADMINDISPLAYFORM_H
#define A8_A9_ADMINDISPLAYFORM_H

#include <QWidget>
#include "../Services/Service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class admindisplayform; }
QT_END_NAMESPACE

class admindisplayform : public QWidget {
Q_OBJECT

public:
    explicit admindisplayform(Services& ser,QWidget *parent = nullptr);
    void loadList();
    void connectSignalsAndSlots();
    ~admindisplayform() override;

private:
    Ui::admindisplayform *ui;
    Services& ser;
};


#endif //A8_A9_ADMINDISPLAYFORM_H
