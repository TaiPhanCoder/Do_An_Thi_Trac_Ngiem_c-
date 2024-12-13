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
    connect(ui->dsachdiem, &QTableWidget::cellDoubleClicked, this, &xemDiem::onTableDoubleClicked);
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
    ui->dsachdiem->setColumnCount(3);
    QStringList headers = {"Mã Môn Học", "Tên Môn Học", "Điểm"};
    ui->dsachdiem->setHorizontalHeaderLabels(headers);

    ui->dsachdiem->setColumnWidth(0, 128);
    ui->dsachdiem->setColumnWidth(1, 385);
    ui->dsachdiem->setColumnWidth(2, 110);

    ui->dsachdiem->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->dsachdiem->setSelectionBehavior(QAbstractItemView::SelectRows); // Chọn cả hàng khi nhấn vào ô
    ui->dsachdiem->setSelectionMode(QAbstractItemView::SingleSelection); // Chỉ chọn 1 dòng

    // Duyệt qua danh sách điểm của sinh viên
    int row = 0;
    monHocDaThi* current = mainUser->ds_diemthi;

    while (current) {
        QString tenMonHoc = timTenMonHoc(current->maMH, root); // Tìm tên môn học dựa trên mã môn học

        ui->dsachdiem->insertRow(row); // Thêm dòng mới
        ui->dsachdiem->setItem(row, 0, new QTableWidgetItem(current->maMH)); // Mã môn học
        ui->dsachdiem->setItem(row, 1, new QTableWidgetItem(tenMonHoc)); // Tên môn học
        ui->dsachdiem->setItem(row, 2, new QTableWidgetItem(QString::number(current->diem))); // Điểm

        current = current->next; // Duyệt sang môn học tiếp theo
        row++;
    }
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

