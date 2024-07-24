/********************************************************************************
** Form generated from reading UI file 'meldungen.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MELDUNGEN_H
#define UI_MELDUNGEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Meldungen
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Meldungen)
    {
        if (Meldungen->objectName().isEmpty())
            Meldungen->setObjectName(QString::fromUtf8("Meldungen"));
        Meldungen->resize(800, 600);
        centralwidget = new QWidget(Meldungen);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(45, 70, 721, 381));
        Meldungen->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Meldungen);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Meldungen->setMenuBar(menubar);
        statusbar = new QStatusBar(Meldungen);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Meldungen->setStatusBar(statusbar);

        retranslateUi(Meldungen);

        QMetaObject::connectSlotsByName(Meldungen);
    } // setupUi

    void retranslateUi(QMainWindow *Meldungen)
    {
        Meldungen->setWindowTitle(QApplication::translate("Meldungen", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Meldungen: public Ui_Meldungen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MELDUNGEN_H
