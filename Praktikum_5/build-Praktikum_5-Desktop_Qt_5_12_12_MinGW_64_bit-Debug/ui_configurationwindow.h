/********************************************************************************
** Form generated from reading UI file 'configurationwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURATIONWINDOW_H
#define UI_CONFIGURATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_configurationWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_Reiseberschneidung;
    QCheckBox *checkBox_berflssige_Htotelbuchung;
    QCheckBox *checkBox_fehlende_hotelBuchungen;
    QCheckBox *checkBox_uberflssige_mietwagenbuchung;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *configurationWindow)
    {
        if (configurationWindow->objectName().isEmpty())
            configurationWindow->setObjectName(QString::fromUtf8("configurationWindow"));
        configurationWindow->resize(421, 302);
        centralwidget = new QWidget(configurationWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 220, 80, 25));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 220, 80, 25));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 261, 161));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox_Reiseberschneidung = new QCheckBox(widget);
        checkBox_Reiseberschneidung->setObjectName(QString::fromUtf8("checkBox_Reiseberschneidung"));

        verticalLayout->addWidget(checkBox_Reiseberschneidung);

        checkBox_berflssige_Htotelbuchung = new QCheckBox(widget);
        checkBox_berflssige_Htotelbuchung->setObjectName(QString::fromUtf8("checkBox_berflssige_Htotelbuchung"));

        verticalLayout->addWidget(checkBox_berflssige_Htotelbuchung);

        checkBox_fehlende_hotelBuchungen = new QCheckBox(widget);
        checkBox_fehlende_hotelBuchungen->setObjectName(QString::fromUtf8("checkBox_fehlende_hotelBuchungen"));

        verticalLayout->addWidget(checkBox_fehlende_hotelBuchungen);

        checkBox_uberflssige_mietwagenbuchung = new QCheckBox(widget);
        checkBox_uberflssige_mietwagenbuchung->setObjectName(QString::fromUtf8("checkBox_uberflssige_mietwagenbuchung"));

        verticalLayout->addWidget(checkBox_uberflssige_mietwagenbuchung);

        configurationWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(configurationWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 421, 25));
        configurationWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(configurationWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        configurationWindow->setStatusBar(statusbar);

        retranslateUi(configurationWindow);

        QMetaObject::connectSlotsByName(configurationWindow);
    } // setupUi

    void retranslateUi(QMainWindow *configurationWindow)
    {
        configurationWindow->setWindowTitle(QApplication::translate("configurationWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("configurationWindow", "Ok", nullptr));
        pushButton_2->setText(QApplication::translate("configurationWindow", "cancel", nullptr));
        checkBox_Reiseberschneidung->setText(QApplication::translate("configurationWindow", "Reise\303\274berschneidungen", nullptr));
        checkBox_berflssige_Htotelbuchung->setText(QApplication::translate("configurationWindow", "\303\234berfl\303\274ssige Hotelbuchung", nullptr));
        checkBox_fehlende_hotelBuchungen->setText(QApplication::translate("configurationWindow", "Fehlende HotelBuchung", nullptr));
        checkBox_uberflssige_mietwagenbuchung->setText(QApplication::translate("configurationWindow", "\303\234berfl\303\274ssige Mietwagenbuchung", nullptr));
    } // retranslateUi

};

namespace Ui {
    class configurationWindow: public Ui_configurationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURATIONWINDOW_H
