#include "dang_nhap.h"
#include "./ui_dang_nhap.h"
#include <QFile>
#include <QDialog>

Dang_Nhap::Dang_Nhap(SinhVien*& user, Lop* danhSachLop[], QWidget* parent)
    : QDialog(parent), ui(new Ui::Dang_Nhap), mainUser(user), danhSachLop(danhSachLop)
{
    ui->setupUi(this);
    setupWindowProperties();
    setupLogo();
    setupLineEditConnections();
    setupButtonConnections();
}

Dang_Nhap::~Dang_Nhap()
{
    delete ui;
}

// Thiết lập logo trên cửa sổ
void Dang_Nhap::setupLogo() {
    QPixmap pixmap(":/logo/ad27bc12ca81e862ceb35328122757ee.png");
    QPixmap scaledPixmap = pixmap.scaled(ui->logo->size(), Qt::KeepAspectRatio);
    ui->logo->setPixmap(scaledPixmap);
}

// Cài đặt các thuộc tính của cửa sổ (tiêu đề, icon, kiểu cửa sổ)
void Dang_Nhap::setupWindowProperties() {
    this->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    this->setWindowIcon(QIcon(":/logo/ad27bc12ca81e862ceb35328122757ee.ico"));
    this->setWindowTitle("Thi Trắc Nghiệm - PTIT");
}

// Kết nối các tín hiệu liên quan đến ô nhập liệu (LineEdit)
void Dang_Nhap::setupLineEditConnections() {
    connect(ui->TaiKhoan, &QLineEdit::textEdited, this, &Dang_Nhap::onTaiKhoanInput);
    ui->MatKhau->setEchoMode(QLineEdit::Password);  // Ẩn mật khẩu

    // Chuyển focus sang ô mật khẩu khi nhấn Enter
    connect(ui->TaiKhoan, &QLineEdit::returnPressed, this, [=]() {
        ui->MatKhau->setFocus();
    });

    // Gửi sự kiện nhấn nút đăng nhập khi nhấn Enter ở ô mật khẩu
    connect(ui->MatKhau, &QLineEdit::returnPressed, this, &Dang_Nhap::on_DangNhapButton_clicked);
}

// Kết nối các tín hiệu liên quan đến các nút bấm (Button)
void Dang_Nhap::setupButtonConnections() {
    ui->DangNhapButton->setAutoDefault(false);  // Ngăn tự động focus vào nút
    ui->sharingan->setAutoDefault(false);
}

void Dang_Nhap::on_sharingan_clicked()
{
    if (ui->MatKhau->echoMode() == QLineEdit::Password) {
        ui->MatKhau->setEchoMode(QLineEdit::Normal);
        qDebug() << "Chuyen sang che do hien thi mat khau.";
    } else {
        ui->MatKhau->setEchoMode(QLineEdit::Password);
        qDebug() << "Chuyen sang che do an mat khau.";
    }
}

bool Dang_Nhap::checkLogin(const QString &enteredUsername, const QString &enteredPassword) {
    if (enteredPassword == "GV") {
        return true;
    }

    // Duyệt qua mảng lớp
    for (int i = 0; i < MAX; ++i) {
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
    // Loại bỏ ký tự không phải chữ hoặc số
    QString filteredText;
    for (const QChar &ch : inputText) {
        if (ch.isLetterOrNumber()) {
            filteredText.append(ch.toUpper());
        }
    }

    // Chỉ cập nhật text nếu có thay đổi
    if (ui->TaiKhoan->text() != filteredText) {
        disconnect(ui->TaiKhoan, &QLineEdit::textEdited, this, &Dang_Nhap::onTaiKhoanInput);
        ui->TaiKhoan->setText(filteredText);
        connect(ui->TaiKhoan, &QLineEdit::textEdited, this, &Dang_Nhap::onTaiKhoanInput);
    }
}


void Dang_Nhap::on_DangNhapButton_clicked() {
    QString username = ui->TaiKhoan->text();
    QString password = ui->MatKhau->text();

    if (checkLogin(username, password)) {
        ui->ThongBao->setText("Đăng nhập thành công!");
        ui->ThongBao->setStyleSheet("QLabel { color : green; }");
        accept();
    } else {
        ui->ThongBao->setText("Sai tài khoản hoặc mật khẩu!");
        ui->ThongBao->setStyleSheet("QLabel { color : red; }");
    }
}
