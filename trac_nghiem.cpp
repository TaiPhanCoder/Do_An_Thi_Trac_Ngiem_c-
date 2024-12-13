#include "trac_nghiem.h"
#include "ui_trac_nghiem.h"
#include "cau_hoi.h"
#include "lop.h"
#include "cau_hoi_da_thi.h"
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <QTime>

Trac_Nghiem::Trac_Nghiem(SinhVien* mainUser, Lop* danhSachLop[], int times, int questions,
                         const QString &monhoc, const QString &maMH, CauHoi* headCauhoi, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Trac_Nghiem), mainUser(mainUser), danhSachLop(danhSachLop),
    times(times), questions(questions), monhoc(monhoc), maMH(maMH), headCauhoi(headCauhoi)
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
    capNhatCauHoiUI();

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
    totalSeconds = times * 60;  // Chuyển đổi thời gian từ phút sang giây
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Trac_Nghiem::updateTime);

    ui->timerLabel->setAlignment(Qt::AlignCenter);
    updateTimerDisplay();  // Cập nhật thời gian hiển thị ban đầu

    timer->start(1000);  // Mỗi giây gọi updateTime()
}

void Trac_Nghiem::updateTimerDisplay() {
    int hours = totalSeconds / 3600;
    int minutes = (totalSeconds % 3600) / 60;
    int seconds = totalSeconds % 60;

    ui->timerLabel->setText(QString("%1:%2:%3")
                                .arg(hours, 2, 10, QChar('0'))
                                .arg(minutes, 2, 10, QChar('0'))
                                .arg(seconds, 2, 10, QChar('0')));
}

void Trac_Nghiem::updateTime() {
    // Nếu thời gian còn lại là 0, dừng bộ đếm và tự động nộp bài
    if (totalSeconds <= 0) {
        timer->stop();  // Dừng bộ đếm

        // Hiển thị kết quả bài thi
        ketQuaLamBai();

        return;  // Kết thúc hàm để không giảm tiếp
    }

    // Giảm 1 giây từ tổng số giây
    totalSeconds--;

    // Cập nhật thời gian hiển thị
    updateTimerDisplay();
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

void Trac_Nghiem::next(){
    cauHienTai++;

    cauhoiHienTai = cauhoiHienTai->next;
    qDebug() << cauHienTai;
    qDebug() << cauhoiHienTai->id;
}

void Trac_Nghiem::prev(){
    cauHienTai--;
    cauhoiHienTai = headCauhoi;
    for (int i = 1; i < cauHienTai; i++) {
        cauhoiHienTai = cauhoiHienTai->next;
    }
    qDebug() << cauHienTai;
    qDebug() << headCauhoi->id;
    qDebug() << cauhoiHienTai->id;
}

void Trac_Nghiem::capNhatCauHoiUI()
{
    QString noiDung = "Câu " + QString::number(cauHienTai) + ": " + cauhoiHienTai->noiDung;
    QFontMetrics metrics(ui->cau_hoi->font());
    int maxWidth = ui->cau_hoi->width();
    QString wrappedText = metrics.elidedText(noiDung, Qt::ElideRight, maxWidth);
    ui->cau_hoi->setText(wrappedText);

    ui->AQ->setText(cauhoiHienTai->A);
    ui->BQ->setText(cauhoiHienTai->B);
    ui->CQ->setText(cauhoiHienTai->C);
    ui->DQ->setText(cauhoiHienTai->D);
}


void Trac_Nghiem::on_right_arow_clicked()
{
    qDebug() << cauhoiHienTai->noiDung;
    if(cauHienTai < questions) {
        next();
        qDebug() << cauhoiHienTai->noiDung;
        capNhatCauHoiUI();
        updateRadioButtonState();
    }
}


void Trac_Nghiem::on_left_arow_clicked()
{
    if(cauHienTai > 1) {
        prev();
        capNhatCauHoiUI();

        // Chỉ gọi hàm updateRadioButtonState khi phát hiện đã sang câu khác
        updateRadioButtonState();
    }
}

void Trac_Nghiem::cauHoi(){
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
    capNhatCauHoiUI();
    updateRadioButtonState();
}

void Trac_Nghiem::luuDuLieuMangDaThi(Lop* danhSachLop[])
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

float Trac_Nghiem::tinhDiemSinhVien(int& soCauDung)
{
    soCauDung = 0;
    for (int i = 0; i < questions; ++i) {
        CauHoi* current = headCauhoi;
        while (current != nullptr) {
            if (current->id == mangDaThi[i].id) {
                if (current->dapAnDung == mangDaThi[i].dapAn) {
                    soCauDung++;
                }
                break;
            }
            current = current->next;
        }
    }

    float diem = (static_cast<float>(soCauDung) / questions) * 10;
    return round(diem * 10) / 10;
}

void Trac_Nghiem::on_NopBai_clicked()
{
    // Hiển thị hộp thoại xác nhận
    QMessageBox::StandardButton reply = QMessageBox::question(
        this,
        "Xác nhận",
        "Bạn có chắc chắn muốn nộp bài?",
        QMessageBox::Yes | QMessageBox::No
        );

    // Nếu người dùng chọn "Yes", thực hiện nộp bài
    if (reply == QMessageBox::Yes) {
        // Dừng bộ đếm thời gian
        if (timer && timer->isActive()) {
            timer->stop();
        }

        ketQuaLamBai();
    }
}

void Trac_Nghiem::ketQuaLamBai() {
    // Tính điểm của sinh viên
    int soCauDung = 0;
    float diem = tinhDiemSinhVien(soCauDung);
    monHocMoi->diem = diem;

    // Lưu kết quả vào danh sách đã thi
    luuDuLieuMangDaThi(danhSachLop);

    ui->grLamBai->setVisible(false);
    ui->grCauHoi->setVisible(false);
    ui->ketQuaThi->setVisible(true);

    // Căn giữa nội dung các label
    ui->mssv->setAlignment(Qt::AlignCenter);
    ui->ten->setAlignment(Qt::AlignCenter);
    ui->diem->setAlignment(Qt::AlignCenter);
    ui->soCauDung->setAlignment(Qt::AlignCenter);
    ui->mamh->setAlignment(Qt::AlignCenter);
    ui->tenMH->setAlignment(Qt::AlignCenter);
    ui->thoiGianLamBai->setAlignment(Qt::AlignCenter);

    // Cập nhật thông tin
    ui->mssv->setText("MSSV: " + mainUser->masv);
    ui->ten->setText("Tên: " + mainUser->ho + " " + mainUser->ten);

    ui->diem->setText("Điểm: " + QString::number(diem));

    // Số câu trả lời đúng
    ui->soCauDung->setText("Số câu đúng: " + QString::number(soCauDung) + "/" + QString::number(questions));

    // Cập nhật mã môn học và tên môn học
    ui->mamh->setText("Mã môn học: " + maMH);
    ui->tenMH->setText("Tên môn học: " + monhoc);

    int timeSpent = times * 60 - totalSeconds;  // Tổng thời gian đã dùng
    int hours = timeSpent / 3600;
    int minutes = (timeSpent % 3600) / 60;
    int seconds = timeSpent % 60;
    ui->thoiGianLamBai->setText(QString("Thời gian làm bài: %1:%2:%3")
                                    .arg(hours, 2, 10, QChar('0'))
                                    .arg(minutes, 2, 10, QChar('0'))
                                    .arg(seconds, 2, 10, QChar('0')));
}

