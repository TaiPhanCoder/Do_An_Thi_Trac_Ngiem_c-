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

    void populateTable();
    void onTextEdited(const QString &text);
    void onSearchTextChanged(const QString &text);

private slots:
    void showContextMenu(const QPoint &pos);
    void xoaSV();

private:
    Ui::GIao_Vien *ui;
    QMenu *contextMenu;
    QAction *editAction;
    QAction *deleteAction;
};


#endif // GIAO_VIEN_H
