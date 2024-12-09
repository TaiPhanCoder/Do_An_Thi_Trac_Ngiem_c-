#ifndef TRAC_NGHIEM_H
#define TRAC_NGHIEM_H
#include "cau_hoi.h"
#include "sinhvien.h"
#include "lop.h"
#include "cau_hoi_da_thi.h"
#include <QListWidgetItem>
#include <QMainWindow>
#include "QTime"
#include <QMessageBox>

namespace Ui {
class Trac_Nghiem;
}

class Trac_Nghiem : public QMainWindow
{
    Q_OBJECT

public:
    explicit Trac_Nghiem(SinhVien* mainUser, Lop* danhSachLop[], int times, int questions,
                         const QString &monhoc, const QString &maMH, CauHoi* headCauhoi, QWidget *parent = nullptr);
    ~Trac_Nghiem();

private slots:
    void on_right_arow_clicked();
    void startCountdown(int times);
    void updateTime();
    void on_left_arow_clicked();
    void handleListWidgetClick(QListWidgetItem *item);
    void handleAnswerSelection();
    void on_NopBai_clicked();
    void ketQuaLamBai(const float &diem);
    void updateTimerDisplay();

private:
    void setupTracNghiem();
    void luuDuLieuMangDaThi(Lop* danhSachLop[]);
    void initializeMangDaThi();
    void updateRadioButtonState();
    void next();
    void prev();
    void cauHoi();
    float tinhDiemSinhVien();
    void taoMonHocDangThi(SinhVien* sinhVien, const QString& maMH, int questions);
    void updateQuestion();
    void on_finish_clicked();

    Ui::Trac_Nghiem *ui;

    QTimer* timer;
    QTime timeLeft;

    SinhVien* mainUser;
    Lop** danhSachLop;
    int times;
    int questions;
    QString monhoc;
    QString maMH;
    CauHoi* headCauhoi;
    monHocDaThi* monHocMoi;
    int cauHienTai = 1;
    DaThi* mangDaThi;
    CauHoi* cauhoiHienTai;
    int totalSeconds;
};

#endif // TRAC_NGHIEM_H
