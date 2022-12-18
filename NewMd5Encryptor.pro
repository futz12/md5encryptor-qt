#-------------------------------------------------
#
# Project created by QtCreator 2021-08-08T12:14:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NewMd5Encryptor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    comparewnd.cpp

HEADERS  += mainwindow.h \
    comparewnd.h

FORMS    += mainwindow.ui \
    comparewnd.ui

RC_FILE   += logo.rc

RESOURCES += \
    res.qrc

OTHER_FILES += \
    logo.rc
