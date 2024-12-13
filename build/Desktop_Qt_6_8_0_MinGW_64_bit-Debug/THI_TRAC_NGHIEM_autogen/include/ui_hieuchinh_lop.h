/********************************************************************************
** Form generated from reading UI file 'hieuchinh_lop.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HIEUCHINH_LOP_H
#define UI_HIEUCHINH_LOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_hieuchinh_lop
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *hieuChinh;
    QLineEdit *MaLop;
    QLineEdit *TenLop;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *hieuchinh_lop)
    {
        if (hieuchinh_lop->objectName().isEmpty())
            hieuchinh_lop->setObjectName("hieuchinh_lop");
        hieuchinh_lop->resize(600, 300);
        buttonBox = new QDialogButtonBox(hieuchinh_lop);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(200, 250, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        hieuChinh = new QLabel(hieuchinh_lop);
        hieuChinh->setObjectName("hieuChinh");
        hieuChinh->setGeometry(QRect(90, 20, 421, 61));
        MaLop = new QLineEdit(hieuchinh_lop);
        MaLop->setObjectName("MaLop");
        MaLop->setGeometry(QRect(0, 120, 251, 51));
        MaLop->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;\n"
"padding-left: 85px;"));
        TenLop = new QLineEdit(hieuchinh_lop);
        TenLop->setObjectName("TenLop");
        TenLop->setGeometry(QRect(330, 120, 251, 51));
        TenLop->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;\n"
"padding-left: 85px;"));
        label = new QLabel(hieuchinh_lop);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 190, 151, 20));
        label_2 = new QLabel(hieuchinh_lop);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(380, 190, 151, 20));

        retranslateUi(hieuchinh_lop);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, hieuchinh_lop, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, hieuchinh_lop, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(hieuchinh_lop);
    } // setupUi

    void retranslateUi(QDialog *hieuchinh_lop)
    {
        hieuchinh_lop->setWindowTitle(QCoreApplication::translate("hieuchinh_lop", "Dialog", nullptr));
        hieuChinh->setText(QCoreApplication::translate("hieuchinh_lop", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700; color:#ff0000;\">Hi\341\273\207u Ch\341\273\211nh</span></p></body></html>", nullptr));
        MaLop->setPlaceholderText(QCoreApplication::translate("hieuchinh_lop", "Ma Lop", nullptr));
        TenLop->setPlaceholderText(QCoreApplication::translate("hieuchinh_lop", "    Ten Lop", nullptr));
        label->setText(QCoreApplication::translate("hieuchinh_lop", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("hieuchinh_lop", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hieuchinh_lop: public Ui_hieuchinh_lop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIEUCHINH_LOP_H
