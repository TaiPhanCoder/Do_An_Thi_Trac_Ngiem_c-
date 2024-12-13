#ifndef SINHVIEN_H
#define SINHVIEN_H

#include "cau_hoi_da_thi.h"
#include <QString>

class sinhvien
{
public:
    sinhvien();
};

struct SinhVien{
    QString masv;
    QString ho;
    QString ten;
    QString phai;
    QString password;
    monHocDaThi* ds_diemthi;
    SinhVien* next;
};

extern SinhVien *headDsachSV;

SinhVien* taoNodeSinhVien(QString masv, QString ho, QString ten, QString phai, QString password);
void themSinhVien(SinhVien*& head, SinhVien* newSV);

#endif // SINHVIEN_H
