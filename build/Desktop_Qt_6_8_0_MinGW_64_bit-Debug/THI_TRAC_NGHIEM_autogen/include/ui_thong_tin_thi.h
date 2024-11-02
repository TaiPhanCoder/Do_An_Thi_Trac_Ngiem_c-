/********************************************************************************
** Form generated from reading UI file 'thong_tin_thi.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THONG_TIN_THI_H
#define UI_THONG_TIN_THI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Thong_Tin_Thi
{
public:
    QLabel *ThongTin;
    QComboBox *DSachMonHoc;
    QSpinBox *spinBox;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinBox_2;
    QPushButton *DangNhapButton;
    QLabel *MSSV;
    QLabel *TEN;
    QLabel *LoiDSach;
    QLabel *LoiCauHoi;
    QLabel *LoiThoiGian;

    void setupUi(QDialog *Thong_Tin_Thi)
    {
        if (Thong_Tin_Thi->objectName().isEmpty())
            Thong_Tin_Thi->setObjectName("Thong_Tin_Thi");
        Thong_Tin_Thi->resize(600, 450);
        ThongTin = new QLabel(Thong_Tin_Thi);
        ThongTin->setObjectName("ThongTin");
        ThongTin->setGeometry(QRect(80, 20, 421, 61));
        DSachMonHoc = new QComboBox(Thong_Tin_Thi);
        DSachMonHoc->setObjectName("DSachMonHoc");
        DSachMonHoc->setGeometry(QRect(90, 160, 391, 41));
        DSachMonHoc->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        spinBox = new QSpinBox(Thong_Tin_Thi);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(370, 230, 111, 41));
        spinBox->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"    border: 2px solid gray;\n"
"    border-radius: 20px;\n"
"    background-color: #F0F0F0;\n"
"    color: black;\n"
"    font-size: 16px;\n"
"    padding: 2px;  /* Th\303\252m kho\341\272\243ng c\303\241ch gi\341\273\257a vi\341\273\201n v\303\240 n\341\273\231i dung */\n"
"    qproperty-alignment: 'AlignCenter';  /* C\304\203n gi\341\273\257a v\304\203n b\341\272\243n */\n"
"}\n"
"\n"
"QSpinBox::up-button, QSpinBox::down-button {\n"
"    width: 0px;\n"
"    height: 0px;\n"
"    border: none;\n"
"}\n"
"\n"
"\n"
""));
        label = new QLabel(Thong_Tin_Thi);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 230, 261, 41));
        label->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"	border-radius: 20px;\n"
"	background-color: #F0F0F0;\n"
"	color: black;\n"
"	font-size: 14px;\n"
"text-align: center;"));
        label_2 = new QLabel(Thong_Tin_Thi);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 300, 261, 41));
        label_2->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"	border-radius: 20px;\n"
"	background-color: #F0F0F0;\n"
"	color: black;\n"
"	font-size: 16px;\n"
"text-align: center;"));
        spinBox_2 = new QSpinBox(Thong_Tin_Thi);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setGeometry(QRect(370, 300, 111, 41));
        spinBox_2->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"    border: 2px solid gray;\n"
"    border-radius: 20px;\n"
"    background-color: #F0F0F0;\n"
"    color: black;\n"
"    font-size: 16px;\n"
"    padding: 2px;  /* Th\303\252m kho\341\272\243ng c\303\241ch gi\341\273\257a vi\341\273\201n v\303\240 n\341\273\231i dung */\n"
"    qproperty-alignment: 'AlignCenter';  /* C\304\203n gi\341\273\257a v\304\203n b\341\272\243n */\n"
"}\n"
"\n"
"QSpinBox::up-button, QSpinBox::down-button {\n"
"    width: 0px;\n"
"    height: 0px;\n"
"    border: none;\n"
"}\n"
"\n"
"\n"
""));
        DangNhapButton = new QPushButton(Thong_Tin_Thi);
        DangNhapButton->setObjectName("DangNhapButton");
        DangNhapButton->setGeometry(QRect(210, 370, 131, 51));
        DangNhapButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"font-size: 18px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(200, 0, 0);  /* M\303\240u n\341\273\201n khi hover (\304\221\341\272\255m h\306\241n) */\n"
"    cursor: pointer;  /* Con tr\341\273\217 chu\341\273\231t s\341\272\275 chuy\341\273\203n th\303\240nh h\303\254nh b\303\240n tay khi hover */\n"
"}\n"
"\n"
""));
        MSSV = new QLabel(Thong_Tin_Thi);
        MSSV->setObjectName("MSSV");
        MSSV->setGeometry(QRect(90, 90, 171, 41));
        MSSV->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"	border-radius: 10px;\n"
"	background-color: #F0F0F0;\n"
"	color: black;\n"
"text-align: center;\n"
"font-size: 12pt;"));
        TEN = new QLabel(Thong_Tin_Thi);
        TEN->setObjectName("TEN");
        TEN->setGeometry(QRect(270, 90, 211, 41));
        TEN->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"	border-radius: 10px;\n"
"	background-color: #F0F0F0;\n"
"	color: black;\n"
"text-align: center;\n"
"font-size: 12pt;"));
        LoiDSach = new QLabel(Thong_Tin_Thi);
        LoiDSach->setObjectName("LoiDSach");
        LoiDSach->setGeometry(QRect(90, 200, 261, 20));
        LoiCauHoi = new QLabel(Thong_Tin_Thi);
        LoiCauHoi->setObjectName("LoiCauHoi");
        LoiCauHoi->setGeometry(QRect(90, 270, 261, 20));
        LoiThoiGian = new QLabel(Thong_Tin_Thi);
        LoiThoiGian->setObjectName("LoiThoiGian");
        LoiThoiGian->setGeometry(QRect(90, 340, 261, 20));

        retranslateUi(Thong_Tin_Thi);

        QMetaObject::connectSlotsByName(Thong_Tin_Thi);
    } // setupUi

    void retranslateUi(QDialog *Thong_Tin_Thi)
    {
        Thong_Tin_Thi->setWindowTitle(QCoreApplication::translate("Thong_Tin_Thi", "Dialog", nullptr));
        ThongTin->setText(QCoreApplication::translate("Thong_Tin_Thi", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:700; color:#ff0000;\">Th\303\264ng Tin Thi Tr\341\272\257c Nghi\341\273\207m</span></p></body></html>", nullptr));
        DSachMonHoc->setPlaceholderText(QCoreApplication::translate("Thong_Tin_Thi", "                           Danh S\303\241ch M\303\264n H\341\273\215c", nullptr));
        label->setText(QCoreApplication::translate("Thong_Tin_Thi", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; color:#000000;\">S\341\273\221 C\303\242u H\341\273\217i Thi:</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Thong_Tin_Thi", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; color:#000000;\">S\341\273\221 Ph\303\272t Thi:</span></p></body></html>", nullptr));
        DangNhapButton->setText(QCoreApplication::translate("Thong_Tin_Thi", "Ho\303\240n Th\303\240nh", nullptr));
        MSSV->setText(QCoreApplication::translate("Thong_Tin_Thi", "<html><head/><body><p><span style=\" font-size:10pt;\">MSSV: </span></p></body></html>", nullptr));
        TEN->setText(QCoreApplication::translate("Thong_Tin_Thi", "<html><head/><body><p><span style=\" font-size:10pt;\">T\303\252n: </span></p></body></html>", nullptr));
        LoiDSach->setText(QString());
        LoiCauHoi->setText(QString());
        LoiThoiGian->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Thong_Tin_Thi: public Ui_Thong_Tin_Thi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THONG_TIN_THI_H
