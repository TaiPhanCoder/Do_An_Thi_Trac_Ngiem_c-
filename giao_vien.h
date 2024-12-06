#ifndef GIAO_VIEN_H
#define GIAO_VIEN_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QTableWidget>
#include "ui_giao_vien.h"
#include "mamh.h"
#include "lop.h"

namespace Ui {
class GIao_Vien;
}

class GIao_Vien : public QMainWindow
{
    Q_OBJECT

public:
    explicit GIao_Vien(Lop* danhSachLop[], QWidget* parent = nullptr);
    ~GIao_Vien();

    void loadSinhVien();
    void onTextEdited(const QString &text);
    void timSinhVien(const QString &text);

private slots:
    void showSinhVienContextMenu(const QPoint &pos);
    void showCauHoiContextMenu(const QPoint &pos);
    void xoaSV();
    QString getSelectedStudentMasv(int row);
    QString getSelectedStudentLop(int row);
    void on_them1sv_clicked();
    void hieuChinhSV();
    void on_sinhVien_clicked();
    void on_sapXep_clicked();
    void on_themNhieuSV_clicked();
    void loadLopVaoComboBox();
    void dsMonHoc(NodeMonHoc* root, bool isFirst);
    void onCauHoiComboBoxChanged(int index);
    void locCauHoi(const QString& selectedCauHoi);
    void loadSinhVienLop(const QString &lop);
    void onLopComboBoxChanged(int index);
    void setupComboBoxFilter(QComboBox *comboBox);
    void on_cauHoi_clicked();
    void loadCauHoi(ptrMonHoc root, int &row);
    void xoaCauHoi();
    void hieuChinhCauHoi();
    void on_Them1CauHoi_clicked();

private:
    Ui::GIao_Vien *ui;
    Lop** danhSachLop;

    QMenu* sinhVienContextMenu;
    QAction* sinhVienDeleteAction;
    QAction* sinhVienEditAction;

    QMenu* cauHoiContextMenu;
    QAction* cauHoiDeleteAction;
    QAction* cauHoiEditAction;
};


#endif // GIAO_VIEN_H
