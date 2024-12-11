#ifndef HIEUCHINH_SINHVIEN_H
#define HIEUCHINH_SINHVIEN_H
#include "sinhvien.h"
#include "lop.h"

#include <QDialog>

namespace Ui {
class HieuChinh;
}

class HieuChinh : public QDialog
{
    Q_OBJECT

public:
    explicit HieuChinh(const QString &mssv, const QString &ho, const QString &ten,
                       const QString &lop, const QString &gioiTinh, Lop* danhSachLop[], bool dasapxep = false, QWidget *parent = nullptr);
    ~HieuChinh();
    QString getMSSV() const;
    QString getHo() const;
    QString getTen() const;
    QString getGioiTinh() const;
    QString getLop() const;
    void accept();

private slots:
    void setupComboBoxes();
    bool thongBaoLoi();
    void chinhSuaSinhVien();
    void capNhatThongTinSinhVien(SinhVien* sv);

private:
    Ui::HieuChinh *ui;
    Lop** danhSachLop;
    QString oldMssv;
    QString oldLop;
    bool dasapxep;
};

#endif // HIEUCHINH_SINHVIEN_H
