#include "xem_mon_lop.h"
#include "ui_xem_mon_lop.h"
#include "mamh.h"
#include "lop.h"
#include "sinhvien.h"
#include "cau_hoi_da_thi.h"
#include "xem_mon_lop.h"
#include "ui_xem_diem_lop.h"
#include "xem_diem_lop.h"
#include <QMessageBox>


xem_mon_lop::xem_mon_lop(Lop* mainClass, NodeMonHoc* root, QWidget *parent)
    : QDialog(parent), ui(new Ui::xem_mon_lop), mainClass(mainClass), root(root)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    this->setWindowTitle("Xem Môn Học");



    setThongTinLop();  // Hiển thị thông tin lớp và sinh viên
    loadBangMonHoc();       // Nạp dữ liệu môn học vào bảng
    connect(ui->dsachmon, &QTableWidget::cellDoubleClicked, this, &xem_mon_lop::onTableDoubleClicked);
}

xem_mon_lop::~xem_mon_lop()
{
    delete ui;
}


QString xem_mon_lop::timTenMonHoc(const QString& maMH, NodeMonHoc* root)
{
    while (root) {
        if (root->MH.MAMH == maMH) {
            return root->MH.TENMH;
        } else if (maMH < root->MH.MAMH) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return "Không xác định";
}

// Hiển thị thông tin lớp và sinh viên
void xem_mon_lop::setThongTinLop()
{
    ui->MaLop->setText("Mã Lớp: " + mainClass->MALOP);
    ui->TenLop->setText("Tên Lớp: " + mainClass->TENLOP);
    ui->MaLop->setAlignment(Qt::AlignCenter);
    ui->TenLop->setAlignment(Qt::AlignCenter);
}



void xem_mon_lop::onTableDoubleClicked(int row, int column) {
    // Lấy Mã Môn Học từ cột đầu tiên của dòng được nhấp đúp
    QString maMonHoc = ui->dsachmon->item(row, 0)->text();

    // Tìm môn học dựa trên Mã Môn Học
    MonHoc* monHoc = SearchMonHoc(root, maMonHoc);

    if (monHoc != nullptr) {
        // Kiểm tra lớp và danh sách sinh viên
        if (mainClass == nullptr || mainClass->DSSV == nullptr) {
            qDebug() << "Không có sinh viên trong lớp.";
            return;
        }

        // Duyệt qua danh sách sinh viên và in thông tin
        SinhVien* currentSinhVien = mainClass->DSSV;
        qDebug() << "Danh sách sinh viên và điểm môn học (" << maMonHoc << "):";
        while (currentSinhVien != nullptr) {
            // Tìm điểm thi của sinh viên cho môn học
            float diem = -1.0; // Mặc định "CHƯA THI"
            monHocDaThi* currentDiem = currentSinhVien->ds_diemthi;

            while (currentDiem != nullptr) {
                if (currentDiem->maMH == maMonHoc) {
                    diem = currentDiem->diem;
                    break;
                }
                currentDiem = currentDiem->next;
            }

            // In thông tin sinh viên và điểm
            QString diemStr = (diem >= 0) ? QString::number(diem, 'f', 2) : "CHƯA THI";
            qDebug() << "Mã SV:" << currentSinhVien->masv
                     << ", Họ Tên:" << currentSinhVien->ho + " " + currentSinhVien->ten
                     << ", Điểm:" << diemStr;

            currentSinhVien = currentSinhVien->next;
        }
    } else {
        qDebug() << "Không tìm thấy Mã Môn Học: " << maMonHoc;
    }

    if (row < 0) return; // Kiểm tra dòng hợp lệ

    QString maMH = ui->dsachmon->item(row, 0)->text();
    qDebug() << "Mã môn học được chọn:" << maMH;

    // Tạo dialog để hiển thị thông tin chi tiết
    xem_diem_lop* dialog = new xem_diem_lop(mainClass, nullptr, root, maMH, this);
    dialog->exec();
    delete dialog;
}




// Nạp danh sách môn học vào bảng QTableWidget
void xem_mon_lop::loadBangMonHoc()
{
    // Xóa dữ liệu cũ
    ui->dsachmon->clearContents();
    ui->dsachmon->setRowCount(0);

    // Thiết lập tiêu đề cho bảng
    ui->dsachmon->setColumnCount(2);
    QStringList headers = {"Mã Môn Học", "Tên Môn Học"};
    ui->dsachmon->setHorizontalHeaderLabels(headers);

    ui->dsachmon->setColumnWidth(0, 150);
    ui->dsachmon->setColumnWidth(1, 400);

    ui->dsachmon->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->dsachmon->setSelectionBehavior(QAbstractItemView::SelectRows); // Chọn cả hàng khi nhấn vào ô
    ui->dsachmon->setSelectionMode(QAbstractItemView::SingleSelection); // Chỉ chọn 1 dòng

    const int MAX_MON_HOC = 100; // Giới hạn số lượng môn học
    QString danhSachMonHoc[MAX_MON_HOC];
    int soLuongMonHoc = 0; // Số lượng môn học đã thêm

    int row = 0;
    SinhVien* sv = mainClass->DSSV;

    while (sv != nullptr) {
        monHocDaThi* current = sv->ds_diemthi;

        while (current != nullptr) {
            // Kiểm tra trùng lặp bằng cách duyệt mảng tĩnh
            bool daTonTai = false;
            for (int i = 0; i < soLuongMonHoc; ++i) {
                if (danhSachMonHoc[i] == current->maMH) {
                    daTonTai = true;
                    break;
                }
            }

            if (!daTonTai) {
                QString tenMonHoc = timTenMonHoc(current->maMH, root);

                ui->dsachmon->insertRow(row); // Thêm dòng mới
                ui->dsachmon->setItem(row, 0, new QTableWidgetItem(current->maMH));
                ui->dsachmon->setItem(row, 1, new QTableWidgetItem(tenMonHoc));

                // Thêm mã môn học vào mảng tĩnh
                if (soLuongMonHoc < MAX_MON_HOC) {
                    danhSachMonHoc[soLuongMonHoc++] = current->maMH;
                } else {
                    qDebug() << "Danh sách môn học vượt quá giới hạn!";
                }
                row++;
            }

            current = current->next;
        }
        sv = sv->next;
    }
}
