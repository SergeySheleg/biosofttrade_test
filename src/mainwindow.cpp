#include <string>
#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "clockform.h"
#include "processingform.h"
#include "actionchooseform.h"
#include "accessdeniedform.h"
#include "accessgrantedform.h"

#include "qpostserver.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    m_clockForm = new ClockForm(this);
    m_currentForm = m_clockForm;

    m_processingForm = new ProcessingForm(this);
    m_processingForm->hide();

    m_actionChooseForm = new ActionChooseForm(this);
    m_actionChooseForm->hide();

    m_accessDeniedForm = new AccessDeniedForm(this);
    m_accessDeniedForm->hide();

    m_accessGrantedForm = new AccessGrantedForm(this);
    m_accessGrantedForm->hide();

    m_qPostServer = new QPostServer(this);

    connect(m_qPostServer, SIGNAL(newFormShowSignal(std::string)), this, SLOT(switchCurrentForm(std::string)));

    initSlotsMap();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::showClockForm() {
    switchCurrentForm(m_clockForm);
}

void MainWindow::showProcessingForm() {
    if (m_currentForm == m_clockForm) {
        switchCurrentForm(m_processingForm);
    }
}

void MainWindow::showActionChooseForm() {
    if (m_currentForm == m_processingForm) {
        switchCurrentForm(m_actionChooseForm);
    }
}

void MainWindow::showAccessDeniedForm() {
    if (m_currentForm == m_actionChooseForm) {
        switchCurrentForm(m_accessDeniedForm);
    }
}

void MainWindow::showAccessGrantedForm() {
    if (m_currentForm == m_actionChooseForm) {
        switchCurrentForm(m_accessGrantedForm);
    }
}

void MainWindow::switchCurrentForm(QWidget *newForm) {
    if (newForm == nullptr) {
        return;
    }

    if (m_currentForm != nullptr) {
        m_currentForm->hide();
    }
    m_currentForm = newForm;
    m_currentForm->show();
}

void MainWindow::switchCurrentForm(std::string formName) {
    auto handler = m_slotsMap.find(formName);
    if (handler != m_slotsMap.end()) {
        handler->second();
    }
}

void MainWindow::initSlotsMap() {
    m_slotsMap.emplace("clock", [this]() {
        return this->showClockForm();
    });

    m_slotsMap.emplace("processing", [this]() {
        return this->showProcessingForm();
    });

    m_slotsMap.emplace("actionchoose", [this]() {
        return this->showActionChooseForm();
    });

    m_slotsMap.emplace("accessdenied", [this]() {
        return this->showAccessDeniedForm();
    });

    m_slotsMap.emplace("accessgranted", [this]() {
        return this->showAccessGrantedForm();
    });
}
