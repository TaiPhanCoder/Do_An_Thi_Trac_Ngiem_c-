/********************************************************************************
** Form generated from reading UI file 'quan_ly_mon.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUAN_LY_MON_H
#define UI_QUAN_LY_MON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_quan_Ly_Mon
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_3;
    QLineEdit *timKiem;
    QTableWidget *dsachdiem;
    QLineEdit *maMH;
    QLineEdit *tenMH;
    QPushButton *them;
    QLabel *LoiMaLop;
    QLabel *loiTenMH;
    QSpinBox *tinChi;
    QLabel *loiTinChi;
    QLabel *label;

    void setupUi(QDialog *quan_Ly_Mon)
    {
        if (quan_Ly_Mon->objectName().isEmpty())
            quan_Ly_Mon->setObjectName("quan_Ly_Mon");
        quan_Ly_Mon->resize(700, 552);
        buttonBox = new QDialogButtonBox(quan_Ly_Mon);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(330, 510, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label_3 = new QLabel(quan_Ly_Mon);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(115, 10, 451, 51));
        timKiem = new QLineEdit(quan_Ly_Mon);
        timKiem->setObjectName("timKiem");
        timKiem->setGeometry(QRect(180, 160, 291, 41));
        timKiem->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;"));
        dsachdiem = new QTableWidget(quan_Ly_Mon);
        dsachdiem->setObjectName("dsachdiem");
        dsachdiem->setGeometry(QRect(30, 240, 641, 261));
        maMH = new QLineEdit(quan_Ly_Mon);
        maMH->setObjectName("maMH");
        maMH->setGeometry(QRect(30, 70, 211, 41));
        maMH->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;\n"
""));
        tenMH = new QLineEdit(quan_Ly_Mon);
        tenMH->setObjectName("tenMH");
        tenMH->setGeometry(QRect(260, 70, 291, 41));
        tenMH->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;\n"
""));
        them = new QPushButton(quan_Ly_Mon);
        them->setObjectName("them");
        them->setGeometry(QRect(580, 70, 91, 41));
        them->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 10px;\n"
"background-color: rgb(255, 35, 35);\n"
"color: white;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2);"));
        LoiMaLop = new QLabel(quan_Ly_Mon);
        LoiMaLop->setObjectName("LoiMaLop");
        LoiMaLop->setGeometry(QRect(30, 110, 211, 20));
        loiTenMH = new QLabel(quan_Ly_Mon);
        loiTenMH->setObjectName("loiTenMH");
        loiTenMH->setGeometry(QRect(260, 110, 291, 20));
        tinChi = new QSpinBox(quan_Ly_Mon);
        tinChi->setObjectName("tinChi");
        tinChi->setGeometry(QRect(40, 160, 111, 41));
        tinChi->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
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
        loiTinChi = new QLabel(quan_Ly_Mon);
        loiTinChi->setObjectName("loiTinChi");
        loiTinChi->setGeometry(QRect(30, 200, 121, 20));
        label = new QLabel(quan_Ly_Mon);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 140, 111, 20));

        retranslateUi(quan_Ly_Mon);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, quan_Ly_Mon, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, quan_Ly_Mon, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(quan_Ly_Mon);
    } // setupUi

    void retranslateUi(QDialog *quan_Ly_Mon)
    {
        quan_Ly_Mon->setWindowTitle(QCoreApplication::translate("quan_Ly_Mon", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("quan_Ly_Mon", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:700; color:#ff0000;\">Qu\341\272\243n l\303\275 m\303\264n h\341\273\215c</span></p></body></html>", nullptr));
        timKiem->setPlaceholderText(QCoreApplication::translate("quan_Ly_Mon", "                           T\303\254m Ki\341\272\277m", nullptr));
        maMH->setPlaceholderText(QCoreApplication::translate("quan_Ly_Mon", "                   M\303\203 MH", nullptr));
        tenMH->setPlaceholderText(QCoreApplication::translate("quan_Ly_Mon", "                     T\303\212N M\303\224N H\341\273\214C", nullptr));
        them->setText(QCoreApplication::translate("quan_Ly_Mon", "TH\303\212M", nullptr));
        LoiMaLop->setText(QString());
        loiTenMH->setText(QString());
        loiTinChi->setText(QString());
        label->setText(QCoreApplication::translate("quan_Ly_Mon", "<html><head/><body><p align=\"center\"><span style=\" font-size:8pt;\">S\341\273\221 t\303\255n ch\341\273\211</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class quan_Ly_Mon: public Ui_quan_Ly_Mon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUAN_LY_MON_H
