#ifndef XEM_DIEM_LOP_H
#define XEM_DIEM_LOP_H
#include "sinhvien.h"
#include "cau_hoi_da_thi.h"
#include "mamh.h"
#include "lop.h"
#include <QDialog>

namespace Ui {
class xem_diem_lop;
}

class xem_diem_lop : public QDialog
{
    Q_OBJECT

public:
    explicit xem_diem_lop(Lop* mainClass, SinhVien* sv, NodeMonHoc* root, const QString maMH,  QWidget *parent = nullptr);
    ~xem_diem_lop();

private:
    Ui::xem_diem_lop *ui;
    void setThongTinMon(const QString &maMH, NodeMonHoc *root);
    float LayDiemThi(SinhVien* sv, QString &maMH);
    // void loadBangDiem(const QString& maMH);
    void xemDiemSinhVien(int row, int column);
    void loadBangDiem(const QString& maMH);

    QString timTenMonHoc(const QString& maMH, NodeMonHoc* root);
    Lop* mainClass;
    NodeMonHoc* root;

};

#endif // XEM_DIEM_LOP_H
