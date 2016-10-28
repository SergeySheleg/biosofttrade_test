#include "accessgrantedform.h"
#include "ui_accessgrantedform.h"

AccessGrantedForm::AccessGrantedForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccessGrantedForm)
{
    ui->setupUi(this);
}

AccessGrantedForm::~AccessGrantedForm()
{
    delete ui;
}
