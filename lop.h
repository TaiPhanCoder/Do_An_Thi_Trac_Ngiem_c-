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

int demSinhVien(Lop** danhSachLop);
int demSoLop(Lop* danhSachLop[]);
int demSVLop(Lop* lop);
void lapdssinhvien(const QString &filename, Lop* danhSachLop[]);

#endif // LOP_H
