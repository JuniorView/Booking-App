#ifndef TRAVELAGENCYUI_H
#define TRAVELAGENCYUI_H

#include <QMainWindow>
#include "travelagency.h"
#include <QTableWidget>
#include "customersearchdialog.h"
#include <QListWidget>
#include "buchungsdetails.h"
#include "check.h"
#include "meldungen.h"
#include "configurationwindow.h"

namespace Ui {
class Travelagencyui;
}

class Travelagencyui : public QMainWindow
{
    Q_OBJECT

public:
    explicit Travelagencyui( shared_ptr<TravelAgency> travelagency,QWidget *parent = nullptr);
//    void addToList();
//    void clearAllBookings();
   void clearBookingsDetails();
    ~Travelagencyui();
    void searchCustomer(long customerId);
    void enableButtons();
    void disableButtons();
    void updateSelectedBooking();
    void updateDetailsView();

     Check &getCheck() ;

private slots:
    void on_actionEinlesen_triggered();


   // void on_bookingList_itemDoubleClicked(QListWidgetItem *item);

    void on_actionsuchen_triggered();

    void on_travelTable_itemDoubleClicked(QTableWidgetItem *item);

    void on_customerTravelTable_itemDoubleClicked(QTableWidgetItem *item);

    void on_savePushButton_clicked();

    void on_cancelPushButton_clicked();

    void on_actionSpeichern_triggered();

    void slotCheck();

    void on_fromDateFlug_textChanged(const QString &arg1);

    void on_toDateflug_textChanged(const QString &arg1);

    void on_actionAnzeigen_triggered();

    void on_actionset_config_triggered();

private:
    Ui::Travelagencyui *ui;
    CustomerSearchDialog* customerSearchDialog;

    //TravelAgency* travelagency;
    shared_ptr<TravelAgency> travelagency;
    Check check;

signals:
   void checkSignal();

};

#endif // TRAVELAGENCYUI_H
