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

class Ui_them_lop
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *MaLop;
    QLineEdit *TenLop;
    QLabel *ThongTin;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *them_lop)
    {
        if (them_lop->objectName().isEmpty())
            them_lop->setObjectName("them_lop");
        them_lop->resize(600, 300);
        buttonBox = new QDialogButtonBox(them_lop);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(220, 250, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        MaLop = new QLineEdit(them_lop);
        MaLop->setObjectName("MaLop");
        MaLop->setGeometry(QRect(10, 120, 251, 51));
        MaLop->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;\n"
"padding-left: 85px;"));
        TenLop = new QLineEdit(them_lop);
        TenLop->setObjectName("TenLop");
        TenLop->setGeometry(QRect(300, 120, 251, 51));
        TenLop->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;\n"
"padding-left: 85px;"));
        ThongTin = new QLabel(them_lop);
        ThongTin->setObjectName("ThongTin");
        ThongTin->setGeometry(QRect(90, 10, 421, 61));
        label = new QLabel(them_lop);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 190, 141, 20));
        label_2 = new QLabel(them_lop);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(370, 190, 121, 20));

        retranslateUi(them_lop);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, them_lop, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, them_lop, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(them_lop);
    } // setupUi

    void retranslateUi(QDialog *them_lop)
    {
        them_lop->setWindowTitle(QCoreApplication::translate("them_lop", "Dialog", nullptr));
        MaLop->setPlaceholderText(QCoreApplication::translate("them_lop", "    Ma Lop", nullptr));
        TenLop->setPlaceholderText(QCoreApplication::translate("them_lop", "    Ten Lop", nullptr));
        ThongTin->setText(QCoreApplication::translate("them_lop", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700; color:#ff0000;\">Th\303\252m Lop</span></p></body></html>", nullptr));
        label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class them_lop: public Ui_them_lop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEM_LOP_H
