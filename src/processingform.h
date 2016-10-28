#ifndef PROCESSINGFORM_H
#define PROCESSINGFORM_H

#include <QWidget>

namespace Ui {
class ProcessingForm;
}

class ProcessingForm : public QWidget
{
    Q_OBJECT

public:
    explicit ProcessingForm(QWidget *parent = 0);
    ~ProcessingForm();

private:
    Ui::ProcessingForm *ui;
};

#endif // PROCESSINGFORM_H
