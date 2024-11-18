#ifndef TRAC_NGHIEM_H
#define TRAC_NGHIEM_H
#include "cau_hoi.h"
#include <QListWidgetItem>

#include <QMainWindow>

namespace Ui {
class Trac_Nghiem;
}

class Trac_Nghiem : public QMainWindow
{
    Q_OBJECT

public:
    explicit Trac_Nghiem(QWidget *parent = nullptr);
    ~Trac_Nghiem();

private slots:
    void on_right_arow_clicked();
    void startCountdown(int times);
    void updateTime();
    void on_left_arow_clicked();
    void indsach();
    void handleListWidgetClick(QListWidgetItem *item);
    void initializeMangDaThi();
    void handleAnswerSelection();
    void updateRadioButtonState();

    void on_NopBai_clicked();

private:
    Ui::Trac_Nghiem *ui;
};

    extern int countcauhoi;

#endif // TRAC_NGHIEM_H
