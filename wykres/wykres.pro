#-------------------------------------------------
#
# Project created by QtCreator 2016-03-08T11:23:40
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = wykres
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    znajdz_pierwiastek.cpp \
    wykres.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    znajdz_pierwiastek.h \
    wykres.h

FORMS    += \
    znajdz_pierwiastek.ui \
    mainwindow.ui \
    wykres.ui
