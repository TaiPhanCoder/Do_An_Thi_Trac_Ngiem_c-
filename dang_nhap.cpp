#include "dang_nhap.h"
#include "./ui_dang_nhap.h"
#include "globals.h"
#include <QFile>
#include <QDialog>
#include "lop.h"

Dang_Nhap::Dang_Nhap(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dang_Nhap)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    this->setWindowIcon(QIcon(":/logo/ad27bc12ca81e862ceb35328122757ee.ico"));
    this->setWindowTitle("Thi Trắc Nghiệm - PTIT");
    QPixmap pixmap(":/logo/ad27bc12ca81e862ceb35328122757ee.png");  // Đường dẫn tới logo
    QPixmap scaledPixmap = pixmap.scaled(ui->logo->size(), Qt::KeepAspectRatio);  // Thay đổi kích thước logo
    ui->logo->setPixmap(scaledPixmap);
    connect(ui->TaiKhoan, &QLineEdit::textEdited, this, &Dang_Nhap::onTaiKhoanInput);
    ui->MatKhau->setEchoMode(QLineEdit::Password);

    connect(ui->TaiKhoan, &QLineEdit::returnPressed, [=]() {
        ui->MatKhau->setFocus();
    });

    connect(ui->sharingan, &QPushButton::clicked, [=]() {
        on_sharingan_clicked();
    });

    connect(ui->MatKhau, &QLineEdit::returnPressed, this, &Dang_Nhap::on_DangNhapButton_clicked);

    ui->DangNhapButton->setAutoDefault(false);
    connect(ui->DangNhapButton, &QPushButton::clicked, this, &Dang_Nhap::on_DangNhapButton_clicked);
}

Dang_Nhap::~Dang_Nhap()
{
    delete ui;
}

// void Dang_Nhap::lapdssinhvien(const QString &filename) {
//     QFile file(filename);
//     if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//         qDebug() << "Cannot open file!";
//         return;
//     }

//     QTextStream in(&file);
//     Lop* currentLop = nullptr;
//     int lopIndex = 0;

//     while (!in.atEnd()) {
//         QString line = in.readLine().trimmed();

//         if (line.contains('-')) {
//             QStringList lopFields = line.split('|');
//             if (lopFields.size() == 2) {
//                 QString malop = lopFields.at(0).trimmed();
//                 QString tenlop = lopFields.at(1).trimmed();

//                 currentLop = new Lop;
//                 currentLop->MALOP = malop;
//                 currentLop->TENLOP = tenlop;
//                 currentLop->DSSV = nullptr;

//                 if (lopIndex < 10000) {
//                     danhSachLop[lopIndex++] = currentLop;
//                 } else {
//                     qDebug() << "Danh sách lớp đã đầy!";
//                     break;
//                 }          }
//         } else if (currentLop) {
//             QStringList fields = line.split('|');
//             if (fields.size() == 5) {
//                 QString masv = fields.at(0).trimmed();
//                 QString ho = fields.at(1).trimmed();
//                 QString ten = fields.at(2).trimmed();
//                 QString phai = fields.at(3).trimmed();
//                 QString password = fields.at(4).trimmed();

//                 // Tạo đối tượng sinh viên mới và thêm vào danh sách sinh viên của lớp hiện tại
//                 SinhVien* newSV = new SinhVien{masv, ho, ten, phai, password};

//                 if (currentLop->DSSV == nullptr) {
//                     currentLop->DSSV = newSV;
//                 } else {
//                     SinhVien* tail = currentLop->DSSV;
//                     while (tail->next) {
//                         tail = tail->next;
//                     }
//                     tail->next = newSV;
//                 }
//             } else {
//                 qDebug() << "Invalid student line format: " << line;
//             }
//         }
//     }

//     file.close();
// }

void Dang_Nhap::lapdssinhvien(const QString &filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Không thể mở file!";
        return;
    }

    QTextStream in(&file);
    Lop* currentLop = nullptr;
    SinhVien* currentSV = nullptr;
    monHocDaThi* currentMonHoc = nullptr;

    int lopIndex = 0;
    int soLop = in.readLine().toInt();  // Đọc số lượng lớp

    for (int i = 0; i < soLop; ++i) {
        // Đọc thông tin lớp
        QString line = in.readLine().trimmed();
        if (line.contains('|')) {
            QStringList lopFields = line.split('|');
            if (lopFields.size() == 2) {
                currentLop = new Lop;
                currentLop->MALOP = lopFields.at(0).trimmed();
                currentLop->TENLOP = lopFields.at(1).trimmed();
                currentLop->DSSV = nullptr;

                if (lopIndex < 10000) {
                    danhSachLop[lopIndex++] = currentLop;
                } else {
                    qDebug() << "Danh sách lớp đã đầy!";
                    break;
                }
            }
        }

        // Đọc số lượng sinh viên trong lớp
        int soSinhVien = in.readLine().toInt();

        for (int j = 0; j < soSinhVien; ++j) {
            line = in.readLine().trimmed();
            QStringList studentFields = line.split('|');
            if (studentFields.size() == 5) {
                // Đọc thông tin sinh viên
                QString masv = studentFields.at(0).trimmed();
                QString ho = studentFields.at(1).trimmed();
                QString ten = studentFields.at(2).trimmed();
                QString phai = studentFields.at(3).trimmed();
                QString password = studentFields.at(4).trimmed();

                // Tạo đối tượng sinh viên mới và thêm vào danh sách sinh viên của lớp hiện tại
                SinhVien* newSV = new SinhVien{masv, ho, ten, phai, password};
                newSV->next = nullptr;

                if (currentLop->DSSV == nullptr) {
                    currentLop->DSSV = newSV;
                } else {
                    SinhVien* tail = currentLop->DSSV;
                    while (tail->next) {
                        tail = tail->next;
                    }
                    tail->next = newSV;
                }
                currentSV = newSV;

                // Đọc số môn học đã thi
                int soMonHocDaThi = in.readLine().toInt();
                for (int k = 0; k < soMonHocDaThi; ++k) {
                    // Đọc thông tin môn học đã thi
                    line = in.readLine().trimmed();
                    QStringList monHocFields = line.split('|');
                    if (monHocFields.size() == 2) {
                        QString maMH = monHocFields.at(0).trimmed();
                        float diem = monHocFields.at(1).toFloat();

                        // Tạo môn học mới
                        monHocDaThi* newMonHoc = new monHocDaThi;
                        newMonHoc->maMH = maMH;
                        newMonHoc->diem = diem;
                        newMonHoc->mangDaThi = nullptr;
                        newMonHoc->next = nullptr;

                        // Thêm môn học vào danh sách môn học đã thi của sinh viên
                        if (currentSV->ds_diemthi == nullptr) {
                            currentSV->ds_diemthi = newMonHoc;
                        } else {
                            monHocDaThi* tailMonHoc = currentSV->ds_diemthi;
                            while (tailMonHoc->next) {
                                tailMonHoc = tailMonHoc->next;
                            }
                            tailMonHoc->next = newMonHoc;
                        }
                        currentMonHoc = newMonHoc;

                        // Đọc số câu hỏi đã thi
                        int soCauThi = in.readLine().toInt();
                        currentMonHoc->soCauThi = soCauThi;
                        currentMonHoc->mangDaThi = new DaThi[soCauThi];

                        // Đọc các câu hỏi và đáp án
                        for (int m = 0; m < soCauThi; ++m) {
                            line = in.readLine().trimmed();
                            QStringList cauHoiFields = line.split('|');
                            if (cauHoiFields.size() == 2) {
                                int id = cauHoiFields.at(0).toInt();
                                QChar dapAn = cauHoiFields.at(1).trimmed().at(0);  // Giả sử đáp án chỉ có một ký tự

                                currentMonHoc->mangDaThi[m].id = id;
                                currentMonHoc->mangDaThi[m].dapAn = dapAn;
                            }
                        }
                    }
                }
            }
        }
    }

    file.close();
    qDebug() << "Dữ liệu đã được đọc thành công.";
}

void Dang_Nhap::on_DangNhapButton_clicked() {
    QString username = ui->TaiKhoan->text();
    QString password = ui->MatKhau->text();

    lapdssinhvien(":/TK-MK-PTIT/DsachDalLamBai.txt");

    if (checkLogin(username, password)) {
        ui->ThongBao->setText("Đăng nhập thành công!");
        ui->ThongBao->setStyleSheet("QLabel { color : green; }");
        accept();
    } else {
        ui->ThongBao->setText("Sai tài khoản hoặc mật khẩu!");
        ui->ThongBao->setStyleSheet("QLabel { color : red; }");
    }
}

void Dang_Nhap::on_sharingan_clicked()
{
    if(ui->MatKhau->echoMode() == QLineEdit::Password) {
        ui->MatKhau->setEchoMode(QLineEdit::Normal); // Hiển thị mật khẩu
    } else {
        ui->MatKhau->setEchoMode(QLineEdit::Password); // Ẩn mật khẩu
    }
}

bool Dang_Nhap::checkLogin(const QString &enteredUsername, const QString &enteredPassword) {
    if (enteredUsername == "GV" && enteredPassword == "GV") {
        GV = true;
        return true;
    }

    // Duyệt qua mảng lớp
    for (int i = 0; i < 10000; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }
        SinhVien* current = danhSachLop[i]->DSSV;
        // Duyệt qua danh sách sinh viên của lớp hiện tại
        while (current != nullptr) {
            if (current->masv == enteredUsername) {
                if (current->password == enteredPassword) {
                    mainUser = current;
                    return true;
                } else {
                    return false;
                }
            }
            current = current->next;
        }
    }
    return false;
}

void Dang_Nhap::onTaiKhoanInput(const QString &inputText)
{
    QString updatedText = inputText.toUpper();

    disconnect(ui->TaiKhoan, &QLineEdit::textEdited, this, &Dang_Nhap::onTaiKhoanInput);
    ui->TaiKhoan->setText(updatedText);
    connect(ui->TaiKhoan, &QLineEdit::textEdited, this, &Dang_Nhap::onTaiKhoanInput);
}

