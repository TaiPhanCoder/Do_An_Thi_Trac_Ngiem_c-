#ifndef HIEUCHINH_SINHVIEN_H
#define HIEUCHINH_SINHVIEN_H
#include "sinhvien.h"
#include "lop.h"
#include "giao_vien.h"

#include <QDialog>

namespace Ui {
class HieuChinh;
}

class HieuChinh : public QDialog
{
    Q_OBJECT

public:
    explicit HieuChinh(const QString &mssv, const QString &ho, const QString &ten,
                       const QString &lop, const QString &gioiTinh, Lop* danhSachLop[],
                       bool dasapxep, GIao_Vien *giaoVien, QWidget *parent = nullptr);
    ~HieuChinh();

    void accept();

private slots:
    void setupComboBoxes();
    bool thongBaoLoi();
    void chinhSuaSinhVien();
    void capNhatThongTinSinhVien(SinhVien* sv);

private:
    Ui::HieuChinh *ui;
    GIao_Vien *giaoVien;
    Lop** danhSachLop;
    QString oldMssv;
    QString oldLop;
    QStringList lopList;
    bool dasapxep;
};

#endif // HIEUCHINH_SINHVIEN_H
