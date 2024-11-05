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

void Dang_Nhap::lapdssinhvien(const QString &filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file!";
        return;
    }

    QTextStream in(&file);
    Lop* currentLop = nullptr;
    int lopIndex = 0;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();

        if (line.contains('-')) {
            QStringList lopFields = line.split('|');
            if (lopFields.size() == 2) {
                QString malop = lopFields.at(0).trimmed();
                QString tenlop = lopFields.at(1).trimmed();

                currentLop = new Lop;
                currentLop->MALOP = malop;
                currentLop->TENLOP = tenlop;
                currentLop->DSSV = nullptr;

                if (lopIndex < 10000) {
                    danhSachLop[lopIndex++] = currentLop;
                } else {
                    qDebug() << "Danh sách lớp đã đầy!";
                    break;
                }          }
        } else if (currentLop) {
            QStringList fields = line.split('|');
            if (fields.size() == 5) {
                QString masv = fields.at(0).trimmed();
                QString ho = fields.at(1).trimmed();
                QString ten = fields.at(2).trimmed();
                QString phai = fields.at(3).trimmed();
                QString password = fields.at(4).trimmed();

                // Tạo đối tượng sinh viên mới và thêm vào danh sách sinh viên của lớp hiện tại
                SinhVien* newSV = new SinhVien{masv, ho, ten, phai, password};

                if (currentLop->DSSV == nullptr) {
                    currentLop->DSSV = newSV;
                } else {
                    SinhVien* tail = currentLop->DSSV;
                    while (tail->next) {
                        tail = tail->next;
                    }
                    tail->next = newSV;
                }

                qDebug() << "Mã lớp:" << currentLop->MALOP << "| Mã SV:" << newSV->masv;
            } else {
                qDebug() << "Invalid student line format: " << line;
            }
        }
    }

    file.close();
}

void Dang_Nhap::on_DangNhapButton_clicked() {
    QString username = ui->TaiKhoan->text();
    QString password = ui->MatKhau->text();

    lapdssinhvien(":/TK-MK-PTIT/TK-MK.txt");

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

    // Duyệt qua mảng lớp
    for (int i = 0; i < 10000; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }
        SinhVien* current = danhSachLop[i]->DSSV;
        // Duyệt qua danh sách sinh viên của lớp hiện tại
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

