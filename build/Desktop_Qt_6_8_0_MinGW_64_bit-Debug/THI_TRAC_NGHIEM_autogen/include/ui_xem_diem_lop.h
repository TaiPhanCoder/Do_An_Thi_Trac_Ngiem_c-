/********************************************************************************
** Form generated from reading UI file 'xem_diem_lop.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XEM_DIEM_LOP_H
#define UI_XEM_DIEM_LOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_xem_diem_lop
{
public:
    QDialogButtonBox *buttonBox;
    QTableWidget *dsachdiem;
    QLabel *tenMH;
    QLabel *maMH;
    QLabel *label_3;

    void setupUi(QDialog *xem_diem_lop)
    {
        if (xem_diem_lop->objectName().isEmpty())
            xem_diem_lop->setObjectName("xem_diem_lop");
        xem_diem_lop->resize(700, 520);
        buttonBox = new QDialogButtonBox(xem_diem_lop);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(340, 470, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        dsachdiem = new QTableWidget(xem_diem_lop);
        dsachdiem->setObjectName("dsachdiem");
        dsachdiem->setGeometry(QRect(30, 180, 641, 261));
        tenMH = new QLabel(xem_diem_lop);
        tenMH->setObjectName("tenMH");
        tenMH->setGeometry(QRect(380, 110, 261, 41));
        tenMH->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 14px;\n"
"text-align: center;"));
        maMH = new QLabel(xem_diem_lop);
        maMH->setObjectName("maMH");
        maMH->setGeometry(QRect(60, 110, 261, 41));
        maMH->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 14px;\n"
"text-align: center;"));
        label_3 = new QLabel(xem_diem_lop);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(120, 30, 451, 51));

        retranslateUi(xem_diem_lop);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, xem_diem_lop, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, xem_diem_lop, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(xem_diem_lop);
    } // setupUi

    void retranslateUi(QDialog *xem_diem_lop)
    {
        xem_diem_lop->setWindowTitle(QCoreApplication::translate("xem_diem_lop", "Dialog", nullptr));
        tenMH->setText(QCoreApplication::translate("xem_diem_lop", "TextLabel", nullptr));
        maMH->setText(QCoreApplication::translate("xem_diem_lop", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("xem_diem_lop", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:700; color:#ff0000;\">\304\220I\341\273\202M THI</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class xem_diem_lop: public Ui_xem_diem_lop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XEM_DIEM_LOP_H
