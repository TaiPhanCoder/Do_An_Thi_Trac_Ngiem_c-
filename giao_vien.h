#ifndef GIAO_VIEN_H
#define GIAO_VIEN_H

#include <QMainWindow>
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

private:
    Ui::GIao_Vien *ui;
};

#endif // GIAO_VIEN_H
