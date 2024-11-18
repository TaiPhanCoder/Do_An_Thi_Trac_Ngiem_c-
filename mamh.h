#ifndef MAMH_H
#define MAMH_H
#include<QString>
#include "cau_hoi.h"

class MaMH
{
public:
    MaMH();
};

struct MonHoc {
    QString MAMH;  // Mã môn học
    QString TENMH; // Tên môn học
    CauHoi *headCauhoi;
};

// Hàm tạo node mới
struct NodeMonHoc {
    MonHoc MH;
    NodeMonHoc* left;
    NodeMonHoc* right;
    int height;
    int bf;
};

typedef NodeMonHoc* ptrMonHoc;

ptrMonHoc readFileAndBuildAVL();
void duyetLNR(ptrMonHoc root, QStringList &danhSachMonHoc);
ptrMonHoc loadToanBoCauHoi();
void duyetLRN(ptrMonHoc p);

#endif // MAMH_H
