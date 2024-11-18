#include "trac_nghiem.h"
#include "ui_trac_nghiem.h"
#include "globals.h"
#include "cau_hoi.h"
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <QTime>

DaThi* mangDaThi = nullptr;
int countcauhoi = 1;
QTimer *timer;
QTime timeLeft;
CauHoi* cauhoiHienTai = nullptr;

Trac_Nghiem::Trac_Nghiem(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Trac_Nghiem)
{
    mangDaThi = new DaThi[questions];
    cauhoiHienTai = headCauhoi;
    ui->setupUi(this);
    this->setWindowTitle("Thi Trắc Nghiệm - PTIT");
    QPixmap pixmap(":/logo/ad27bc12ca81e862ceb35328122757ee.png");
    QTime timeLeft(0, times, 0);
    qDebug() << "Thoi Gian Thi" << times;
    startCountdown(times);
    // initializeMangDaThi();
    ui->MSSV->setText("MSSV: " + mainUser.masv);
    ui->TEN->setText("Tên: " + mainUser.ho + " " + mainUser.ten);
    ui->Questions->setText("Số Câu Hỏi: " + QString::number(questions));
    ui->Times->setText("Số Phút Thi: " + QString::number(times));
    ui->MonHoc->setText("Môn Thi: " + monhoc);
    ui->maMH->setText("Môn Thi: " + maMH);
    ui->logo_PTIT->setPixmap(pixmap);
    ui->logo_PTIT->setScaledContents(true);
    // inDanhSachCauHoi(headCauhoi);
    ui->cau_hoi->setText("Câu " + QString::number(1) +": "+ headCauhoi->noiDung);
    ui->AQ->setText(headCauhoi->A);
    ui->BQ->setText(headCauhoi->B);
    ui->CQ->setText(headCauhoi->C);
    ui->DQ->setText(headCauhoi->D);
    for (int var = 1; var <= questions; ++var) {
        ui->listWidget->addItem("Câu hỏi " + QString::number(var) + ": ");
    }
    connect(ui->listWidget, &QListWidget::itemClicked, this, &Trac_Nghiem::handleListWidgetClick);
    indsach();
    initializeMangDaThi();
    connect(ui->AQ, &QRadioButton::toggled, this, &Trac_Nghiem::handleAnswerSelection);
    connect(ui->BQ, &QRadioButton::toggled, this, &Trac_Nghiem::handleAnswerSelection);
    connect(ui->CQ, &QRadioButton::toggled, this, &Trac_Nghiem::handleAnswerSelection);
    connect(ui->DQ, &QRadioButton::toggled, this, &Trac_Nghiem::handleAnswerSelection);
}

Trac_Nghiem::~Trac_Nghiem()
{
    delete ui;
}

void Trac_Nghiem::startCountdown(int times) {
    timeLeft = QTime(0, times, 0);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Trac_Nghiem::updateTime);

    ui->timerLabel->setAlignment(Qt::AlignCenter);
    ui->timerLabel->setText(timeLeft.toString("mm:ss"));

    // Bắt đầu đếm ngược, mỗi giây một lần
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
    int index = countcauhoi - 1;

    if (ui->AQ->isChecked()) {
        mangDaThi[index].dapAn = QChar('A');
    } else if (ui->BQ->isChecked()) {
        mangDaThi[index].dapAn = QChar('B');
    } else if (ui->CQ->isChecked()) {
        mangDaThi[index].dapAn = QChar('C');
    } else if (ui->DQ->isChecked()) {
        mangDaThi[index].dapAn = QChar('D');
    } else {
        mangDaThi[index].dapAn = QChar();  // Không chọn đáp án nào
    }

    qDebug() << "Câu hỏi " << countcauhoi << " đã chọn đáp án: " << mangDaThi[index].dapAn;
}

void Trac_Nghiem::updateRadioButtonState() {
    int index = countcauhoi - 1;

    // Kiểm tra nếu chưa có đáp án, bỏ chọn tất cả các RadioButton
    if (mangDaThi[index].dapAn.isNull() || mangDaThi[index].dapAn == QChar()) {
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
        mangDaThi[index].dapAn = QChar();  // Khởi tạo giá trị mặc định cho dapAn
        qDebug() << "id: " << mangDaThi[index].id << '\t' << "dapAn: " << mangDaThi[index].dapAn;
        temp = temp->next;
        index++;
    }
}

void next(){
    countcauhoi++;

    cauhoiHienTai = cauhoiHienTai->next;
    qDebug() << countcauhoi;
    qDebug() << headCauhoi->id;
    qDebug() << cauhoiHienTai->id;
}

void prev(){
    countcauhoi--;
    // qDebug() << countcauhoi;
    cauhoiHienTai = headCauhoi;
    for (int i = 1; i < countcauhoi; i++) {
        cauhoiHienTai = cauhoiHienTai->next;
    }
    qDebug() << countcauhoi;
    qDebug() << headCauhoi->id;
    qDebug() << cauhoiHienTai->id;
}

void Trac_Nghiem::on_right_arow_clicked()
{
    qDebug() << cauhoiHienTai->noiDung;
    if(countcauhoi < questions){
        next();
        qDebug() << cauhoiHienTai->noiDung;
        ui->cau_hoi->setText("Câu " + QString::number(countcauhoi) + ": " + cauhoiHienTai->noiDung);
        ui->AQ->setText(cauhoiHienTai->A);
        ui->BQ->setText(cauhoiHienTai->B);
        ui->CQ->setText(cauhoiHienTai->C);
        ui->DQ->setText(cauhoiHienTai->D);

        updateRadioButtonState();
    }
}


void Trac_Nghiem::on_left_arow_clicked()
{
    if(countcauhoi>1){
        prev();
        ui->cau_hoi->setText("Câu " + QString::number(countcauhoi) + ": " +cauhoiHienTai->noiDung);
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
    while (cauhoiHienTai != nullptr && count < countcauhoi) {
        cauhoiHienTai = cauhoiHienTai->next;
        count++;
    }
}

void Trac_Nghiem::handleListWidgetClick(QListWidgetItem *item)
{
    int row = ui->listWidget->row(item);
    countcauhoi = row + 1;
    cauHoi();
    ui->cau_hoi->setText("Câu " + QString::number(countcauhoi) + ": " + cauhoiHienTai->noiDung);
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

void luuDuLieuMangDaThi()
{
    float diem = tinhDiemSinhVien();
    QFile file("C:/1.Code/C++/DO_AN_THI_TRAC_NGHIEM/THI_TRAC_NGHIEM/DsachDalLamBai.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Không thể mở file để ghi dữ liệu.";
        return;
    }

    QTextStream out(&file);

    out << mainUser.masv << "|" << maMH << "|" << questions << "|" << diem << "\n";

    for (int i = 0; i < questions; ++i) {
        out << mangDaThi[i].id << "|";
        if (!mangDaThi[i].dapAn.isNull()) {
            out << mangDaThi[i].dapAn;
        } else {
            out << "NULL";
        }
        if (i < questions - 1) {
            out << "|";
        }
    }
    out << "\n";

    file.close();
    qDebug() << "Dữ liệu đã được lưu thành công.";
}

void Trac_Nghiem::on_NopBai_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Xác nhận", "Bạn có chắc chắn muốn nộp bài?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        luuDuLieuMangDaThi();
    }
}
