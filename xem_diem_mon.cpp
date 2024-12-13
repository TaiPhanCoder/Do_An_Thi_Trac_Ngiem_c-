#include "xem_diem_mon.h"
#include "ui_xem_diem_mon.h"

#include <QVBoxLayout>
#include <QGroupBox>
#include <QRadioButton>

xem_Diem_Mon::xem_Diem_Mon(SinhVien* sinhVien, MonHoc* monHoc, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::xem_Diem_Mon)
    , sinhVien(sinhVien)
    , monHoc(monHoc)
{
    ui->setupUi(this);
    this->setWindowTitle("Xem Điểm");

    diemthi = timMonHocDaThi(sinhVien, monHoc->MAMH);
    setupLables();
    ui->khuVucCauHoi->setWidgetResizable(true);
    taoNoiDungCauHoi();
}

xem_Diem_Mon::~xem_Diem_Mon()
{
    delete ui;
}

monHocDaThi* xem_Diem_Mon::timMonHocDaThi(SinhVien* sinhVien, const QString& maMH) {
    monHocDaThi* current = sinhVien->ds_diemthi;
    while (current != nullptr) {
        if (current->maMH == maMH) {
            return current; // Trả về con trỏ tới môn học đã thi nếu tìm thấy
        }
        current = current->next;
    }
    return nullptr; // Trả về nullptr nếu không tìm thấy môn học
}

void xem_Diem_Mon::taoNoiDungCauHoi() {
    // Tạo nội dung động cho khu vực câu hỏi
    QWidget* scrollContent = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(scrollContent);

    int soCauHoi = diemthi->soCauThi; // Lấy số câu hỏi từ thuộc tính soCauThi của monHocDaThi

    for (int i = 0; i < soCauHoi; ++i) {
        // Tìm id câu hỏi từ mangDaThi của sinh viên
        int cauHoiId = diemthi->mangDaThi[i].id;
        QChar dapAnDaChon = diemthi->mangDaThi[i].dapAn;
        CauHoi* cauHoi = timCauHoi(cauHoiId);

        QString noiDungCauHoi = cauHoi->noiDung;

        QGroupBox* groupBox = new QGroupBox();
        QVBoxLayout* questionLayout = new QVBoxLayout(groupBox);

        QLabel* noiDungLabel = new QLabel(QString("Câu hỏi %1: %2").arg(i + 1).arg(noiDungCauHoi));
        questionLayout->addWidget(noiDungLabel);

        QRadioButton* optionA = new QRadioButton("A. " + cauHoi->A);
        QRadioButton* optionB = new QRadioButton("B. " + cauHoi->B);
        QRadioButton* optionC = new QRadioButton("C. " + cauHoi->C);
        QRadioButton* optionD = new QRadioButton("D. " + cauHoi->D);

        if (dapAnDaChon == 'A') optionA->setChecked(true);
        else if (dapAnDaChon == 'B') optionB->setChecked(true);
        else if (dapAnDaChon == 'C') optionC->setChecked(true);
        else if (dapAnDaChon == 'D') optionD->setChecked(true);

        // Xác định đáp án đúng và tô màu
        if (cauHoi->dapAnDung == 'A') optionA->setStyleSheet("color: green; font-weight: bold;");
        if (cauHoi->dapAnDung == 'B') optionB->setStyleSheet("color: green; font-weight: bold;");
        if (cauHoi->dapAnDung == 'C') optionC->setStyleSheet("color: green; font-weight: bold;");
        if (cauHoi->dapAnDung == 'D') optionD->setStyleSheet("color: green; font-weight: bold;");

        if (dapAnDaChon != cauHoi->dapAnDung) {
            if (dapAnDaChon == 'A') optionA->setStyleSheet("color: red; font-weight: bold;");
            else if (dapAnDaChon == 'B') optionB->setStyleSheet("color: red; font-weight: bold;");
            else if (dapAnDaChon == 'C') optionC->setStyleSheet("color: red; font-weight: bold;");
            else if (dapAnDaChon == 'D') optionD->setStyleSheet("color: red; font-weight: bold;");
        }

        // Hiển thị nhắn *Chưa chọn đáp án* đỏ nếu người dùng chưa chọn đáp án
        if (dapAnDaChon != 'A' && dapAnDaChon != 'B' && dapAnDaChon != 'C' && dapAnDaChon != 'D') {
            QLabel* chuaChonLabel = new QLabel("*Chưa chọn đáp án");
            chuaChonLabel->setStyleSheet("color: red; font-weight: bold;");
            questionLayout->addWidget(chuaChonLabel);
        }

        // Không cho phép chọn nhưng không bị mờ
        optionA->setAttribute(Qt::WA_TransparentForMouseEvents);
        optionB->setAttribute(Qt::WA_TransparentForMouseEvents);
        optionC->setAttribute(Qt::WA_TransparentForMouseEvents);
        optionD->setAttribute(Qt::WA_TransparentForMouseEvents);

        questionLayout->addWidget(optionA);
        questionLayout->addWidget(optionB);
        questionLayout->addWidget(optionC);
        questionLayout->addWidget(optionD);

        layout->addWidget(groupBox);
    }

    // Đặt layout cho widget cuộn
    scrollContent->setLayout(layout);
    ui->khuVucCauHoi->setWidget(scrollContent);
}

CauHoi* xem_Diem_Mon::timCauHoi(int id) {
    if (monHoc == nullptr || monHoc->headCauhoi == nullptr) {
        return nullptr;
    }

    CauHoi* current = monHoc->headCauhoi;
    while (current != nullptr) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }

    return nullptr;
}

void xem_Diem_Mon::setupLables() {
    // Ghi thông tin sinh viên lên các label và căn giữa
    ui->ten->setText("Tên: " + sinhVien->ho + " " + sinhVien->ten);
    ui->ten->setAlignment(Qt::AlignCenter);

    ui->mssv->setText("MSSV: " + sinhVien->masv);
    ui->mssv->setAlignment(Qt::AlignCenter);

    // Ghi thông tin môn học lên các label và căn giữa
    ui->maMH->setText("Mã MH: " + monHoc->MAMH);
    ui->maMH->setAlignment(Qt::AlignCenter);

    // Cắt bớt nội dung nếu quá dài và thêm "..."
    QString elidedMaMH = ui->maMH->fontMetrics().elidedText(ui->maMH->text(), Qt::ElideRight, ui->maMH->width());
    ui->maMH->setText(elidedMaMH);

    ui->tenMH->setText("Tên MH: " + monHoc->TENMH);
    ui->tenMH->setAlignment(Qt::AlignCenter);

    // Cắt bớt nội dung nếu quá dài và thêm "..."
    QString elidedTenMH = ui->tenMH->fontMetrics().elidedText(ui->tenMH->text(), Qt::ElideRight, ui->tenMH->width());
    ui->tenMH->setText(elidedTenMH);

    ui->diem->setText("<b>Điểm: " + QString::number(diemthi->diem) + "</b>");
    ui->diem->setAlignment(Qt::AlignCenter);
}

