#include "cau_hoi_da_thi.h"
#include "globals.h"
#include "cau_hoi.h"

cau_hoi_da_thi::cau_hoi_da_thi() {}

CauHoiDaChon* taoMangCauHoiDaChon() {
    CauHoiDaChon* mangCauHoiDaChon = new CauHoiDaChon[questions];

    CauHoi* current = headCauhoi;
    int index = 0;

    // Khởi tạo mỗi phần tử trong mảng với giá trị mặc định
    while (current != nullptr && index < questions) {
        mangCauHoiDaChon[index].id = current->id;    // Lấy id từ câu hỏi và gán vào mảng
        mangCauHoiDaChon[index].dapAn = '\0'; // Đáp án mặc định là ký tự rỗng
        current = current->next; // Chuyển sang câu hỏi tiếp theo
        index++;
    }

    // Trả về con trỏ đến mảng vừa tạo
    return mangCauHoiDaChon;
}


