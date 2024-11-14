#ifndef HIEUCHINH_H
#define HIEUCHINH_H
#include "globals.h"

#include <QDialog>

namespace Ui {
class HieuChinh;
}

class HieuChinh : public QDialog
{
    Q_OBJECT

public:
    explicit HieuChinh(const QString &mssv, const QString &ho, const QString &ten, const QString &lop, const QString &gioiTinh, QWidget *parent = nullptr);
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
    QString oldMssv;
    QString oldLop;
};

#endif // HIEUCHINH_H
