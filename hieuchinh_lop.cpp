#include "hieuchinh_Lop.h"
#include "ui_hieuchinh_Lop.h"
#include "lop.h"
#include "giao_vien.h"
#include "them_lop.h"

HieuChinh_Lop::HieuChinh_Lop(const QString &maLop, const QString &tenLop,
                             Lop* danhSachLop[],
                             GIao_Vien *giaoVien, QWidget *parent)
    : QDialog(parent), ui(new Ui::HieuChinh_Lop), oldMaLop(maLop),
    danhSachLop(danhSachLop), giaoVien(giaoVien) {

    ui->setupUi(this);
    this->setWindowTitle("Hiệu Chỉnh Lớp");

    ui->MaLop->setText(maLop);
    ui->TenLop->setText(tenLop);
}


// bool HieuChinh_Lop::checkMaLop(const QString &maLop, Lop* danhSachLop[]) {
//     for (int i = 0; danhSachLop[i] != nullptr; ++i) {
//         if (danhSachLop[i]->getMaLop() == maLop) {
//             return false;  // Mã lớp đã tồn tại
//         }
//     }
//     return true;  // Mã lớp không trùng

bool HieuChinh_Lop::checkMaLop(const QString& maLop, Lop** danhSachLop) {
    for (int i = 0; i < 10000; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }
        if (danhSachLop[i]->MALOP == maLop) {
            return false;
        }
    }
    return true;
}

// QString HieuChinh_Lop::getMaLop() const {
//     return ui->MaLop->text();
// }

// QString HieuChinh_Lop::getTenLop() const {
//     return ui->TenLop->text();
// }
HieuChinh_Lop::~HieuChinh_Lop() {
    delete ui;
}


void HieuChinh_Lop::chinhSuaLop() {
    QString newMaLop = ui->MaLop->text();
    QString newTenLop = ui->TenLop->text();

    Lop *lop = timLop(oldMaLop, danhSachLop);

    if (lop != nullptr) {
        lop->MALOP = newMaLop;
        lop->TENLOP = newTenLop;
    }
}

void HieuChinh_Lop::accept() {
    if (thongBaoLoi()) {
        chinhSuaLop();
        QDialog::accept();
    }
}

bool HieuChinh_Lop::thongBaoLoi() {
    bool isValid = true;

    if (ui->MaLop->text().isEmpty()) {
        ui->LoiMaLop->setText("Mã lớp không được để trống");
        ui->LoiMaLop->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else if (oldMaLop != ui->MaLop->text() && !checkMaLop(ui->MaLop->text(), danhSachLop)) {
        ui->LoiMaLop->setText("Mã lớp đã tồn tại");
        ui->LoiMaLop->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->LoiMaLop->clear();
    }

    if (ui->TenLop->text().isEmpty()) {
        ui->LoiTenLop->setText("Tên lớp không được để trống");
        ui->LoiTenLop->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->LoiTenLop->clear();
    }

    return isValid;
}

Lop* HieuChinh_Lop::timLop(const QString &maLop, Lop* danhSachLop[]) {
    for (int i = 0; i < MAX; ++i) {
        if (danhSachLop[i] != nullptr && danhSachLop[i]->MALOP == maLop) {
            return danhSachLop[i];
        }
    }
    return nullptr;
}

// bool HieuChinh_Lop::thongBaoLoi(const QString &maLop, Lop* danhSachLop[]) {
//     return timLop(maLop, danhSachLop) == nullptr;
// }
