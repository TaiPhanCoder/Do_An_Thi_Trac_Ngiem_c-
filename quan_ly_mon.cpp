#include "quan_ly_mon.h"
#include "ui_quan_ly_mon.h"
#include <QMenu>
#include <QAction>
#include <QMessageBox>

quan_Ly_Mon::quan_Ly_Mon(QWidget *parent, NodeMonHoc* root)
    : QDialog(parent)
    , ui(new Ui::quan_Ly_Mon)
    , root(root)
{
    ui->setupUi(this);
    this->setWindowTitle("Quản lý môn học");

    setupBangDuLieu();
    ui->dsachdiem->setEditTriggers(QAbstractItemView::NoEditTriggers); // Không cho phép chỉnh sửa trực tiếp
    setupLineEdit();

    // Context menu cho đổi tên môn học và xoá môn học
    QMenu *contextMenu = new QMenu(this);

    QAction *doiTenMonHocAction = new QAction("Đổi tên môn học", this);
    QAction *xoaMonHocAction = new QAction("Xoá môn học", this);

    contextMenu->addAction(doiTenMonHocAction);
    contextMenu->addAction(xoaMonHocAction);

    ui->dsachdiem->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui->dsachdiem, &QWidget::customContextMenuRequested, [=](const QPoint &pos) {
        // Chọn nguyên một dòng khi chuột phải
        QModelIndex index = ui->dsachdiem->indexAt(pos);
        if (index.isValid()) {
            ui->dsachdiem->selectRow(index.row());
            contextMenu->exec(ui->dsachdiem->viewport()->mapToGlobal(pos));
        }
    });

    connect(doiTenMonHocAction, &QAction::triggered, this, &quan_Ly_Mon::doiTenMonHoc);
    connect(xoaMonHocAction, &QAction::triggered, this, &quan_Ly_Mon::xoaMonHoc);
}

quan_Ly_Mon::~quan_Ly_Mon()
{
    delete ui;
}

void quan_Ly_Mon::doiTenMonHoc() {
    QModelIndex currentIndex = ui->dsachdiem->currentIndex();
    if (!currentIndex.isValid()) {
        QMessageBox::warning(this, "Lỗi", "Vui lòng chọn một môn học để đổi tên.");
        return;
    }

    // Cho phép chỉnh sửa trực tiếp trên ô "Tên môn học"
    ui->dsachdiem->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);

    // Đặt tiêu điểm vào ô "Tên môn học" của dòng hiện tại
    ui->dsachdiem->edit(ui->dsachdiem->model()->index(currentIndex.row(), 1));

    // Sau khi chỉnh sửa xong, cập nhật lại dữ liệu môn học
    connect(ui->dsachdiem->model(), &QAbstractItemModel::dataChanged, this, [=](const QModelIndex &topLeft, const QModelIndex &bottomRight) {
        if (topLeft.column() == 1 && topLeft.row() == currentIndex.row()) {
            QString maMonHoc = ui->dsachdiem->item(currentIndex.row(), 0)->text();
            QString tenMoi = ui->dsachdiem->item(currentIndex.row(), 1)->text();

            MonHoc *monHoc = SearchMonHoc(root, maMonHoc);
            monHoc->TENMH = tenMoi;

            // Khôi phục trạng thái không cho chỉnh sửa trực tiếp sau khi đổi tên
            ui->dsachdiem->setEditTriggers(QAbstractItemView::NoEditTriggers);
        }
    });
}

void quan_Ly_Mon::xoaMonHoc() {
    QModelIndex currentIndex = ui->dsachdiem->currentIndex();

    QString maMonHoc = ui->dsachdiem->item(currentIndex.row(), 0)->text();
    MonHoc* monHoc = SearchMonHoc(root, maMonHoc);

    // Kiểm tra xem có câu hỏi nào trong môn học đã được thi hay chưa
    CauHoi* currentCauHoi = monHoc->headCauhoi;
    while (currentCauHoi != nullptr) {
        if (currentCauHoi->daThi) {
            QMessageBox::warning(this, "Cảnh báo", "Môn học này đã có sinh viên thi, không thể xoá.");
            return;
        }
        currentCauHoi = currentCauHoi->next;
    }

    int ret = QMessageBox::question(this, "Xoá môn học", "Bạn có chắc chắn muốn xoá môn học này?", QMessageBox::Yes | QMessageBox::No);

    if (ret == QMessageBox::Yes) {
        root = deleteNodeAVL(root, maMonHoc);
        ui->dsachdiem->removeRow(currentIndex.row());
        QMessageBox::information(this, "Thành công", "Môn học đã được xoá thành công.");
    }
}

void quan_Ly_Mon::setupBangDuLieu()
{
    ui->dsachdiem->setColumnCount(4);
    QStringList headers = {"Mã MH", "Tên MH", "Tín chỉ", "Số lượng câu hỏi"};
    ui->dsachdiem->setHorizontalHeaderLabels(headers);
    ui->dsachdiem->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->dsachdiem->setRowCount(0);
    loadMonHoc(root);
}

void quan_Ly_Mon::setupLineEdit(){
    // Xử lý LineEdit maMH
    connect(ui->maMH, &QLineEdit::textEdited, this, [=](const QString &inputText) {
        QString filteredText;
        for (const QChar &ch : inputText) {
            if (ch.isLetterOrNumber()) {
                filteredText.append(ch.toUpper());
            }
        }

        // Chỉ cập nhật nếu khác nội dung hiện tại
        if (ui->maMH->text() != filteredText) {
            ui->maMH->blockSignals(true);  // Tạm ngắt tín hiệu
            ui->maMH->setText(filteredText);
            ui->maMH->blockSignals(false); // Bật lại tín hiệu
        }
    });

    connect(ui->tenMH, &QLineEdit::textEdited, this, [=](const QString &inputText) {
        QString filteredText;
        for (const QChar &ch : inputText) {
            if (ch.isLetter()) {
                filteredText.append(ch.toUpper());
            } else {
                filteredText.append(ch);
            }
        }

        // Chỉ cập nhật nếu khác nội dung hiện tại
        if (ui->tenMH->text() != filteredText) {
            ui->tenMH->blockSignals(true);  // Tạm ngắt tín hiệu
            ui->tenMH->setText(filteredText);
            ui->tenMH->blockSignals(false); // Bật lại tín hiệu
        }
    });
}

void quan_Ly_Mon::loadMonHoc(NodeMonHoc* root)
{
    int row = 0;
    if (root == nullptr) return;

    loadMonHoc(root->left);

    ui->dsachdiem->insertRow(row);
    ui->dsachdiem->setItem(row, 0, new QTableWidgetItem(root->MH.MAMH));
    ui->dsachdiem->setItem(row, 1, new QTableWidgetItem(root->MH.TENMH));
    ui->dsachdiem->setItem(row, 2, new QTableWidgetItem(QString::number(root->MH.tinChi)));
    int soLuongCauHoi = demCauHoi(root->MH.headCauhoi);
    ui->dsachdiem->setItem(row, 3, new QTableWidgetItem(QString::number(soLuongCauHoi)));
    row++;

    loadMonHoc(root->right);
}

bool quan_Ly_Mon::thongBaoLoi() {
    bool isValid = true;

    if (ui->maMH->text().isEmpty()) {
        ui->LoiMaLop->setText("Mã môn học không được để trống");
        ui->LoiMaLop->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else if (SearchMonHoc(root, ui->maMH->text()) != nullptr) {
        ui->LoiMaLop->setText("Mã môn học đã tồn tại");
        ui->LoiMaLop->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->LoiMaLop->clear();
    }

    if (ui->tenMH->text().isEmpty()) {
        ui->loiTenMH->setText("Tên môn học không được để trống");
        ui->loiTenMH->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->loiTenMH->clear();
    }

    if (ui->tinChi->value() <= 0) {
        ui->loiTinChi->setText("Tín chỉ phải lớn hơn 0");
        ui->loiTinChi->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->loiTinChi->clear();
    }

    return isValid;
}

void quan_Ly_Mon::on_them_clicked()
{
    // Lấy thông tin từ giao diện người dùng (UI)
    QString maMH = ui->maMH->text();
    QString tenMH = ui->tenMH->text();
    int tinChi = ui->tinChi->value();

    // Gọi hàm kiểm tra lỗi
    bool isValid = thongBaoLoi();
    if (!isValid) {
        return;
    }

    // Gọi hàm thêm môn học mới vào cây AVL
    root = insertNodeAVL(root, maMH, tenMH, tinChi);

    // Đặt số hàng của bảng về 0 trước khi tải lại dữ liệu
    ui->dsachdiem->setRowCount(0);
    loadMonHoc(root);

    // Cập nhật lại giao diện nếu cần
    ui->maMH->clear();
    ui->tenMH->clear();
    ui->tinChi->setValue(0);
}
