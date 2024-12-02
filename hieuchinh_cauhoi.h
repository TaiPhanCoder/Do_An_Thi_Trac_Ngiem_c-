#ifndef HIEUCHINH_CAUHOI_H
#define HIEUCHINH_CAUHOI_H

#include <QDialog>
#include "mamh.h"

namespace Ui {
class hieuchinh_CauHoi;
}

class hieuchinh_CauHoi : public QDialog
{
    Q_OBJECT

public:
    explicit hieuchinh_CauHoi(QWidget *parent = nullptr,
                              QString mamh = "", int id = -1,
                              NodeMonHoc* root = nullptr);
    ~hieuchinh_CauHoi();

private slots:
    void themDapAnVaoComboBox();
    void dsMonHoc(NodeMonHoc* root);
    void setupHieuChinh();
    QString getNoiDung();
    QString getMonHoc();
    QString getDapAn();
    QString getA();
    QString getB();
    QString getC();
    QString getD();
    bool thongBaoLoi();
    void accept();

private:
    Ui::hieuchinh_CauHoi *ui;
    QString m_monHoc;
    int m_id;
    QString m_noiDung;
    QString m_A;
    QString m_B;
    QString m_C;
    QString m_D;
    QString m_dapAnDung;
    NodeMonHoc* m_root;
};

#endif // HIEUCHINH_CAUHOI_H