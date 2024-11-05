#include "giao_vien.h"
#include "ui_giao_vien.h"
#include"sinhvien.h"
#include"lop.h"
#include<QDebug>

GIao_Vien::GIao_Vien(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GIao_Vien)
{
    ui->setupUi(this);
    this->setWindowTitle("Giảng Viên - PTIT");
    QPixmap pixmap(":/logo/ad27bc12ca81e862ceb35328122757ee.png");
    QPixmap scaledPixmap = pixmap.scaled(ui->logo->size(), Qt::KeepAspectRatio);
    ui->logo->setPixmap(scaledPixmap);
    int rows = demSinhVien();
    //tạo context menu
    setContextMenuPolicy(Qt::CustomContextMenu);

    contextMenu = new QMenu(this);
    deleteAction = new QAction("Xóa", this);

    contextMenu->addAction(deleteAction);

    connect(this, &QTableWidget::customContextMenuRequested, this, &GIao_Vien::showContextMenu);

    connect(deleteAction, &QAction::triggered, this, &GIao_Vien::xoaSV);

    ui->bangDuLieu->setRowCount(rows);
    ui->bangDuLieu->setColumnCount(5);
    ui->bangDuLieu->setColumnWidth(0, 350);
    ui->bangDuLieu->setColumnWidth(1, 400);
    ui->bangDuLieu->setColumnWidth(2, 200);
    ui->bangDuLieu->setColumnWidth(3, 200);
    ui->bangDuLieu->setColumnWidth(4, 200);
    QStringList headers;
    headers << "MSSV" << "Họ" << "Tên" <<"Lớp" << "Giới tính";
    ui->bangDuLieu->setHorizontalHeaderLabels(headers);
    loadSinhVien();
    connect(ui->timMSSV, &QLineEdit::textEdited, this, &GIao_Vien::onTextEdited);
    connect(ui->timMSSV, &QLineEdit::textChanged, this, &GIao_Vien::onSearchTextChanged);

}

GIao_Vien::~GIao_Vien()
{
    delete ui;
}

void GIao_Vien::showContextMenu(const QPoint &pos) {
    contextMenu->exec(mapToGlobal(pos));
}

void GIao_Vien::xoaSV(){}

void GIao_Vien::loadSinhVien() {
    int row = 0;

    // Duyệt qua mảng lớp
    for (int i = 0; i < 10000; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }
        SinhVien* current = danhSachLop[i]->DSSV;
        QString tenLop = danhSachLop[i]->TENLOP;

        // Duyệt qua danh sách sinh viên của lớp hiện tại
        while (current != nullptr) {
            // Tạo và thêm các mục cho từng cột trong hàng
            QTableWidgetItem *masvItem = new QTableWidgetItem(current->masv);
            QTableWidgetItem *hoItem = new QTableWidgetItem(current->ho);
            QTableWidgetItem *tenItem = new QTableWidgetItem(current->ten);
            QTableWidgetItem *phaiItem = new QTableWidgetItem(current->phai);
            QTableWidgetItem *tenLopItem = new QTableWidgetItem(tenLop);

            // Đặt các mục vào bảng
            ui->bangDuLieu->setItem(row, 0, masvItem);
            ui->bangDuLieu->setItem(row, 1, hoItem);
            ui->bangDuLieu->setItem(row, 2, tenItem);
            ui->bangDuLieu->setItem(row, 3, tenLopItem);
            ui->bangDuLieu->setItem(row, 4, phaiItem);
            qDebug() << "MSSV:" << current->masv;
            current = current->next;
            row++;
        }
    }
}

void GIao_Vien::onTextEdited(const QString &text) {
    disconnect(ui->timMSSV, &QLineEdit::textEdited, this, &GIao_Vien::onTextEdited);
    QString upperText = text.toUpper();
    ui->timMSSV->setText(upperText);
    ui->timMSSV->setCursorPosition(upperText.length());
    connect(ui->timMSSV, &QLineEdit::textEdited, this, &GIao_Vien::onTextEdited);
}

void GIao_Vien::onSearchTextChanged(const QString &text) {
    ui->bangDuLieu->setRowCount(0);

    SinhVien* current = headDsachSV;
    int row = 0;

    while (current != nullptr) {
        if (current->masv.contains(text, Qt::CaseInsensitive)) {
            ui->bangDuLieu->insertRow(row);

            ui->bangDuLieu->setItem(row, 0, new QTableWidgetItem(current->masv));
            ui->bangDuLieu->setItem(row, 1, new QTableWidgetItem(current->ho));
            ui->bangDuLieu->setItem(row, 2, new QTableWidgetItem(current->ten));
            ui->bangDuLieu->setItem(row, 3, new QTableWidgetItem(current->phai));

            row++;
        }

        current = current->next;
    }
}
