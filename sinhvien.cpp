#include "sinhvien.h"
#include "globals.h"
#include "QString"
#include "lop.h"

#include<QDebug>

sinhvien::sinhvien() {}

SinhVien* taoNodeSinhVien(QString masv, QString ho, QString ten, QString phai, QString password) {
    SinhVien* sv = new SinhVien;
    sv->masv = masv;
    sv->ho = ho;
    sv->ten = ten;
    sv->phai = phai;
    sv->password = password;
    sv->ds_diemthi = nullptr;
    sv->next = nullptr;
    return sv;
}

void themSinhVienVaoLop(SinhVien* newSV, const QString &lop){
    for (int i = 0; i < 10000; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }
        if (danhSachLop[i]->TENLOP == lop) {
            newSV->next = danhSachLop[i]->DSSV;
            danhSachLop[i]->DSSV = newSV;
            qDebug() << "Đã thêm sinh viên vào lớp:" << lop;
            break;
        }
    }
}

int demSinhVien() {
    int count = 0;

    // Duyệt qua mảng lớp
    for (int i = 0; i < 10000; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }
        SinhVien* current = danhSachLop[i]->DSSV;

        // Duyệt qua danh sách sinh viên của lớp hiện tại
        while (current != nullptr) {
            count++;
            current = current->next;
        }
    }

    return count;
}
