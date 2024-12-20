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
    int tinChi;
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

ptrMonHoc deleteNodeAVL(ptrMonHoc root, QString mamh_input);
ptrMonHoc insertNodeAVL(ptrMonHoc node, QString mamh, QString tenmh, int tinchi);
CauHoi** loadCauHoiThi(ptrMonHoc root, const QString &mamh, int &questions, int &socauhoi);
CauHoi* DsachCauHoiThi(ptrMonHoc root, CauHoi** cauhoiArray, int questions, int slCauHoi, const QString &maMH);
void deleteAVLTree(NodeMonHoc* root);
void duyetLNR(ptrMonHoc root, QStringList &danhSachMonHoc);
void luuMonHocVaCauHoi(ptrMonHoc root, const QString& filePath);
ptrMonHoc loadToanBoCauHoi();
void duyetLRN(ptrMonHoc p);
CauHoi* findCauHoi(NodeMonHoc* root, QString mamh, int id);
MonHoc* SearchMonHoc(ptrMonHoc p, QString mamh_input);
int demCauHoi(ptrMonHoc root, QString mamh);


#endif // MAMH_H
