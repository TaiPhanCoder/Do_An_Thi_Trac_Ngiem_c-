#include "quan_ly_mon.h"
#include "ui_quan_ly_mon.h"

quan_Ly_Mon::quan_Ly_Mon(QWidget *parent, NodeMonHoc* root)
    : QDialog(parent)
    , ui(new Ui::quan_Ly_Mon)
    , root(root)
{
    ui->setupUi(this);
    this->setWindowTitle("Quản lý môn học");

    setupBangDuLieu();
    ui->dsachdiem->setEditTriggers(QAbstractItemView::NoEditTriggers);
    setupLineEdit();
}

quan_Ly_Mon::~quan_Ly_Mon()
{
    delete ui;
}

void quan_Ly_Mon::setupBangDuLieu()
{
    ui->dsachdiem->setColumnCount(3);
    QStringList headers = {"Mã MH", "Tên MH", "Số lượng câu hỏi"};
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
    int soLuongCauHoi = demCauHoi(root->MH.headCauhoi);
    ui->dsachdiem->setItem(row, 2, new QTableWidgetItem(QString::number(soLuongCauHoi)));
    row++;

    loadMonHoc(root->right);
}

bool quan_Ly_Mon::thongBaoLoi() {
    bool isValid = true;

    if (ui->maMH->text().isEmpty()) {
        ui->LoiMaLop->setText("Mã môn học không được để trống");
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
