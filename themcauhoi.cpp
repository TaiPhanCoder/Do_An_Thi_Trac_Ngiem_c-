#include "themcauhoi.h"
#include "ui_themcauhoi.h"
#include "cau_hoi.h"

themcauhoi::themcauhoi(QWidget *parent, NodeMonHoc* root, int* index)
    : QDialog(parent), ui(new Ui::themcauhoi), m_root(root), m_index(index)
{
    ui->setupUi(this);
    this->setWindowTitle("Thêm Câu Hỏi");
    this->setWindowIcon(QIcon(":/logo/ad27bc12ca81e862ceb35328122757ee.ico"));
    themDapAnVaoComboBox();
    connect(ui->monHoc, &QComboBox::currentIndexChanged, this, &themcauhoi::randomID);
    dsMonHoc(m_root);
    if (*m_index != -1) {
        ui->monHoc->setCurrentIndex(*m_index);
    }
}

themcauhoi::~themcauhoi()
{
    delete ui;
}

void themcauhoi::themDapAnVaoComboBox()
{
    ui->dapAnDung->clear();

    ui->dapAnDung->addItem("Đáp án đúng: A", QVariant::fromValue('A'));
    ui->dapAnDung->addItem("Đáp án đúng: B", QVariant::fromValue('B'));
    ui->dapAnDung->addItem("Đáp án đúng: C", QVariant::fromValue('C'));
    ui->dapAnDung->addItem("Đáp án đúng: D", QVariant::fromValue('D'));

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

bool themcauhoi::thongBaoLoi() {
    bool isValid = true;

    // Kiểm tra trường Nội dung
    if (ui->noiDung->text().isEmpty()) {
        ui->loiNoiDung->setText("Nội dung không được để trống");
        ui->loiNoiDung->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->loiNoiDung->clear();
    }

    // Kiểm tra trường Môn học
    if (ui->monHoc->currentText().isEmpty()) {
        ui->loiMonHoc->setText("Môn học không được để trống");
        ui->loiMonHoc->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->loiMonHoc->clear();
    }

    // Kiểm tra trường Đáp án
    if (ui->dapAnDung->currentText().isEmpty()) {
        ui->loiDapAn->setText("Đáp án không được để trống");
        ui->loiDapAn->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->loiDapAn->clear();
    }

    // Kiểm tra các đáp án A, B, C, D
    if (ui->A->text().isEmpty()) {
        ui->loiA->setText("Đáp án A không được để trống");
        ui->loiA->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->loiA->clear();
    }

    if (ui->B->text().isEmpty()) {
        ui->loiB->setText("Đáp án B không được để trống");
        ui->loiB->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->loiB->clear();
    }

    if (ui->C->text().isEmpty()) {
        ui->loiC->setText("Đáp án C không được để trống");
        ui->loiC->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->loiC->clear();
    }

    if (ui->D->text().isEmpty()) {
        ui->loiD->setText("Đáp án D không được để trống");
        ui->loiD->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        isValid = false;
    } else {
        ui->loiD->clear();
    }

    return isValid;
}

void themcauhoi::luuCauHoi() {
    QString noiDung = ui->noiDung->text();
    QString monHoc = ui->monHoc->itemData(ui->monHoc->currentIndex()).toString();
    QChar dapAnDung = ui->dapAnDung->itemData(ui->dapAnDung->currentIndex()).value<QChar>();
    QString a = ui->A->text();
    QString b = ui->B->text();
    QString c = ui->C->text();
    QString d = ui->D->text();

    CauHoi* newCauHoi = taoNodeCauHoi(randomId, noiDung, a, b, c, d, dapAnDung);

    NodeMonHoc* current = m_root;
    while (current != nullptr) {
        if (current->MH.MAMH == monHoc) {
            newCauHoi->next = current->MH.headCauhoi;
            current->MH.headCauhoi = newCauHoi;
            break;
        } else if (monHoc < current->MH.MAMH) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
}

void themcauhoi::accept() {
    if (thongBaoLoi()) {
        luuCauHoi();
        *m_index = ui->monHoc->currentIndex();
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

    srand(time(0));
    while (true) {
        randomId = rand() % 1000;
        if (idNgauNhien[randomId] == 0) {
            break;
        }
    }

    ui->idMonHoc->setText(selectedMAMH + QString::number(randomId));
    ui->idMonHoc->setAlignment(Qt::AlignCenter);

    delete[] idNgauNhien;
}
