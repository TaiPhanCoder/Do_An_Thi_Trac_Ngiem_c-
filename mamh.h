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
    CauHoi *headCauhoi = nullptr;
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
void deleteAVLTree(NodeMonHoc* root);
void duyetLNR(ptrMonHoc root, QStringList &danhSachMonHoc);
ptrMonHoc loadToanBoCauHoi();
void duyetLRN(ptrMonHoc p);
int demTatCaCauHoi(ptrMonHoc root);
CauHoi* findCauHoi(NodeMonHoc* root, QString mamh, int id);
MonHoc* SearchMonHoc(ptrMonHoc p, QString mamh_input);

#endif // MAMH_H
