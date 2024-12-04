#ifndef LOP_H
#define LOP_H
#define MAX 10000
#include<QString>
#include"sinhvien.h"

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

int demSoLop();
int demSVLop(Lop* lop);

extern Lop* danhSachLop[MAX];

#endif // LOP_H
