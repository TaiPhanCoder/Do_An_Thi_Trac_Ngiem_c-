#include "cau_hoi.h"
#include <QString>
#include <QFile>
#include <QDebug>

CauHoi *headCauhoi = nullptr;

cau_hoi::cau_hoi() {}

CauHoi* taoNodeCauHoi(int id, QString noiDung, QString A, QString B, QString C, QString D, QChar dapAnDung) {

    CauHoi* cauHoi = new CauHoi;
    cauHoi->id = id;
    cauHoi->noiDung = noiDung;
    cauHoi->A = A;
    cauHoi->B = B;
    cauHoi->C = C;
    cauHoi->D = D;
    cauHoi->dapAnDung = dapAnDung;
    cauHoi->next = nullptr;
    cauHoi->daThi = false;

    return cauHoi;
}

void shuffleArray(CauHoi* arr[], int questions, int slCauHoi) {
    std::srand(std::time(0));

    for (int i = 0; i < questions; ++i) {
        int randomIndex = rand() % (slCauHoi - i) + i;
        CauHoi* temp = arr[i];
        arr[i] = arr[randomIndex];
        arr[randomIndex] = temp;

        arr[i]->daThi = true;
    }
}

int demCauHoi(CauHoi* head) {
    int count = 0;
    CauHoi* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void duyetDSach(CauHoi* head) {
    CauHoi* current = head;
    while (current != nullptr) {
        qDebug() << "ID Câu hỏi:" << current->id;
        current = current->next;
    }
}
