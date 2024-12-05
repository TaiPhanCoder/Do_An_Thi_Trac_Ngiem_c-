/********************************************************************************
** Form generated from reading UI file 'trac_nghiem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAC_NGHIEM_H
#define UI_TRAC_NGHIEM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Trac_Nghiem
{
public:
    QWidget *centralwidget;
    QGroupBox *Khung_Thong_Tin;
    QLabel *MSSV;
    QLabel *TEN;
    QLabel *maMH;
    QLabel *Questions;
    QLabel *Times;
    QLabel *MonHoc;
    QLabel *logo_PTIT;
    QGroupBox *groupBox;
    QLabel *timerLabel;
    QGroupBox *grLamBai;
    QFrame *Lam_Bai;
    QLabel *cau_hoi;
    QRadioButton *AQ;
    QRadioButton *BQ;
    QRadioButton *CQ;
    QRadioButton *DQ;
    QPushButton *left_arow;
    QPushButton *right_arow;
    QPushButton *NopBai;
    QGroupBox *grCauHoi;
    QListWidget *listWidget;
    QGroupBox *groupBox_4;
    QGroupBox *ketQuaThi;
    QLabel *mssv;
    QLabel *ten;
    QLabel *label_3;
    QLabel *diem;
    QLabel *soCauDung;
    QLabel *thoiGianLamBai;
    QLabel *tenMH;
    QLabel *mamh;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Trac_Nghiem)
    {
        if (Trac_Nghiem->objectName().isEmpty())
            Trac_Nghiem->setObjectName("Trac_Nghiem");
        Trac_Nghiem->resize(1536, 960);
        centralwidget = new QWidget(Trac_Nghiem);
        centralwidget->setObjectName("centralwidget");
        Khung_Thong_Tin = new QGroupBox(centralwidget);
        Khung_Thong_Tin->setObjectName("Khung_Thong_Tin");
        Khung_Thong_Tin->setGeometry(QRect(20, 10, 991, 151));
        Khung_Thong_Tin->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"	color: black;\n"
"	font-size: 14px;"));
        MSSV = new QLabel(Khung_Thong_Tin);
        MSSV->setObjectName("MSSV");
        MSSV->setGeometry(QRect(170, 30, 251, 31));
        MSSV->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 14px;\n"
"text-align: center;"));
        TEN = new QLabel(Khung_Thong_Tin);
        TEN->setObjectName("TEN");
        TEN->setGeometry(QRect(470, 30, 481, 31));
        maMH = new QLabel(Khung_Thong_Tin);
        maMH->setObjectName("maMH");
        maMH->setGeometry(QRect(170, 70, 251, 31));
        Questions = new QLabel(Khung_Thong_Tin);
        Questions->setObjectName("Questions");
        Questions->setGeometry(QRect(170, 110, 251, 31));
        Questions->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"	border-radius: 20px;"));
        Times = new QLabel(Khung_Thong_Tin);
        Times->setObjectName("Times");
        Times->setGeometry(QRect(470, 110, 481, 31));
        MonHoc = new QLabel(Khung_Thong_Tin);
        MonHoc->setObjectName("MonHoc");
        MonHoc->setGeometry(QRect(470, 70, 481, 31));
        logo_PTIT = new QLabel(Khung_Thong_Tin);
        logo_PTIT->setObjectName("logo_PTIT");
        logo_PTIT->setGeometry(QRect(12, 30, 101, 101));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(1020, 10, 231, 151));
        groupBox->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"	color: black;\n"
"	font-size: 14px;"));
        timerLabel = new QLabel(groupBox);
        timerLabel->setObjectName("timerLabel");
        timerLabel->setGeometry(QRect(22, 40, 191, 91));
        timerLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 30px;\n"
"    font-weight: bold;\n"
"    color: black;\n"
"    background-color: lightgray;\n"
"    border-radius: 10px;\n"
"}\n"
""));
        grLamBai = new QGroupBox(centralwidget);
        grLamBai->setObjectName("grLamBai");
        grLamBai->setGeometry(QRect(19, 169, 1231, 651));
        Lam_Bai = new QFrame(grLamBai);
        Lam_Bai->setObjectName("Lam_Bai");
        Lam_Bai->setGeometry(QRect(30, 50, 1171, 501));
        Lam_Bai->setFrameShape(QFrame::Shape::StyledPanel);
        Lam_Bai->setFrameShadow(QFrame::Shadow::Raised);
        cau_hoi = new QLabel(Lam_Bai);
        cau_hoi->setObjectName("cau_hoi");
        cau_hoi->setGeometry(QRect(70, 30, 1031, 101));
        cau_hoi->setStyleSheet(QString::fromUtf8("font-size:22pt; font-weight:700; color:#ff0000;"));
        cau_hoi->setAlignment(Qt::AlignmentFlag::AlignCenter);
        AQ = new QRadioButton(Lam_Bai);
        AQ->setObjectName("AQ");
        AQ->setGeometry(QRect(100, 150, 1000, 50));
        AQ->setStyleSheet(QString::fromUtf8("font-size: 16pt; color: #000000;"));
        BQ = new QRadioButton(Lam_Bai);
        BQ->setObjectName("BQ");
        BQ->setGeometry(QRect(100, 220, 1000, 50));
        BQ->setStyleSheet(QString::fromUtf8("font-size: 16pt; color: #000000;"));
        CQ = new QRadioButton(Lam_Bai);
        CQ->setObjectName("CQ");
        CQ->setGeometry(QRect(100, 290, 1000, 50));
        CQ->setStyleSheet(QString::fromUtf8("font-size: 16pt; color: #000000;"));
        DQ = new QRadioButton(Lam_Bai);
        DQ->setObjectName("DQ");
        DQ->setGeometry(QRect(100, 360, 1000, 50));
        DQ->setStyleSheet(QString::fromUtf8("font-size: 16pt; color: #000000;"));
        left_arow = new QPushButton(grLamBai);
        left_arow->setObjectName("left_arow");
        left_arow->setGeometry(QRect(350, 580, 151, 51));
        left_arow->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/logo/left-long-solid.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        left_arow->setIcon(icon);
        left_arow->setIconSize(QSize(40, 150));
        right_arow = new QPushButton(grLamBai);
        right_arow->setObjectName("right_arow");
        right_arow->setGeometry(QRect(670, 580, 151, 51));
        right_arow->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/logo/right-long-solid.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        right_arow->setIcon(icon1);
        right_arow->setIconSize(QSize(40, 150));
        NopBai = new QPushButton(grLamBai);
        NopBai->setObjectName("NopBai");
        NopBai->setGeometry(QRect(520, 580, 131, 51));
        NopBai->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        grCauHoi = new QGroupBox(centralwidget);
        grCauHoi->setObjectName("grCauHoi");
        grCauHoi->setGeometry(QRect(1279, 169, 241, 651));
        grCauHoi->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"	color: black;\n"
"	font-size: 14px;"));
        listWidget = new QListWidget(grCauHoi);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(10, 41, 221, 591));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(1279, 9, 231, 151));
        groupBox_4->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"	color: black;\n"
"	font-size: 14px;"));
        ketQuaThi = new QGroupBox(centralwidget);
        ketQuaThi->setObjectName("ketQuaThi");
        ketQuaThi->setGeometry(QRect(530, 170, 601, 651));
        ketQuaThi->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 20px;\n"
"color: black;\n"
"font-size: 14px;"));
        mssv = new QLabel(ketQuaThi);
        mssv->setObjectName("mssv");
        mssv->setGeometry(QRect(40, 120, 261, 41));
        mssv->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 14px;\n"
"text-align: center;"));
        ten = new QLabel(ketQuaThi);
        ten->setObjectName("ten");
        ten->setGeometry(QRect(320, 120, 261, 41));
        label_3 = new QLabel(ketQuaThi);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 40, 451, 51));
        diem = new QLabel(ketQuaThi);
        diem->setObjectName("diem");
        diem->setGeometry(QRect(180, 250, 261, 101));
        soCauDung = new QLabel(ketQuaThi);
        soCauDung->setObjectName("soCauDung");
        soCauDung->setGeometry(QRect(40, 380, 261, 51));
        thoiGianLamBai = new QLabel(ketQuaThi);
        thoiGianLamBai->setObjectName("thoiGianLamBai");
        thoiGianLamBai->setGeometry(QRect(40, 460, 261, 51));
        tenMH = new QLabel(ketQuaThi);
        tenMH->setObjectName("tenMH");
        tenMH->setGeometry(QRect(320, 180, 261, 41));
        mamh = new QLabel(ketQuaThi);
        mamh->setObjectName("mamh");
        mamh->setGeometry(QRect(40, 180, 261, 41));
        mamh->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"background-color: #F0F0F0;\n"
"color: black;\n"
"font-size: 14px;\n"
"text-align: center;"));
        Trac_Nghiem->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Trac_Nghiem);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1536, 25));
        Trac_Nghiem->setMenuBar(menubar);
        statusbar = new QStatusBar(Trac_Nghiem);
        statusbar->setObjectName("statusbar");
        Trac_Nghiem->setStatusBar(statusbar);

        retranslateUi(Trac_Nghiem);

        QMetaObject::connectSlotsByName(Trac_Nghiem);
    } // setupUi

    void retranslateUi(QMainWindow *Trac_Nghiem)
    {
        Trac_Nghiem->setWindowTitle(QCoreApplication::translate("Trac_Nghiem", "Thi Tr\341\272\257c Nghi\341\273\207m", nullptr));
        Khung_Thong_Tin->setTitle(QCoreApplication::translate("Trac_Nghiem", "Th\303\264ng Tin Thi Tr\341\272\257c Nghi\341\273\207m", nullptr));
        MSSV->setText(QCoreApplication::translate("Trac_Nghiem", "MSSV:", nullptr));
        TEN->setText(QCoreApplication::translate("Trac_Nghiem", "T\303\252n:", nullptr));
        maMH->setText(QCoreApplication::translate("Trac_Nghiem", "M\303\243 M\303\264n H\341\273\215c:", nullptr));
        Questions->setText(QCoreApplication::translate("Trac_Nghiem", "S\341\273\221 C\303\242u H\341\273\217i:", nullptr));
        Times->setText(QCoreApplication::translate("Trac_Nghiem", "S\341\273\221 Ph\303\272t:", nullptr));
        MonHoc->setText(QCoreApplication::translate("Trac_Nghiem", "M\303\264n H\341\273\215c:", nullptr));
        logo_PTIT->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("Trac_Nghiem", "Th\341\273\235i Gian Thi", nullptr));
        timerLabel->setText(QCoreApplication::translate("Trac_Nghiem", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">25:00</span></p></body></html>", nullptr));
        grLamBai->setTitle(QCoreApplication::translate("Trac_Nghiem", "Ph\341\272\247n L\303\240m B\303\240i", nullptr));
        cau_hoi->setText(QCoreApplication::translate("Trac_Nghiem", "<html><head/><body><p><span style=\" font-size:22pt; font-weight:700; color:#ff0000;\">C\303\242u h\341\273\217i: Th\341\273\247 \304\221\303\264 c\341\273\247a Vi\341\273\207t Nam l\303\240 th\303\240nh ph\341\273\221 n\303\240o?</span></p></body></html>", nullptr));
        AQ->setText(QCoreApplication::translate("Trac_Nghiem", "A. H\341\273\223 Ch\303\255 Minh", nullptr));
        BQ->setText(QCoreApplication::translate("Trac_Nghiem", "B. \304\220\303\240 N\341\272\265ng", nullptr));
        CQ->setText(QCoreApplication::translate("Trac_Nghiem", "C. H\303\240 N\341\273\231i", nullptr));
        DQ->setText(QCoreApplication::translate("Trac_Nghiem", "D. H\341\272\243i Ph\303\262ng", nullptr));
        left_arow->setText(QString());
        right_arow->setText(QString());
        NopBai->setText(QCoreApplication::translate("Trac_Nghiem", "N\341\273\231p B\303\240i", nullptr));
        grCauHoi->setTitle(QCoreApplication::translate("Trac_Nghiem", "Danh S\303\241ch C\303\242u H\341\273\217i", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Trac_Nghiem", "H\306\260\341\273\233ng D\341\272\253n L\303\240m B\303\240i", nullptr));
        ketQuaThi->setTitle(QCoreApplication::translate("Trac_Nghiem", "K\341\272\277t Qu\341\272\243 Thi", nullptr));
        mssv->setText(QCoreApplication::translate("Trac_Nghiem", "TextLabel", nullptr));
        ten->setText(QCoreApplication::translate("Trac_Nghiem", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("Trac_Nghiem", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:700; color:#ff0000;\">K\341\272\277t Qu\341\272\243 Thi</span></p></body></html>", nullptr));
        diem->setText(QCoreApplication::translate("Trac_Nghiem", "TextLabel", nullptr));
        soCauDung->setText(QCoreApplication::translate("Trac_Nghiem", "TextLabel", nullptr));
        thoiGianLamBai->setText(QCoreApplication::translate("Trac_Nghiem", "TextLabel", nullptr));
        tenMH->setText(QCoreApplication::translate("Trac_Nghiem", "TextLabel", nullptr));
        mamh->setText(QCoreApplication::translate("Trac_Nghiem", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Trac_Nghiem: public Ui_Trac_Nghiem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAC_NGHIEM_H
