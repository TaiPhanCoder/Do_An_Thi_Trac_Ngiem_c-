#include "them_sinh_vien.h"
#include "ui_them_sinh_vien.h"
#include "lop.h"
#include "sinhvien.h"

Them_Sinh_Vien::Them_Sinh_Vien(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Them_Sinh_Vien)
{
    ui->setupUi(this);
    this->setWindowTitle("Thêm Sinh Viên");
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

void Them_Sinh_Vien::accept() {
    bool continueAdding = true;

    while (continueAdding) {
        if (thongBaoLoi()) {
            QDialog::accept();
            qDebug() << "Đã thêm sinh viên.";

            Them_Sinh_Vien dialog(this);
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
