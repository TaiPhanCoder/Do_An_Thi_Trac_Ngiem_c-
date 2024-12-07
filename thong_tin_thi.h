#ifndef THONG_TIN_THI_H
#define THONG_TIN_THI_H

#include <QDialog>
#include <QCompleter>
#include "mamh.h"
#include "sinhvien.h"

namespace Ui {
class Thong_Tin_Thi;
}

class Thong_Tin_Thi : public QDialog
{
    Q_OBJECT

public:
    explicit Thong_Tin_Thi(SinhVien* mainUser, CauHoi*& danhSachCauHoi, QWidget* parent = nullptr);
    ~Thong_Tin_Thi();

    // Getter cho dữ liệu đầu ra
    int getTime() const;
    int getQuestions() const;
    QString getMonHoc() const;
    QString getMaMH() const;
    CauHoi* getHeadCauhoi() const;

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void on_DangNhapButton_clicked();

    void on_xemDiem_clicked();

private:
    void setupUI();
    void setupCompleter();
    void setupDSMonHoc(NodeMonHoc* root);
    bool isMonHocDaThi(const QString& maMH);

private:
    Ui::Thong_Tin_Thi *ui;
    SinhVien* mainUser;
    CauHoi*& danhSachCauHoi;
    QStringList danhSachMonHoc; // Dữ liệu cho QCompleter
    QCompleter *completer;

    int times;
    int questions;
    QString monhoc;
    QString maMH;
    NodeMonHoc* root;
};

#endif // THONG_TIN_THI_H
