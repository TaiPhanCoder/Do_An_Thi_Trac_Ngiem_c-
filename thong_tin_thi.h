#ifndef THONG_TIN_THI_H
#define THONG_TIN_THI_H

#include <QDialog>
#include <QCompleter>

namespace Ui {
class Thong_Tin_Thi;
}

class Thong_Tin_Thi : public QDialog
{
    Q_OBJECT

public:
    explicit Thong_Tin_Thi(QWidget *parent = nullptr);
    ~Thong_Tin_Thi();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void on_DangNhapButton_clicked();

private:
    Ui::Thong_Tin_Thi *ui;
    QStringList danhSachMonHoc;
    QCompleter *completer;
};

#endif // THONG_TIN_THI_H
