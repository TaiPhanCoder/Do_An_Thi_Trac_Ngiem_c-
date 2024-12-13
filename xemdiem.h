#ifndef XEMDIEM_H
#define XEMDIEM_H
#include "cau_hoi_da_thi.h"
#include "mamh.h"
#include "sinhvien.h"

#include <QDialog>

namespace Ui {
class xemDiem;
}

class xemDiem : public QDialog
{
    Q_OBJECT

public:
    explicit xemDiem(SinhVien* mainUser, NodeMonHoc* root, bool isGV, QWidget *parent = nullptr);
    ~xemDiem();

private:
    Ui::xemDiem *ui;
    NodeMonHoc* root;
    SinhVien* mainUser;
    bool isGV;

    void onTableDoubleClicked(int row, int column);
    void setThongTinSinhVien();
    void loadBangDiem();
    QString timTenMonHoc(const QString& maMH, NodeMonHoc* root);
};

#endif // XEMDIEM_H
