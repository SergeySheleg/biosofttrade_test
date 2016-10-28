#include "actionchooseform.h"
#include "ui_actionchooseform.h"

ActionChooseForm::ActionChooseForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ActionChooseForm)
{
    ui->setupUi(this);
}

ActionChooseForm::~ActionChooseForm()
{
    delete ui;
}
