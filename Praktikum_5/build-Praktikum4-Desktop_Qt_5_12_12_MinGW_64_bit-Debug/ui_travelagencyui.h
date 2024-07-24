/********************************************************************************
** Form generated from reading UI file 'travelagencyui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAVELAGENCYUI_H
#define UI_TRAVELAGENCYUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Travelagencyui
{
public:
    QAction *actionEinlesen;
    QAction *actionExit;
    QAction *actionsuchen;
    QAction *actionSpeichern;
    QWidget *centralwidget;
    QGroupBox *customerGroupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *customerIdEdit;
    QLineEdit *customerVornameEdit;
    QLineEdit *customerNachnameedit;
    QTableWidget *customerTravelTable;
    QLabel *label_4;
    QGroupBox *travelGroupBox;
    QLabel *label_5;
    QLineEdit *travelIdEdit;
    QLabel *label_6;
    QTableWidget *travelTable;
    QGroupBox *bookingGroupBox;
    QTabWidget *tabWidget;
    QWidget *flug;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *label_11;
    QLineEdit *airlineEdit;
    QLabel *label_12;
    QLineEdit *fromDateFlug;
    QLabel *label_13;
    QLineEdit *toDateflug;
    QLabel *label_14;
    QLineEdit *bookingclassFlug;
    QLabel *label_28;
    QLineEdit *departurAirportNameEdit;
    QLabel *label_29;
    QLineEdit *arrivalAirportNameEdit;
    QWidget *mietwagen;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QLabel *label_15;
    QLineEdit *pickuplocationEdit;
    QLabel *label_16;
    QLineEdit *returnlocationedit;
    QLabel *label_17;
    QLineEdit *companyedit;
    QLabel *label_18;
    QLineEdit *vehicleclassedit;
    QWidget *hotel;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *label_19;
    QLineEdit *hotelEdit;
    QLabel *label_20;
    QLineEdit *townEdit;
    QLabel *label_21;
    QLineEdit *roomtypeedit;
    QWidget *zug;
    QLabel *label_27;
    QListWidget *connectionsStationlistWidget;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_4;
    QLabel *label_22;
    QLineEdit *fromDestEdit;
    QLabel *label_23;
    QTimeEdit *departureTimeEdit;
    QLabel *label_24;
    QLineEdit *toDestEdit;
    QLabel *label_25;
    QTimeEdit *arrivalTimeEdit;
    QLabel *label_26;
    QLineEdit *ticketTypEdit;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *bookingIdEdit;
    QDoubleSpinBox *priceSpinBox;
    QDateEdit *fromDateEdit;
    QDateEdit *toDateEdit;
    QPushButton *savePushButton;
    QPushButton *cancelPushButton;
    QMenuBar *menubar;
    QMenu *menuDatei;
    QMenu *menukund_innen;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Travelagencyui)
    {
        if (Travelagencyui->objectName().isEmpty())
            Travelagencyui->setObjectName(QString::fromUtf8("Travelagencyui"));
        Travelagencyui->resize(1279, 782);
        actionEinlesen = new QAction(Travelagencyui);
        actionEinlesen->setObjectName(QString::fromUtf8("actionEinlesen"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/iconss/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEinlesen->setIcon(icon);
        actionExit = new QAction(Travelagencyui);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionsuchen = new QAction(Travelagencyui);
        actionsuchen->setObjectName(QString::fromUtf8("actionsuchen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/iconss/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionsuchen->setIcon(icon1);
        actionSpeichern = new QAction(Travelagencyui);
        actionSpeichern->setObjectName(QString::fromUtf8("actionSpeichern"));
        centralwidget = new QWidget(Travelagencyui);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        customerGroupBox = new QGroupBox(centralwidget);
        customerGroupBox->setObjectName(QString::fromUtf8("customerGroupBox"));
        customerGroupBox->setGeometry(QRect(12, 12, 651, 351));
        label = new QLabel(customerGroupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(14, 33, 16, 16));
        label_2 = new QLabel(customerGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(14, 64, 52, 16));
        label_3 = new QLabel(customerGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(14, 95, 60, 16));
        customerIdEdit = new QLineEdit(customerGroupBox);
        customerIdEdit->setObjectName(QString::fromUtf8("customerIdEdit"));
        customerIdEdit->setGeometry(QRect(36, 33, 51, 24));
        customerVornameEdit = new QLineEdit(customerGroupBox);
        customerVornameEdit->setObjectName(QString::fromUtf8("customerVornameEdit"));
        customerVornameEdit->setGeometry(QRect(81, 64, 181, 24));
        customerNachnameedit = new QLineEdit(customerGroupBox);
        customerNachnameedit->setObjectName(QString::fromUtf8("customerNachnameedit"));
        customerNachnameedit->setGeometry(QRect(81, 95, 181, 24));
        customerTravelTable = new QTableWidget(customerGroupBox);
        if (customerTravelTable->columnCount() < 3)
            customerTravelTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        customerTravelTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        customerTravelTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        customerTravelTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        customerTravelTable->setObjectName(QString::fromUtf8("customerTravelTable"));
        customerTravelTable->setGeometry(QRect(80, 140, 561, 201));
        customerTravelTable->horizontalHeader()->setDefaultSectionSize(200);
        customerTravelTable->verticalHeader()->setMinimumSectionSize(24);
        customerTravelTable->verticalHeader()->setDefaultSectionSize(37);
        label_4 = new QLabel(customerGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 140, 38, 16));
        travelGroupBox = new QGroupBox(centralwidget);
        travelGroupBox->setObjectName(QString::fromUtf8("travelGroupBox"));
        travelGroupBox->setGeometry(QRect(10, 375, 651, 301));
        label_5 = new QLabel(travelGroupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 30, 55, 16));
        travelIdEdit = new QLineEdit(travelGroupBox);
        travelIdEdit->setObjectName(QString::fromUtf8("travelIdEdit"));
        travelIdEdit->setGeometry(QRect(70, 30, 113, 24));
        label_6 = new QLabel(travelGroupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 80, 61, 16));
        travelTable = new QTableWidget(travelGroupBox);
        if (travelTable->columnCount() < 4)
            travelTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        travelTable->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        travelTable->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        travelTable->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        travelTable->setHorizontalHeaderItem(3, __qtablewidgetitem6);
        travelTable->setObjectName(QString::fromUtf8("travelTable"));
        travelTable->setGeometry(QRect(80, 80, 481, 211));
        bookingGroupBox = new QGroupBox(centralwidget);
        bookingGroupBox->setObjectName(QString::fromUtf8("bookingGroupBox"));
        bookingGroupBox->setGeometry(QRect(730, 40, 461, 641));
        tabWidget = new QTabWidget(bookingGroupBox);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(30, 210, 381, 381));
        flug = new QWidget();
        flug->setObjectName(QString::fromUtf8("flug"));
        widget = new QWidget(flug);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(11, 18, 351, 311));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 0, 0, 1, 1);

        airlineEdit = new QLineEdit(widget);
        airlineEdit->setObjectName(QString::fromUtf8("airlineEdit"));

        gridLayout_2->addWidget(airlineEdit, 0, 2, 1, 2);

        label_12 = new QLabel(widget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 1, 0, 1, 1);

        fromDateFlug = new QLineEdit(widget);
        fromDateFlug->setObjectName(QString::fromUtf8("fromDateFlug"));

        gridLayout_2->addWidget(fromDateFlug, 1, 1, 1, 3);

        label_13 = new QLabel(widget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 2, 0, 1, 1);

        toDateflug = new QLineEdit(widget);
        toDateflug->setObjectName(QString::fromUtf8("toDateflug"));

        gridLayout_2->addWidget(toDateflug, 2, 1, 1, 3);

        label_14 = new QLabel(widget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_2->addWidget(label_14, 3, 0, 1, 2);

        bookingclassFlug = new QLineEdit(widget);
        bookingclassFlug->setObjectName(QString::fromUtf8("bookingclassFlug"));

        gridLayout_2->addWidget(bookingclassFlug, 3, 2, 1, 2);

        label_28 = new QLabel(widget);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout_2->addWidget(label_28, 4, 0, 1, 3);

        departurAirportNameEdit = new QLineEdit(widget);
        departurAirportNameEdit->setObjectName(QString::fromUtf8("departurAirportNameEdit"));

        gridLayout_2->addWidget(departurAirportNameEdit, 4, 3, 1, 1);

        label_29 = new QLabel(widget);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        gridLayout_2->addWidget(label_29, 5, 0, 1, 2);

        arrivalAirportNameEdit = new QLineEdit(widget);
        arrivalAirportNameEdit->setObjectName(QString::fromUtf8("arrivalAirportNameEdit"));

        gridLayout_2->addWidget(arrivalAirportNameEdit, 5, 3, 1, 1);

        tabWidget->addTab(flug, QString());
        mietwagen = new QWidget();
        mietwagen->setObjectName(QString::fromUtf8("mietwagen"));
        layoutWidget = new QWidget(mietwagen);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 40, 341, 241));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_3->addWidget(label_15, 0, 0, 1, 1);

        pickuplocationEdit = new QLineEdit(layoutWidget);
        pickuplocationEdit->setObjectName(QString::fromUtf8("pickuplocationEdit"));

        gridLayout_3->addWidget(pickuplocationEdit, 0, 1, 1, 2);

        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_3->addWidget(label_16, 1, 0, 1, 2);

        returnlocationedit = new QLineEdit(layoutWidget);
        returnlocationedit->setObjectName(QString::fromUtf8("returnlocationedit"));

        gridLayout_3->addWidget(returnlocationedit, 1, 2, 1, 1);

        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_3->addWidget(label_17, 2, 0, 1, 2);

        companyedit = new QLineEdit(layoutWidget);
        companyedit->setObjectName(QString::fromUtf8("companyedit"));

        gridLayout_3->addWidget(companyedit, 2, 2, 1, 1);

        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_3->addWidget(label_18, 3, 0, 1, 2);

        vehicleclassedit = new QLineEdit(layoutWidget);
        vehicleclassedit->setObjectName(QString::fromUtf8("vehicleclassedit"));

        gridLayout_3->addWidget(vehicleclassedit, 3, 2, 1, 1);

        tabWidget->addTab(mietwagen, QString());
        hotel = new QWidget();
        hotel->setObjectName(QString::fromUtf8("hotel"));
        layoutWidget1 = new QWidget(hotel);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(13, 40, 361, 151));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(layoutWidget1);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout->addWidget(label_19, 0, 0, 1, 1);

        hotelEdit = new QLineEdit(layoutWidget1);
        hotelEdit->setObjectName(QString::fromUtf8("hotelEdit"));

        gridLayout->addWidget(hotelEdit, 0, 1, 1, 1);

        label_20 = new QLabel(layoutWidget1);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout->addWidget(label_20, 1, 0, 1, 1);

        townEdit = new QLineEdit(layoutWidget1);
        townEdit->setObjectName(QString::fromUtf8("townEdit"));

        gridLayout->addWidget(townEdit, 1, 1, 1, 1);

        label_21 = new QLabel(layoutWidget1);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout->addWidget(label_21, 2, 0, 1, 1);

        roomtypeedit = new QLineEdit(layoutWidget1);
        roomtypeedit->setObjectName(QString::fromUtf8("roomtypeedit"));

        gridLayout->addWidget(roomtypeedit, 2, 1, 1, 1);

        tabWidget->addTab(hotel, QString());
        zug = new QWidget();
        zug->setObjectName(QString::fromUtf8("zug"));
        label_27 = new QLabel(zug);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(40, 180, 41, 16));
        connectionsStationlistWidget = new QListWidget(zug);
        connectionsStationlistWidget->setObjectName(QString::fromUtf8("connectionsStationlistWidget"));
        connectionsStationlistWidget->setGeometry(QRect(100, 180, 261, 161));
        layoutWidget2 = new QWidget(zug);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(30, 20, 341, 152));
        gridLayout_4 = new QGridLayout(layoutWidget2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_22 = new QLabel(layoutWidget2);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_4->addWidget(label_22, 0, 0, 1, 1);

        fromDestEdit = new QLineEdit(layoutWidget2);
        fromDestEdit->setObjectName(QString::fromUtf8("fromDestEdit"));

        gridLayout_4->addWidget(fromDestEdit, 0, 1, 1, 3);

        label_23 = new QLabel(layoutWidget2);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_4->addWidget(label_23, 1, 0, 1, 2);

        departureTimeEdit = new QTimeEdit(layoutWidget2);
        departureTimeEdit->setObjectName(QString::fromUtf8("departureTimeEdit"));

        gridLayout_4->addWidget(departureTimeEdit, 1, 2, 1, 2);

        label_24 = new QLabel(layoutWidget2);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_4->addWidget(label_24, 2, 0, 1, 1);

        toDestEdit = new QLineEdit(layoutWidget2);
        toDestEdit->setObjectName(QString::fromUtf8("toDestEdit"));

        gridLayout_4->addWidget(toDestEdit, 2, 3, 1, 1);

        label_25 = new QLabel(layoutWidget2);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_4->addWidget(label_25, 3, 0, 1, 2);

        arrivalTimeEdit = new QTimeEdit(layoutWidget2);
        arrivalTimeEdit->setObjectName(QString::fromUtf8("arrivalTimeEdit"));

        gridLayout_4->addWidget(arrivalTimeEdit, 3, 3, 1, 1);

        label_26 = new QLabel(layoutWidget2);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_4->addWidget(label_26, 4, 0, 1, 3);

        ticketTypEdit = new QLineEdit(layoutWidget2);
        ticketTypEdit->setObjectName(QString::fromUtf8("ticketTypEdit"));

        gridLayout_4->addWidget(ticketTypEdit, 4, 3, 1, 1);

        tabWidget->addTab(zug, QString());
        label_7 = new QLabel(bookingGroupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(50, 40, 16, 16));
        label_8 = new QLabel(bookingGroupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(50, 90, 31, 16));
        label_9 = new QLabel(bookingGroupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(50, 130, 31, 16));
        label_10 = new QLabel(bookingGroupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(50, 170, 31, 16));
        bookingIdEdit = new QLineEdit(bookingGroupBox);
        bookingIdEdit->setObjectName(QString::fromUtf8("bookingIdEdit"));
        bookingIdEdit->setGeometry(QRect(80, 40, 361, 24));
        priceSpinBox = new QDoubleSpinBox(bookingGroupBox);
        priceSpinBox->setObjectName(QString::fromUtf8("priceSpinBox"));
        priceSpinBox->setGeometry(QRect(100, 90, 211, 25));
        fromDateEdit = new QDateEdit(bookingGroupBox);
        fromDateEdit->setObjectName(QString::fromUtf8("fromDateEdit"));
        fromDateEdit->setGeometry(QRect(90, 130, 221, 25));
        toDateEdit = new QDateEdit(bookingGroupBox);
        toDateEdit->setObjectName(QString::fromUtf8("toDateEdit"));
        toDateEdit->setGeometry(QRect(90, 170, 221, 25));
        savePushButton = new QPushButton(bookingGroupBox);
        savePushButton->setObjectName(QString::fromUtf8("savePushButton"));
        savePushButton->setGeometry(QRect(240, 600, 80, 25));
        cancelPushButton = new QPushButton(bookingGroupBox);
        cancelPushButton->setObjectName(QString::fromUtf8("cancelPushButton"));
        cancelPushButton->setGeometry(QRect(340, 600, 80, 25));
        Travelagencyui->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Travelagencyui);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1279, 25));
        menuDatei = new QMenu(menubar);
        menuDatei->setObjectName(QString::fromUtf8("menuDatei"));
        menukund_innen = new QMenu(menubar);
        menukund_innen->setObjectName(QString::fromUtf8("menukund_innen"));
        Travelagencyui->setMenuBar(menubar);
        statusbar = new QStatusBar(Travelagencyui);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Travelagencyui->setStatusBar(statusbar);
        toolBar = new QToolBar(Travelagencyui);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        Travelagencyui->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuDatei->menuAction());
        menubar->addAction(menukund_innen->menuAction());
        menuDatei->addAction(actionEinlesen);
        menuDatei->addAction(actionExit);
        menuDatei->addAction(actionSpeichern);
        menukund_innen->addAction(actionsuchen);
        toolBar->addAction(actionEinlesen);
        toolBar->addAction(actionsuchen);

        retranslateUi(Travelagencyui);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Travelagencyui);
    } // setupUi

    void retranslateUi(QMainWindow *Travelagencyui)
    {
        Travelagencyui->setWindowTitle(QApplication::translate("Travelagencyui", "MainWindow", nullptr));
        actionEinlesen->setText(QApplication::translate("Travelagencyui", "Einlesen", nullptr));
#ifndef QT_NO_SHORTCUT
        actionEinlesen->setShortcut(QApplication::translate("Travelagencyui", "Ctrl+I", nullptr));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("Travelagencyui", "Exit", nullptr));
        actionsuchen->setText(QApplication::translate("Travelagencyui", "suchen", nullptr));
        actionSpeichern->setText(QApplication::translate("Travelagencyui", "Speichern", nullptr));
        customerGroupBox->setTitle(QApplication::translate("Travelagencyui", "kund*in", nullptr));
        label->setText(QApplication::translate("Travelagencyui", "ID", nullptr));
        label_2->setText(QApplication::translate("Travelagencyui", "Vorname", nullptr));
        label_3->setText(QApplication::translate("Travelagencyui", "Nachname", nullptr));
        QTableWidgetItem *___qtablewidgetitem = customerTravelTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Travelagencyui", "Reise-ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = customerTravelTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Travelagencyui", "Beginn der Reise", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = customerTravelTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Travelagencyui", "Ende der Reise", nullptr));
        label_4->setText(QApplication::translate("Travelagencyui", "Reisen", nullptr));
        travelGroupBox->setTitle(QApplication::translate("Travelagencyui", "Reise", nullptr));
        label_5->setText(QApplication::translate("Travelagencyui", "Reise-ID", nullptr));
        label_6->setText(QApplication::translate("Travelagencyui", "Buchungen", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = travelTable->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("Travelagencyui", "BuchungsTyp", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = travelTable->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("Travelagencyui", "Start", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = travelTable->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("Travelagencyui", "Ende", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = travelTable->horizontalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("Travelagencyui", "Preis", nullptr));
        bookingGroupBox->setTitle(QApplication::translate("Travelagencyui", "Buchungsdetails", nullptr));
        label_11->setText(QApplication::translate("Travelagencyui", "Airline", nullptr));
        label_12->setText(QApplication::translate("Travelagencyui", "FromDest", nullptr));
        label_13->setText(QApplication::translate("Travelagencyui", "ToDest", nullptr));
        label_14->setText(QApplication::translate("Travelagencyui", "BookingClass", nullptr));
        label_28->setText(QApplication::translate("Travelagencyui", "depaturAirport", nullptr));
        label_29->setText(QApplication::translate("Travelagencyui", "arrivalAirport", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(flug), QApplication::translate("Travelagencyui", "Flug", nullptr));
        label_15->setText(QApplication::translate("Travelagencyui", "PickupLocation", nullptr));
        label_16->setText(QApplication::translate("Travelagencyui", "returnLocation", nullptr));
        label_17->setText(QApplication::translate("Travelagencyui", "Company", nullptr));
        label_18->setText(QApplication::translate("Travelagencyui", "VehicleClass", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(mietwagen), QApplication::translate("Travelagencyui", "Mietwagen", nullptr));
        label_19->setText(QApplication::translate("Travelagencyui", "Hotel", nullptr));
        label_20->setText(QApplication::translate("Travelagencyui", "Town", nullptr));
        label_21->setText(QApplication::translate("Travelagencyui", "Roomtype", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(hotel), QApplication::translate("Travelagencyui", "Hotel", nullptr));
        label_27->setText(QApplication::translate("Travelagencyui", "\303\234ber", nullptr));
        label_22->setText(QApplication::translate("Travelagencyui", "Von", nullptr));
        label_23->setText(QApplication::translate("Travelagencyui", "Abfahrt", nullptr));
        label_24->setText(QApplication::translate("Travelagencyui", "Nach", nullptr));
        label_25->setText(QApplication::translate("Travelagencyui", "Ankunft", nullptr));
        label_26->setText(QApplication::translate("Travelagencyui", "TicketType", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(zug), QApplication::translate("Travelagencyui", "Zug", nullptr));
        label_7->setText(QApplication::translate("Travelagencyui", "ID", nullptr));
        label_8->setText(QApplication::translate("Travelagencyui", "Price", nullptr));
        label_9->setText(QApplication::translate("Travelagencyui", "Von", nullptr));
        label_10->setText(QApplication::translate("Travelagencyui", "Bis", nullptr));
        savePushButton->setText(QApplication::translate("Travelagencyui", "Speichern", nullptr));
        cancelPushButton->setText(QApplication::translate("Travelagencyui", "Abbrechen", nullptr));
        menuDatei->setTitle(QApplication::translate("Travelagencyui", "Datei", nullptr));
        menukund_innen->setTitle(QApplication::translate("Travelagencyui", "kund*innen", nullptr));
        toolBar->setWindowTitle(QApplication::translate("Travelagencyui", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Travelagencyui: public Ui_Travelagencyui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAVELAGENCYUI_H
