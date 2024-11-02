#include "sinhvien.h"
#include "globals.h"
#include "QString"

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

int demSinhVien() {
    int count = 0;
    struct SinhVien* current = headDsachSV;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}
