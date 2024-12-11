#ifndef HIEUCHINH_LOP_H
#define HIEUCHINH_LOP_H

#include <QDialog>

namespace Ui {
class hieuchinh_lop;
}

class hieuchinh_lop : public QDialog
{
    Q_OBJECT

public:
    explicit hieuchinh_lop(QWidget *parent = nullptr);
    ~hieuchinh_lop();

private:
    Ui::hieuchinh_lop *ui;
};

#endif // HIEUCHINH_LOP_H
