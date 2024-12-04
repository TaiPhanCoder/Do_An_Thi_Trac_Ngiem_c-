#ifndef GLOBALS_H
#define GLOBALS_H
#include<QString>

struct DiemThi{
    QString maMH;
    float diem;
    DiemThi* next;
};

struct SinhVien{
    QString masv;
    QString ho;
    QString ten;
    QString phai;
    QString password;
    DiemThi* ds_diemthi;
    SinhVien* next;
};

extern bool GV;
extern int times;
extern int questions;
extern QString monhoc;
extern QString maMH;
extern SinhVien *headDsachSV;
extern SinhVien mainUser;

#endif
