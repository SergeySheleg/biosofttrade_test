#ifndef ACCESSGRANTEDFORM_H
#define ACCESSGRANTEDFORM_H

#include <QWidget>

namespace Ui {
class AccessGrantedForm;
}

class AccessGrantedForm : public QWidget
{
    Q_OBJECT

public:
    explicit AccessGrantedForm(QWidget *parent = 0);
    ~AccessGrantedForm();

private:
    Ui::AccessGrantedForm *ui;
};

#endif // ACCESSGRANTEDFORM_H
