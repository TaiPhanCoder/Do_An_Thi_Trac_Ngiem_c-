/********************************************************************************
** Form generated from reading UI file 'them_lop.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEM_LOP_H
#define UI_THEM_LOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Them_Lop
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *MaLop;
    QLineEdit *TenLop;
    QLabel *ThongTin;
    QLabel *LoiMaLop;
    QLabel *LoiTenLop;

    void setupUi(QDialog *Them_Lop)
    {
        if (Them_Lop->objectName().isEmpty())
            Them_Lop->setObjectName("Them_Lop");
        Them_Lop->resize(600, 300);
        buttonBox = new QDialogButtonBox(Them_Lop);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(220, 250, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        MaLop = new QLineEdit(Them_Lop);
        MaLop->setObjectName("MaLop");
        MaLop->setGeometry(QRect(10, 120, 251, 51));
        MaLop->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;\n"
"padding-left: 85px;"));
        TenLop = new QLineEdit(Them_Lop);
        TenLop->setObjectName("TenLop");
        TenLop->setGeometry(QRect(300, 120, 251, 51));
        TenLop->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;\n"
"padding-left: 85px;"));
        ThongTin = new QLabel(Them_Lop);
        ThongTin->setObjectName("ThongTin");
        ThongTin->setGeometry(QRect(90, 10, 421, 61));
        LoiMaLop = new QLabel(Them_Lop);
        LoiMaLop->setObjectName("LoiMaLop");
        LoiMaLop->setGeometry(QRect(70, 190, 141, 20));
        LoiTenLop = new QLabel(Them_Lop);
        LoiTenLop->setObjectName("LoiTenLop");
        LoiTenLop->setGeometry(QRect(370, 190, 121, 20));

        retranslateUi(Them_Lop);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Them_Lop, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Them_Lop, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Them_Lop);
    } // setupUi

    void retranslateUi(QDialog *Them_Lop)
    {
        Them_Lop->setWindowTitle(QCoreApplication::translate("Them_Lop", "Dialog", nullptr));
        MaLop->setPlaceholderText(QCoreApplication::translate("Them_Lop", "    Ma Lop", nullptr));
        TenLop->setPlaceholderText(QCoreApplication::translate("Them_Lop", "    Ten Lop", nullptr));
        ThongTin->setText(QCoreApplication::translate("Them_Lop", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700; color:#ff0000;\">Th\303\252m Lop</span></p></body></html>", nullptr));
        LoiMaLop->setText(QString());
        LoiTenLop->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Them_Lop: public Ui_Them_Lop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEM_LOP_H
