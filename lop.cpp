#include "lop.h"

lop::lop() {}

Lop* danhSachLop[MAX];

int demSoLop() {
    int count = 0;
    int i = 0;
    while (danhSachLop[i] != nullptr && i < MAX) {
        count++;
        i++;
    }
    return count;
}

int demSVLop(Lop* lop) {
    int count = 0;
    SinhVien* current = lop->DSSV;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}
