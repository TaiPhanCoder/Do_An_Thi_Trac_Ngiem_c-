#include "cau_hoi_da_thi.h"
#include <QDebug>

cau_hoi_da_thi::cau_hoi_da_thi() {}

void themMonHoc(monHocDaThi*& head, monHocDaThi* monHocMoi) {
    if (monHocMoi == nullptr) {
        qDebug() << "Môn học không hợp lệ!";
        return;
    }

    // Thêm monHocMoi vào đầu danh sách
    monHocMoi->next = head;
    head = monHocMoi;
}


monHocDaThi* newmonHocDaThi(const QString& mamh, float diem, int questions) {
    monHocDaThi* newMH = new monHocDaThi;
    newMH->maMH = mamh;
    newMH->diem = diem;
    newMH->soCauThi = questions;
    newMH->mangDaThi = new DaThi[questions];
    newMH->next = nullptr;
    return newMH;
}

int demSoMonThi(monHocDaThi* head) {
    int count = 0;
    monHocDaThi* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

