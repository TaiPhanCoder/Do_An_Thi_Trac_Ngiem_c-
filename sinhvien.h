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
int demSinhVien();
void themSinhVien(SinhVien*& head, SinhVien* newSV);
void themSinhVienVaoLopCoThuTu(SinhVien* newSV, const QString &lop);
SinhVien* timSinhVien(const QString& mssv, const QString& lop);
void xoaSinhVienKhoiLop(SinhVien* sv, const QString& lop);
void themSinhVienVaoLop(SinhVien* newSV, const QString &lop);
bool checkMSSV(const QString &newMssv);

#endif // SINHVIEN_H
