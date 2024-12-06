#ifndef TRAC_NGHIEM_H
#define TRAC_NGHIEM_H
#include "cau_hoi.h"
#include "sinhvien.h"
#include "lop.h"
#include "cau_hoi_da_thi.h"
#include <QListWidgetItem>

#include <QMainWindow>

namespace Ui {
class Trac_Nghiem;
}

class Trac_Nghiem : public QMainWindow
{
    Q_OBJECT

public:
    explicit Trac_Nghiem(SinhVien* mainUser, Lop* danhSachLop[], int times, int questions,
                         const QString &monhoc, const QString &maMH, QWidget *parent = nullptr);
    ~Trac_Nghiem();

private slots:
    void on_right_arow_clicked();
    void startCountdown(int times);
    void updateTime();
    void on_left_arow_clicked();
    void indsach();
    void handleListWidgetClick(QListWidgetItem *item);
    void initializeMangDaThi();
    void handleAnswerSelection();
    void updateRadioButtonState();
    void setupTracNghiem();
    void on_NopBai_clicked();
    void ketQuaLamBai(const float &diem);

private:

    float tinhDiemSinhVien();

    Ui::Trac_Nghiem *ui;
    SinhVien* mainUser;
    Lop** danhSachLop;
    int times;
    int questions;
    QString monhoc;
    QString maMH;

    void taoMonHocDangThi(SinhVien* sinhVien, const QString& maMH, int questions);
    monHocDaThi* monHocMoi;
};

    extern int countcauhoi;

#endif // TRAC_NGHIEM_H
