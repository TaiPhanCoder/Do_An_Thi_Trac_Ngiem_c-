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

CauHoi** loadCauHoiThi(const QString &monHoc, int &questions, int &soCauHoi);
CauHoi* DsachCauHoiThi(CauHoi** cauhoiArray, int questions);
void shuffleArray(CauHoi* arr[], int questions);
void duyetDSach(CauHoi* head);
CauHoi* taoNodeCauHoi(QString id, QString noiDung, QString A, QString B, QString C, QString D, QChar dapAnDung);


#endif // CAU_HOI_H
