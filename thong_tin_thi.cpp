#include "thong_tin_thi.h"
#include "ui_thong_tin_thi.h"
#include "cau_hoi.h"
#include <QLineEdit>
#include <QCompleter>
#include <QAbstractItemView>
#include "mamh.h"
#include "xemdiem.h"

// Constructor
Thong_Tin_Thi::Thong_Tin_Thi(SinhVien* mainUser, CauHoi*& danhSachCauHoi, QWidget* parent)
    : QDialog(parent), ui(new Ui::Thong_Tin_Thi), mainUser(mainUser), danhSachCauHoi(danhSachCauHoi)
{
    ui->setupUi(this);
    setupUI();
    setupCompleter();

    // Đọc danh sách môn học và thêm vào combo box
    root = readFileAndBuildAVL();
    setupDSMonHoc(root);
}

// Destructor
Thong_Tin_Thi::~Thong_Tin_Thi()
{
    delete ui;
    delete completer;
}

// Thiết lập giao diện người dùng
void Thong_Tin_Thi::setupUI()
{
    this->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    this->setWindowIcon(QIcon(":/logo/ad27bc12ca81e862ceb35328122757ee.ico"));
    this->setWindowTitle("Thi Trắc Nghiệm - PTIT");

    // Hiển thị thông tin sinh viên
    ui->MSSV->setText("  MSSV: " + mainUser->masv);
    ui->TEN->setText("  Tên: " + mainUser->ho + " " + mainUser->ten);

    ui->DangNhapButton->setAutoDefault(false);
    ui->DSachMonHoc->installEventFilter(this); // Lọc sự kiện cho combo box
}

// Thiết lập completer cho gợi ý tìm kiếm
void Thong_Tin_Thi::setupCompleter()
{
    completer = new QCompleter(danhSachMonHoc, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setFilterMode(Qt::MatchContains);
    ui->DSachMonHoc->setCompleter(completer);
    ui->DSachMonHoc->setEditable(true);
    ui->DSachMonHoc->completer()->setCompletionMode(QCompleter::PopupCompletion);
}

// Thêm danh sách môn học vào combo box
void Thong_Tin_Thi::setupDSMonHoc(NodeMonHoc* root)
{
    if (!root) return;

    // Duyệt cây AVL và thêm môn học vào combobox
    if (!isMonHocDaThi(root->MH.MAMH)) {
        ui->DSachMonHoc->addItem(root->MH.TENMH, QVariant::fromValue(root->MH.MAMH));
        int index = ui->DSachMonHoc->count() - 1;
        ui->DSachMonHoc->setItemData(index, Qt::AlignCenter, Qt::TextAlignmentRole);
    }
    setupDSMonHoc(root->left);
    setupDSMonHoc(root->right);
}

// Kiểm tra mã môn học đã thi
bool Thong_Tin_Thi::isMonHocDaThi(const QString& maMH)
{
    monHocDaThi* current = mainUser->ds_diemthi;
    while (current) {
        if (current->maMH == maMH) return true; // Đã thi
        current = current->next;
    }
    return false; // Chưa thi
}

// Event filter để mở combobox khi nhấn chuột
bool Thong_Tin_Thi::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->DSachMonHoc && event->type() == QEvent::MouseButtonPress) {
        ui->DSachMonHoc->showPopup();
        return true; // Đã xử lý
    }
    return QDialog::eventFilter(obj, event);
}

// Getter cho thông tin bài thi
int Thong_Tin_Thi::getTime() const { return ui->spinBox_2->value(); }
int Thong_Tin_Thi::getQuestions() const { return ui->spinBox->value(); }
QString Thong_Tin_Thi::getMonHoc() const { return ui->DSachMonHoc->currentText(); }
QString Thong_Tin_Thi::getMaMH() const { return ui->DSachMonHoc->currentData().toString(); }

// Xử lý nút bắt đầu bài thi
void Thong_Tin_Thi::on_DangNhapButton_clicked()
{
    bool hasError = false;
    QString MonHoc = ui->DSachMonHoc->currentText();
    int soCauHoi = 0;

    questions = ui->spinBox->value();
    CauHoi** mangCauHoi = loadCauHoiThi(MonHoc, questions, soCauHoi);

    // Kiểm tra lỗi
    if (questions == 0) {
        ui->LoiCauHoi->setText("Vui Lòng Nhập Số Câu Hỏi Thi");
        ui->LoiCauHoi->setStyleSheet("QLabel { color : red; }");
        hasError = true;
    } else if (questions > soCauHoi) {
        ui->LoiCauHoi->setText("Số câu hỏi tối đa: " + QString::number(soCauHoi));
        ui->LoiCauHoi->setStyleSheet("QLabel { color : red; }");
        hasError = true;
    }

    if (ui->spinBox_2->value() == 0) {
        ui->LoiThoiGian->setText("Vui Lòng Nhập Số Phút Thi");
        ui->LoiThoiGian->setStyleSheet("QLabel { color : red; }");
        hasError = true;
    }

    if (!hasError) {
        shuffleArray(mangCauHoi, questions);
        danhSachCauHoi = DsachCauHoiThi(mangCauHoi, questions);
        accept();
    }
}

void Thong_Tin_Thi::on_xemDiem_clicked()
{
    xemDiem dialog(mainUser, root, this);
    dialog.exec();

}

