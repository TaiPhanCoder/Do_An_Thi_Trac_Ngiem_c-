/********************************************************************************
** Form generated from reading UI file 'themcauhoi.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEMCAUHOI_H
#define UI_THEMCAUHOI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_themcauhoi
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *noiDung;
    QLabel *ThongTin;
    QComboBox *monHoc;
    QLineEdit *A;
    QLabel *idMonHoc;
    QLineEdit *B;
    QLineEdit *D;
    QLineEdit *C;
    QComboBox *dapAnDung;
    QLabel *loiNoiDung;
    QLabel *loiMonHoc;
    QLabel *loiId;
    QLabel *loiDapAn;
    QLabel *loiA;
    QLabel *loiB;
    QLabel *loiD;
    QLabel *loiC;

    void setupUi(QDialog *themcauhoi)
    {
        if (themcauhoi->objectName().isEmpty())
            themcauhoi->setObjectName("themcauhoi");
        themcauhoi->resize(692, 519);
        buttonBox = new QDialogButtonBox(themcauhoi);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(310, 470, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        noiDung = new QLineEdit(themcauhoi);
        noiDung->setObjectName("noiDung");
        noiDung->setGeometry(QRect(40, 190, 621, 51));
        noiDung->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;"));
        ThongTin = new QLabel(themcauhoi);
        ThongTin->setObjectName("ThongTin");
        ThongTin->setGeometry(QRect(130, 30, 421, 61));
        monHoc = new QComboBox(themcauhoi);
        monHoc->setObjectName("monHoc");
        monHoc->setGeometry(QRect(40, 120, 291, 51));
        monHoc->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        A = new QLineEdit(themcauhoi);
        A->setObjectName("A");
        A->setGeometry(QRect(40, 330, 291, 51));
        A->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;\n"
""));
        idMonHoc = new QLabel(themcauhoi);
        idMonHoc->setObjectName("idMonHoc");
        idMonHoc->setGeometry(QRect(360, 119, 291, 51));
        idMonHoc->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;"));
        B = new QLineEdit(themcauhoi);
        B->setObjectName("B");
        B->setGeometry(QRect(360, 330, 291, 51));
        B->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;"));
        D = new QLineEdit(themcauhoi);
        D->setObjectName("D");
        D->setGeometry(QRect(360, 400, 291, 51));
        D->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;"));
        C = new QLineEdit(themcauhoi);
        C->setObjectName("C");
        C->setGeometry(QRect(40, 400, 291, 51));
        C->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;"));
        dapAnDung = new QComboBox(themcauhoi);
        dapAnDung->setObjectName("dapAnDung");
        dapAnDung->setGeometry(QRect(40, 260, 291, 51));
        dapAnDung->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        loiNoiDung = new QLabel(themcauhoi);
        loiNoiDung->setObjectName("loiNoiDung");
        loiNoiDung->setGeometry(QRect(40, 240, 621, 20));
        loiMonHoc = new QLabel(themcauhoi);
        loiMonHoc->setObjectName("loiMonHoc");
        loiMonHoc->setGeometry(QRect(40, 170, 291, 20));
        loiId = new QLabel(themcauhoi);
        loiId->setObjectName("loiId");
        loiId->setGeometry(QRect(360, 170, 291, 20));
        loiDapAn = new QLabel(themcauhoi);
        loiDapAn->setObjectName("loiDapAn");
        loiDapAn->setGeometry(QRect(40, 310, 291, 20));
        loiA = new QLabel(themcauhoi);
        loiA->setObjectName("loiA");
        loiA->setGeometry(QRect(40, 380, 291, 20));
        loiB = new QLabel(themcauhoi);
        loiB->setObjectName("loiB");
        loiB->setGeometry(QRect(360, 380, 291, 20));
        loiD = new QLabel(themcauhoi);
        loiD->setObjectName("loiD");
        loiD->setGeometry(QRect(360, 450, 291, 20));
        loiC = new QLabel(themcauhoi);
        loiC->setObjectName("loiC");
        loiC->setGeometry(QRect(40, 450, 291, 20));

        retranslateUi(themcauhoi);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, themcauhoi, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, themcauhoi, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(themcauhoi);
    } // setupUi

    void retranslateUi(QDialog *themcauhoi)
    {
        themcauhoi->setWindowTitle(QCoreApplication::translate("themcauhoi", "Dialog", nullptr));
        noiDung->setPlaceholderText(QCoreApplication::translate("themcauhoi", "                                                             N\341\273\231i Dung C\303\242u H\341\273\217i", nullptr));
        ThongTin->setText(QCoreApplication::translate("themcauhoi", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700; color:#ff0000;\">Th\303\252m C\303\242u H\341\273\217i</span></p></body></html>", nullptr));
        monHoc->setPlaceholderText(QCoreApplication::translate("themcauhoi", "                           M\303\264n H\341\273\215c", nullptr));
        A->setText(QString());
        A->setPlaceholderText(QCoreApplication::translate("themcauhoi", "                           \304\220\303\241p \303\241n A", nullptr));
        idMonHoc->setText(QCoreApplication::translate("themcauhoi", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">ID M\303\264n H\341\273\215c</span></p></body></html>", nullptr));
        B->setText(QString());
        B->setPlaceholderText(QCoreApplication::translate("themcauhoi", "                           \304\220\303\241p \303\241n B", nullptr));
        D->setText(QString());
        D->setPlaceholderText(QCoreApplication::translate("themcauhoi", "                           \304\220\303\241p \303\241n D", nullptr));
        C->setText(QString());
        C->setPlaceholderText(QCoreApplication::translate("themcauhoi", "                           \304\220\303\241p \303\241n C", nullptr));
        dapAnDung->setPlaceholderText(QCoreApplication::translate("themcauhoi", "                        \304\220\303\241p \303\241n \304\221\303\272ng", nullptr));
        loiNoiDung->setText(QString());
        loiMonHoc->setText(QString());
        loiId->setText(QString());
        loiDapAn->setText(QString());
        loiA->setText(QString());
        loiB->setText(QString());
        loiD->setText(QString());
        loiC->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class themcauhoi: public Ui_themcauhoi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEMCAUHOI_H
