#include "sinhvien.h"
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

void themSinhVien(SinhVien*& head, SinhVien* newSV) {
    if (newSV == nullptr) {
        qDebug() << "Sinh viên không hợp lệ!";
        return;
    }

    // Thêm sinh viên mới vào đầu danh sách
    newSV->next = head;
    head = newSV;
}
