#include <QFileDialog>
#include <OpenXLSX.hpp>
#include <QString>
#include <QDebug>
#include "globals.h"
#include "sinhvien.h"
#include "lop.h"

void loadSinhVienTuFile(Lop* danhSachLop[], const QString &fileName)
{
    OpenXLSX::XLDocument xlsx;
    try {
        xlsx.open(fileName.toStdString());
    } catch (const std::exception &e) {
        qDebug() << "Failed to load the file.";
        return;
    }

    auto workbook = xlsx.workbook();
    auto worksheet = workbook.worksheet("Sheet1");

    // Lấy thông tin lớp từ file Excel
    QString lop = QString::fromStdString(worksheet.cell("B1").value().get<std::string>()).trimmed();
    if (lop.isEmpty()) {
        qDebug() << "Lớp không được để trống.";
        return;
    }

    // Kiểm tra xem lớp đã tồn tại trong danh sách lớp hay chưa, nếu chưa thì thêm mới
    Lop* currentLop = nullptr;
    int i = 0;
    while (danhSachLop[i] != nullptr) {
        if (danhSachLop[i]->MALOP == lop) {
            currentLop = danhSachLop[i];
            break;
        }
        ++i;
    }

    if (currentLop == nullptr) {
        currentLop = new Lop;
        currentLop->MALOP = lop;
        currentLop->TENLOP = lop;  // Giả sử tên lớp giống mã lớp
        currentLop->DSSV = nullptr;
        danhSachLop[i] = currentLop;
        danhSachLop[i + 1] = nullptr; // Cập nhật danh sách lớp
        qDebug() << "Đã thêm lớp mới:" << lop;
    }

    // Đọc danh sách sinh viên bắt đầu từ hàng 4
    int row = 4;
    while (true) {
        QString masv = QString::fromStdString(worksheet.cell(row, 2).value().get<std::string>()).trimmed();
        QString ho = QString::fromStdString(worksheet.cell(row, 3).value().get<std::string>()).trimmed();
        QString ten = QString::fromStdString(worksheet.cell(row, 4).value().get<std::string>()).trimmed();
        QString phai = QString::fromStdString(worksheet.cell(row, 5).value().get<std::string>()).trimmed();

        if (masv.isEmpty()) {
            break; // Hết sinh viên để đọc
        }

        SinhVien* newSV = taoNodeSinhVien(masv, ho, ten, phai, "");
        themSinhVienVaoLop(newSV, lop);

        qDebug() << "Đã thêm sinh viên MSSV:" << masv << "Họ:" << ho << "Tên:" << ten << "Phái:" << phai;
        ++row;
    }
}
