#ifndef DANG_NHAP_H
#define DANG_NHAP_H

#include <QMainWindow>
#include <QDialog>
#include <QString>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class Dang_Nhap;
}
QT_END_NAMESPACE

class Dang_Nhap : public QDialog
{
    Q_OBJECT

public:
    Dang_Nhap(QWidget *parent = nullptr);  // Constructor
    ~Dang_Nhap();  // Destructor
    bool isGV() const;

private:
    Ui::Dang_Nhap *ui;  // Con trỏ tới giao diện người dùng
    bool checkLogin(const QString &enteredUsername, const QString &enteredPassword);
    bool userIsGV = false;

private slots:
    void loadSinhVienFromFile(const QString &filename);
    void on_sharingan_clicked();
    void onTaiKhoanInput(const QString &inputText);
    void on_DangNhapButton_clicked();
};



#endif // DANG_NHAP_H
