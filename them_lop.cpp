#include "them_lop.h"
#include "ui_them_lop.h"

them_lop::them_lop(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::them_lop)
{
    ui->setupUi(this);
}

them_lop::~them_lop()
{
    delete ui;
}
