/********************************************************************************
** Form generated from reading UI file 'hieuchinh_cauhoi.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HIEUCHINH_CAUHOI_H
#define UI_HIEUCHINH_CAUHOI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_hieuchinh_CauHoi
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *A;
    QLineEdit *B;
    QLabel *loiNoiDung;
    QLabel *idMonHoc;
    QLineEdit *C;
    QLabel *loiC;
    QLabel *loiId;
    QLineEdit *D;
    QLabel *loiDapAn;
    QLineEdit *noiDung;
    QComboBox *monHoc;
    QLabel *ThongTin;
    QComboBox *dapAnDung;
    QLabel *loiA;
    QLabel *loiB;
    QLabel *loiD;
    QLabel *loiMonHoc;

    void setupUi(QDialog *hieuchinh_CauHoi)
    {
        if (hieuchinh_CauHoi->objectName().isEmpty())
            hieuchinh_CauHoi->setObjectName("hieuchinh_CauHoi");
        hieuchinh_CauHoi->resize(692, 519);
        buttonBox = new QDialogButtonBox(hieuchinh_CauHoi);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(320, 470, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        A = new QLineEdit(hieuchinh_CauHoi);
        A->setObjectName("A");
        A->setGeometry(QRect(30, 330, 291, 51));
        A->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;\n"
""));
        B = new QLineEdit(hieuchinh_CauHoi);
        B->setObjectName("B");
        B->setGeometry(QRect(350, 330, 291, 51));
        B->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;"));
        loiNoiDung = new QLabel(hieuchinh_CauHoi);
        loiNoiDung->setObjectName("loiNoiDung");
        loiNoiDung->setGeometry(QRect(30, 240, 621, 20));
        idMonHoc = new QLabel(hieuchinh_CauHoi);
        idMonHoc->setObjectName("idMonHoc");
        idMonHoc->setGeometry(QRect(350, 119, 291, 51));
        idMonHoc->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;"));
        C = new QLineEdit(hieuchinh_CauHoi);
        C->setObjectName("C");
        C->setGeometry(QRect(30, 400, 291, 51));
        C->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;"));
        loiC = new QLabel(hieuchinh_CauHoi);
        loiC->setObjectName("loiC");
        loiC->setGeometry(QRect(30, 450, 291, 20));
        loiId = new QLabel(hieuchinh_CauHoi);
        loiId->setObjectName("loiId");
        loiId->setGeometry(QRect(350, 170, 291, 20));
        D = new QLineEdit(hieuchinh_CauHoi);
        D->setObjectName("D");
        D->setGeometry(QRect(350, 400, 291, 51));
        D->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;"));
        loiDapAn = new QLabel(hieuchinh_CauHoi);
        loiDapAn->setObjectName("loiDapAn");
        loiDapAn->setGeometry(QRect(30, 310, 291, 20));
        noiDung = new QLineEdit(hieuchinh_CauHoi);
        noiDung->setObjectName("noiDung");
        noiDung->setGeometry(QRect(30, 190, 611, 51));
        noiDung->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;"));
        monHoc = new QComboBox(hieuchinh_CauHoi);
        monHoc->setObjectName("monHoc");
        monHoc->setGeometry(QRect(30, 120, 291, 51));
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
        ThongTin = new QLabel(hieuchinh_CauHoi);
        ThongTin->setObjectName("ThongTin");
        ThongTin->setGeometry(QRect(120, 30, 421, 61));
        dapAnDung = new QComboBox(hieuchinh_CauHoi);
        dapAnDung->setObjectName("dapAnDung");
        dapAnDung->setGeometry(QRect(30, 260, 291, 51));
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
        loiA = new QLabel(hieuchinh_CauHoi);
        loiA->setObjectName("loiA");
        loiA->setGeometry(QRect(30, 380, 291, 20));
        loiB = new QLabel(hieuchinh_CauHoi);
        loiB->setObjectName("loiB");
        loiB->setGeometry(QRect(350, 380, 291, 20));
        loiD = new QLabel(hieuchinh_CauHoi);
        loiD->setObjectName("loiD");
        loiD->setGeometry(QRect(350, 450, 291, 20));
        loiMonHoc = new QLabel(hieuchinh_CauHoi);
        loiMonHoc->setObjectName("loiMonHoc");
        loiMonHoc->setGeometry(QRect(30, 170, 291, 20));

        retranslateUi(hieuchinh_CauHoi);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, hieuchinh_CauHoi, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, hieuchinh_CauHoi, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(hieuchinh_CauHoi);
    } // setupUi

    void retranslateUi(QDialog *hieuchinh_CauHoi)
    {
        hieuchinh_CauHoi->setWindowTitle(QCoreApplication::translate("hieuchinh_CauHoi", "Dialog", nullptr));
        A->setText(QString());
        A->setPlaceholderText(QCoreApplication::translate("hieuchinh_CauHoi", "                           \304\220\303\241p \303\241n A", nullptr));
        B->setText(QString());
        B->setPlaceholderText(QCoreApplication::translate("hieuchinh_CauHoi", "                           \304\220\303\241p \303\241n B", nullptr));
        loiNoiDung->setText(QString());
        idMonHoc->setText(QCoreApplication::translate("hieuchinh_CauHoi", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">ID M\303\264n H\341\273\215c</span></p></body></html>", nullptr));
        C->setText(QString());
        C->setPlaceholderText(QCoreApplication::translate("hieuchinh_CauHoi", "                           \304\220\303\241p \303\241n C", nullptr));
        loiC->setText(QString());
        loiId->setText(QString());
        D->setText(QString());
        D->setPlaceholderText(QCoreApplication::translate("hieuchinh_CauHoi", "                           \304\220\303\241p \303\241n D", nullptr));
        loiDapAn->setText(QString());
        noiDung->setPlaceholderText(QCoreApplication::translate("hieuchinh_CauHoi", "                                                             N\341\273\231i Dung C\303\242u H\341\273\217i", nullptr));
        monHoc->setPlaceholderText(QCoreApplication::translate("hieuchinh_CauHoi", "                           M\303\264n H\341\273\215c", nullptr));
        ThongTin->setText(QCoreApplication::translate("hieuchinh_CauHoi", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:700; color:#ff0000;\">Hi\341\273\207u Ch\341\273\211nh C\303\242u H\341\273\217i</span></p></body></html>", nullptr));
        dapAnDung->setPlaceholderText(QCoreApplication::translate("hieuchinh_CauHoi", "                        \304\220\303\241p \303\241n \304\221\303\272ng", nullptr));
        loiA->setText(QString());
        loiB->setText(QString());
        loiD->setText(QString());
        loiMonHoc->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class hieuchinh_CauHoi: public Ui_hieuchinh_CauHoi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIEUCHINH_CAUHOI_H
