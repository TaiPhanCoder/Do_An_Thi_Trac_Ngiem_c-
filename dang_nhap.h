#ifndef DANG_NHAP_H
#define DANG_NHAP_H

#include <QDialog>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dang_Nhap;
}
QT_END_NAMESPACE

class Dang_Nhap : public QDialog
{
    Q_OBJECT

public:
    explicit Dang_Nhap(QWidget *parent = nullptr);
    ~Dang_Nhap();
    bool isGV() const;

private:
    Ui::Dang_Nhap *ui;
    bool userIsGV = false;

    void setupWindowProperties();
    void setupLogo();
    void setupLineEditConnections();
    void setupButtonConnections();
    bool checkLogin(const QString &enteredUsername, const QString &enteredPassword);

private slots:
    void lapdssinhvien(const QString &filename);
    void on_sharingan_clicked();
    void onTaiKhoanInput(const QString &inputText);
    void on_DangNhapButton_clicked();
};

#endif // DANG_NHAP_H
