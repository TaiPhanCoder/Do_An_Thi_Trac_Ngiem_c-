#ifndef XEM_MON_LOP_H
#define XEM_MON_LOP_H
#include "mamh.h"
#include "sinhvien.h"
#include "lop.h"
#include <QDialog>

namespace Ui {
class xem_mon_lop;
}

class xem_mon_lop : public QDialog
{
    Q_OBJECT

public:
    explicit xem_mon_lop(Lop* mainClass, NodeMonHoc* root, QWidget *parent = nullptr);
    ~xem_mon_lop();


private:
    Ui::xem_mon_lop *ui;
    NodeMonHoc* root;
    Lop* mainClass;
    QString timTenMonHoc(const QString& maMH, NodeMonHoc* root);
    void setThongTinLop();

    void onTableDoubleClicked(int row, int column);

    void loadBangMonHoc();

};

#endif // XEM_MON_LOP_H
