#include "hieuchinh_SinhVien.h"
#include "ui_hieuchinh_SinhVien.h"
#include "lop.h"
#include "sinhvien.h"

HieuChinh::HieuChinh(const QString &mssv, const QString &ho, const QString &ten,
                     const QString &lop, const QString &gioiTinh, Lop* danhSachLop[], QWidget *parent)
    : QDialog(parent), ui(new Ui::HieuChinh), oldMssv(mssv), oldLop(lop), danhSachLop(danhSachLop)
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

QString HieuChinh::getMSSV() const {
    return ui->MSSV->text();
}

QString HieuChinh::getHo() const {
    return ui->Ho->text();
}

QString HieuChinh::getTen() const {
    return ui->Ten->text();
}

QString HieuChinh::getGioiTinh() const {
    return ui->GioiTinh->currentText();
}

QString HieuChinh::getLop() const {
    return ui->Lop->currentText();
}

void HieuChinh::chinhSuaSinhVien() {
    QString oldLop = this->oldLop;
    QString oldMssv = this->oldMssv;
    QString newLop = getLop();

    if (oldLop != newLop) {
        SinhVien* sv = timSinhVien(oldMssv, oldLop);

        if (sv != nullptr) {
            xoaSinhVienKhoiLop(sv, oldLop);
            themSinhVienVaoLop(sv, newLop);
            capNhatThongTinSinhVien(sv);
        }
    } else {
        SinhVien* sv = timSinhVien(oldMssv, oldLop);
        capNhatThongTinSinhVien(sv);
    }
}

void HieuChinh::capNhatThongTinSinhVien(SinhVien* sv) {
    sv->masv = getMSSV();
    sv->ho = getHo();
    sv->ten = getTen();
    sv->phai = getGioiTinh();
}

void HieuChinh::accept() {
    if (thongBaoLoi()) {
        chinhSuaSinhVien();
        QDialog::accept();
    }
}

bool HieuChinh::thongBaoLoi() {
    bool isValid = true;

    if (getMSSV().isEmpty()) {
        ui->LoiMSSV->setText("MSSV không được để trống");
        ui->LoiMSSV->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else if (!checkMSSV(getMSSV())) {
        ui->LoiMSSV->setText("MSSV đã tồn tại");
        ui->LoiMSSV->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->LoiMSSV->clear();
    }

    if (getHo().isEmpty()) {
        ui->LoiHo->setText("Họ không được để trống");
        ui->LoiHo->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->LoiHo->clear();
    }

    if (getTen().isEmpty()) {
        ui->LoiTen->setText("Tên không được để trống");
        ui->LoiTen->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->LoiTen->clear();
    }

    if (getGioiTinh().isEmpty()) {
        ui->LoiGioiTinh->setText("Giới tính không được để trống");
        ui->LoiGioiTinh->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->LoiGioiTinh->clear();
    }

    if (getLop().isEmpty()) {
        ui->LoiLop->setText("Lớp không được để trống");
        ui->LoiLop->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->LoiLop->clear();
    }

    return isValid;
}
