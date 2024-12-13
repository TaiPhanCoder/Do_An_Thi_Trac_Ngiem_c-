#include "hieuchinh_SinhVien.h"
#include "ui_hieuchinh_SinhVien.h"
#include "lop.h"
#include "sinhvien.h"
#include "giao_vien.h"

HieuChinh::HieuChinh(const QString &mssv, const QString &ho, const QString &ten,
                     const QString &lop, const QString &gioiTinh, Lop* danhSachLop[],
                     bool dasapxep, GIao_Vien *giaoVien, QWidget *parent)
    : QDialog(parent), ui(new Ui::HieuChinh), oldMssv(mssv), oldLop(lop), danhSachLop(danhSachLop), dasapxep(dasapxep), giaoVien(giaoVien)
{
    ui->setupUi(this);
    this->setWindowTitle("Hiệu Chỉnh");
    setupComboBoxes();

    ui->MSSV->setText(mssv);
    ui->Ho->setText(ho);
    ui->Ten->setText(ten);
    ui->Lop->setCurrentText(lop);
    ui->GioiTinh->setCurrentText(gioiTinh);
}

HieuChinh::~HieuChinh()
{
    delete ui;
}

void HieuChinh::setupComboBoxes() {
    for (int i = 0; i < MAX; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }
        QString malop = danhSachLop[i]->MALOP;
        ui->Lop->addItem(malop);
        ui->Lop->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
        lopList.append(malop);
    }

    giaoVien->setupComboBoxFilter(ui->Lop, lopList);

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

void HieuChinh::chinhSuaSinhVien() {
    QString oldLop = this->oldLop;
    QString oldMssv = this->oldMssv;
    QString newLop = ui->Lop->currentText();

    if (oldLop != newLop) {
        SinhVien* sv = timSinhVien(oldMssv, oldLop, danhSachLop);

        if (sv != nullptr) {
            xoaSinhVienKhoiLop(sv, oldLop, danhSachLop);
            if (dasapxep) {
                themSinhVienVaoLopCoThuTu(sv, newLop, danhSachLop);
            } else {
                themSinhVienVaoLop(sv, newLop, danhSachLop);
            }
            capNhatThongTinSinhVien(sv);
        }
    } else {
        SinhVien* sv = timSinhVien(oldMssv, oldLop, danhSachLop);
        capNhatThongTinSinhVien(sv);
    }
}

void HieuChinh::capNhatThongTinSinhVien(SinhVien* sv) {
    sv->masv = ui->MSSV->text();
    sv->ho = ui->Ho->text();
    sv->ten = ui->Ten->text();
    sv->phai = ui->GioiTinh->currentText();
}

void HieuChinh::accept() {
    if (thongBaoLoi()) {
        chinhSuaSinhVien();
        QDialog::accept();
    }
}

bool HieuChinh::thongBaoLoi() {
    bool isValid = true;

    if (ui->MSSV->text().isEmpty()) {
        ui->LoiMSSV->setText("MSSV không được để trống");
        ui->LoiMSSV->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else if (oldMssv != ui->MSSV->text() && !checkMSSV(ui->MSSV->text(), danhSachLop)) {
        ui->LoiMSSV->setText("MSSV đã tồn tại");
        ui->LoiMSSV->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    }
     else {
        ui->LoiMSSV->clear();
    }

    if (ui->Ho->text().isEmpty()) {
        ui->LoiHo->setText("Họ không được để trống");
        ui->LoiHo->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->LoiHo->clear();
    }

    if (ui->Ten->text().isEmpty()) {
        ui->LoiTen->setText("Tên không được để trống");
        ui->LoiTen->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->LoiTen->clear();
    }

    if (ui->GioiTinh->currentText().isEmpty()) {
        ui->LoiGioiTinh->setText("Giới tính không được để trống");
        ui->LoiGioiTinh->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->LoiGioiTinh->clear();
    }

    if (ui->Lop->currentText().isEmpty()) {
        ui->LoiLop->setText("Lớp không được để trống");
        ui->LoiLop->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->LoiLop->clear();
    }

    return isValid;
}
