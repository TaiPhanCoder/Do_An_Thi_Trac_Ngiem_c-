// #ifndef THEM_LOP_H
#define THEM_LOP_H
// #ifndef THEM_LOP_H
#define THEM_LOP_H

#include "ui_them_lop.h"
#include <QDialog>
#include "lop.h"

namespace Ui {
class Them_Lop;
}

class Them_Lop : public QDialog
{
    Q_OBJECT

public:
    explicit Them_Lop(Lop* danhSachLop[], QWidget *parent = nullptr);
    ~Them_Lop();

    QString getMaLop() const;
    QString getTenLop() const;

private slots:
    void accept();

private:
    Ui::Them_Lop *ui;
    Lop** danhSachLop;

    QString oldLop;
    bool thongBaoLoi();       // Kiểm tra lỗi nhập liệu
    bool checkMaLop(const QString &maLop, Lop** danhSachLop);  // Kiểm tra trùng mã lớp
};
