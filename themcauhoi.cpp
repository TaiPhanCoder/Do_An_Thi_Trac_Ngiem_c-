#include "themcauhoi.h"
#include "ui_themcauhoi.h"

themcauhoi::themcauhoi(QWidget *parent, NodeMonHoc* root)
    : QDialog(parent), ui(new Ui::themcauhoi), m_root(root)
{
    ui->setupUi(this);
    this->setWindowTitle("Thêm Câu Hỏi");
    themDapAnVaoComboBox();
    connect(ui->monHoc, &QComboBox::currentIndexChanged, this, &themcauhoi::randomID);
    dsMonHoc(m_root);
}

themcauhoi::~themcauhoi()
{
    delete ui;
}

void themcauhoi::themDapAnVaoComboBox()
{
    ui->dapAnDung->clear();

    ui->dapAnDung->addItem("Đáp án đúng: A");
    ui->dapAnDung->addItem("Đáp án đúng: B");
    ui->dapAnDung->addItem("Đáp án đúng: C");
    ui->dapAnDung->addItem("Đáp án đúng: D");

    int itemCount = ui->dapAnDung->count();
    for (int i = 0; i < itemCount; ++i) {
        ui->dapAnDung->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    }
}

void themcauhoi::dsMonHoc(NodeMonHoc* root)
{
    if (root == nullptr) {
        return;
    }

    ui->monHoc->addItem(root->MH.TENMH, QVariant::fromValue(root->MH.MAMH));
    int index = ui->monHoc->count() - 1;
    ui->monHoc->setItemData(index, Qt::AlignCenter, Qt::TextAlignmentRole);

    dsMonHoc(root->left);
    dsMonHoc(root->right);
}

QString themcauhoi::getNoiDung() {
    return ui->noiDung->text();
}

QString themcauhoi::getMonHoc() {
    return ui->monHoc->currentText();
}

QString themcauhoi::getDapAn() {
    return ui->dapAnDung->currentText();
}

QString themcauhoi::getA() {
    return ui->A->text();
}

QString themcauhoi::getB() {
    return ui->B->text();
}

QString themcauhoi::getC() {
    return ui->C->text();
}

QString themcauhoi::getD() {
    return ui->D->text();
}

bool themcauhoi::thongBaoLoi() {
    bool isValid = true;

    // Kiểm tra trường Nội dung
    if (getNoiDung().isEmpty()) {
        ui->loiNoiDung->setText("Nội dung không được để trống");
        ui->loiNoiDung->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->loiNoiDung->clear();
    }

    // Kiểm tra trường Môn học
    if (getMonHoc().isEmpty()) {
        ui->loiMonHoc->setText("Môn học không được để trống");
        ui->loiMonHoc->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->loiMonHoc->clear();
    }

    // Kiểm tra trường Đáp án
    if (getDapAn().isEmpty()) {
        ui->loiDapAn->setText("Đáp án không được để trống");
        ui->loiDapAn->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->loiDapAn->clear();
    }

    // Kiểm tra các đáp án A, B, C, D
    if (getA().isEmpty()) {
        ui->loiA->setText("Đáp án A không được để trống");
        ui->loiA->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->loiA->clear();
    }

    if (getB().isEmpty()) {
        ui->loiB->setText("Đáp án B không được để trống");
        ui->loiB->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->loiB->clear();
    }

    if (getC().isEmpty()) {
        ui->loiC->setText("Đáp án C không được để trống");
        ui->loiC->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->loiC->clear();
    }

    if (getD().isEmpty()) {
        ui->loiD->setText("Đáp án D không được để trống");
        ui->loiD->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->loiD->clear();
    }

    return isValid;
}

void themcauhoi::accept() {
    if (thongBaoLoi()) {
        QDialog::accept();
    }
}

void themcauhoi::randomID(int index)
{
    QString selectedMAMH = ui->monHoc->itemData(index).toString();

    int* idNgauNhien = new int[1000]();

    NodeMonHoc* current = m_root;
    while (current != nullptr) {
        if (current->MH.MAMH == selectedMAMH) {
            CauHoi* cauHoi = current->MH.headCauhoi;
            while (cauHoi != nullptr) {
                // Tăng giá trị trong mảng khi gặp ID đã tồn tại
                if (cauHoi->id >= 0 && cauHoi->id < 1000) {
                    idNgauNhien[cauHoi->id]++;
                }
                cauHoi = cauHoi->next;
            }
            break;
        } else if (selectedMAMH < current->MH.MAMH) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // Sinh số ngẫu nhiên và kiểm tra sự trùng lặp
    srand(time(0));
    int randomId;
    while (true) {
        randomId = rand() % 1000;
        // Nếu ID chưa được sử dụng, thoát khỏi vòng lặp
        if (idNgauNhien[randomId] == 0) {
            break;
        }
    }

    QString result = selectedMAMH + QString::number(randomId);
    ui->idMonHoc->setText(result);
    ui->idMonHoc->setAlignment(Qt::AlignCenter);

    delete[] idNgauNhien;
}

