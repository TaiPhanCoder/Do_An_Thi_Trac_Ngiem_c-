#ifndef CAU_HOI_DA_THI_H
#define CAU_HOI_DA_THI_H
#include<QString>

class cau_hoi_da_thi
{
public:
    cau_hoi_da_thi();
};

// struct CauHoiDaChon {
//     int id;
//     QChar dapAn;
// };

struct DaThi {
    int id;
    QChar dapAn;
};

struct monHoc {
    QString maMH;
    float diem;
    DaThi* mangDaThi;
    monHoc* next;
};

monHoc* newMonHoc(const QString& mamh, float diem, int questions);

#endif // CAU_HOI_DA_THI_H
