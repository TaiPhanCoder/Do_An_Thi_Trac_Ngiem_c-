/********************************************************************************
** Form generated from reading UI file 'them_sinh_vien.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEM_SINH_VIEN_H
#define UI_THEM_SINH_VIEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Them_Sinh_Vien
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *Lop;
    QLabel *ThongTin;
    QLineEdit *MSSV;
    QLineEdit *Ho;
    QLineEdit *Ten;
    QComboBox *GioiTinh;
    QLabel *LoiLop;
    QLabel *LoiMSSV;
    QLabel *LoiTen;
    QLabel *LoiHo;
    QLabel *LoiGioiTinh;

    void setupUi(QDialog *Them_Sinh_Vien)
    {
        if (Them_Sinh_Vien->objectName().isEmpty())
            Them_Sinh_Vien->setObjectName("Them_Sinh_Vien");
        Them_Sinh_Vien->resize(600, 450);
        buttonBox = new QDialogButtonBox(Them_Sinh_Vien);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(230, 400, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        Lop = new QComboBox(Them_Sinh_Vien);
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
        ThongTin = new QLabel(Them_Sinh_Vien);
        ThongTin->setObjectName("ThongTin");
        ThongTin->setGeometry(QRect(90, 30, 421, 61));
        MSSV = new QLineEdit(Them_Sinh_Vien);
        MSSV->setObjectName("MSSV");
        MSSV->setGeometry(QRect(310, 120, 251, 51));
        MSSV->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;\n"
"padding-left: 85px;"));
        Ho = new QLineEdit(Them_Sinh_Vien);
        Ho->setObjectName("Ho");
        Ho->setGeometry(QRect(40, 210, 251, 51));
        Ho->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;\n"
"padding-left: 85px;"));
        Ten = new QLineEdit(Them_Sinh_Vien);
        Ten->setObjectName("Ten");
        Ten->setGeometry(QRect(310, 210, 251, 51));
        Ten->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;\n"
"padding-left: 85px;"));
        GioiTinh = new QComboBox(Them_Sinh_Vien);
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
        LoiLop = new QLabel(Them_Sinh_Vien);
        LoiLop->setObjectName("LoiLop");
        LoiLop->setGeometry(QRect(40, 180, 251, 20));
        LoiMSSV = new QLabel(Them_Sinh_Vien);
        LoiMSSV->setObjectName("LoiMSSV");
        LoiMSSV->setGeometry(QRect(310, 180, 251, 20));
        LoiTen = new QLabel(Them_Sinh_Vien);
        LoiTen->setObjectName("LoiTen");
        LoiTen->setGeometry(QRect(310, 270, 251, 20));
        LoiHo = new QLabel(Them_Sinh_Vien);
        LoiHo->setObjectName("LoiHo");
        LoiHo->setGeometry(QRect(40, 270, 251, 20));
        LoiGioiTinh = new QLabel(Them_Sinh_Vien);
        LoiGioiTinh->setObjectName("LoiGioiTinh");
        LoiGioiTinh->setGeometry(QRect(170, 360, 251, 20));

        retranslateUi(Them_Sinh_Vien);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Them_Sinh_Vien, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Them_Sinh_Vien, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Them_Sinh_Vien);
    } // setupUi

    void retranslateUi(QDialog *Them_Sinh_Vien)
    {
        Them_Sinh_Vien->setWindowTitle(QCoreApplication::translate("Them_Sinh_Vien", "Dialog", nullptr));
        Lop->setPlaceholderText(QCoreApplication::translate("Them_Sinh_Vien", "                  Ch\341\273\215n L\341\273\233p", nullptr));
        ThongTin->setText(QCoreApplication::translate("Them_Sinh_Vien", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700; color:#ff0000;\">Th\303\252m Sinh Vi\303\252n</span></p></body></html>", nullptr));
        MSSV->setPlaceholderText(QCoreApplication::translate("Them_Sinh_Vien", "    MSSV", nullptr));
        Ho->setPlaceholderText(QCoreApplication::translate("Them_Sinh_Vien", "    H\341\273\215", nullptr));
        Ten->setText(QString());
        Ten->setPlaceholderText(QCoreApplication::translate("Them_Sinh_Vien", "    T\303\252n", nullptr));
        GioiTinh->setPlaceholderText(QCoreApplication::translate("Them_Sinh_Vien", "                      Gi\341\273\233i T\303\255nh", nullptr));
        LoiLop->setText(QString());
        LoiMSSV->setText(QString());
        LoiTen->setText(QString());
        LoiHo->setText(QString());
        LoiGioiTinh->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Them_Sinh_Vien: public Ui_Them_Sinh_Vien {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEM_SINH_VIEN_H
