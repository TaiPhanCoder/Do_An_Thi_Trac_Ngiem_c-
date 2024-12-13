/********************************************************************************
** Form generated from reading UI file 'xem_diem_mon.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XEM_DIEM_MON_H
#define UI_XEM_DIEM_MON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_xem_Diem_Mon
{
public:
    QScrollArea *khuVucCauHoi;
    QWidget *scrollAreaWidgetContents;
    QLabel *tenMH;
    QLabel *ten;
    QLabel *maMH;
    QLabel *mssv;
    QLabel *diem;

    void setupUi(QDialog *xem_Diem_Mon)
    {
        if (xem_Diem_Mon->objectName().isEmpty())
            xem_Diem_Mon->setObjectName("xem_Diem_Mon");
        xem_Diem_Mon->resize(600, 800);
        khuVucCauHoi = new QScrollArea(xem_Diem_Mon);
        khuVucCauHoi->setObjectName("khuVucCauHoi");
        khuVucCauHoi->setGeometry(QRect(0, 199, 601, 601));
        khuVucCauHoi->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 599, 599));
        khuVucCauHoi->setWidget(scrollAreaWidgetContents);
        tenMH = new QLabel(xem_Diem_Mon);
        tenMH->setObjectName("tenMH");
        tenMH->setGeometry(QRect(320, 80, 261, 31));
        tenMH->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 10px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 14px;\n"
"text-align: center;"));
        ten = new QLabel(xem_Diem_Mon);
        ten->setObjectName("ten");
        ten->setGeometry(QRect(320, 30, 261, 31));
        ten->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 10px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 14px;\n"
"text-align: center;"));
        maMH = new QLabel(xem_Diem_Mon);
        maMH->setObjectName("maMH");
        maMH->setGeometry(QRect(10, 80, 261, 31));
        maMH->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 10px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 14px;\n"
"text-align: center;"));
        mssv = new QLabel(xem_Diem_Mon);
        mssv->setObjectName("mssv");
        mssv->setGeometry(QRect(10, 30, 261, 31));
        mssv->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 10px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 14px;\n"
"text-align: center;"));
        diem = new QLabel(xem_Diem_Mon);
        diem->setObjectName("diem");
        diem->setGeometry(QRect(190, 130, 201, 51));
        diem->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 10px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 14px;\n"
"text-align: center;"));

        retranslateUi(xem_Diem_Mon);

        QMetaObject::connectSlotsByName(xem_Diem_Mon);
    } // setupUi

    void retranslateUi(QDialog *xem_Diem_Mon)
    {
        xem_Diem_Mon->setWindowTitle(QCoreApplication::translate("xem_Diem_Mon", "Dialog", nullptr));
        tenMH->setText(QCoreApplication::translate("xem_Diem_Mon", "TextLabel", nullptr));
        ten->setText(QCoreApplication::translate("xem_Diem_Mon", "TextLabel", nullptr));
        maMH->setText(QCoreApplication::translate("xem_Diem_Mon", "TextLabel", nullptr));
        mssv->setText(QCoreApplication::translate("xem_Diem_Mon", "TextLabel", nullptr));
        diem->setText(QCoreApplication::translate("xem_Diem_Mon", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class xem_Diem_Mon: public Ui_xem_Diem_Mon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XEM_DIEM_MON_H
