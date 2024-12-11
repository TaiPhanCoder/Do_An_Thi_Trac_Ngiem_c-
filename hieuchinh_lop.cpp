#include "hieuchinh_lop.h"
#include "ui_hieuchinh_lop.h"

hieuchinh_lop::hieuchinh_lop(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::hieuchinh_lop)
{
    ui->setupUi(this);
}

hieuchinh_lop::~hieuchinh_lop()
{
    delete ui;
}
