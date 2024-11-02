#ifndef SINHVIEN_H
#define SINHVIEN_H
#include"globals.h"

class sinhvien
{
public:
    sinhvien();
};

SinhVien* taoNodeSinhVien(QString masv, QString ho, QString ten, QString phai, QString password);
int demSinhVien();

#endif // SINHVIEN_H
