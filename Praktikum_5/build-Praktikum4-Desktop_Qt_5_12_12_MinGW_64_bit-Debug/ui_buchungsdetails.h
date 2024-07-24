/********************************************************************************
** Form generated from reading UI file 'buchungsdetails.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUCHUNGSDETAILS_H
#define UI_BUCHUNGSDETAILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BuchungsDetails
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *flug;
    QWidget *mietwagen;
    QWidget *hotel;
    QWidget *zug;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QDoubleSpinBox *doubleSpinBox;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BuchungsDetails)
    {
        if (BuchungsDetails->objectName().isEmpty())
            BuchungsDetails->setObjectName(QString::fromUtf8("BuchungsDetails"));
        BuchungsDetails->resize(800, 600);
        centralwidget = new QWidget(BuchungsDetails);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(190, 240, 331, 241));
        flug = new QWidget();
        flug->setObjectName(QString::fromUtf8("flug"));
        tabWidget->addTab(flug, QString());
        mietwagen = new QWidget();
        mietwagen->setObjectName(QString::fromUtf8("mietwagen"));
        tabWidget->addTab(mietwagen, QString());
        hotel = new QWidget();
        hotel->setObjectName(QString::fromUtf8("hotel"));
        tabWidget->addTab(hotel, QString());
        zug = new QWidget();
        zug->setObjectName(QString::fromUtf8("zug"));
        tabWidget->addTab(zug, QString());
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 40, 21, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(190, 90, 41, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(190, 130, 31, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(190, 180, 21, 16));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(220, 40, 241, 24));
        doubleSpinBox = new QDoubleSpinBox(centralwidget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(240, 90, 221, 25));
        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(240, 130, 221, 25));
        dateEdit_2 = new QDateEdit(centralwidget);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(240, 180, 221, 25));
        BuchungsDetails->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BuchungsDetails);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        BuchungsDetails->setMenuBar(menubar);
        statusbar = new QStatusBar(BuchungsDetails);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        BuchungsDetails->setStatusBar(statusbar);

        retranslateUi(BuchungsDetails);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(BuchungsDetails);
    } // setupUi

    void retranslateUi(QMainWindow *BuchungsDetails)
    {
        BuchungsDetails->setWindowTitle(QApplication::translate("BuchungsDetails", "MainWindow", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(flug), QApplication::translate("BuchungsDetails", "Flug", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(mietwagen), QApplication::translate("BuchungsDetails", "Mietwagen", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(hotel), QApplication::translate("BuchungsDetails", "Hotel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(zug), QApplication::translate("BuchungsDetails", "Zug", nullptr));
        label->setText(QApplication::translate("BuchungsDetails", "ID", nullptr));
        label_2->setText(QApplication::translate("BuchungsDetails", "Preis", nullptr));
        label_3->setText(QApplication::translate("BuchungsDetails", "Von", nullptr));
        label_4->setText(QApplication::translate("BuchungsDetails", "Bis", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BuchungsDetails: public Ui_BuchungsDetails {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUCHUNGSDETAILS_H
