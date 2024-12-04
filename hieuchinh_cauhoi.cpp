#include "hieuchinh_cauhoi.h"
#include "ui_hieuchinh_cauhoi.h"
#include "mamh.h"

hieuchinh_CauHoi::hieuchinh_CauHoi(QWidget *parent, QString mamh, int id, NodeMonHoc* root)
    : QDialog(parent), ui(new Ui::hieuchinh_CauHoi), m_monHoc(mamh), m_id(id), m_root(root)
{
    ui->setupUi(this);
    this->setWindowTitle("Thêm Câu Hỏi");
    dsMonHoc(m_root);
    themDapAnVaoComboBox();
    cauhoi = findCauHoi(m_root, m_monHoc, m_id);
    setupHieuChinh();
}

hieuchinh_CauHoi::~hieuchinh_CauHoi()
{
    delete ui;
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

QString hieuchinh_CauHoi::getNoiDung() {
    return ui->noiDung->text();
}

QString hieuchinh_CauHoi::getMonHoc() {
    return ui->monHoc->currentText();
}

QString hieuchinh_CauHoi::getDapAn() {
    return ui->dapAnDung->currentText();
}

QString hieuchinh_CauHoi::getA() {
    return ui->A->text();
}

QString hieuchinh_CauHoi::getB() {
    return ui->B->text();
}

QString hieuchinh_CauHoi::getC() {
    return ui->C->text();
}

QString hieuchinh_CauHoi::getD() {
    return ui->D->text();
}

bool hieuchinh_CauHoi::thongBaoLoi() {
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

void hieuchinh_CauHoi::accept() {
    if (thongBaoLoi()) {
        QDialog::accept();
    }
}
