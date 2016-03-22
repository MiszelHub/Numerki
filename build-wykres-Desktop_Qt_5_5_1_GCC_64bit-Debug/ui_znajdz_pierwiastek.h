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
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit_4;
    QLineEdit *pierwiastek;

    void setupUi(QDialog *Znajdz_pierwiastek)
    {
        if (Znajdz_pierwiastek->objectName().isEmpty())
            Znajdz_pierwiastek->setObjectName(QStringLiteral("Znajdz_pierwiastek"));
        Znajdz_pierwiastek->resize(400, 300);
        comboBox = new QComboBox(Znajdz_pierwiastek);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(20, 30, 131, 33));
        lineEdit = new QLineEdit(Znajdz_pierwiastek);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 170, 81, 27));
        pushButton = new QPushButton(Znajdz_pierwiastek);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(110, 240, 151, 27));
        label = new QLabel(Znajdz_pierwiastek);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 0, 191, 17));
        label_2 = new QLabel(Znajdz_pierwiastek);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(230, 0, 171, 17));
        lineEdit_3 = new QLineEdit(Znajdz_pierwiastek);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(130, 170, 71, 27));
        label_5 = new QLabel(Znajdz_pierwiastek);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 150, 121, 17));
        label_6 = new QLabel(Znajdz_pierwiastek);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(110, 170, 59, 17));
        comboBox_2 = new QComboBox(Znajdz_pierwiastek);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(240, 30, 131, 33));
        lineEdit_4 = new QLineEdit(Znajdz_pierwiastek);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(240, 70, 71, 27));
        pierwiastek = new QLineEdit(Znajdz_pierwiastek);
        pierwiastek->setObjectName(QStringLiteral("pierwiastek"));
        pierwiastek->setGeometry(QRect(260, 170, 113, 27));

        retranslateUi(Znajdz_pierwiastek);

        QMetaObject::connectSlotsByName(Znajdz_pierwiastek);
    } // setupUi

    void retranslateUi(QDialog *Znajdz_pierwiastek)
    {
        Znajdz_pierwiastek->setWindowTitle(QApplication::translate("Znajdz_pierwiastek", "Dialog", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Znajdz_pierwiastek", "none", 0)
         << QApplication::translate("Znajdz_pierwiastek", "Metoda Bisekcji", 0)
         << QApplication::translate("Znajdz_pierwiastek", "Metoda Siecznych", 0)
        );
        pushButton->setText(QApplication::translate("Znajdz_pierwiastek", "Znajd\305\272 pierwiastek", 0));
        label->setText(QApplication::translate("Znajdz_pierwiastek", "Wybierz metod\304\231 obliczania pierwiastka", 0));
        label_2->setText(QApplication::translate("Znajdz_pierwiastek", "kryteruim zatrzeymania algorytmu", 0));
        label_5->setText(QApplication::translate("Znajdz_pierwiastek", "podaj przedzia\305\202 od", 0));
        label_6->setText(QApplication::translate("Znajdz_pierwiastek", "do", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Znajdz_pierwiastek", "none", 0)
         << QApplication::translate("Znajdz_pierwiastek", "Ilo\305\233\304\207 iteracji", 0)
         << QApplication::translate("Znajdz_pierwiastek", "dok\305\202adnos\304\207 do epsilon", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class Znajdz_pierwiastek: public Ui_Znajdz_pierwiastek {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZNAJDZ_PIERWIASTEK_H
