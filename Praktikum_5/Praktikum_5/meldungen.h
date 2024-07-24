#ifndef MELDUNGEN_H
#define MELDUNGEN_H
#include "travelagency.h"
#include "travelagencyui.h"
#include <QMainWindow>

namespace Ui {
class Meldungen;
}

class Meldungen : public QMainWindow
{
    Q_OBJECT

public:
    explicit Meldungen(vector<IncorrectReservation> incorrectReservations,QWidget *parent = nullptr);
    ~Meldungen();

private:
    Ui::Meldungen *ui;
    vector<IncorrectReservation> incorrectReservations;
   // shared_ptr<Travelagencyui> travelagencyui;
};

#endif // MELDUNGEN_H
