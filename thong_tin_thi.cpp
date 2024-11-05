#include "thong_tin_thi.h"
#include "ui_thong_tin_thi.h"
#include "cau_hoi.h"
#include "globals.h"
#include <QLineEdit>
#include <QCompleter>
#include <QAbstractItemView>
#include "mamh.h"

Thong_Tin_Thi::Thong_Tin_Thi(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Thong_Tin_Thi)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    this->setWindowIcon(QIcon(":/logo/ad27bc12ca81e862ceb35328122757ee.ico"));
    this->setWindowTitle("Thi Trắc Nghiệm - PTIT");

    ui->MSSV->setText("  MSSV: " + mainUser.masv);
    ui->TEN->setText("  Tên: " + mainUser.ho + " " + mainUser.ten);

    ptrMonHoc root = readFileAndBuildAVL();
    QStringList danhSachMonHoc;
    duyetLNR(root, danhSachMonHoc);
    // Cài đặt bộ lọc sự kiện và các mục khác
    ui->DSachMonHoc->addItems(danhSachMonHoc);
    ui->DSachMonHoc->installEventFilter(this);

    // Căn giữa các mục trong danh sách thả xuống
    for (int i = 0; i < ui->DSachMonHoc->count(); ++i) {
        ui->DSachMonHoc->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    }

    completer = new QCompleter(danhSachMonHoc, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setFilterMode(Qt::MatchContains);
    ui->DSachMonHoc->setCompleter(completer);
    ui->DSachMonHoc->setEditable(true);
    ui->DSachMonHoc->completer()->setCompletionMode(QCompleter::PopupCompletion);

    ui->DangNhapButton->setAutoDefault(false);
}

Thong_Tin_Thi::~Thong_Tin_Thi()
{
    delete ui;
    delete completer;
}

bool Thong_Tin_Thi::eventFilter(QObject *obj, QEvent *event) {
    if (obj == ui->DSachMonHoc && event->type() == QEvent::MouseButtonPress) {
        ui->DSachMonHoc->setEditable(true);
        ui->DSachMonHoc->showPopup();
        return true;  // Đã xử lý sự kiện
    }

    return QWidget::eventFilter(obj, event);
}

void Thong_Tin_Thi::on_DangNhapButton_clicked()
{
    bool hasError = false;
    QString MonHoc = ui->DSachMonHoc->currentText();

    if (ui->spinBox->value() == 0) {
        ui->LoiCauHoi->setText("Vui Lòng Nhập Số Câu Hỏi Thi");
        ui->LoiCauHoi->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        hasError = true;
    }
    // else if(ui->spinBox->value() > so_luong_cau_hoi){
    //     ui->LoiCauHoi->setText("Số lượng câu hỏi đề thi: " + QString::number(so_luong_cau_hoi) + ". Vui lòng nhập ít hơn");
    //     ui->LoiCauHoi->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
    //     hasError = true;
    //     }
    else {
        ui->LoiCauHoi->clear();  // Xóa thông báo lỗi nếu không có lỗi
    }

    // Kiểm tra spinBox_2 (Số Phút Thi)
    if (ui->spinBox_2->value() == 0) {
        ui->LoiThoiGian->setText("Vui Lòng Nhập Số Phút Thi");
        ui->LoiThoiGian->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        hasError = true;
    } else {
        ui->LoiThoiGian->clear();  // Xóa thông báo lỗi nếu không có lỗi
    }

    // Kiểm tra DSachMonHoc (QComboBox)
    if (ui->DSachMonHoc->currentIndex() == -1) {
        ui->LoiDSach->setText("Vui lòng chọn Môn Thi");
        ui->LoiDSach->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        hasError = true;
    } else {
        ui->LoiDSach->clear();  // Xóa thông báo lỗi nếu không có lỗi
    }

    if (!hasError) {
        times = ui->spinBox_2->value();
        questions = ui->spinBox->value();
        headCauhoi = docCauHoiTuFile(MonHoc);
        monhoc = MonHoc;
        cauhoiHienTai = headCauhoi;
        // inDanhSachCauHoi(headCauhoi);
        accept();
    }
}
