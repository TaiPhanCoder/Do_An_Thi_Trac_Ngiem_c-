#include "sinhvien.h"
#include "QString"
#include "lop.h"

#include<QDebug>

sinhvien::sinhvien() {}

SinhVien* taoNodeSinhVien(QString masv, QString ho, QString ten, QString phai, QString password) {
    SinhVien* sv = new SinhVien;
    sv->masv = masv;
    sv->ho = ho;
    sv->ten = ten;
    sv->phai = phai;
    sv->password = password;
    sv->ds_diemthi = nullptr;
    sv->next = nullptr;
    return sv;
}

void themSinhVien(SinhVien*& tail, SinhVien* newSV) {
    if (newSV == nullptr) {
        qDebug() << "Sinh viên không hợp lệ!";
        return;
    }

    if (tail == nullptr) {
        qDebug() << "Danh sách hiện tại không có sinh viên!";
        return;
    }

    tail->next = newSV;
    tail = newSV;
}

int soSanhTen(SinhVien* sv1, SinhVien* sv2) {
    if (sv1->ten != sv2->ten) {
        return (sv1->ten < sv2->ten) ? -1 : 1; // So sánh tên trước, nếu khác thì trả về kết quả
    }

    // Tách họ thành các cụm
    QStringList ho1_parts = sv1->ho.split(" ", Qt::SkipEmptyParts);
    QStringList ho2_parts = sv2->ho.split(" ", Qt::SkipEmptyParts);

    int size1 = ho1_parts.size();
    int size2 = ho2_parts.size();

    // So sánh từ phần cuối trở về đầu
    for (int i = 1; i <= qMin(size1, size2); ++i) {
        const QString& part1 = ho1_parts[size1 - i];
        const QString& part2 = ho2_parts[size2 - i];
        if (part1 != part2) {
            return (part1 < part2) ? -1 : 1; // So sánh phần cuối của họ trước
        }
    }

    // Nếu phần cuối giống nhau, so sánh số lượng cụm
    if (size1 != size2) {
        return (size1 < size2) ? -1 : 1;
    }

    return 0; // Nếu cả họ và tên đều giống nhau
}

void quickSortArray(SinhVien** arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partitionArray(arr, low, high);
        quickSortArray(arr, low, pivotIndex - 1);
        quickSortArray(arr, pivotIndex + 1, high);
    }
}

// Hàm phân hoạch mảng (Lomuto Partition Scheme)
int partitionArray(SinhVien** arr, int low, int high) {
    SinhVien* pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (soSanhTen(arr[j], pivot) < 0) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}
