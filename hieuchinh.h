#ifndef HIEUCHINH_H
#define HIEUCHINH_H

#include <QDialog>

namespace Ui {
class HieuChinh;
}

class HieuChinh : public QDialog
{
    Q_OBJECT

public:
    explicit HieuChinh(const QString &mssv, const QString &ho, const QString &ten, const QString &lop, const QString &gioiTinh, QWidget *parent = nullptr);
    ~HieuChinh();

private slots:
    void setupComboBoxes();
private:
    Ui::HieuChinh *ui;
};

#endif // HIEUCHINH_H
