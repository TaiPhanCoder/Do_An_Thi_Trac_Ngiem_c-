#include "dang_nhap.h"
#include "trac_nghiem.h"
#include "giao_vien.h"
#include "globals.h"
#include "thong_tin_thi.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dang_Nhap *loginDlg = new Dang_Nhap();
    if (loginDlg->exec() == QDialog::Accepted) {

        if (GV) {
            // Nếu là giảng viên, mở giao diện giảng viên
            GIao_Vien gvWindow;
            gvWindow.setWindowIcon(QIcon(":/logo/ad27bc12ca81e862ceb35328122757ee.ico"));
            gvWindow.showMaximized();
            return a.exec();
        } else {
            Thong_Tin_Thi *TTThi = new Thong_Tin_Thi();
            if (TTThi->exec() == QDialog::Accepted) {
                // Nếu thông tin thi được chấp nhận, mở giao diện Trắc Nghiệm
                Trac_Nghiem w;
                w.setWindowIcon(QIcon(":/logo/ad27bc12ca81e862ceb35328122757ee.ico"));
                w.showMaximized();
                return a.exec();
            }
        }
    }

    return 0;
}
