/********************************************************************************
** Form generated from reading UI file 'customersearchdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERSEARCHDIALOG_H
#define UI_CUSTOMERSEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_CustomerSearchDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QSpinBox *customerIdSpinBox;

    void setupUi(QDialog *CustomerSearchDialog)
    {
        if (CustomerSearchDialog->objectName().isEmpty())
            CustomerSearchDialog->setObjectName(QString::fromUtf8("CustomerSearchDialog"));
        CustomerSearchDialog->resize(387, 154);
        buttonBox = new QDialogButtonBox(CustomerSearchDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(20, 110, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(CustomerSearchDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 31, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Serif"));
        font.setPointSize(14);
        label->setFont(font);
        customerIdSpinBox = new QSpinBox(CustomerSearchDialog);
        customerIdSpinBox->setObjectName(QString::fromUtf8("customerIdSpinBox"));
        customerIdSpinBox->setGeometry(QRect(35, 70, 241, 25));

        retranslateUi(CustomerSearchDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CustomerSearchDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CustomerSearchDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CustomerSearchDialog);
    } // setupUi

    void retranslateUi(QDialog *CustomerSearchDialog)
    {
        CustomerSearchDialog->setWindowTitle(QApplication::translate("CustomerSearchDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("CustomerSearchDialog", "ID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomerSearchDialog: public Ui_CustomerSearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERSEARCHDIALOG_H
