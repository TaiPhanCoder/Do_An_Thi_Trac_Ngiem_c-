/********************************************************************************
** Form generated from reading UI file 'dang_nhap.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DANG_NHAP_H
#define UI_DANG_NHAP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dang_Nhap
{
public:
    QWidget *centralwidget;
    QLabel *labelDN;
    QLabel *logo;
    QLineEdit *TaiKhoan;
    QLineEdit *MatKhau;
    QPushButton *DangNhapButton;
    QPushButton *sharingan;
    QLabel *ThongBao;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QDialog *Dang_Nhap)
    {
        if (Dang_Nhap->objectName().isEmpty())
            Dang_Nhap->setObjectName("Dang_Nhap");
        Dang_Nhap->resize(600, 450);
        centralwidget = new QWidget(Dang_Nhap);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(0, 0, 591, 431));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        labelDN = new QLabel(centralwidget);
        labelDN->setObjectName("labelDN");
        labelDN->setGeometry(QRect(120, 30, 351, 61));
        logo = new QLabel(centralwidget);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(270, 110, 131, 71));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/logo/ad27bc12ca81e862ceb35328122757ee.png")));
        TaiKhoan = new QLineEdit(centralwidget);
        TaiKhoan->setObjectName("TaiKhoan");
        TaiKhoan->setGeometry(QRect(160, 200, 271, 51));
        TaiKhoan->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;\n"
"padding-left: 85px;"));
        MatKhau = new QLineEdit(centralwidget);
        MatKhau->setObjectName("MatKhau");
        MatKhau->setGeometry(QRect(160, 270, 271, 51));
        MatKhau->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;\n"
"padding-left: 85px;\n"
""));
        DangNhapButton = new QPushButton(centralwidget);
        DangNhapButton->setObjectName("DangNhapButton");
        DangNhapButton->setGeometry(QRect(240, 360, 121, 41));
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
        sharingan = new QPushButton(centralwidget);
        sharingan->setObjectName("sharingan");
        sharingan->setGeometry(QRect(370, 270, 71, 51));
        sharingan->setStyleSheet(QString::fromUtf8("border-radius: 25px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/logo/R.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        sharingan->setIcon(icon);
        ThongBao = new QLabel(centralwidget);
        ThongBao->setObjectName("ThongBao");
        ThongBao->setGeometry(QRect(220, 330, 231, 21));
        menubar = new QMenuBar(Dang_Nhap);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 600, 25));
        statusbar = new QStatusBar(Dang_Nhap);
        statusbar->setObjectName("statusbar");
        statusbar->setGeometry(QRect(0, 0, 3, 25));

        retranslateUi(Dang_Nhap);

        QMetaObject::connectSlotsByName(Dang_Nhap);
    } // setupUi

    void retranslateUi(QDialog *Dang_Nhap)
    {
        Dang_Nhap->setWindowTitle(QCoreApplication::translate("Dang_Nhap", "Dang_Nhap", nullptr));
        labelDN->setText(QCoreApplication::translate("Dang_Nhap", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:700; color:#ff0000;\">\304\220\304\203ng Nh\341\272\255p T\303\240i Kho\341\272\243n</span></p></body></html>", nullptr));
        logo->setText(QString());
        TaiKhoan->setPlaceholderText(QCoreApplication::translate("Dang_Nhap", "    T\303\240i Kho\341\272\243n", nullptr));
        MatKhau->setPlaceholderText(QCoreApplication::translate("Dang_Nhap", "     M\341\272\255t Kh\341\272\251u", nullptr));
        DangNhapButton->setText(QCoreApplication::translate("Dang_Nhap", "\304\220\304\203ng Nh\341\272\255p", nullptr));
        sharingan->setText(QString());
        ThongBao->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dang_Nhap: public Ui_Dang_Nhap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DANG_NHAP_H
