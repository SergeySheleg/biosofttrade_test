#include "processingform.h"
#include "ui_processingform.h"

ProcessingForm::ProcessingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProcessingForm)
{
    ui->setupUi(this);
}

ProcessingForm::~ProcessingForm() {
    delete ui;
}
