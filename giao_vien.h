#ifndef GIAO_VIEN_H
#define GIAO_VIEN_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QTableWidget>
#include "ui_giao_vien.h"

namespace Ui {
class GIao_Vien;
}

class GIao_Vien : public QMainWindow
{
    Q_OBJECT

public:
    explicit GIao_Vien(QWidget *parent = nullptr);
    ~GIao_Vien();

    void loadSinhVien();
    void onTextEdited(const QString &text);
    void timSinhVien(const QString &text);

private slots:
    void showContextMenu(const QPoint &pos);
    void xoaSV();
    QString getSelectedStudentMasv(int row);
    QString getSelectedStudentLop(int row);
    void on_them1sv_clicked();
    void hieuChinhSV();
    void on_sinhVien_clicked();
    void on_sapXep_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::GIao_Vien *ui;
    QMenu *contextMenu;
    QAction *editAction;
    QAction *deleteAction;
};


#endif // GIAO_VIEN_H
