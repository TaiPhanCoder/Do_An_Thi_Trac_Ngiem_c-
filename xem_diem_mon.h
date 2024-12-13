#ifndef XEM_DIEM_MON_H
#define XEM_DIEM_MON_H

#include <QDialog>
#include "sinhvien.h"
#include "mamh.h"

namespace Ui {
class xem_Diem_Mon;
}

class xem_Diem_Mon : public QDialog
{
    Q_OBJECT

public:
    explicit xem_Diem_Mon(SinhVien* sinhVien, MonHoc* monHoc, QWidget *parent = nullptr);
    ~xem_Diem_Mon();

private:
    Ui::xem_Diem_Mon *ui;
    SinhVien* sinhVien;
    MonHoc* monHoc;
    monHocDaThi* diemthi;

    void setupLables();
    CauHoi* timCauHoi(int id);
    monHocDaThi* timMonHocDaThi(SinhVien* sinhVien, const QString& maMH);
    void taoNoiDungCauHoi();
};

#endif // XEM_DIEM_MON_H
