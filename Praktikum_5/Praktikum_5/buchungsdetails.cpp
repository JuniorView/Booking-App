#include "buchungsdetails.h"
#include "ui_buchungsdetails.h"

BuchungsDetails::BuchungsDetails(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BuchungsDetails)
{
    ui->setupUi(this);
    ui->tabWidget->setTabIcon(0,QIcon("plane.png"));
    ui->tabWidget->setTabIcon(1,QIcon ("Car.png"));
    ui->tabWidget->setTabIcon(2,QIcon ("hotel.png"));
    ui->tabWidget->setTabIcon(3,QIcon ("train.png"));

}

BuchungsDetails::~BuchungsDetails()
{
    delete ui;
}
