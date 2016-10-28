#include <QTime>
#include <QTimer>

#include "clockform.h"
#include "ui_clockform.h"


ClockForm::ClockForm(QWidget *parent) : QWidget(parent), ui(new Ui::ClockForm) {
    ui->setupUi(this);

    updateCurrentTime();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateCurrentTime()));
    timer->start(1000);
}

ClockForm::~ClockForm() {
    delete ui;
}

void ClockForm::updateCurrentTime() {
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    ui->CurrentTimeLabel->setText(text);
}
