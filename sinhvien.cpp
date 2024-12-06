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

void themSinhVienVaoLopCoThuTu(SinhVien* newSV, const QString &lop){
    // int i = 0;
    // while (danhSachLop[i] != nullptr) {
    //     if (danhSachLop[i]->MALOP == lop) {
    //         SinhVien* current = danhSachLop[i]->DSSV;
    //         SinhVien* prev = nullptr;

    //         while (current != nullptr && current->ten < newSV->ten) {
    //             prev = current;
    //             current = current->next;
    //         }

    //         if (prev == nullptr) {
    //             newSV->next = danhSachLop[i]->DSSV;
    //             danhSachLop[i]->DSSV = newSV;
    //         } else {
    //             prev->next = newSV;
    //             newSV->next = current;
    //         }
    //         return;
    //     }
    //     ++i;
    // }
}

void themSinhVienVaoLop(SinhVien* newSV, const QString &lop){
    // int i = 0;
    // while (danhSachLop[i] != nullptr) {
    //     if (danhSachLop[i]->MALOP == lop) {
    //         newSV->next = danhSachLop[i]->DSSV;
    //         danhSachLop[i]->DSSV = newSV;
    //         return;
    //     }
    //     ++i;
    // }
}

SinhVien* timSinhVien(const QString& mssv, const QString& lop) {
    // for (int i = 0; i < 10000; ++i) {
    //     if (danhSachLop[i] == nullptr) {
    //         break;
    //     }
    //     if (danhSachLop[i]->MALOP == lop) {
    //         SinhVien* current = danhSachLop[i]->DSSV;
    //         while (current != nullptr) {
    //             if (current->masv == mssv) {
    //                 return current;
    //             }
    //             current = current->next;
    //         }
    //     }
    // }
    return nullptr;
}

void xoaSinhVienKhoiLop(SinhVien* sv, const QString& lop) {
    // for (int i = 0; i < 10000; ++i) {
    //     if (danhSachLop[i] == nullptr) {
    //         break;
    //     }
    //     if (danhSachLop[i]->MALOP == lop) {
    //         SinhVien* current = danhSachLop[i]->DSSV;
    //         SinhVien* prev = nullptr;
    //         while (current != nullptr) {
    //             if (current == sv) {
    //                 if (prev == nullptr) {
    //                     danhSachLop[i]->DSSV = current->next;
    //                 } else {
    //                     prev->next = current->next;
    //                 }
    //                 return;
    //             }
    //             prev = current;
    //             current = current->next;
    //         }
    //     }
    // }
}


int demSinhVien() {
    int count = 0;

    // for (int i = 0; i < MAX; ++i) {
    //     if (danhSachLop[i] == nullptr) {
    //         break;
    //     }
    //     SinhVien* current = danhSachLop[i]->DSSV;

    //     while (current != nullptr) {
    //         count++;
    //         current = current->next;
    //     }
    // }

    return count;
}

bool checkMSSV(const QString &newMssv) {
    // for (int i = 0; i < 10000; ++i) {
    //     if (danhSachLop[i] == nullptr) {
    //         break;
    //     }
    //     SinhVien* current = danhSachLop[i]->DSSV;
    //     while (current != nullptr) {
    //         if (current->masv == newMssv) {
    //             qDebug() << "MSSV bị trùng:" << newMssv;
    //             return false;
    //         }
    //         current = current->next;
    //     }
    // }
    // return true;
}
