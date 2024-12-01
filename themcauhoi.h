#ifndef THEMCAUHOI_H
#define THEMCAUHOI_H

#include <QDialog>
#include "mamh.h"

namespace Ui {
class themcauhoi;
}

class themcauhoi : public QDialog
{
    Q_OBJECT

public:
    explicit themcauhoi(QWidget *parent = nullptr, NodeMonHoc* root = nullptr, int* index = nullptr);
    ~themcauhoi();

private slots:
    void dsMonHoc(NodeMonHoc* root);
    void randomID(int index);
    void themDapAnVaoComboBox();
    bool thongBaoLoi();
    QString getNoiDung();
    QString getMonHoc();
    QString getDapAn();
    QString getA();
    QString getB();
    QString getC();
    QString getD();
    void accept();
    void luuCauHoi();

private:
    int randomId;
    Ui::themcauhoi *ui;
    NodeMonHoc* m_root;
    int* m_index;
};


#endif // THEMCAUHOI_H
