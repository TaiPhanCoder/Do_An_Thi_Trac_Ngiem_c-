#ifndef CAU_HOI_H
#define CAU_HOI_H
#include <QFile>

class cau_hoi
{
public:
    cau_hoi();
};

struct  CauHoi{
    int id;
    QString noiDung;
    QString A;
    QString B;
    QString C;
    QString D;
    QChar dapAnDung;
    bool daThi;

    CauHoi* next;
};

void shuffleArray(CauHoi* arr[], int questions, int slCauHoi);
void duyetDSach(CauHoi* head);
CauHoi* taoNodeCauHoi(int id, QString noiDung, QString A, QString B, QString C, QString D, QChar dapAnDung);
int demCauHoi(CauHoi* head);

#endif // CAU_HOI_H
