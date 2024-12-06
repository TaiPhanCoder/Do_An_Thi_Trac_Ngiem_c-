#include "dang_nhap.h"
#include "trac_nghiem.h"
#include "giao_vien.h"
#include "globals.h"
#include "sinhvien.h"
#include "thong_tin_thi.h"
#include "lop.h"

#include <QApplication>
#include <QPalette>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SinhVien* mainUser = nullptr;
    Lop* danhSachLop[MAX] = {nullptr};

    lapdssinhvien(":/TK-MK-PTIT/DsachDalLamBai.txt", danhSachLop);

    Dang_Nhap* loginDlg = new Dang_Nhap(mainUser, danhSachLop);
    if (loginDlg->exec() == QDialog::Accepted) {
        if (mainUser == nullptr) {
            GIao_Vien gvWindow(danhSachLop);
            gvWindow.showMaximized();
            return a.exec();
        } else {
            // Nếu mainUser != nullptr, mở giao diện thông tin thi
            Thong_Tin_Thi* TTThi = new Thong_Tin_Thi(mainUser, danhSachLop);
            if (TTThi->exec() == QDialog::Accepted) {
                Trac_Nghiem w(mainUser, danhSachLop);
                w.showMaximized();
                return a.exec();
            }
        }
    }

    return 0;
}
