#ifndef LOP_H
#define LOP_H
#include<QString>
#include"sinhvien.h"

#define MAX 10000

class lop
{
public:
    lop();
    int demSoLop();
};

struct Lop {
    QString MALOP;
    QString TENLOP;
    SinhVien* DSSV;
};

int demSoLop(Lop* danhSachLop[]);
int demSVLop(Lop* lop);
void lapdssinhvien(const QString &filename, Lop* danhSachLop[]);
bool checkMSSV(const QString &newMssv, Lop** danhSachLop);
void themSinhVienVaoLop(SinhVien* newSV, const QString &lop, Lop** danhSachLop);
void themSinhVienVaoLopCoThuTu(SinhVien* newSV, const QString &lop, Lop** danhSachLop);
void xoaSinhVienKhoiLop(SinhVien* sv, const QString& lop, Lop** danhSachLop);
SinhVien* timSinhVien(const QString& mssv, const QString& lop, Lop** danhSachLop);

Lop* timKiemLop(const QString& malop, Lop** danhSachLop);// AOMALAZ

void themLopVaoDanhSach(Lop* newLop, const QString &maLop);
#endif // LOP_H
