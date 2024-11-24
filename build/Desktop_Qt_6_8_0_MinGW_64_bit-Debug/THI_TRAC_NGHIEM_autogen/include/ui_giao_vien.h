/********************************************************************************
** Form generated from reading UI file 'giao_vien.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GIAO_VIEN_H
#define UI_GIAO_VIEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GIao_Vien
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *sinhVien;
    QPushButton *cauHoi;
    QLabel *logo;
    QLabel *label_2;
    QGroupBox *tinhNangSinhVien;
    QLineEdit *timMSSV;
    QLabel *label;
    QGroupBox *themSinhVien;
    QPushButton *them1sv;
    QPushButton *themNhieuSV;
    QPushButton *sapXep;
    QComboBox *locLop;
    QTableWidget *bangDuLieu;
    QGroupBox *tinhNangCauHoi;
    QLineEdit *timMSSV_3;
    QLabel *label_4;
    QGroupBox *themSinhVien_3;
    QPushButton *them1sv_3;
    QPushButton *themNhieuSV_3;
    QComboBox *locLop_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GIao_Vien)
    {
        if (GIao_Vien->objectName().isEmpty())
            GIao_Vien->setObjectName("GIao_Vien");
        GIao_Vien->resize(1687, 960);
        centralwidget = new QWidget(GIao_Vien);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 180, 321, 641));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(80, 180, 151, 61));
        pushButton->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: rgb(255, 35, 35);\n"
"color: white;\n"
"font-size: 16px;\n"
"padding: 10px 20px;\n"
"font-weight: bold;\n"
"box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2);"));
        sinhVien = new QPushButton(groupBox);
        sinhVien->setObjectName("sinhVien");
        sinhVien->setGeometry(QRect(80, 100, 151, 61));
        sinhVien->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: rgb(255, 35, 35);\n"
"color: white;\n"
"font-size: 16px;\n"
"padding: 10px 20px;\n"
"font-weight: bold;\n"
"box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2);"));
        cauHoi = new QPushButton(groupBox);
        cauHoi->setObjectName("cauHoi");
        cauHoi->setGeometry(QRect(80, 260, 151, 61));
        cauHoi->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: rgb(255, 35, 35);\n"
"color: white;\n"
"font-size: 16px;\n"
"padding: 10px 20px;\n"
"font-weight: bold;\n"
"box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2);"));
        logo = new QLabel(centralwidget);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(120, 10, 201, 121));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/logo/ad27bc12ca81e862ceb35328122757ee.png")));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(12, 150, 311, 31));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: red;                      /* \304\220\341\272\267t m\303\240u ch\341\273\257 th\303\240nh \304\221\341\273\217 */\n"
"    font-weight: bold;               /* B\303\264i \304\221\341\272\255m ch\341\273\257 */\n"
"    qproperty-alignment: 'AlignCenter';  /* C\304\203n gi\341\273\257a n\341\273\231i dung */\n"
"}\n"
""));
        tinhNangSinhVien = new QGroupBox(centralwidget);
        tinhNangSinhVien->setObjectName("tinhNangSinhVien");
        tinhNangSinhVien->setGeometry(QRect(319, 0, 1201, 191));
        timMSSV = new QLineEdit(tinhNangSinhVien);
        timMSSV->setObjectName("timMSSV");
        timMSSV->setGeometry(QRect(10, 60, 261, 28));
        timMSSV->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 10px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;\n"
"padding-left: 85px;"));
        label = new QLabel(tinhNangSinhVien);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 261, 20));
        themSinhVien = new QGroupBox(tinhNangSinhVien);
        themSinhVien->setObjectName("themSinhVien");
        themSinhVien->setGeometry(QRect(10, 90, 261, 91));
        them1sv = new QPushButton(themSinhVien);
        them1sv->setObjectName("them1sv");
        them1sv->setGeometry(QRect(10, 28, 111, 51));
        them1sv->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 10px;\n"
"background-color: rgb(255, 35, 35);\n"
"color: white;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2);"));
        themNhieuSV = new QPushButton(themSinhVien);
        themNhieuSV->setObjectName("themNhieuSV");
        themNhieuSV->setGeometry(QRect(140, 28, 111, 51));
        themNhieuSV->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 10px;\n"
"background-color: rgb(255, 35, 35);\n"
"color: white;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2);"));
        sapXep = new QPushButton(tinhNangSinhVien);
        sapXep->setObjectName("sapXep");
        sapXep->setGeometry(QRect(320, 60, 231, 29));
        sapXep->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 10px;\n"
"background-color: rgb(255, 35, 35);\n"
"color: white;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2);"));
        locLop = new QComboBox(tinhNangSinhVien);
        locLop->setObjectName("locLop");
        locLop->setGeometry(QRect(310, 120, 251, 51));
        locLop->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        bangDuLieu = new QTableWidget(centralwidget);
        bangDuLieu->setObjectName("bangDuLieu");
        bangDuLieu->setGeometry(QRect(325, 191, 1201, 631));
        tinhNangCauHoi = new QGroupBox(centralwidget);
        tinhNangCauHoi->setObjectName("tinhNangCauHoi");
        tinhNangCauHoi->setGeometry(QRect(320, 0, 1201, 191));
        timMSSV_3 = new QLineEdit(tinhNangCauHoi);
        timMSSV_3->setObjectName("timMSSV_3");
        timMSSV_3->setGeometry(QRect(10, 60, 261, 28));
        timMSSV_3->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 10px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;\n"
"padding-left: 85px;"));
        label_4 = new QLabel(tinhNangCauHoi);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 30, 261, 20));
        themSinhVien_3 = new QGroupBox(tinhNangCauHoi);
        themSinhVien_3->setObjectName("themSinhVien_3");
        themSinhVien_3->setGeometry(QRect(10, 90, 261, 91));
        them1sv_3 = new QPushButton(themSinhVien_3);
        them1sv_3->setObjectName("them1sv_3");
        them1sv_3->setGeometry(QRect(10, 28, 111, 51));
        them1sv_3->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 10px;\n"
"background-color: rgb(255, 35, 35);\n"
"color: white;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2);"));
        themNhieuSV_3 = new QPushButton(themSinhVien_3);
        themNhieuSV_3->setObjectName("themNhieuSV_3");
        themNhieuSV_3->setGeometry(QRect(140, 28, 111, 51));
        themNhieuSV_3->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 10px;\n"
"background-color: rgb(255, 35, 35);\n"
"color: white;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2);"));
        locLop_3 = new QComboBox(tinhNangCauHoi);
        locLop_3->setObjectName("locLop_3");
        locLop_3->setGeometry(QRect(310, 120, 251, 51));
        locLop_3->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        GIao_Vien->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GIao_Vien);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1687, 25));
        GIao_Vien->setMenuBar(menubar);
        statusbar = new QStatusBar(GIao_Vien);
        statusbar->setObjectName("statusbar");
        GIao_Vien->setStatusBar(statusbar);

        retranslateUi(GIao_Vien);

        QMetaObject::connectSlotsByName(GIao_Vien);
    } // setupUi

    void retranslateUi(QMainWindow *GIao_Vien)
    {
        GIao_Vien->setWindowTitle(QCoreApplication::translate("GIao_Vien", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("GIao_Vien", "Tu\341\273\263 Ch\341\273\215n", nullptr));
        pushButton->setText(QCoreApplication::translate("GIao_Vien", "L\341\273\233p", nullptr));
        sinhVien->setText(QCoreApplication::translate("GIao_Vien", "Sinh Vi\303\252n", nullptr));
        cauHoi->setText(QCoreApplication::translate("GIao_Vien", "C\303\242u H\341\273\217i", nullptr));
        logo->setText(QString());
        label_2->setText(QCoreApplication::translate("GIao_Vien", "H\341\273\215c Vi\341\273\207n Ho\303\240ng Gia HCM", nullptr));
        tinhNangSinhVien->setTitle(QCoreApplication::translate("GIao_Vien", "T\303\255nh N\304\203ng", nullptr));
        timMSSV->setPlaceholderText(QCoreApplication::translate("GIao_Vien", "MSSV", nullptr));
        label->setText(QCoreApplication::translate("GIao_Vien", "T\303\254m ki\341\272\277m:", nullptr));
        themSinhVien->setTitle(QCoreApplication::translate("GIao_Vien", "Th\303\252m Sinh Vi\303\252n", nullptr));
        them1sv->setText(QCoreApplication::translate("GIao_Vien", "M\341\273\231t Ng\306\260\341\273\235i", nullptr));
        themNhieuSV->setText(QCoreApplication::translate("GIao_Vien", "Danh S\303\241ch", nullptr));
        sapXep->setText(QCoreApplication::translate("GIao_Vien", "S\341\272\257p x\341\272\277p theo t\303\252n", nullptr));
        locLop->setPlaceholderText(QCoreApplication::translate("GIao_Vien", "                      L\341\273\215c L\341\273\233p", nullptr));
        tinhNangCauHoi->setTitle(QCoreApplication::translate("GIao_Vien", "T\303\255nh N\304\203ng", nullptr));
        timMSSV_3->setPlaceholderText(QCoreApplication::translate("GIao_Vien", "MSSV", nullptr));
        label_4->setText(QCoreApplication::translate("GIao_Vien", "T\303\254m ki\341\272\277m:", nullptr));
        themSinhVien_3->setTitle(QCoreApplication::translate("GIao_Vien", "Th\303\252m Sinh Vi\303\252n", nullptr));
        them1sv_3->setText(QCoreApplication::translate("GIao_Vien", "M\341\273\231t Ng\306\260\341\273\235i", nullptr));
        themNhieuSV_3->setText(QCoreApplication::translate("GIao_Vien", "Danh S\303\241ch", nullptr));
        locLop_3->setPlaceholderText(QCoreApplication::translate("GIao_Vien", "                      L\341\273\215c L\341\273\233p", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GIao_Vien: public Ui_GIao_Vien {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GIAO_VIEN_H
