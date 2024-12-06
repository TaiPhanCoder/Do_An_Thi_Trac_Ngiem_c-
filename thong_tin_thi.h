#ifndef THONG_TIN_THI_H
#define THONG_TIN_THI_H

#include <QDialog>
#include <QCompleter>
#include "mamh.h"
#include "sinhvien.h"
#include "lop.h"

namespace Ui {
class Thong_Tin_Thi;
}

class Thong_Tin_Thi : public QDialog
{
    Q_OBJECT

public:
    explicit Thong_Tin_Thi(SinhVien* mainUser, Lop* danhSachLop[], QWidget* parent = nullptr);
    ~Thong_Tin_Thi();
    int getTime() const;
    int getQuestions() const;
    QString getMonHoc() const;
    QString getMaMH() const;
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void on_DangNhapButton_clicked();
    void setUpDSMonHoc(NodeMonHoc* root);

private:
    Ui::Thong_Tin_Thi *ui;
    SinhVien* mainUser;
    Lop** danhSachLop;

    int times;
    int questions;
    QString monhoc;
    QString maMH;

    QStringList danhSachMonHoc;
    QCompleter *completer;
};

#endif // THONG_TIN_THI_H
