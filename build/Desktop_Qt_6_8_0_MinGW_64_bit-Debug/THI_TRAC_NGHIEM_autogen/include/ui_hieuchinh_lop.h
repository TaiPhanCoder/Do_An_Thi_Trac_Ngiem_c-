/********************************************************************************
** Form generated from reading UI file 'hieuchinh_lop.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HIEUCHINH_LOP_H
#define UI_HIEUCHINH_LOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_HieuChinh_Lop
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *hieuChinh;
    QLineEdit *MaLop;
    QLineEdit *TenLop;
    QLabel *LoiMaLop;
    QLabel *LoiTenLop;

    void setupUi(QDialog *HieuChinh_Lop)
    {
        if (HieuChinh_Lop->objectName().isEmpty())
            HieuChinh_Lop->setObjectName("HieuChinh_Lop");
        HieuChinh_Lop->resize(600, 300);
        buttonBox = new QDialogButtonBox(HieuChinh_Lop);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(200, 250, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        hieuChinh = new QLabel(HieuChinh_Lop);
        hieuChinh->setObjectName("hieuChinh");
        hieuChinh->setGeometry(QRect(90, 20, 421, 61));
        MaLop = new QLineEdit(HieuChinh_Lop);
        MaLop->setObjectName("MaLop");
        MaLop->setGeometry(QRect(0, 120, 251, 51));
        MaLop->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;\n"
"padding-left: 85px;"));
        TenLop = new QLineEdit(HieuChinh_Lop);
        TenLop->setObjectName("TenLop");
        TenLop->setGeometry(QRect(330, 120, 251, 51));
        TenLop->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;\n"
"padding-left: 85px;"));
        LoiMaLop = new QLabel(HieuChinh_Lop);
        LoiMaLop->setObjectName("LoiMaLop");
        LoiMaLop->setGeometry(QRect(70, 190, 151, 20));
        LoiTenLop = new QLabel(HieuChinh_Lop);
        LoiTenLop->setObjectName("LoiTenLop");
        LoiTenLop->setGeometry(QRect(380, 190, 151, 20));

        retranslateUi(HieuChinh_Lop);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, HieuChinh_Lop, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, HieuChinh_Lop, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(HieuChinh_Lop);
    } // setupUi

    void retranslateUi(QDialog *HieuChinh_Lop)
    {
        HieuChinh_Lop->setWindowTitle(QCoreApplication::translate("HieuChinh_Lop", "Dialog", nullptr));
        hieuChinh->setText(QCoreApplication::translate("HieuChinh_Lop", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700; color:#ff0000;\">Hi\341\273\207u Ch\341\273\211nh</span></p></body></html>", nullptr));
        MaLop->setPlaceholderText(QCoreApplication::translate("HieuChinh_Lop", "Ma Lop", nullptr));
        TenLop->setPlaceholderText(QCoreApplication::translate("HieuChinh_Lop", "    Ten Lop", nullptr));
        LoiMaLop->setText(QString());
        LoiTenLop->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HieuChinh_Lop: public Ui_HieuChinh_Lop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIEUCHINH_LOP_H
