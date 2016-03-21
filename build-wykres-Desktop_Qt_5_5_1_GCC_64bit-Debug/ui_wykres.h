/********************************************************************************
** Form generated from reading UI file 'wykres.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WYKRES_H
#define UI_WYKRES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Wykres
{
public:
    QWidget *centralwidget;
    QCustomPlot *widget;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QLineEdit *wspolczynniki;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Wykres)
    {
        if (Wykres->objectName().isEmpty())
            Wykres->setObjectName(QStringLiteral("Wykres"));
        Wykres->resize(800, 622);
        centralwidget = new QWidget(Wykres);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QCustomPlot(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 60, 741, 521));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(40, 10, 113, 27));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(320, 10, 82, 33));
        wspolczynniki = new QLineEdit(centralwidget);
        wspolczynniki->setObjectName(QStringLiteral("wspolczynniki"));
        wspolczynniki->setGeometry(QRect(180, 10, 113, 27));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(420, 10, 121, 27));
        Wykres->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Wykres);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 27));
        Wykres->setMenuBar(menubar);
        statusbar = new QStatusBar(Wykres);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Wykres->setStatusBar(statusbar);

        retranslateUi(Wykres);

        QMetaObject::connectSlotsByName(Wykres);
    } // setupUi

    void retranslateUi(QMainWindow *Wykres)
    {
        Wykres->setWindowTitle(QApplication::translate("Wykres", "MainWindow", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Wykres", "W(x)", 0)
         << QApplication::translate("Wykres", "Tan(W(x))", 0)
         << QApplication::translate("Wykres", "Sin(x)^W(x)", 0)
         << QString()
        );
        pushButton->setText(QApplication::translate("Wykres", "Rysuj Wykres", 0));
    } // retranslateUi

};

namespace Ui {
    class Wykres: public Ui_Wykres {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WYKRES_H
