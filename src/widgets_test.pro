QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = widgets_test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    clockform.cpp \
    processingform.cpp \
    actionchooseform.cpp \
    accessdeniedform.cpp \
    accessgrantedform.cpp \
    qpostserver.cpp

HEADERS  += mainwindow.h \
    clockform.h \
    processingform.h \
    actionchooseform.h \
    accessdeniedform.h \
    accessgrantedform.h \
    qpostserver.h

FORMS    += mainwindow.ui \
    clockform.ui \
    processingform.ui \
    actionchooseform.ui \
    accessdeniedform.ui \
    accessgrantedform.ui

INSTALLS        = target
target.files    = widgets_test
target.path     = /home/pi

