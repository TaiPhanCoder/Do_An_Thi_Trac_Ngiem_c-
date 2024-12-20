#include "xemdiem.h"
#include "ui_xemdiem.h"
#include "xem_diem_mon.h"
#include "QMessageBox"

xemDiem::xemDiem(SinhVien* mainUser, NodeMonHoc* root, bool isGV, QWidget *parent)
    : QDialog(parent), ui(new Ui::xemDiem), mainUser(mainUser), root(root), isGV(isGV)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    this->setWindowTitle("Xem Điểm");

    setThongTinSinhVien(); // Hiển thị MSSV và Tên
    loadBangDiem(); // Nạp điểm vào bảng
    if (isGV) {
        connect(ui->dsachdiem, &QTableWidget::cellDoubleClicked, this, &xemDiem::onTableDoubleClicked);
    }
}

xemDiem::~xemDiem()
{
    delete ui;
}

void xemDiem::onTableDoubleClicked(int row, int column) {
    // Lấy Mã Môn Học từ cột đầu tiên của dòng được nhấp đúp
    QString maMonHoc = ui->dsachdiem->item(row, 0)->text();

    // Tìm môn học dựa trên Mã Môn Học
    MonHoc* monHoc = SearchMonHoc(root, maMonHoc);

    if (monHoc != nullptr) {
        // Tạo và hiển thị dialog xem điểm môn
        xem_Diem_Mon* dialog = new xem_Diem_Mon(mainUser, monHoc, this);
        dialog->exec();
        delete dialog;
    } else {
        qDebug() << "Không tìm thấy Mã Môn Học: " << maMonHoc;
    }
}

// Hiển thị MSSV và Tên của sinh viên
void xemDiem::setThongTinSinhVien()
{
    ui->mssv->setText("MSSV: " + mainUser->masv);
    ui->ten->setText("Tên: " + mainUser->ho + " " + mainUser->ten);
    ui->mssv->setAlignment(Qt::AlignCenter);
    ui->ten->setAlignment(Qt::AlignCenter);
}

// Nạp điểm vào bảng QTableWidget
void xemDiem::loadBangDiem()
{
    // Xóa dữ liệu cũ
    ui->dsachdiem->clearContents();
    ui->dsachdiem->setRowCount(0);

    // Thiết lập tiêu đề cho bảng
    ui->dsachdiem->setColumnCount(5);
    QStringList headers = {"Mã Môn Học", "Tên Môn Học", "Điểm TK (10)", "Điểm TK (4)", "Điểm TK (C)"};
    ui->dsachdiem->setHorizontalHeaderLabels(headers);

    ui->dsachdiem->setColumnWidth(0, 75);
    ui->dsachdiem->setColumnWidth(1, 300);
    ui->dsachdiem->setColumnWidth(2, 90);
    ui->dsachdiem->setColumnWidth(3, 80);
    ui->dsachdiem->setColumnWidth(4, 78);

    ui->dsachdiem->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->dsachdiem->setSelectionBehavior(QAbstractItemView::SelectRows); // Chọn cả hàng khi nhấn vào ô
    ui->dsachdiem->setSelectionMode(QAbstractItemView::SingleSelection); // Chỉ chọn 1 dòng

    // Duyệt qua danh sách điểm của sinh viên
    int row = 0;
    monHocDaThi* current = mainUser->ds_diemthi;

    while (current) {
        QString tenMonHoc = timTenMonHoc(current->maMH, root); // Tìm tên môn học dựa trên mã môn học

        float diemThang4 = quyDoiDiem4(current->diem); // Quy đổi điểm thang 4
        QString diemChu = quyDoiDiemChu(current->diem); // Quy đổi điểm chữ

        ui->dsachdiem->insertRow(row); // Thêm dòng mới

        QTableWidgetItem* maMHItem = new QTableWidgetItem(current->maMH);
        QTableWidgetItem* tenMHItem = new QTableWidgetItem(tenMonHoc);
        QTableWidgetItem* diem10Item = new QTableWidgetItem(QString::number(current->diem));
        QTableWidgetItem* diem4Item = new QTableWidgetItem(QString::number(diemThang4));
        QTableWidgetItem* diemChuItem = new QTableWidgetItem(diemChu);

        maMHItem->setTextAlignment(Qt::AlignCenter);
        tenMHItem->setTextAlignment(Qt::AlignCenter);
        diem10Item->setTextAlignment(Qt::AlignCenter);
        diem4Item->setTextAlignment(Qt::AlignCenter);
        diemChuItem->setTextAlignment(Qt::AlignCenter);

        ui->dsachdiem->setItem(row, 0, maMHItem); // Mã môn học
        ui->dsachdiem->setItem(row, 1, tenMHItem); // Tên môn học
        ui->dsachdiem->setItem(row, 2, diem10Item); // Điểm TK (10)
        ui->dsachdiem->setItem(row, 3, diem4Item); // Điểm TK (4)
        ui->dsachdiem->setItem(row, 4, diemChuItem); // Điểm TK (C)

        current = current->next; // Duyệt sang môn học tiếp theo
        row++;
    }
}

float xemDiem::quyDoiDiem4(float diem10) {
    if (diem10 >= 9.0) return 4.0;
    if (diem10 >= 8.5) return 3.7;
    if (diem10 >= 8.0) return 3.5;
    if (diem10 >= 7.0) return 3.0;
    if (diem10 >= 6.5) return 2.5;
    if (diem10 >= 5.5) return 2.0;
    if (diem10 >= 5.0) return 1.5;
    if (diem10 >= 4.0) return 1.0;
    return 0.0;
}

QString xemDiem::quyDoiDiemChu(float diem10) {
    if (diem10 >= 9.0) return "A+";
    if (diem10 >= 8.5) return "A";
    if (diem10 >= 8.0) return "B+";
    if (diem10 >= 7.0) return "B";
    if (diem10 >= 6.5) return "C+";
    if (diem10 >= 5.5) return "C";
    if (diem10 >= 5.0) return "D+";
    if (diem10 >= 4.0) return "D";
    return "F";
}


// Tìm tên môn học dựa trên mã môn học
QString xemDiem::timTenMonHoc(const QString& maMH, NodeMonHoc* root)
{
    while (root) {
        if (root->MH.MAMH == maMH) {
            return root->MH.TENMH;
        } else if (maMH < root->MH.MAMH) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return "Không xác định";
}

