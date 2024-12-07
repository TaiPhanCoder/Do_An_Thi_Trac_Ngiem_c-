/********************************************************************************
** Form generated from reading UI file 'xemdiem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XEMDIEM_H
#define UI_XEMDIEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_xemDiem
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_3;
    QLabel *mssv;
    QLabel *ten;
    QTableWidget *dsachdiem;
    QLineEdit *timKiem;

    void setupUi(QDialog *xemDiem)
    {
        if (xemDiem->objectName().isEmpty())
            xemDiem->setObjectName("xemDiem");
        xemDiem->resize(700, 520);
        buttonBox = new QDialogButtonBox(xemDiem);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(330, 470, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label_3 = new QLabel(xemDiem);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(120, 10, 451, 51));
        mssv = new QLabel(xemDiem);
        mssv->setObjectName("mssv");
        mssv->setGeometry(QRect(40, 80, 261, 41));
        mssv->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 14px;\n"
"text-align: center;"));
        ten = new QLabel(xemDiem);
        ten->setObjectName("ten");
        ten->setGeometry(QRect(410, 80, 261, 41));
        ten->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 14px;\n"
"text-align: center;"));
        dsachdiem = new QTableWidget(xemDiem);
        dsachdiem->setObjectName("dsachdiem");
        dsachdiem->setGeometry(QRect(35, 200, 641, 261));
        timKiem = new QLineEdit(xemDiem);
        timKiem->setObjectName("timKiem");
        timKiem->setGeometry(QRect(40, 140, 261, 41));
        timKiem->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 16px;\n"
"padding-left: 85px;"));

        retranslateUi(xemDiem);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, xemDiem, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, xemDiem, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(xemDiem);
    } // setupUi

    void retranslateUi(QDialog *xemDiem)
    {
        xemDiem->setWindowTitle(QCoreApplication::translate("xemDiem", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("xemDiem", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:700; color:#ff0000;\">\304\220I\341\273\202M THI</span></p></body></html>", nullptr));
        mssv->setText(QCoreApplication::translate("xemDiem", "TextLabel", nullptr));
        ten->setText(QCoreApplication::translate("xemDiem", "TextLabel", nullptr));
        timKiem->setPlaceholderText(QCoreApplication::translate("xemDiem", "   T\303\254m Ki\341\272\277m", nullptr));
    } // retranslateUi

};

namespace Ui {
    class xemDiem: public Ui_xemDiem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XEMDIEM_H
