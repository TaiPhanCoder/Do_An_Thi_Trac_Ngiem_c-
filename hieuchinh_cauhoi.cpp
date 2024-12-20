#include "hieuchinh_cauhoi.h"
#include "ui_hieuchinh_cauhoi.h"
#include "mamh.h"

hieuchinh_CauHoi::hieuchinh_CauHoi(QWidget *parent, QString mamh, int id, NodeMonHoc* root)
    : QDialog(parent), ui(new Ui::hieuchinh_CauHoi), m_monHoc(mamh), m_id(id), m_root(root)
{
    ui->setupUi(this);
    this->setWindowTitle("Hiệu Chỉnh Câu Hỏi");
    selectedMAMH = m_monHoc;

    dsMonHoc(m_root);
    themDapAnVaoComboBox();
    cauhoi = findCauHoi(m_root, m_monHoc, m_id);
    setupHieuChinh();
    connect(ui->monHoc, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &hieuchinh_CauHoi::randomID);
}

hieuchinh_CauHoi::~hieuchinh_CauHoi()
{
    delete ui;
}

void hieuchinh_CauHoi::randomID(int index)
{
    selectedMAMH = ui->monHoc->itemData(index).toString();

    if (selectedMAMH == m_monHoc) {
        // Set text directly if the selected MAMH matches the current MAMH
        ui->idMonHoc->setText(m_monHoc + QString::number(m_id));
        ui->idMonHoc->setAlignment(Qt::AlignCenter);
        return;
    }

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

void hieuchinh_CauHoi::dsMonHoc(NodeMonHoc* root)
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

void hieuchinh_CauHoi::themDapAnVaoComboBox()
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

void hieuchinh_CauHoi::setupHieuChinh()
{
    QString idCombined = m_monHoc + QString::number(m_id);
    ui->idMonHoc->setText(idCombined);
    ui->idMonHoc->setAlignment(Qt::AlignCenter);
    ui->noiDung->setText(cauhoi->noiDung);
    ui->A->setText(cauhoi->A);
    ui->B->setText(cauhoi->B);
    ui->C->setText(cauhoi->C);
    ui->D->setText(cauhoi->D);

    int indexMonHoc = ui->monHoc->findData(QVariant::fromValue(m_monHoc));
    if (indexMonHoc != -1) {
        ui->monHoc->setCurrentIndex(indexMonHoc);
    }

    setDapAn(cauhoi->dapAnDung);
}

void hieuchinh_CauHoi::setDapAn(QChar dapAn)
{
    switch (dapAn.toLatin1()) {
    case 'A':
        ui->dapAnDung->setCurrentIndex(0);
        break;
    case 'B':
        ui->dapAnDung->setCurrentIndex(1);
        break;
    case 'C':
        ui->dapAnDung->setCurrentIndex(2);
        break;
    case 'D':
        ui->dapAnDung->setCurrentIndex(3);
        break;
    default:
        break;
    }
}

bool hieuchinh_CauHoi::thongBaoLoi() {
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

void hieuchinh_CauHoi::updateCauHoiData(CauHoi* cauhoi) {
    if (cauhoi) {
        cauhoi->noiDung = ui->noiDung->text();
        cauhoi->A = ui->A->text();
        cauhoi->B = ui->B->text();
        cauhoi->C = ui->C->text();
        cauhoi->D = ui->D->text();
        cauhoi->dapAnDung = ui->dapAnDung->currentData().toChar();
    }
}

void hieuchinh_CauHoi::accept() {
    if (thongBaoLoi()) {
        if (selectedMAMH == m_monHoc) {
            // Tìm câu hỏi cũ và cập nhật dữ liệu
            CauHoi* cauhoi = findCauHoi(m_root, selectedMAMH, m_id);
            updateCauHoiData(cauhoi);
        } else {
            // Tìm môn học cũ và xóa câu hỏi khỏi danh sách câu hỏi cũ
            MonHoc* oldMonHoc = SearchMonHoc(m_root, m_monHoc);
            CauHoi* current = oldMonHoc->headCauhoi;
            if (oldMonHoc != nullptr) {
                CauHoi* prev = nullptr;
                while (current != nullptr) {
                    if (current->id == m_id) {
                        if (prev == nullptr) {
                            oldMonHoc->headCauhoi = current->next;
                        } else {
                            prev->next = current->next;
                        }
                        updateCauHoiData(current);
                        break;
                    }
                    prev = current;
                    current = current->next;
                }
            }
            current->id = randomId;
            // Tìm môn học mới và thêm câu hỏi vào đầu danh sách câu hỏi mới
            MonHoc* newMonHoc = SearchMonHoc(m_root, selectedMAMH);
            if (newMonHoc != nullptr) {
                current->next = newMonHoc->headCauhoi;
                newMonHoc->headCauhoi = current;
            }
        }
        QDialog::accept();
    }
}

