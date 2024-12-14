#include "them_lop.h"
#include "ui_them_lop.h"
#include "lop.h"
#include <QDebug>

Them_Lop::Them_Lop(Lop* danhSachLop[], QWidget* parent)
    : QDialog(parent), ui(new Ui::Them_Lop), danhSachLop(danhSachLop) {
    ui->setupUi(this);
    this->setWindowTitle("Thêm Lớp");

    connect(ui->MaLop, &QLineEdit::textEdited, this, [=](const QString& text) {
        QString filteredText;
        for (QChar ch : text) {
            if (ch.isLetterOrNumber() || ch == '-') {
                filteredText.append(ch.toUpper());
            }
        }
        ui->MaLop->setText(filteredText);
        ui->MaLop->setCursorPosition(filteredText.length());
    });
}

Them_Lop::~Them_Lop() {
    delete ui;
}

QString Them_Lop::getMaLop() const {
    return ui->MaLop->text();
}

QString Them_Lop::getTenLop() const {
    return ui->TenLop->text();
}

void Them_Lop::accept() {
    if (thongBaoLoi()) {
        QString maLop = ui->MaLop->text();
        QString tenLop = ui->TenLop->text();

        Lop* newLop = new Lop();
        newLop->MALOP = maLop;
        newLop->TENLOP = tenLop;

        for (int i = 0; i < 10000; ++i) {
            if (danhSachLop[i] == nullptr) {
                danhSachLop[i] = newLop;
                break;
            }
        }

        qDebug() << "Đã thêm lớp: Mã lớp:" << maLop << "Tên lớp:" << tenLop;
        QDialog::accept();
    }
}

bool Them_Lop::thongBaoLoi() {
    bool isValid = true;

    if (ui->MaLop->text().isEmpty()) {
        ui->LoiMaLop->setText("Mã lớp không được để trống");
        ui->LoiMaLop->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else if (!checkMaLop(ui->MaLop->text(), danhSachLop)) {
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

bool Them_Lop::checkMaLop(const QString& maLop, Lop** danhSachLop) {
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
