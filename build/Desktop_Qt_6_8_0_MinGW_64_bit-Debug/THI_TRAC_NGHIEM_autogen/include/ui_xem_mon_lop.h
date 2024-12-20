/********************************************************************************
** Form generated from reading UI file 'xem_mon_lop.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XEM_MON_LOP_H
#define UI_XEM_MON_LOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_xem_mon_lop
{
public:
    QDialogButtonBox *buttonBox;
    QTableWidget *dsachmon;
    QLabel *MaLop;
    QLabel *TenLop;
    QLabel *label_3;

    void setupUi(QDialog *xem_mon_lop)
    {
        if (xem_mon_lop->objectName().isEmpty())
            xem_mon_lop->setObjectName("xem_mon_lop");
        xem_mon_lop->resize(700, 520);
        buttonBox = new QDialogButtonBox(xem_mon_lop);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(340, 460, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        dsachmon = new QTableWidget(xem_mon_lop);
        dsachmon->setObjectName("dsachmon");
        dsachmon->setGeometry(QRect(30, 170, 641, 261));
        MaLop = new QLabel(xem_mon_lop);
        MaLop->setObjectName("MaLop");
        MaLop->setGeometry(QRect(50, 100, 261, 41));
        MaLop->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 14px;\n"
"text-align: center;"));
        TenLop = new QLabel(xem_mon_lop);
        TenLop->setObjectName("TenLop");
        TenLop->setGeometry(QRect(380, 100, 261, 41));
        TenLop->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 14px;\n"
"text-align: center;"));
        label_3 = new QLabel(xem_mon_lop);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(110, 30, 451, 51));

        retranslateUi(xem_mon_lop);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, xem_mon_lop, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, xem_mon_lop, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(xem_mon_lop);
    } // setupUi

    void retranslateUi(QDialog *xem_mon_lop)
    {
        xem_mon_lop->setWindowTitle(QCoreApplication::translate("xem_mon_lop", "Dialog", nullptr));
        MaLop->setText(QCoreApplication::translate("xem_mon_lop", "TextLabel", nullptr));
        TenLop->setText(QCoreApplication::translate("xem_mon_lop", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("xem_mon_lop", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:700; color:#ff0000;\">M\303\224N THI</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class xem_mon_lop: public Ui_xem_mon_lop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XEM_MON_LOP_H
