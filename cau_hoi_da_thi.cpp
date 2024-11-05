#include "cau_hoi_da_thi.h"
#include "globals.h"
#include "cau_hoi.h"

cau_hoi_da_thi::cau_hoi_da_thi() {}

CauHoiDaChon* taoMangCauHoiDaChon() {
    CauHoiDaChon* mangCauHoiDaChon = new CauHoiDaChon[questions];

    CauHoi* current = headCauhoi;
    int index = 0;

    while (current != nullptr && index < questions) {
        mangCauHoiDaChon[index].id = current->id;
        mangCauHoiDaChon[index].dapAn = '\0';
        current = current->next;
        index++;
    }

    return mangCauHoiDaChon;
}


