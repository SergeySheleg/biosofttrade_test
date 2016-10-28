#include "accessdeniedform.h"
#include "ui_accessdeniedform.h"

AccessDeniedForm::AccessDeniedForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccessDeniedForm)
{
    ui->setupUi(this);
}

AccessDeniedForm::~AccessDeniedForm()
{
    delete ui;
}
