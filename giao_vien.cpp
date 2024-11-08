#include "giao_vien.h"
#include "ui_giao_vien.h"
#include "sinhvien.h"
#include"lop.h"
#include"them_sinh_vien.h"
#include<QDebug>

GIao_Vien::GIao_Vien(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GIao_Vien)
{
    ui->setupUi(this);
    this->setWindowTitle("Giảng Viên - PTIT");
    QPixmap pixmap(":/logo/ad27bc12ca81e862ceb35328122757ee.png");
    QPixmap scaledPixmap = pixmap.scaled(ui->logo->size(), Qt::KeepAspectRatio);
    ui->logo->setPixmap(scaledPixmap);
    on_sinhVien_clicked();
}

GIao_Vien::~GIao_Vien()
{
    delete ui;
}

void GIao_Vien::showContextMenu(const QPoint &pos) {
    QModelIndex index = ui->bangDuLieu->indexAt(pos);
    if (!index.isValid()) {
        return;
    }

    ui->bangDuLieu->selectRow(index.row());

    contextMenu->exec(ui->bangDuLieu->viewport()->mapToGlobal(pos));
}

void xoaSinhVienKhoiDanhSach(const QString &masv, const QString &tenLop) {
    for (int i = 0; i < 10000; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }

        if (danhSachLop[i]->TENLOP == tenLop) {
            SinhVien* current = danhSachLop[i]->DSSV;
            SinhVien* previous = nullptr;

            while (current != nullptr) {
                if (current->masv == masv) {
                    if (previous == nullptr) {
                        danhSachLop[i]->DSSV = current->next;
                    } else {
                        previous->next = current->next;
                    }

                    delete current;
                    qDebug() << "Sinh viên với MSSV:" << masv << "đã bị xóa khỏi lớp:" << tenLop;
                    return;
                }

                previous = current;
                current = current->next;
            }
        }
    }
}

QString GIao_Vien::getSelectedStudentMasv(int row) {
    return ui->bangDuLieu->item(row, 0)->text();
}

QString GIao_Vien::getSelectedStudentLop(int row) {
    return ui->bangDuLieu->item(row, 3)->text();
}

void GIao_Vien::xoaSV() {
    QModelIndexList selectedRows = ui->bangDuLieu->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        return;
    }

    int row = selectedRows.first().row();

    QString masv = getSelectedStudentMasv(row);
    QString tenLop = getSelectedStudentLop(row);

    qDebug() << "Người dùng muốn xóa MSSV:" << masv << ", thuộc lớp:" << tenLop;

    xoaSinhVienKhoiDanhSach(masv, tenLop);

    ui->bangDuLieu->removeRow(row);
}

// void duyetDanhSach() {
//     for (int i = 0; i < 10000; ++i) {
//         if (danhSachLop[i] == nullptr) {
//             break;
//         }

//         QString tenLop = danhSachLop[i]->MALOP;
//         SinhVien* currentSV = danhSachLop[i]->DSSV;
//         qDebug() << "Duyệt lớp: " << tenLop;

//         while (currentSV != nullptr) {
//             qDebug() << "MSSV: " << currentSV->masv;
//             currentSV = currentSV->next;
//         }
//     }
// }

void GIao_Vien::loadSinhVien() {
    int row = 0;

    // Duyệt qua mảng lớp
    for (int i = 0; i < 10000; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }
        SinhVien* current = danhSachLop[i]->DSSV;
        QString tenLop = danhSachLop[i]->MALOP;

        // Duyệt qua danh sách sinh viên của lớp hiện tại
        while (current != nullptr) {
            // Tạo và thêm các mục cho từng cột trong hàng
            QTableWidgetItem *masvItem = new QTableWidgetItem(current->masv);
            QTableWidgetItem *hoItem = new QTableWidgetItem(current->ho);
            QTableWidgetItem *tenItem = new QTableWidgetItem(current->ten);
            QTableWidgetItem *phaiItem = new QTableWidgetItem(current->phai);
            QTableWidgetItem *tenLopItem = new QTableWidgetItem(tenLop);

            // Đặt các mục vào bảng
            ui->bangDuLieu->setItem(row, 0, masvItem);
            ui->bangDuLieu->setItem(row, 1, hoItem);
            ui->bangDuLieu->setItem(row, 2, tenItem);
            ui->bangDuLieu->setItem(row, 3, tenLopItem);
            ui->bangDuLieu->setItem(row, 4, phaiItem);
            current = current->next;
            row++;
        }
    }
}

void GIao_Vien::onTextEdited(const QString &text) {
    disconnect(ui->timMSSV, &QLineEdit::textEdited, this, &GIao_Vien::onTextEdited);
    QString upperText = text.toUpper();
    ui->timMSSV->setText(upperText);
    ui->timMSSV->setCursorPosition(upperText.length());
    connect(ui->timMSSV, &QLineEdit::textEdited, this, &GIao_Vien::onTextEdited);
}

void GIao_Vien::timSinhVien(const QString &text) {
    ui->bangDuLieu->setRowCount(0);

    int row = 0;

    // Duyệt qua mảng lớp
    for (int i = 0; i < 10000; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }
        SinhVien* current = danhSachLop[i]->DSSV;
        QString tenLop = danhSachLop[i]->TENLOP;

        // Duyệt qua danh sách sinh viên của lớp hiện tại
        while (current != nullptr) {
            if (current->masv.contains(text, Qt::CaseInsensitive)) {
                ui->bangDuLieu->insertRow(row);

                ui->bangDuLieu->setItem(row, 0, new QTableWidgetItem(current->masv));
                ui->bangDuLieu->setItem(row, 1, new QTableWidgetItem(current->ho));
                ui->bangDuLieu->setItem(row, 2, new QTableWidgetItem(current->ten));
                ui->bangDuLieu->setItem(row, 3, new QTableWidgetItem(tenLop));
                ui->bangDuLieu->setItem(row, 4, new QTableWidgetItem(current->phai));

                row++;
            }

            current = current->next;
        }
    }
}

void GIao_Vien::on_them1sv_clicked() {
    Them_Sinh_Vien dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString masv = dialog.getMSSV();
        QString ho = dialog.getHo();
        QString ten = dialog.getTen();
        QString phai = dialog.getGioiTinh();
        QString lop = dialog.getLop();

        SinhVien* newSV = taoNodeSinhVien(masv, ho, ten, phai, "");

        themSinhVienVaoLop(newSV, lop);

        loadSinhVien();

        qDebug() << "Đã thêm sinh viên mới vào bảng dữ liệu. Thông tin sinh viên: MSSV:" << newSV->masv << ", Họ:" << newSV->ho << ", Tên:" << newSV->ten << ", Giới tính:" << newSV->phai << ", Lớp:" << lop;
    }
}


void GIao_Vien::on_sinhVien_clicked() {
    int rows = demSinhVien();

    ui->bangDuLieu->setContextMenuPolicy(Qt::CustomContextMenu);

    contextMenu = new QMenu(this);
    deleteAction = new QAction("Xóa", this);

    contextMenu->addAction(deleteAction);

    connect(ui->bangDuLieu, &QTableWidget::customContextMenuRequested, this, &GIao_Vien::showContextMenu);
    connect(deleteAction, &QAction::triggered, this, &GIao_Vien::xoaSV);

    ui->bangDuLieu->setRowCount(rows);
    ui->bangDuLieu->setColumnCount(5);
    ui->bangDuLieu->setColumnWidth(0, 300);
    ui->bangDuLieu->setColumnWidth(1, 350);
    ui->bangDuLieu->setColumnWidth(2, 150);
    ui->bangDuLieu->setColumnWidth(3, 200);
    ui->bangDuLieu->setColumnWidth(4, 150);
    QStringList headers;
    headers << "MSSV" << "Họ" << "Tên" <<"Lớp" << "Giới tính";
    ui->bangDuLieu->setHorizontalHeaderLabels(headers);
    loadSinhVien();
    connect(ui->timMSSV, &QLineEdit::textEdited, this, &GIao_Vien::onTextEdited);
    connect(ui->timMSSV, &QLineEdit::textChanged, this, &GIao_Vien::timSinhVien);
}

void GIao_Vien::on_sapXep_clicked()
{
    for (int i = 0; i < 10000; ++i) {
        qDebug() << "CB sap xep";
        if (danhSachLop[i] == nullptr) {
            break;
        }

        SinhVien* head = danhSachLop[i]->DSSV;
        if (head == nullptr || head->next == nullptr) {
            continue;
        }

        bool swapped;
        do {
            swapped = false;
            SinhVien* current = head;
            SinhVien* prev = nullptr;
            SinhVien* next = current->next;

            while (next != nullptr) {
                if (current->ten > next->ten) {
                    // Đổi chỗ hai node
                    if (prev == nullptr) {
                        // Đổi chỗ tại đầu danh sách
                        head = next;
                    } else {
                        prev->next = next;
                    }
                    current->next = next->next;
                    next->next = current;

                    // Cập nhật con trỏ
                    swapped = true;
                    prev = next;
                    next = current->next;
                } else {
                    // Di chuyển con trỏ
                    prev = current;
                    current = next;
                    next = next->next;
                }
            }
        } while (swapped);

        // Cập nhật lại danh sách sinh viên của lớp
        danhSachLop[i]->DSSV = head;
    }

    // Tải lại bảng sinh viên sau khi sắp xếp
    loadSinhVien();
    qDebug() << "Đã sắp xếp danh sách sinh viên theo tên.";
}

