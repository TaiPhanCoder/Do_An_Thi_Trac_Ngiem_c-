#include "xem_diem_lop.h"
#include "ui_xem_diem_lop.h"
#include "mamh.h"
#include "sinhvien.h"
#include <QMessageBox>
#include <QDebug>
xem_diem_lop::xem_diem_lop(Lop* mainClass, SinhVien* sv, NodeMonHoc* root,const QString maMH,   QWidget *parent)
    : QDialog(parent), ui(new Ui::xem_diem_lop), mainClass(mainClass)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    this->setWindowTitle("Xem Điểm Lớp");


    setThongTinMon(maMH, root);
        // Hiển thị thông tin lớp và sinh viên
    loadBangDiem(maMH);
        // Nạp dữ liệu môn học vào bảng
}


xem_diem_lop::~xem_diem_lop()
{
    delete ui;
}


float xem_diem_lop::LayDiemThi(SinhVien* sv, QString& maMH)
{

    monHocDaThi* current = sv->ds_diemthi;
    while (current != nullptr)
    {
        if (current->maMH == maMH)
        {
            return current->diem;
        }
        current = current->next;
    }
    return -1; // Chưa thi
}

QString xem_diem_lop::timTenMonHoc(const QString& maMH, NodeMonHoc* root)
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


void xem_diem_lop::setThongTinMon(const QString& maMH, NodeMonHoc* root)
{


    ui->maMH->setText("Mã MH: " + maMH );
    ui->tenMH->setText("Tên MH: " + timTenMonHoc(maMH,root));
    ui->maMH->setAlignment(Qt::AlignCenter);
    ui->tenMH->setAlignment(Qt::AlignCenter);
}

void xem_diem_lop::loadBangDiem(const QString& maMH)
{
    // Kiểm tra lớp và danh sách sinh viên
    if (!mainClass || !mainClass->DSSV) {
        // QMessageBox::warning(this, "Lỗi", "Không có sinh viên trong lớp.");

        return;
    }

    // Xóa dữ liệu cũ
    ui->dsachdiem->clearContents();
    ui->dsachdiem->setRowCount(0);

    // Thiết lập tiêu đề cho bảng
    ui->dsachdiem->setColumnCount(4);
    QStringList headers = {"Mã Sinh Viên", "Họ", "Tên", "Điểm"};
    ui->dsachdiem->setHorizontalHeaderLabels(headers);

    ui->dsachdiem->setColumnWidth(0, 150); // Mã Sinh Viên
    ui->dsachdiem->setColumnWidth(1, 200); // Họ
    ui->dsachdiem->setColumnWidth(2, 200); // Tên
    ui->dsachdiem->setColumnWidth(3, 100); // Điểm

    ui->dsachdiem->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->dsachdiem->setSelectionBehavior(QAbstractItemView::SelectRows); // Chọn cả hàng
    ui->dsachdiem->setSelectionMode(QAbstractItemView::SingleSelection); // Chỉ chọn 1 dòng

    // Duyệt qua danh sách sinh viên trong lớp
    qDebug() << "Nạp dữ liệu bảng điểm cho môn học: " << maMH;
    int row = 0;
    SinhVien* currentSinhVien = mainClass->DSSV;


    while (currentSinhVien != nullptr) {
        // Tìm điểm thi của sinh viên cho môn học
        float diem = -1.0; // Mặc định "CHƯA THI"
        monHocDaThi* currentDiem = currentSinhVien->ds_diemthi;

        while (currentDiem != nullptr) {
            if (currentDiem->maMH == maMH) {
                diem = currentDiem->diem;
                break;
            }
            currentDiem = currentDiem->next;
        }



        // Thêm dòng mới vào bảng
        ui->dsachdiem->insertRow(row);

        // Thêm thông tin sinh viên vào các cột
        ui->dsachdiem->setItem(row, 0, new QTableWidgetItem(currentSinhVien->masv));
        ui->dsachdiem->setItem(row, 1, new QTableWidgetItem(currentSinhVien->ho));
        ui->dsachdiem->setItem(row, 2, new QTableWidgetItem(currentSinhVien->ten));

        // Thêm điểm hoặc "CHƯA THI"
        if (diem >= 0) {
            ui->dsachdiem->setItem(row, 3, new QTableWidgetItem(QString::number(diem, 'f', 2)));
        } else {
            ui->dsachdiem->setItem(row, 3, new QTableWidgetItem("CHƯA THI"));
        }

        row++;
        currentSinhVien = currentSinhVien->next;
    }
}
