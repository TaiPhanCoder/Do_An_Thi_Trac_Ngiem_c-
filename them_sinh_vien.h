#ifndef THEM_SINH_VIEN_H
#define THEM_SINH_VIEN_H

#include <QDialog>

namespace Ui {
class Them_Sinh_Vien;
}

class Them_Sinh_Vien : public QDialog
{
    Q_OBJECT

public:
    explicit Them_Sinh_Vien(QWidget *parent = nullptr);
    ~Them_Sinh_Vien();
    QString getMSSV() const;
    QString getHo() const;
    QString getTen() const;
    QString getGioiTinh() const;
    QString getLop() const;

private slots:
private:
    Ui::Them_Sinh_Vien *ui;
};

#endif // THEM_SINH_VIEN_H
