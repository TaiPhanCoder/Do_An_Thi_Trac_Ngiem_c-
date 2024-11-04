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
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *logo;
    QLabel *label_2;
    QGroupBox *groupBox_2;
    QLineEdit *timMSSV;
    QLabel *label;
    QTableWidget *bangDuLieu;
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
        groupBox->setGeometry(QRect(0, 180, 321, 681));
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
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(80, 100, 151, 61));
        pushButton_2->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: rgb(255, 35, 35);\n"
"color: white;\n"
"font-size: 16px;\n"
"padding: 10px 20px;\n"
"font-weight: bold;\n"
"box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2);"));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(80, 260, 151, 61));
        pushButton_3->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
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
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(319, 0, 1201, 191));
        timMSSV = new QLineEdit(groupBox_2);
        timMSSV->setObjectName("timMSSV");
        timMSSV->setGeometry(QRect(10, 60, 261, 28));
        label = new QLabel(groupBox_2);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 261, 20));
        bangDuLieu = new QTableWidget(centralwidget);
        bangDuLieu->setObjectName("bangDuLieu");
        bangDuLieu->setGeometry(QRect(325, 191, 1201, 671));
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
        pushButton_2->setText(QCoreApplication::translate("GIao_Vien", "Sinh Vi\303\252n", nullptr));
        pushButton_3->setText(QCoreApplication::translate("GIao_Vien", "C\303\242u H\341\273\217i", nullptr));
        logo->setText(QString());
        label_2->setText(QCoreApplication::translate("GIao_Vien", "H\341\273\215c Vi\341\273\207n Ho\303\240ng Gia HCM", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("GIao_Vien", "T\303\255nh N\304\203ng", nullptr));
        timMSSV->setPlaceholderText(QCoreApplication::translate("GIao_Vien", "MSSV", nullptr));
        label->setText(QCoreApplication::translate("GIao_Vien", "T\303\254m ki\341\272\277m:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GIao_Vien: public Ui_GIao_Vien {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GIAO_VIEN_H
