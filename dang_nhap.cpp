#include "dang_nhap.h"
#include "./ui_dang_nhap.h"
#include "globals.h"
#include <QFile>
#include <QDialog>
#include "sinhvien.h"
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


void Dang_Nhap::loadSinhVienFromFile(const QString &filename) {
    SinhVien* tail = nullptr;

    QFile file(filename);  // Sử dụng QFile để mở tệp từ resource
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file!";
        return;
    }

    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine();  // Đọc từng dòng
        QStringList fields = line.split('|');  // Tách chuỗi theo dấu '|'

        if (fields.size() == 5) {  // Kiểm tra nếu có đúng 5 trường
            QString masv = fields.at(0);
            QString ho = fields.at(1);
            QString ten = fields.at(2);
            QString phai = fields.at(3);
            QString password = fields.at(4);

            SinhVien* newSV = taoNodeSinhVien(masv, ho, ten, phai, password);

            if (tail == nullptr) {
                headDsachSV = newSV;
                tail = newSV;
            } else {
                tail->next = newSV;
                tail = newSV;
            }
        } else {
            qDebug() << "Invalid line format: " << line;
        }
    }

    file.close();  // Đóng tệp sau khi đọc
}

// void Dang_Nhap::loadSinhVienFromFile(const QString &filename) {
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

//         // Kiểm tra xem đây có phải là dòng lớp học hay không
//         if (line.contains('-')) {  // Giả sử mã lớp chứa dấu '-'
//             QStringList lopFields = line.split('|');
//             if (lopFields.size() == 2) {
//                 QString malop = lopFields.at(0).trimmed();
//                 QString tenlop = lopFields.at(1).trimmed();

//                 // Tạo đối tượng lớp mới
//                 currentLop = new Lop;
//                 currentLop->MALOP = malop;
//                 currentLop->TENLOP = tenlop;
//                 currentLop->DSSV = nullptr; // Chưa có sinh viên trong danh sách

//                 // Thêm lớp mới vào danh sách lớp
//                 if (lopIndex < 10000) {
//                     danhSachLop[lopIndex++] = currentLop;
//                 } else {
//                     qDebug() << "Danh sách lớp đã đầy!";
//                     break;
//                 }

//                 qDebug() << "Mã lớp mới: " << malop << "| Tên lớp: " << tenlop; // Debug thông tin lớp mới
//             } else {
//                 qDebug() << "Invalid class line format: " << line;
//             }
//         } else if (currentLop) {
//             // Đây là dòng sinh viên
//             QStringList fields = line.split('|');
//             if (fields.size() == 5) {
//                 QString masv = fields.at(0).trimmed();
//                 QString ho = fields.at(1).trimmed();
//                 QString ten = fields.at(2).trimmed();
//                 QString phai = fields.at(3).trimmed();
//                 QString password = fields.at(4).trimmed();

//                 // Tạo đối tượng sinh viên mới và thêm vào danh sách sinh viên của lớp hiện tại
//                 SinhVien* newSV = new SinhVien{masv, ho, ten, phai, nullptr};

//                 if (currentLop->DSSV == nullptr) {
//                     currentLop->DSSV = newSV;
//                 } else {
//                     SinhVien* tail = currentLop->DSSV;
//                     while (tail->next) {
//                         tail = tail->next;
//                     }
//                     tail->next = newSV;
//                 }

//                 // Debug thông tin sinh viên
//                 qDebug() << "Mã lớp:" << currentLop->MALOP << "| Mã SV:" << newSV->masv;
//             } else {
//                 qDebug() << "Invalid student line format: " << line;
//             }
//         }
//     }

//     file.close();
// }

void Dang_Nhap::on_DangNhapButton_clicked() {
    QString username = ui->TaiKhoan->text();
    QString password = ui->MatKhau->text();

    loadSinhVienFromFile(":/TK-MK-PTIT/TK-MK.txt");

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
    qDebug() << "Sharingan button clicked!"; // Kiểm tra xem phương thức có được gọi
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

    SinhVien* current = headDsachSV;
    while (current != nullptr) {
        if (current->masv == enteredUsername && current->password == enteredPassword) {
            mainUser.masv = current->masv;
            mainUser.ho = current->ho;
            mainUser.ten = current->ten;
            mainUser.phai = current->phai;
            mainUser.password = current->password;
            mainUser.ds_diemthi = current->ds_diemthi;
            mainUser.next = nullptr;
            return true;
        }
        current = current->next;
    }
    return false;
}

void Dang_Nhap::onTaiKhoanInput(const QString &inputText)
{
    QString updatedText = inputText.toUpper();

    // Đặt lại nội dung vào QLineEdit TaiKhoan
    disconnect(ui->TaiKhoan, &QLineEdit::textEdited, this, &Dang_Nhap::onTaiKhoanInput);
    ui->TaiKhoan->setText(updatedText);
    connect(ui->TaiKhoan, &QLineEdit::textEdited, this, &Dang_Nhap::onTaiKhoanInput);
}

