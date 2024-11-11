#include "hieuchinh.h"
#include "ui_hieuchinh.h"
#include "lop.h"

HieuChinh::HieuChinh(const QString &mssv, const QString &ho, const QString &ten, const QString &lop, const QString &gioiTinh, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HieuChinh)
{
    ui->setupUi(this);
    setupComboBoxes();

    ui->MSSV->setText(mssv);
    ui->Ho->setText(ho);
    ui->Ten->setText(ten);
    ui->Lop->setCurrentText(lop);
    ui->GioiTinh->setCurrentText(gioiTinh);
}

void HieuChinh::setupComboBoxes() {
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
}


HieuChinh::~HieuChinh()
{
    delete ui;
}
