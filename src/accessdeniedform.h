#ifndef ACCESSDENIEDFORM_H
#define ACCESSDENIEDFORM_H

#include <QWidget>

namespace Ui {
class AccessDeniedForm;
}

class AccessDeniedForm : public QWidget
{
    Q_OBJECT

public:
    explicit AccessDeniedForm(QWidget *parent = 0);
    ~AccessDeniedForm();

private:
    Ui::AccessDeniedForm *ui;
};

#endif // ACCESSDENIEDFORM_H
