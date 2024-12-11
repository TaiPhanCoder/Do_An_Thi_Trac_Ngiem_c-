#ifndef THEM_LOP_H
#define THEM_LOP_H

#include <QDialog>

namespace Ui {
class them_lop;
}

class them_lop : public QDialog
{
    Q_OBJECT

public:
    explicit them_lop(QWidget *parent = nullptr);
    ~them_lop();

private:
    Ui::them_lop *ui;
};

#endif // THEM_LOP_H
