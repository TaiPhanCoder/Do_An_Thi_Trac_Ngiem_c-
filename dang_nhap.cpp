#include "dang_nhap.h"
#include "./ui_dang_nhap.h"
#include "globals.h"
#include <QFile>
#include <QDialog>

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

SinhVien* taoNodeSinhVien(QString masv, QString ho, QString ten, QString phai, QString password) {
    SinhVien* sv = new SinhVien;
    sv->masv = masv;
    sv->ho = ho;
    sv->ten = ten;
    sv->phai = phai;
    sv->password = password;
    sv->ds_diemthi = nullptr;
    sv->next = nullptr;
    return sv;
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
    // Chỉnh sửa nội dung inputText theo yêu cầu của bạn
    QString updatedText = inputText.toUpper(); // Ví dụ: chuyển thành chữ hoa

    // Đặt lại nội dung vào QLineEdit TaiKhoan
    disconnect(ui->TaiKhoan, &QLineEdit::textEdited, this, &Dang_Nhap::onTaiKhoanInput); // Tạm thời ngắt kết nối để tránh gọi lại sự kiện
    ui->TaiKhoan->setText(updatedText);
    connect(ui->TaiKhoan, &QLineEdit::textEdited, this, &Dang_Nhap::onTaiKhoanInput); // Kết nối lại sau khi cập nhật
}

