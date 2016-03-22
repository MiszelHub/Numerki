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
#include <QtWidgets/QLabel>
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
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Wykres)
    {
        if (Wykres->objectName().isEmpty())
            Wykres->setObjectName(QStringLiteral("Wykres"));
        Wykres->resize(800, 668);
        centralwidget = new QWidget(Wykres);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QCustomPlot(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 100, 741, 521));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(40, 50, 51, 27));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(270, 40, 161, 33));
        wspolczynniki = new QLineEdit(centralwidget);
        wspolczynniki->setObjectName(QStringLiteral("wspolczynniki"));
        wspolczynniki->setGeometry(QRect(140, 50, 113, 27));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(450, 40, 121, 27));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 101, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 20, 101, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(310, 10, 101, 16));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(590, 40, 121, 27));
        Wykres->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Wykres);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
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
         << QApplication::translate("Wykres", "f(x)=Exp(x)*Cos(W(x))", 0)
         << QApplication::translate("Wykres", "f(x)=Tan(W(x))", 0)
         << QApplication::translate("Wykres", "f(x)=Sin(x)^W(x)", 0)
         << QString()
        );
        pushButton->setText(QApplication::translate("Wykres", "Rysuj Wykres", 0));
        label->setText(QApplication::translate("Wykres", "Stopien Wielomianu", 0));
        label_2->setText(QApplication::translate("Wykres", "Wp\303\263\305\202czynniki", 0));
        label_3->setText(QApplication::translate("Wykres", "Funkcja", 0));
        pushButton_2->setText(QApplication::translate("Wykres", "Oblicz Pierwiastek", 0));
    } // retranslateUi

};

namespace Ui {
    class Wykres: public Ui_Wykres {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WYKRES_H
