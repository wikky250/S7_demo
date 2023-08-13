#pragma once

#include <intsafe.h>

#include <QDir>
#include <QHeaderView>
#include "ui_union_demo.h"
#include <intsafe.h>
#include <QMetaType>


#include "ui_union_demo.h"
#include "S7Model.h"

class Qtunion_demo : public QMainWindow
{
    Q_OBJECT
   public:
    Qtunion_demo(QWidget* parent = Q_NULLPTR);
    ~Qtunion_demo();
   private:
    Ui::Union_Demo ui;
    MyClass* cla;
    void CreateConnect();
};
