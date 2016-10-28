#ifndef ACTIONCHOOSEFORM_H
#define ACTIONCHOOSEFORM_H

#include <QWidget>

namespace Ui {
class ActionChooseForm;
}

class ActionChooseForm : public QWidget
{
    Q_OBJECT

public:
    explicit ActionChooseForm(QWidget *parent = 0);
    ~ActionChooseForm();

private:
    Ui::ActionChooseForm *ui;
};

#endif // ACTIONCHOOSEFORM_H
