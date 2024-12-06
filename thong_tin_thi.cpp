#include "thong_tin_thi.h"
#include "ui_thong_tin_thi.h"
#include "cau_hoi.h"
#include <QLineEdit>
#include <QCompleter>
#include <QAbstractItemView>
#include "mamh.h"

Thong_Tin_Thi::Thong_Tin_Thi(SinhVien* user, Lop* danhSachLop[], QWidget* parent)
    : QDialog(parent) , mainUser(user), danhSachLop(danhSachLop)
    , ui(new Ui::Thong_Tin_Thi)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    this->setWindowIcon(QIcon(":/logo/ad27bc12ca81e862ceb35328122757ee.ico"));
    this->setWindowTitle("Thi Trắc Nghiệm - PTIT");

    ui->MSSV->setText("  MSSV: " + mainUser->masv);
    ui->TEN->setText("  Tên: " + mainUser->ho + " " + mainUser->ten);

    ptrMonHoc root = readFileAndBuildAVL();
    setUpDSMonHoc(root);
    ui->DSachMonHoc->installEventFilter(this);

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

void Thong_Tin_Thi::setUpDSMonHoc(NodeMonHoc* root){
    if (root == nullptr) {
        return;
    }

    ui->DSachMonHoc->addItem(root->MH.TENMH, QVariant::fromValue(root->MH.MAMH));

    int index = ui->DSachMonHoc->count() - 1;
    ui->DSachMonHoc->setItemData(index, Qt::AlignCenter, Qt::TextAlignmentRole);

    setUpDSMonHoc(root->left);

    setUpDSMonHoc(root->right);
}

bool Thong_Tin_Thi::eventFilter(QObject *obj, QEvent *event) {
    if (obj == ui->DSachMonHoc && event->type() == QEvent::MouseButtonPress) {
        ui->DSachMonHoc->setEditable(true);
        ui->DSachMonHoc->showPopup();
        return true;  // Đã xử lý sự kiện
    }

    return QWidget::eventFilter(obj, event);
}

int Thong_Tin_Thi::getTime() const {
    return ui->spinBox_2->value(); // Lấy giá trị từ spinBox_2
}

int Thong_Tin_Thi::getQuestions() const {
    return ui->spinBox->value(); // Lấy giá trị từ spinBox
}

QString Thong_Tin_Thi::getMonHoc() const {
    return ui->DSachMonHoc->currentText(); // Lấy tên môn học từ combobox
}

QString Thong_Tin_Thi::getMaMH() const {
    return ui->DSachMonHoc->currentData().toString(); // Lấy mã môn học từ dữ liệu combobox
}


void Thong_Tin_Thi::on_DangNhapButton_clicked()
{
    bool hasError = false;
    QString MonHoc = ui->DSachMonHoc->currentText();
    int soCauHoi = 0;
    CauHoi** mangCauHoi= loadCauHoiThi(MonHoc,questions,soCauHoi);
    if (ui->spinBox->value() == 0) {
        ui->LoiCauHoi->setText("Vui Lòng Nhập Số Câu Hỏi Thi");
        ui->LoiCauHoi->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        hasError = true;
    }
    else if(ui->spinBox->value() > soCauHoi){
        ui->LoiCauHoi->setText("Số lượng câu hỏi đề thi: " + QString::number(soCauHoi) + ". Vui lòng nhập ít hơn");
        ui->LoiCauHoi->setStyleSheet("QLabel { color : red; qproperty-alignment: 'AlignCenter'; }");
        hasError = true;
        }
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
        shuffleArray(mangCauHoi,questions);
        headCauhoi = DsachCauHoiThi(mangCauHoi,questions);
        accept();
    }
}
