#include "them_sinh_vien.h"
#include "ui_them_sinh_vien.h"
#include "lop.h"

Them_Sinh_Vien::Them_Sinh_Vien(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Them_Sinh_Vien)
{
    ui->setupUi(this);
    ui->Lop->clear();
    for (int i = 0; i < 10000; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }
        ui->Lop->addItem(danhSachLop[i]->MALOP);
    }

    for (int i = 0; i < ui->Lop->count(); ++i) {
        ui->Lop->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    }

    ui->GioiTinh->addItem("Nam");
    ui->GioiTinh->addItem("Nữ");

    for (int i = 0; i < ui->GioiTinh->count(); ++i) {
        ui->GioiTinh->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    }

    connect(ui->MSSV, &QLineEdit::textEdited, this, [=](const QString &text) {
        QString filteredText;
        for (QChar ch : text) {
            if (ch.isLetterOrNumber()) {
                filteredText.append(ch.toUpper());
            }
        }
        ui->MSSV->setText(filteredText);
        ui->MSSV->setCursorPosition(filteredText.length());
    });
}

Them_Sinh_Vien::~Them_Sinh_Vien()
{
    delete ui;
}

QString Them_Sinh_Vien::getMSSV() const {
    return ui->MSSV->text();
}

QString Them_Sinh_Vien::getHo() const {
    return ui->Ho->text();
}

QString Them_Sinh_Vien::getTen() const {
    return ui->Ten->text();
}

QString Them_Sinh_Vien::getGioiTinh() const {
    return ui->GioiTinh->currentText();
}

QString Them_Sinh_Vien::getLop() const {
    return ui->Lop->currentText();
}
