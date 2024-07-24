#ifndef CONFIGURATIONWINDOW_H
#define CONFIGURATIONWINDOW_H

#include <QMainWindow>
#include "travelagencyui.h"
#include "travelagency.h"

namespace Ui {
class configurationWindow;
}

class configurationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit configurationWindow(shared_ptr<TravelAgency> travelagency,QWidget *parent = nullptr);
    ~configurationWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::configurationWindow *ui;
    shared_ptr<TravelAgency> travelagency;
    Check check;
    // shared_ptr<Travelagencyui> travelagencyui;
};

#endif // CONFIGURATIONWINDOW_H
