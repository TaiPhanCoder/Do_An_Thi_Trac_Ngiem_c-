#ifndef CAU_HOI_DA_THI_H
#define CAU_HOI_DA_THI_H
#include<QString>

class cau_hoi_da_thi
{
public:
    cau_hoi_da_thi();
};

struct DaThi {
    int id;
    QChar dapAn;
};

struct monHocDaThi {
    QString maMH;
    float diem;
    int soCauThi;
    DaThi* mangDaThi;
    monHocDaThi* next;
};

void themMonHoc(monHocDaThi*& head, monHocDaThi* monHocMoi);
monHocDaThi* newmonHocDaThi(const QString& mamh, float diem, int questions);
int demSoMonThi(monHocDaThi* head);

#endif // CAU_HOI_DA_THI_H
