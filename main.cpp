#include "dang_nhap.h"
#include "trac_nghiem.h"
#include "giao_vien.h"
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
    CauHoi* danhSachCauHoi = nullptr;

    lapdssinhvien(":/TK-MK-PTIT/DsachDalLamBai.txt", danhSachLop);

    Dang_Nhap* loginDlg = new Dang_Nhap(mainUser, danhSachLop);
    if (loginDlg->exec() == QDialog::Accepted) {
        if (mainUser == nullptr) {
            GIao_Vien gvWindow(danhSachLop);
            gvWindow.showMaximized();
            delete loginDlg;
            return a.exec();
        } else {
            Thong_Tin_Thi* TTThi = new Thong_Tin_Thi(mainUser, danhSachCauHoi);
            delete loginDlg;
            if (TTThi->exec() == QDialog::Accepted) {
                // Lấy các giá trị từ TTThi ngay khi nó vẫn còn hoạt động
                int times = TTThi->getTime();
                int questions = TTThi->getQuestions();
                QString monhoc = TTThi->getMonHoc();
                QString maMH = TTThi->getMaMH();

                // Tạo cửa sổ Trac_Nghiem với các giá trị đã lấy được
                Trac_Nghiem* TT = new Trac_Nghiem(mainUser, danhSachLop, times, questions, monhoc, maMH, danhSachCauHoi);
                TT->showMaximized();
                delete TTThi;
                return a.exec();
            }
        }
    }

    return 0;
}
