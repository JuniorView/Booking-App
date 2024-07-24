#ifndef BUCHUNGSDETAILS_H
#define BUCHUNGSDETAILS_H

#include <QMainWindow>

namespace Ui {
class BuchungsDetails;
}

class BuchungsDetails : public QMainWindow
{
    Q_OBJECT

public:
    explicit BuchungsDetails(QWidget *parent = nullptr);
    ~BuchungsDetails();

private:
    Ui::BuchungsDetails *ui;
};

#endif // BUCHUNGSDETAILS_H
