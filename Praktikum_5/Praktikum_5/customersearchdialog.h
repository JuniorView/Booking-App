#ifndef CUSTOMERSEARCHDIALOG_H
#define CUSTOMERSEARCHDIALOG_H

#include <QDialog>

namespace Ui {
class CustomerSearchDialog;
}

class CustomerSearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerSearchDialog(QWidget *parent = nullptr);
    ~CustomerSearchDialog();
    long getCustomerId();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::CustomerSearchDialog *ui;
};

#endif // CUSTOMERSEARCHDIALOG_H
