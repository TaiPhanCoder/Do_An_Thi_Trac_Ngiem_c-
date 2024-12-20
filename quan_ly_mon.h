#ifndef QUAN_LY_MON_H
#define QUAN_LY_MON_H

#include "mamh.h"

#include <QDialog>

namespace Ui {
class quan_Ly_Mon;
}

class quan_Ly_Mon : public QDialog
{
    Q_OBJECT

public:
    explicit quan_Ly_Mon(QWidget *parent = nullptr, NodeMonHoc* root = nullptr);
    ~quan_Ly_Mon();

private slots:
    void on_them_clicked();
    bool thongBaoLoi();

private:
    Ui::quan_Ly_Mon *ui;
    NodeMonHoc* root = nullptr;

    void setupLineEdit();
    void setupBangDuLieu();
    void loadMonHoc(NodeMonHoc* root);

};

#endif // QUAN_LY_MON_H
