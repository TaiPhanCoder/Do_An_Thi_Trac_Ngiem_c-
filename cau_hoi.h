#ifndef CAU_HOI_H
#define CAU_HOI_H
#include <QFile>

class cau_hoi
{
public:
    cau_hoi();
};

struct  CauHoi{
    QString id;
    QString noiDung;
    QString A;
    QString B;
    QString C;
    QString D;
    QChar dapAnDung;

    CauHoi* next;
};

extern CauHoi *headCauhoi;

CauHoi* docCauHoiTuFile(const QString& monHoc);

void inDanhSachCauHoi(CauHoi* head);
extern CauHoi *cauhoiHienTai;
extern int so_luong_cau_hoi;
int* taoRanDom(int question_count, int bank_size);

#endif // CAU_HOI_H
