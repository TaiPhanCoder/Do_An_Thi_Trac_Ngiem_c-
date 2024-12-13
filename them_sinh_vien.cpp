#include "them_sinh_vien.h"
#include "ui_them_sinh_vien.h"
#include "lop.h"
#include "sinhvien.h"

Them_Sinh_Vien::Them_Sinh_Vien(Lop* danhSachLop[], bool dasapxep, GIao_Vien *giaoVien, QWidget* parent)
    : QDialog(parent), ui(new Ui::Them_Sinh_Vien), danhSachLop(danhSachLop), dasapxep(dasapxep), giaoVien(giaoVien)
{
    ui->setupUi(this);
    this->setWindowTitle("Thêm Sinh Viên");
    ui->Lop->clear();

    for (int i = 0; i < 10000; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }
        int index = ui->Lop->count();
        ui->Lop->addItem(danhSachLop[i]->MALOP);
        ui->Lop->setItemData(index, Qt::AlignCenter, Qt::TextAlignmentRole);
        lopList.append(danhSachLop[i]->MALOP);
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

Them_Sinh_Vien::~Them_Sinh_Vien()
{
    delete ui;
}

void Them_Sinh_Vien::accept() {
    bool continueAdding = true;

    while (continueAdding) {
        if (thongBaoLoi()) {
            QString lop = ui->Lop->currentText();
            SinhVien* newSV = taoNodeSinhVien(ui->MSSV->text(), ui->Ho->text(), ui->Ten->text(), ui->GioiTinh->currentText(), "123");

            if (dasapxep) {
                themSinhVienVaoLopCoThuTu(newSV, lop, danhSachLop);
            } else {
                themSinhVienVaoLop(newSV, lop, danhSachLop);
            }

            QDialog::accept();
            qDebug() << "Đã thêm sinh viên.";

            oldLop = lop; // Cập nhật oldLop với lớp hiện tại

            Them_Sinh_Vien dialog(danhSachLop, dasapxep, giaoVien, this);
            dialog.ui->Lop->setCurrentText(oldLop);
            if (dialog.exec() == QDialog::Accepted) {
                continueAdding = true;
            } else {
                continueAdding = false;
            }
        } else {
            continueAdding = false;
        }
    }
}

bool Them_Sinh_Vien::thongBaoLoi() {
    bool isValid = true;

    if (ui->MSSV->text().isEmpty()) {
        ui->LoiMSSV->setText("MSSV không được để trống");
        ui->LoiMSSV->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else if (!checkMSSV(ui->MSSV->text(), danhSachLop)) {
        ui->LoiMSSV->setText("MSSV đã tồn tại");
        ui->LoiMSSV->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
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
