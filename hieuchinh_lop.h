#ifndef HIEUCHINH_LOP_H
#define HIEUCHINH_LOP_H

#include "lop.h"
#include "giao_vien.h"
#include "ui_hieuchinh_lop.h"
#include <QDialog>

namespace Ui {
class HieuChinh_Lop;
}

class HieuChinh_Lop : public QDialog {
    Q_OBJECT

public:
    explicit HieuChinh_Lop(const QString &maLop, const QString &tenLop,
                           Lop* danhSachLop[],
                           GIao_Vien *giaoVien, QWidget *parent = nullptr);
    ~HieuChinh_Lop();

    void accept();
    // QString getMaLop() const;
    // QString getTenLop() const;

private slots:

    void chinhSuaLop();
    bool thongBaoLoi();

private:
    Ui::HieuChinh_Lop *ui;
    GIao_Vien *giaoVien;
    Lop** danhSachLop;
    QString oldMaLop;


    Lop* timLop(const QString &maLop, Lop* danhSachLop[]);
    bool checkMaLop(const QString &maLop, Lop** danhSachLop);
};

#endif // HIEUCHINH_LOP_H
