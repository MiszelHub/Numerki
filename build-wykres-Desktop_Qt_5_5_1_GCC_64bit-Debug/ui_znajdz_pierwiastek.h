/********************************************************************************
** Form generated from reading UI file 'znajdz_pierwiastek.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZNAJDZ_PIERWIASTEK_H
#define UI_ZNAJDZ_PIERWIASTEK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Znajdz_pierwiastek
{
public:
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *Znajdz_pierwiastek)
    {
        if (Znajdz_pierwiastek->objectName().isEmpty())
            Znajdz_pierwiastek->setObjectName(QStringLiteral("Znajdz_pierwiastek"));
        Znajdz_pierwiastek->resize(400, 300);
        comboBox = new QComboBox(Znajdz_pierwiastek);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 70, 82, 33));
        comboBox_2 = new QComboBox(Znajdz_pierwiastek);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(150, 70, 82, 33));
        lineEdit = new QLineEdit(Znajdz_pierwiastek);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 30, 81, 27));
        lineEdit_2 = new QLineEdit(Znajdz_pierwiastek);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(130, 30, 113, 27));
        pushButton = new QPushButton(Znajdz_pierwiastek);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 230, 85, 27));
        label = new QLabel(Znajdz_pierwiastek);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 59, 17));
        label_2 = new QLabel(Znajdz_pierwiastek);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(150, 0, 59, 17));
        label_3 = new QLabel(Znajdz_pierwiastek);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 60, 59, 17));
        label_4 = new QLabel(Znajdz_pierwiastek);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(170, 60, 59, 17));
        lineEdit_3 = new QLineEdit(Znajdz_pierwiastek);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(40, 150, 113, 27));
        lineEdit_4 = new QLineEdit(Znajdz_pierwiastek);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(220, 150, 113, 27));
        label_5 = new QLabel(Znajdz_pierwiastek);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 150, 59, 17));
        label_6 = new QLabel(Znajdz_pierwiastek);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(150, 150, 59, 17));

        retranslateUi(Znajdz_pierwiastek);

        QMetaObject::connectSlotsByName(Znajdz_pierwiastek);
    } // setupUi

    void retranslateUi(QDialog *Znajdz_pierwiastek)
    {
        Znajdz_pierwiastek->setWindowTitle(QApplication::translate("Znajdz_pierwiastek", "Dialog", 0));
        pushButton->setText(QApplication::translate("Znajdz_pierwiastek", "PushButton", 0));
        label->setText(QApplication::translate("Znajdz_pierwiastek", "TextLabel", 0));
        label_2->setText(QApplication::translate("Znajdz_pierwiastek", "TextLabel", 0));
        label_3->setText(QApplication::translate("Znajdz_pierwiastek", "TextLabel", 0));
        label_4->setText(QApplication::translate("Znajdz_pierwiastek", "TextLabel", 0));
        label_5->setText(QApplication::translate("Znajdz_pierwiastek", "TextLabel", 0));
        label_6->setText(QApplication::translate("Znajdz_pierwiastek", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class Znajdz_pierwiastek: public Ui_Znajdz_pierwiastek {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZNAJDZ_PIERWIASTEK_H
