#include "trac_nghiem.h"
#include "ui_trac_nghiem.h"
#include "globals.h"
#include "cau_hoi.h"
#include "lop.h"
#include "cau_hoi_da_thi.h"
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <QTime>

DaThi* mangDaThi = nullptr;
int cauHienTai = 1;
QTimer *timer;
QTime timeLeft;
CauHoi* cauhoiHienTai = nullptr;

Trac_Nghiem::Trac_Nghiem(SinhVien* user, Lop* danhSachLop[], QWidget* parent)
    : QMainWindow(parent), ui(new Ui::Trac_Nghiem), mainUser(user), danhSachLop(danhSachLop)
{
    mangDaThi = new DaThi[questions];
    cauhoiHienTai = headCauhoi;
    ui->setupUi(this);
    this->setWindowTitle("Thi Trắc Nghiệm - PTIT");
    QPixmap pixmap(":/logo/ad27bc12ca81e862ceb35328122757ee.png");
    ui->ketQuaThi->setVisible(false);
    QTime timeLeft(0, times, 0);
    startCountdown(times);
    setupTracNghiem();
    indsach();
    initializeMangDaThi();
    taoMonHocDangThi(mainUser, maMH, questions);
}

Trac_Nghiem::~Trac_Nghiem()
{
    delete ui;
}

void Trac_Nghiem::setupTracNghiem() {
    // Hiển thị thông tin sinh viên
    ui->MSSV->setText("MSSV: " + mainUser->masv);
    ui->TEN->setText("Tên: " + mainUser->ho + " " + mainUser->ten);

    // Hiển thị thông tin thi
    ui->Questions->setText("Số Câu Hỏi: " + QString::number(questions));
    ui->Times->setText("Số Phút Thi: " + QString::number(times));
    ui->MonHoc->setText("Tên Môn Học: " + monhoc);
    ui->maMH->setText("Mã Môn Học: " + maMH);

    // Cập nhật logo PTIT
    QPixmap pixmap(":/logo/ad27bc12ca81e862ceb35328122757ee.png");
    ui->logo_PTIT->setPixmap(pixmap);
    ui->logo_PTIT->setScaledContents(true);

    // Cập nhật câu hỏi đầu tiên
    ui->cau_hoi->setText("Câu " + QString::number(1) + ": " + headCauhoi->noiDung);
    ui->AQ->setText(headCauhoi->A);
    ui->BQ->setText(headCauhoi->B);
    ui->CQ->setText(headCauhoi->C);
    ui->DQ->setText(headCauhoi->D);

    // Thêm câu hỏi vào danh sách
    for (int var = 1; var <= questions; ++var) {
        ui->listWidget->addItem("Câu hỏi " + QString::number(var) + ": ");
    }

    // Kết nối các sự kiện
    connect(ui->listWidget, &QListWidget::itemClicked, this, &Trac_Nghiem::handleListWidgetClick);

    connect(ui->AQ, &QRadioButton::toggled, this, &Trac_Nghiem::handleAnswerSelection);
    connect(ui->BQ, &QRadioButton::toggled, this, &Trac_Nghiem::handleAnswerSelection);
    connect(ui->CQ, &QRadioButton::toggled, this, &Trac_Nghiem::handleAnswerSelection);
    connect(ui->DQ, &QRadioButton::toggled, this, &Trac_Nghiem::handleAnswerSelection);
}

void Trac_Nghiem::taoMonHocDangThi(SinhVien* sinhVien, const QString& maMH, int questions) {
    if (sinhVien == nullptr) {
        qDebug() << "Sinh viên không hợp lệ!";
        return;
    }
    monHocMoi = newmonHocDaThi(maMH, 0.0f, questions);

    monHocMoi->mangDaThi = mangDaThi;

    themMonHoc(sinhVien->ds_diemthi, monHocMoi);
}


void Trac_Nghiem::startCountdown(int times) {
    timeLeft = QTime(0, times, 0);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Trac_Nghiem::updateTime);

    ui->timerLabel->setAlignment(Qt::AlignCenter);
    ui->timerLabel->setText(timeLeft.toString("mm:ss"));

    timer->start(1000);
}

void Trac_Nghiem::updateTime() {
    // Giảm 1 giây từ thời gian hiện tại
    timeLeft = timeLeft.addSecs(-1);

    ui->timerLabel->setAlignment(Qt::AlignCenter);
    ui->timerLabel->setText(timeLeft.toString("mm:ss"));

    // Kiểm tra nếu thời gian còn lại bằng 00:00
    if (timeLeft == QTime(0, 0, 0)) {
        timer->stop();
    }
}

void Trac_Nghiem::handleAnswerSelection() {
    int index = cauHienTai - 1;

    if (ui->AQ->isChecked()) {
        mangDaThi[index].dapAn = QChar('A');
    } else if (ui->BQ->isChecked()) {
        mangDaThi[index].dapAn = QChar('B');
    } else if (ui->CQ->isChecked()) {
        mangDaThi[index].dapAn = QChar('C');
    } else if (ui->DQ->isChecked()) {
        mangDaThi[index].dapAn = QChar('D');
    } else {
        mangDaThi[index].dapAn = '-';
    }

    qDebug() << "Câu hỏi " << cauHienTai << " đã chọn đáp án: " << mangDaThi[index].dapAn;
}

void Trac_Nghiem::updateRadioButtonState() {
    int index = cauHienTai - 1;

    // Kiểm tra nếu chưa có đáp án, bỏ chọn tất cả các RadioButton
    if (mangDaThi[index].dapAn == '-' || mangDaThi[index].dapAn.isNull()) {
        ui->AQ->setAutoExclusive(false);
        ui->BQ->setAutoExclusive(false);
        ui->CQ->setAutoExclusive(false);
        ui->DQ->setAutoExclusive(false);
        ui->AQ->setChecked(false);
        ui->BQ->setChecked(false);
        ui->CQ->setChecked(false);
        ui->DQ->setChecked(false);
        ui->AQ->setAutoExclusive(true);
        ui->BQ->setAutoExclusive(true);
        ui->CQ->setAutoExclusive(true);
        ui->DQ->setAutoExclusive(true);
    } else {
        // Nếu đã có đáp án trước đó, tự động hiện đáp án đã chọn
        switch (mangDaThi[index].dapAn.toLatin1()) {
        case 'A':
            ui->AQ->setChecked(true);
            break;
        case 'B':
            ui->BQ->setChecked(true);
            break;
        case 'C':
            ui->CQ->setChecked(true);
            break;
        case 'D':
            ui->DQ->setChecked(true);
            break;
        }
    }
}

void Trac_Nghiem::indsach() {
    CauHoi* temp = cauhoiHienTai;
    int stt = 1;
    if(cauhoiHienTai == nullptr){
        qDebug() << "Cau Hoi Hien Tai Rong";
    }
    while (temp != nullptr) {
        qDebug() << "STT: " << stt << " | ID: " << temp->id;
        temp = temp->next;
        stt++;
    }
}

void Trac_Nghiem::initializeMangDaThi() {
    if (headCauhoi == nullptr) {
        qDebug() << "Danh sách câu hỏi trống.";
        return;
    }

    CauHoi* temp = headCauhoi;
    int index = 0;
    while (temp != nullptr && index < questions) {
        mangDaThi[index].id = temp->id;
        mangDaThi[index].dapAn = '-';
        qDebug() << "id: " << mangDaThi[index].id << '\t' << "dapAn: " << mangDaThi[index].dapAn;
        temp = temp->next;
        index++;
    }
}

void next(){
    cauHienTai++;

    cauhoiHienTai = cauhoiHienTai->next;
    qDebug() << cauHienTai;
    qDebug() << headCauhoi->id;
    qDebug() << cauhoiHienTai->id;
}

void prev(){
    cauHienTai--;
    cauhoiHienTai = headCauhoi;
    for (int i = 1; i < cauHienTai; i++) {
        cauhoiHienTai = cauhoiHienTai->next;
    }
    qDebug() << cauHienTai;
    qDebug() << headCauhoi->id;
    qDebug() << cauhoiHienTai->id;
}

void Trac_Nghiem::on_right_arow_clicked()
{
    qDebug() << cauhoiHienTai->noiDung;
    if(cauHienTai < questions){
        next();
        qDebug() << cauhoiHienTai->noiDung;
        ui->cau_hoi->setText("Câu " + QString::number(cauHienTai) + ": " + cauhoiHienTai->noiDung);
        ui->AQ->setText(cauhoiHienTai->A);
        ui->BQ->setText(cauhoiHienTai->B);
        ui->CQ->setText(cauhoiHienTai->C);
        ui->DQ->setText(cauhoiHienTai->D);

        updateRadioButtonState();
    }
}

void Trac_Nghiem::on_left_arow_clicked()
{
    if(cauHienTai>1){
        prev();
        ui->cau_hoi->setText("Câu " + QString::number(cauHienTai) + ": " +cauhoiHienTai->noiDung);
        ui->AQ->setText(cauhoiHienTai->A);
        ui->BQ->setText(cauhoiHienTai->B);
        ui->CQ->setText(cauhoiHienTai->C);
        ui->DQ->setText(cauhoiHienTai->D);

        // Chỉ gọi hàm updateRadioButtonState khi phát hiện đã sang câu khác
        updateRadioButtonState();
    }
}

void cauHoi(){
    cauhoiHienTai = headCauhoi;
    int count = 1;  // Đếm vị trí của node hiện tại
    // Duyệt đến câu hỏi tại vị trí index trong danh sách liên kết head
    while (cauhoiHienTai != nullptr && count < cauHienTai) {
        cauhoiHienTai = cauhoiHienTai->next;
        count++;
    }
}

void Trac_Nghiem::handleListWidgetClick(QListWidgetItem *item)
{
    int row = ui->listWidget->row(item);
    cauHienTai = row + 1;
    cauHoi();
    ui->cau_hoi->setText("Câu " + QString::number(cauHienTai) + ": " + cauhoiHienTai->noiDung);
    ui->AQ->setText(cauhoiHienTai->A);
    ui->BQ->setText(cauhoiHienTai->B);
    ui->CQ->setText(cauhoiHienTai->C);
    ui->DQ->setText(cauhoiHienTai->D);

    updateRadioButtonState();
}

float tinhDiemSinhVien()
{
    int soCauDung = 0;
    CauHoi* current = headCauhoi;
    for (int i = 0; i < questions; ++i) {
        while (current != nullptr) {
            if (current->id == mangDaThi[i].id) {
                if (current->dapAnDung == mangDaThi[i].dapAn) {
                    soCauDung++;
                }
                break;
            }
            current = current->next;
        }
        current = headCauhoi;
    }
    float diem = (static_cast<float>(soCauDung) / questions) * 10;
    return round(diem * 10) / 10;
}

void luuDuLieuMangDaThi(Lop* danhSachLop[])
{
    QFile file("D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/DsachDalLamBai.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Không thể mở file để ghi dữ liệu.";
        return;
    }

    QTextStream out(&file);

    // Ghi số lượng lớp hiện tại
    int soLop = demSoLop(danhSachLop);
    out << soLop << "\n";

    // Vòng lặp ghi thông tin cho từng lớp
    for (int i = 0; i < soLop; ++i) {
        Lop* lop = danhSachLop[i];
        if (lop == nullptr) {
            continue;
        }

        // Ghi thông tin lớp học
        out << lop->MALOP << "|" << lop->TENLOP << "\n";

        // Đếm số sinh viên trong lớp và ghi thông tin
        int soSinhVien = demSVLop(lop);
        out << soSinhVien << "\n";

        // Ghi thông tin của từng sinh viên
        SinhVien* sv = lop->DSSV;
        while (sv != nullptr) {
            out << sv->masv << "|" << sv->ho << "|" << sv->ten << "|" << sv->phai << "|" << sv->password << "\n";

            // Đếm số môn học đã thi và ghi thông tin
            monHocDaThi* diemThi = sv->ds_diemthi;
            int soMonHocDaThi = demSoMonThi(diemThi);
            out << soMonHocDaThi << "\n";

            // Ghi thông tin từng môn học đã thi
            diemThi = sv->ds_diemthi;
            while (diemThi != nullptr) {
                out << diemThi->maMH << "|" << diemThi->diem << "\n";

                // Ghi số lượng câu hỏi đã thi
                int soCauThi = diemThi->soCauThi;
                out << soCauThi << "\n";

                // Ghi danh sách câu hỏi và đáp án của sinh viên
                for (int j = 0; j < soCauThi; ++j) {
                    out << diemThi->mangDaThi[j].id << "|" << diemThi->mangDaThi[j].dapAn << "\n";
                }
                diemThi = diemThi->next;
            }
            sv = sv->next;
        }
    }
    file.close();
    qDebug() << "Dữ liệu đã được lưu thành công.";
}

void Trac_Nghiem::on_NopBai_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Xác nhận", "Bạn có chắc chắn muốn nộp bài?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        float diem =tinhDiemSinhVien();
        monHocMoi->diem = diem;
        luuDuLieuMangDaThi(danhSachLop);
        ketQuaLamBai(diem);
    }
}

void Trac_Nghiem::ketQuaLamBai(const float & diem) {
    ui->grLamBai->setVisible(false);
    ui->grCauHoi->setVisible(false);
    ui->ketQuaThi->setVisible(true);
    ui->mssv->setAlignment(Qt::AlignCenter);
    ui->ten->setAlignment(Qt::AlignCenter);
    ui->diem->setAlignment(Qt::AlignCenter);
    ui->soCauDung->setAlignment(Qt::AlignCenter);
    ui->mamh->setAlignment(Qt::AlignCenter);
    ui->tenMH->setAlignment(Qt::AlignCenter);
    ui->thoiGianLamBai->setAlignment(Qt::AlignCenter);
    ui->mssv->setText("MSSV: " + mainUser->masv);
    ui->ten->setText("Tên: " + mainUser->ho + " " + mainUser->ten);
    ui->diem->setText("Điểm: " + QString::number(diem));
}
