//
// Created by mok_a on 5/21/2023.
//

#ifndef TEST3_PRACTICE_CARGUI2_H
#define TEST3_PRACTICE_CARGUI2_H

#include <QWidget>
#include "Service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class cargui2; }
QT_END_NAMESPACE

class cargui2 : public QWidget {
Q_OBJECT

public:
    explicit cargui2(Service& s,QWidget *parent = nullptr);
    void loadList();
    ~cargui2() override;

private:
    Ui::cargui2 *ui;
    Service s;
};


#endif //TEST3_PRACTICE_CARGUI2_H
