/********************************************************************************
** Form generated from reading UI file 'hieuchinh.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HIEUCHINH_H
#define UI_HIEUCHINH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_HieuChinh
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *hieuChinh;
    QLineEdit *Ho;
    QLineEdit *MSSV;
    QLabel *LoiTen;
    QComboBox *GioiTinh;
    QLabel *LoiHo;
    QLabel *LoiMSSV;
    QLineEdit *Ten;
    QComboBox *Lop;
    QLabel *LoiLop;

    void setupUi(QDialog *HieuChinh)
    {
        if (HieuChinh->objectName().isEmpty())
            HieuChinh->setObjectName("HieuChinh");
        HieuChinh->resize(600, 450);
        buttonBox = new QDialogButtonBox(HieuChinh);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(240, 400, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        hieuChinh = new QLabel(HieuChinh);
        hieuChinh->setObjectName("hieuChinh");
        hieuChinh->setGeometry(QRect(90, 30, 421, 61));
        Ho = new QLineEdit(HieuChinh);
        Ho->setObjectName("Ho");
        Ho->setGeometry(QRect(40, 210, 251, 51));
        Ho->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;\n"
"padding-left: 85px;"));
        MSSV = new QLineEdit(HieuChinh);
        MSSV->setObjectName("MSSV");
        MSSV->setGeometry(QRect(310, 120, 251, 51));
        MSSV->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;\n"
"padding-left: 85px;"));
        LoiTen = new QLabel(HieuChinh);
        LoiTen->setObjectName("LoiTen");
        LoiTen->setGeometry(QRect(310, 270, 251, 20));
        GioiTinh = new QComboBox(HieuChinh);
        GioiTinh->setObjectName("GioiTinh");
        GioiTinh->setGeometry(QRect(170, 300, 251, 51));
        GioiTinh->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	border: 2px solid gray;\n"
"	border-radius: 20px;\n"
"	background-color: #F0F0F0;\n"
"	color: black;\n"
"	font-size: 16px;\n"
"text-align: center;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"width: 30px;\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: top right;\n"
"border: 2px solid gray;\n"
"border-radius: 10px;\n"
"background-color: #F0F0F0;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/logo/down-arrow (1).png); /* \304\220\306\260\341\273\235ng d\341\272\253n h\303\254nh \341\272\243nh m\305\251i t\303\252n */\n"
"    width: 20px;\n"
"    height: 20px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    background-color: white;\n"
"    selection-background-color: lightblue;  /* M\303\240u n\341\273\201n c\341\273\247a m\341\273\245c \304\221\306\260\341\273\243c ch\341\273\215n */\n"
"    selection-color: black;  /* M\303\240u ch\341\273\257 c\341\273\247a m\341\273\245c \304\221\306\260\341\273\243c ch\341\273"
                        "\215n */\n"
"    padding: 5px;\n"
"	font-size: 12px;\n"
"}\n"
"\n"
""));
        LoiHo = new QLabel(HieuChinh);
        LoiHo->setObjectName("LoiHo");
        LoiHo->setGeometry(QRect(40, 270, 251, 20));
        LoiMSSV = new QLabel(HieuChinh);
        LoiMSSV->setObjectName("LoiMSSV");
        LoiMSSV->setGeometry(QRect(310, 180, 251, 20));
        Ten = new QLineEdit(HieuChinh);
        Ten->setObjectName("Ten");
        Ten->setGeometry(QRect(310, 210, 251, 51));
        Ten->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;\n"
"padding-left: 85px;"));
        Lop = new QComboBox(HieuChinh);
        Lop->setObjectName("Lop");
        Lop->setGeometry(QRect(40, 120, 251, 51));
        Lop->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	border: 2px solid gray;\n"
"	border-radius: 20px;\n"
"	background-color: #F0F0F0;\n"
"	color: black;\n"
"	font-size: 16px;\n"
"text-align: center;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"width: 30px;\n"
"subcontrol-origin: padding;\n"
"subcontrol-position: top right;\n"
"border: 2px solid gray;\n"
"border-radius: 10px;\n"
"background-color: #F0F0F0;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/logo/down-arrow (1).png); /* \304\220\306\260\341\273\235ng d\341\272\253n h\303\254nh \341\272\243nh m\305\251i t\303\252n */\n"
"    width: 20px;\n"
"    height: 20px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    border: 2px solid gray;\n"
"    border-radius: 10px;\n"
"    background-color: white;\n"
"    selection-background-color: lightblue;  /* M\303\240u n\341\273\201n c\341\273\247a m\341\273\245c \304\221\306\260\341\273\243c ch\341\273\215n */\n"
"    selection-color: black;  /* M\303\240u ch\341\273\257 c\341\273\247a m\341\273\245c \304\221\306\260\341\273\243c ch\341\273"
                        "\215n */\n"
"    padding: 5px;\n"
"	font-size: 12px;\n"
"}\n"
"\n"
""));
        LoiLop = new QLabel(HieuChinh);
        LoiLop->setObjectName("LoiLop");
        LoiLop->setGeometry(QRect(40, 180, 251, 20));

        retranslateUi(HieuChinh);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, HieuChinh, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, HieuChinh, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(HieuChinh);
    } // setupUi

    void retranslateUi(QDialog *HieuChinh)
    {
        HieuChinh->setWindowTitle(QCoreApplication::translate("HieuChinh", "Dialog", nullptr));
        hieuChinh->setText(QCoreApplication::translate("HieuChinh", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700; color:#ff0000;\">Hi\341\273\207u Ch\341\273\211nh</span></p></body></html>", nullptr));
        Ho->setPlaceholderText(QCoreApplication::translate("HieuChinh", "    H\341\273\215", nullptr));
        MSSV->setPlaceholderText(QCoreApplication::translate("HieuChinh", "    MSSV", nullptr));
        LoiTen->setText(QString());
        GioiTinh->setPlaceholderText(QCoreApplication::translate("HieuChinh", "                      Gi\341\273\233i T\303\255nh", nullptr));
        LoiHo->setText(QString());
        LoiMSSV->setText(QString());
        Ten->setText(QString());
        Ten->setPlaceholderText(QCoreApplication::translate("HieuChinh", "    T\303\252n", nullptr));
        Lop->setPlaceholderText(QCoreApplication::translate("HieuChinh", "                  Ch\341\273\215n L\341\273\233p", nullptr));
        LoiLop->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HieuChinh: public Ui_HieuChinh {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIEUCHINH_H
