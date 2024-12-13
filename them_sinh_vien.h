#ifndef THEM_SINH_VIEN_H
#define THEM_SINH_VIEN_H

#include "lop.h"
#include "giao_vien.h"
#include <QDialog>

namespace Ui {
class Them_Sinh_Vien;
}

class Them_Sinh_Vien : public QDialog
{
    Q_OBJECT

public:
    explicit Them_Sinh_Vien(Lop* danhSachLop[], bool dasapxep, GIao_Vien *giaoVien, QWidget *parent = nullptr);
    ~Them_Sinh_Vien();

private slots:
    void accept();
private:
    Ui::Them_Sinh_Vien *ui;
    Lop** danhSachLop;
    bool dasapxep;
    QString oldLop;
    QStringList lopList;
    GIao_Vien *giaoVien;

    bool thongBaoLoi();
};

#endif // THEM_SINH_VIEN_H
