#ifndef CLOCKFORM_H
#define CLOCKFORM_H

#include <QWidget>

namespace Ui {
class ClockForm;
}

class ClockForm : public QWidget
{
    Q_OBJECT

public:
    explicit ClockForm(QWidget *parent = 0);
    ~ClockForm();

private:
    Ui::ClockForm *ui;

private slots:
    void updateCurrentTime();
};

#endif // CLOCKFORM_H
