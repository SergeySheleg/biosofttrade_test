#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <map>
#include <functional>
#include "qpostserver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QWidget *m_clockForm = nullptr;
    QWidget *m_processingForm = nullptr;
    QWidget *m_actionChooseForm = nullptr;
    QWidget *m_accessDeniedForm = nullptr;
    QWidget *m_accessGrantedForm = nullptr;
    QWidget *m_currentForm = nullptr;

    QPostServer *m_qPostServer = nullptr;

    std::map<std::string, std::function<void(void)>> m_slotsMap;

private:
    void switchCurrentForm(QWidget*);
    void initSlotsMap();

public slots:
    void showClockForm();
    void showProcessingForm();
    void showActionChooseForm();
    void showAccessDeniedForm();
    void showAccessGrantedForm();
    void switchCurrentForm(std::string);
};

#endif // MAINWINDOW_H
