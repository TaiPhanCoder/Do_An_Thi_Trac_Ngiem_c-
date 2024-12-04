#include "cau_hoi_da_thi.h"
#include "globals.h"
#include "cau_hoi.h"

cau_hoi_da_thi::cau_hoi_da_thi() {}

monHoc* newMonHoc(const QString& mamh, float diem, int questions) {
    monHoc* newMH = new monHoc;
    newMH->maMH = mamh;
    newMH->diem = diem;
    newMH->mangDaThi = new DaThi[questions];
    newMH->next = nullptr;
    return newMH;
}

int demSoMonThi(monHoc* head) {
    int count = 0;
    monHoc* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

