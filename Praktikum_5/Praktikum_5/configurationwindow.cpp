#include "configurationwindow.h"
#include "ui_configurationwindow.h"

configurationWindow::configurationWindow(shared_ptr<TravelAgency> travelagency,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::configurationWindow),
    travelagency(travelagency),
   check(travelagency)
{
    ui->setupUi(this);
    Config config = travelagency->getConfig();
    ui->checkBox_Reiseberschneidung->setChecked(config.overlappedTravel);
    ui->checkBox_berflssige_Htotelbuchung->setChecked(config.overlappedHotel);
    ui->checkBox_fehlende_hotelBuchungen->setChecked(config.missedHotel);
    ui->checkBox_uberflssige_mietwagenbuchung->setChecked(config.overlappedCar);
}

configurationWindow::~configurationWindow()
{
    delete ui;
}

void configurationWindow::on_pushButton_clicked()
{
    Config newConfig;
    newConfig.missedHotel = ui->checkBox_fehlende_hotelBuchungen->isChecked();
    newConfig.overlappedHotel = ui->checkBox_berflssige_Htotelbuchung->isChecked();
    newConfig.overlappedCar = ui->checkBox_uberflssige_mietwagenbuchung->isChecked();
    newConfig.overlappedTravel = ui->checkBox_Reiseberschneidung->isChecked();
    travelagency->setConfig(newConfig);
    travelagency->clearIncorrectReservations();
    check();
    close();
}

