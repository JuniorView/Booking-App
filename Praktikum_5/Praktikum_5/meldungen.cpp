#include "meldungen.h"
#include "ui_meldungen.h"

Meldungen::Meldungen(vector<IncorrectReservation> incorrectReservations,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Meldungen),
   incorrectReservations(incorrectReservations)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(incorrectReservations.size());

    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Fehlertyp"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Beschreibung"));
    ui->tableWidget->setColumnWidth(0, 70);//////// 40
    ui->tableWidget->setColumnWidth(1, 950);///////////////// 650




    for (unsigned int row = 0; row < incorrectReservations.size(); ++row) {
        IncorrectReservation reservation = incorrectReservations[row];

        QTableWidgetItem *item = new QTableWidgetItem;

        if (reservation.type == MissingHotel) {
            item->setIcon(QIcon("MissingHotel.png"));

        } else if (reservation.type == OverlappedCar) {
            item->setIcon(QIcon("Car.png"));

        } else if (reservation.type == OverlappedHotel) {
            item->setIcon(QIcon("hotel.png"));

        } else if (reservation.type == OverlappedTravel) {
            item->setIcon(QIcon("uberlappung.png"));

        }
        ui->tableWidget->setItem(row, 0, item);
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(reservation.errorInfo));
    }
}

Meldungen::~Meldungen()
{
    delete ui;
}
