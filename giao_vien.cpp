#include "giao_vien.h"
#include "ui_giao_vien.h"
#include "sinhvien.h"
#include "hieuchinh_SinhVien.h"
#include "excel.h"
#include "lop.h"
#include "them_lop.h"
#include "hieuchinh_lop.h"
#include "xem_mon_lop.h"
#include "mamh.h"
#include"them_sinh_vien.h"
#include "themcauhoi.h"
#include "hieuchinh_cauhoi.h"
#include "xemdiem.h"
#include "quan_ly_mon.h"

#include<QTimer>
#include<QDebug>
#include<QTableWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QCompleter>
#include <QLineEdit>

GIao_Vien::GIao_Vien(Lop* danhSachLop[], QWidget* parent)
    : QMainWindow(parent)
    , danhSachLop(danhSachLop)
    , ui(new Ui::GIao_Vien)
{
    ui->setupUi(this);
    this->setWindowTitle("Giảng Viên - PTIT");
    QPixmap pixmap(":/logo/ad27bc12ca81e862ceb35328122757ee.png");
    QPixmap scaledPixmap = pixmap.scaled(ui->logo->size(), Qt::KeepAspectRatio);
    ui->logo->setPixmap(scaledPixmap);
    this->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    this->setWindowIcon(QIcon(":/logo/ad27bc12ca81e862ceb35328122757ee.ico"));
    root =loadToanBoCauHoi();
    on_sinhVien_clicked();
    ui->bangDuLieu->setEditTriggers(QAbstractItemView::NoEditTriggers);
    loadLopVaoComboBox();

    // Tạo context menu
    setupContextMenus();
}

GIao_Vien::~GIao_Vien()
{
    delete ui;
}

void GIao_Vien::setupContextMenus() {
    // Context menu cho sinh viên
    sinhVienContextMenu = new QMenu(this);
    sinhVienDeleteAction = new QAction("Xóa Sinh Viên", this);
    sinhVienEditAction = new QAction("Hiệu chỉnh Sinh Viên", this);
    sinhVienViewScoreAction = new QAction("Xem Điểm", this);

    sinhVienContextMenu->addAction(sinhVienDeleteAction);
    sinhVienContextMenu->addAction(sinhVienEditAction);
    sinhVienContextMenu->addAction(sinhVienViewScoreAction);

    // Context menu cho câu hỏi
    cauHoiContextMenu = new QMenu(this);
    cauHoiDeleteAction = new QAction("Xóa Câu Hỏi", this);
    cauHoiEditAction = new QAction("Hiệu chỉnh Câu Hỏi", this);

    cauHoiContextMenu->addAction(cauHoiDeleteAction);
    cauHoiContextMenu->addAction(cauHoiEditAction);

    // Context menu cho lớp
    lopContextMenu = new QMenu(this);
    lopDeleteAction = new QAction("Xóa Lớp", this);
    lopEditAction = new QAction("Hiệu chỉnh Lớp", this);
    lopViewScoreAction = new QAction("Xem Điểm", this);

    lopContextMenu->addAction(lopDeleteAction);
    lopContextMenu->addAction(lopEditAction);
    lopContextMenu->addAction(lopViewScoreAction);

    // Kết nối sự kiện cho context menu sinh viên
    connect(sinhVienDeleteAction, &QAction::triggered, this, &GIao_Vien::xoaSV);
    connect(sinhVienEditAction, &QAction::triggered, this, &GIao_Vien::hieuChinhSV);
    connect(sinhVienViewScoreAction, &QAction::triggered, this, &GIao_Vien::xemDiemSinhVien);

    // Kết nối sự kiện cho context menu lớp
    connect(lopDeleteAction, &QAction::triggered, this, &GIao_Vien::xoaLop);
    connect(lopEditAction, &QAction::triggered, this, &GIao_Vien::hieuChinhLop);
    connect(lopViewScoreAction, &QAction::triggered, this, &GIao_Vien::xemMonLop);

    // Kết nối sự kiện cho context menu câu hỏi
    connect(cauHoiDeleteAction, &QAction::triggered, this, &GIao_Vien::xoaCauHoi);
    connect(cauHoiEditAction, &QAction::triggered, this, &GIao_Vien::hieuChinhCauHoi);
}

void GIao_Vien::showSinhVienContextMenu(const QPoint &pos) {
    QModelIndex index = ui->bangDuLieu->indexAt(pos);
    if (!index.isValid()) {
        return;
    }

    // Chọn dòng tương ứng
    ui->bangDuLieu->selectRow(index.row());

    // Hiển thị context menu của sinh viên
    sinhVienContextMenu->exec(ui->bangDuLieu->viewport()->mapToGlobal(pos));
}

void GIao_Vien::showCauHoiContextMenu(const QPoint &pos) {
    QModelIndex index = ui->bangDuLieu->indexAt(pos);
    if (!index.isValid()) {
        return;
    }

    // Chọn dòng tương ứng
    ui->bangDuLieu->selectRow(index.row());

    // Hiển thị context menu của câu hỏi
    cauHoiContextMenu->exec(ui->bangDuLieu->viewport()->mapToGlobal(pos));
}

void GIao_Vien::showLopContextMenu(const QPoint &pos) {// AOMALAZADA
    // Lấy chỉ số của vị trí nhấp chuột
    QModelIndex index = ui->bangDuLieu->indexAt(pos);

    // Nếu không phải một dòng hợp lệ, thoát ra
    if (!index.isValid()) {
        return;
    }

    // Chọn dòng tương ứng
    ui->bangDuLieu->selectRow(index.row());

    // Hiển thị context menu cho lớp
    lopContextMenu->exec(ui->bangDuLieu->viewport()->mapToGlobal(pos));
}

void xoaSinhVienKhoiDanhSach(Lop* danhSachLop[], const QString &masv, const QString &tenLop) {
    for (int i = 0; i < MAX; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }

        if (danhSachLop[i]->MALOP == tenLop) {
            SinhVien* current = danhSachLop[i]->DSSV;
            SinhVien* previous = nullptr;

            while (current != nullptr) {
                if (current->masv == masv) {
                    if (previous == nullptr) {
                        danhSachLop[i]->DSSV = current->next;
                    } else {
                        previous->next = current->next;
                    }

                    delete current;
                    qDebug() << "Sinh viên với MSSV:" << masv << "đã bị xóa khỏi lớp:" << tenLop;
                    return;
                }

                previous = current;
                current = current->next;
            }
        }
    }
}

QString GIao_Vien::getSelectedStudentMasv(int row) {
    return ui->bangDuLieu->item(row, 0)->text();
}

QString GIao_Vien::getSelectedStudentLop(int row) {
    return ui->bangDuLieu->item(row, 3)->text();
}

void GIao_Vien::xoaSV() {
    int row = ui->bangDuLieu->currentRow();
    QString masv = ui->bangDuLieu->item(row, 0)->text();
    QString tenLop = ui->bangDuLieu->item(row, 3)->text();

    SinhVien* sinhVien = timSinhVien(masv, tenLop, danhSachLop);

    if (sinhVien == nullptr) {
        QMessageBox::warning(this, "Lỗi", "Không tìm thấy sinh viên!");
        return;
    }

    if (sinhVien->ds_diemthi != nullptr) {
        QMessageBox::warning(this, "Không thể xóa", "Sinh viên đã làm bài, không thể xóa!");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Xóa Sinh Viên", "Bạn có chắc chắn muốn xóa sinh viên này?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        // Thực hiện xóa sinh viên
        xoaSinhVienKhoiDanhSach(danhSachLop, masv, tenLop);
        loadSinhVien();
    }
}

void duyetDanhSach(Lop* danhSachLop[]) {
    for (int i = 0; i < MAX; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }

        QString tenLop = danhSachLop[i]->MALOP;
        SinhVien* currentSV = danhSachLop[i]->DSSV;
        qDebug() << "Duyệt lớp: " << tenLop;

        while (currentSV != nullptr) {
            qDebug() << "MSSV: " << currentSV->masv;
            currentSV = currentSV->next;
        }
    }
}

void GIao_Vien::loadSinhVien() {
    ui->bangDuLieu->setRowCount(0);
    ui->bangDuLieu->clear();
    QStringList headers;
    headers << "MSSV" << "Họ" << "Tên" <<"Lớp" << "Giới tính";
    ui->bangDuLieu->setHorizontalHeaderLabels(headers);
    int row = 0;

    // Duyệt qua mảng lớp
    for (int i = 0; i < MAX; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }
        SinhVien* current = danhSachLop[i]->DSSV;
        QString tenLop = danhSachLop[i]->MALOP;

        while (current != nullptr) {
            ui->bangDuLieu->insertRow(row);

            QTableWidgetItem *masvItem = new QTableWidgetItem(current->masv);
            QTableWidgetItem *hoItem = new QTableWidgetItem(current->ho);
            QTableWidgetItem *tenItem = new QTableWidgetItem(current->ten);
            QTableWidgetItem *phaiItem = new QTableWidgetItem(current->phai);
            QTableWidgetItem *tenLopItem = new QTableWidgetItem(tenLop);

            // Đặt các mục vào bảng
            ui->bangDuLieu->setItem(row, 0, masvItem);
            ui->bangDuLieu->setItem(row, 1, hoItem);
            ui->bangDuLieu->setItem(row, 2, tenItem);
            ui->bangDuLieu->setItem(row, 3, tenLopItem);
            ui->bangDuLieu->setItem(row, 4, phaiItem);
            current = current->next;
            row++;
        }
    }
}

void GIao_Vien::onTextEdited(const QString &text) {
    disconnect(ui->timMSSV, &QLineEdit::textEdited, this, &GIao_Vien::onTextEdited);
    QString upperText = text.toUpper();
    ui->timMSSV->setText(upperText);
    ui->timMSSV->setCursorPosition(upperText.length());
    connect(ui->timMSSV, &QLineEdit::textEdited, this, &GIao_Vien::onTextEdited);
}

    void GIao_Vien::timKiemSinhVien(const QString &text) {
        ui->bangDuLieu->setRowCount(0);

        int row = 0;

        // Duyệt qua mảng lớp
        for (int i = 0; i < MAX; ++i) {
            if (danhSachLop[i] == nullptr) {
                break;
            }
            SinhVien* current = danhSachLop[i]->DSSV;
            QString tenLop = danhSachLop[i]->MALOP;

            // Duyệt qua danh sách sinh viên của lớp hiện tại
            while (current != nullptr) {
                if (current->masv.contains(text, Qt::CaseInsensitive)) {
                    ui->bangDuLieu->insertRow(row);

                    ui->bangDuLieu->setItem(row, 0, new QTableWidgetItem(current->masv));
                    ui->bangDuLieu->setItem(row, 1, new QTableWidgetItem(current->ho));
                    ui->bangDuLieu->setItem(row, 2, new QTableWidgetItem(current->ten));
                    ui->bangDuLieu->setItem(row, 3, new QTableWidgetItem(tenLop));
                    ui->bangDuLieu->setItem(row, 4, new QTableWidgetItem(current->phai));

                    row++;
                }

                current = current->next;
            }
        }
    }

void GIao_Vien::dsMonHoc(NodeMonHoc* root, bool isFirst) {
    if (root == nullptr) {
        return;
    }

    // Nếu là lần đầu tiên, xóa tất cả các item cũ trong combobox trước khi thêm mới
    if (isFirst) {
        ui->locCauHoi->clear();
        monHocList.clear();

        ui->locCauHoi->insertItem(0, "Tất Cả Câu Hỏi");
        monHocList << "Tất Cả Câu Hỏi";

        int indexAllQuestions = 0;
        ui->locCauHoi->setItemData(indexAllQuestions, Qt::AlignCenter, Qt::TextAlignmentRole);
    }

    ui->locCauHoi->addItem(root->MH.TENMH, QVariant::fromValue(root->MH.MAMH));
    monHocList << root->MH.TENMH;

    int index = ui->locCauHoi->count() - 1;
    ui->locCauHoi->setItemData(index, Qt::AlignCenter, Qt::TextAlignmentRole);

    dsMonHoc(root->left, false);

    dsMonHoc(root->right, false);
}

void GIao_Vien::locCauHoi(const QString& selectedCauHoi) {
    ui->bangDuLieu->setRowCount(0);
    int row = 0;

    if (selectedCauHoi == "Tất Cả Câu Hỏi") {
        ui->bangDuLieu->setRowCount(0);
        loadCauHoi(root);
        return;
    }

    QString selectedMAMH = "";
    int count = ui->locCauHoi->count();
    for (int i = 0; i < count; ++i) {
        if (ui->locCauHoi->itemText(i) == selectedCauHoi) {
            selectedMAMH = ui->locCauHoi->itemData(i).toString();  // Lấy MAMH từ itemData
            break;
        }
    }

    NodeMonHoc* current = root;
    while (current != nullptr) {
        if (current->MH.MAMH == selectedMAMH) {
            CauHoi* currentCauHoi = current->MH.headCauhoi;
            while (current != nullptr) {
                if (current->MH.MAMH == selectedMAMH) {
                    CauHoi* currentCauHoi = current->MH.headCauhoi;
                    while (currentCauHoi != nullptr) {
                        ui->bangDuLieu->insertRow(row);
                        ui->bangDuLieu->setItem(row, 0, new QTableWidgetItem(current->MH.MAMH));
                        QString idCauHoi = current->MH.MAMH + QString::number(currentCauHoi->id);
                        ui->bangDuLieu->setItem(row, 1, new QTableWidgetItem(idCauHoi));
                        ui->bangDuLieu->setItem(row, 2, new QTableWidgetItem(current->MH.TENMH));
                        ui->bangDuLieu->setItem(row, 3, new QTableWidgetItem(currentCauHoi->noiDung));
                        ui->bangDuLieu->setItem(row, 4, new QTableWidgetItem(currentCauHoi->A));
                        ui->bangDuLieu->setItem(row, 5, new QTableWidgetItem(currentCauHoi->B));
                        ui->bangDuLieu->setItem(row, 6, new QTableWidgetItem(currentCauHoi->C));
                        ui->bangDuLieu->setItem(row, 7, new QTableWidgetItem(currentCauHoi->D));

                        currentCauHoi = currentCauHoi->next;
                        row++;
                    }
                    break; // Dừng duyệt khi đã tìm thấy và xử lý môn học
                } else if (selectedMAMH < current->MH.MAMH) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
            break; // Dừng duyệt khi đã tìm thấy và xử lý môn học
        } else if (selectedMAMH < current->MH.MAMH) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
}

void GIao_Vien::onCauHoiComboBoxChanged(int index) {
    QString selectedCauHoi = ui->locCauHoi->itemText(index);
    locCauHoi(selectedCauHoi);
}

void GIao_Vien::on_Them1CauHoi_clicked() {
    int currentIndex = -1;

    while (true) {
        themcauhoi dialog(this, root, &currentIndex);

        int result = dialog.exec();

        if (result == QDialog::Accepted) {
            qDebug() << "Môn học đã chọn có index: " << currentIndex;
        } else {
            ui->bangDuLieu->setRowCount(0);
            loadCauHoi(root);
            break;
        }
    }
}


void GIao_Vien::loadLopVaoComboBox() {
    ui->locLop->clear();

    lopList << "Tất Cả Sinh Viên";

    for (int i = 0; i < MAX; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }
        lopList << danhSachLop[i]->MALOP;
    }

    ui->locLop->addItems(lopList);

    for (int i = 0; i < ui->locLop->count(); ++i) {
        ui->locLop->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    }

    setupComboBoxFilter(ui->locLop, lopList);
}


void GIao_Vien::onLopComboBoxChanged(int index) {
    QString selectedLop = ui->locLop->itemText(index);
    loadSinhVienLop(selectedLop);
}

void GIao_Vien::setupComboBoxFilter(QComboBox *comboBox, const QStringList &list) {
    comboBox->setEditable(true);

    // Tạo QCompleter để hỗ trợ gợi ý
    QCompleter *completer = new QCompleter(list, comboBox);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setFilterMode(Qt::MatchContains);
    completer->setCompletionMode(QCompleter::PopupCompletion);

    comboBox->setCompleter(completer);
}

void GIao_Vien::loadSinhVienLop(const QString &lop) {
    if (lop == "Tất Cả Sinh Viên") {
        loadSinhVien();
        return;
    }

    ui->bangDuLieu->setRowCount(0);

    for (int i = 0; i < MAX; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }
        if (danhSachLop[i]->MALOP == lop) {
            SinhVien* current = danhSachLop[i]->DSSV;
            int row = 0;
            while (current != nullptr) {
                ui->bangDuLieu->insertRow(row);
                ui->bangDuLieu->setItem(row, 0, new QTableWidgetItem(current->masv));
                ui->bangDuLieu->setItem(row, 1, new QTableWidgetItem(current->ho));
                ui->bangDuLieu->setItem(row, 2, new QTableWidgetItem(current->ten));
                ui->bangDuLieu->setItem(row, 3, new QTableWidgetItem(danhSachLop[i]->MALOP));
                ui->bangDuLieu->setItem(row, 4, new QTableWidgetItem(current->phai));
                row++;
                current = current->next;
            }
        }
    }
}

void GIao_Vien::on_them1sv_clicked() {
    Them_Sinh_Vien* dialog = new Them_Sinh_Vien(danhSachLop, dasapxep, this, this);
    int result = dialog->exec();
    if (result == QDialog::Accepted || result == QDialog::Rejected) {
        loadSinhVien();
    }
    delete dialog;
}

void GIao_Vien::xemDiemSinhVien() {
    int row = ui->bangDuLieu->currentRow();
    QString mssv = ui->bangDuLieu->item(row, 0)->text();
    QString lop = ui->bangDuLieu->item(row, 3)->text();

    // Tìm sinh viên trong danh sách lớp
    SinhVien* sv = timSinhVien(mssv, lop, danhSachLop);
    if (sv == nullptr) {
        QMessageBox::warning(this, "Cảnh báo", "Không tìm thấy sinh viên trong danh sách.");
        return;
    }

    if (sv->ds_diemthi == nullptr) {
        QMessageBox::information(this, "Thông báo", "Sinh viên chưa thi môn nào.");
        return;
    }

    // Mở dialog xem điểm cho sinh viên
    xemDiem dialog(sv, root, true, this);
    dialog.exec();
}


void GIao_Vien::xemMonLop() {
    int row = ui->bangDuLieu->currentRow();
    QString maLop = ui->bangDuLieu->item(row, 0)->text();  // Lấy mã lớp từ bảng
    Lop* mainClass = timLop(maLop, danhSachLop);


    if (!mainClass) {
        QMessageBox::warning(this, "Cảnh báo", "Không tìm thấy lớp trong danh sách.");
        return;
    }

    xem_mon_lop dialog(mainClass, root, this);
    dialog.exec();

}

void GIao_Vien::hieuChinhSV() {
    int row = ui->bangDuLieu->currentRow();

    QString mssv = ui->bangDuLieu->item(row, 0)->text();
    QString ho = ui->bangDuLieu->item(row, 1)->text();
    QString ten = ui->bangDuLieu->item(row, 2)->text();
    QString lop = ui->bangDuLieu->item(row, 3)->text();
    QString gioiTinh = ui->bangDuLieu->item(row, 4)->text();
    HieuChinh dialog(mssv, ho, ten, lop, gioiTinh, danhSachLop, dasapxep, this);

    if (dialog.exec() == QDialog::Accepted){
        loadSinhVien();
    }
}

void GIao_Vien::on_cauHoi_clicked() {
    ui->tinhNangSinhVien->hide();
    ui->tinhNangLop->hide();
    ui->tinhNangCauHoi->show();

    // Thiết lập context menu cho bảng Câu hỏi
    ui->bangDuLieu->setContextMenuPolicy(Qt::CustomContextMenu);
    disconnect(ui->bangDuLieu, &QTableWidget::customContextMenuRequested, this, &GIao_Vien::showSinhVienContextMenu);
     disconnect(ui->bangDuLieu, &QTableWidget::customContextMenuRequested, this, &GIao_Vien::showLopContextMenu);
    connect(ui->bangDuLieu, &QTableWidget::customContextMenuRequested, this, &GIao_Vien::showCauHoiContextMenu);

    ui->bangDuLieu->clear();
    ui->bangDuLieu->setColumnCount(8);

    ui->bangDuLieu->setColumnWidth(0, 100);
    ui->bangDuLieu->setColumnWidth(1, 100);
    ui->bangDuLieu->setColumnWidth(2, 250);
    ui->bangDuLieu->setColumnWidth(3, 300);
    ui->bangDuLieu->setColumnWidth(4, 200);
    ui->bangDuLieu->setColumnWidth(5, 200);
    ui->bangDuLieu->setColumnWidth(6, 200);
    ui->bangDuLieu->setColumnWidth(7, 200);

    QStringList headers;
    headers << "Mã MH" << "ID câu hỏi" << "Tên Môn Học" << "Câu Hỏi" << "A" << "B" << "C" << "D";
    ui->bangDuLieu->setHorizontalHeaderLabels(headers);
    ui->bangDuLieu->setRowCount(0);
    loadCauHoi(root);
    connect(ui->locCauHoi, SIGNAL(currentIndexChanged(int)), this, SLOT(onCauHoiComboBoxChanged(int)));
    bool isFirst = true;
    dsMonHoc(root, isFirst);
    setupComboBoxFilter(ui->locCauHoi, monHocList);
}

void GIao_Vien::xoaCauHoi()
{
    int currentRow = ui->bangDuLieu->currentRow();

    QString mamh = ui->bangDuLieu->item(currentRow, 0)->text();
    QString fullId = ui->bangDuLieu->item(currentRow, 1)->text();

    QString idStr = fullId.mid(mamh.length());
    int id = idStr.toInt();

    // Tìm môn học cần xoá câu hỏi
    MonHoc* monHoc = SearchMonHoc(root, mamh);
    if (!monHoc) {
        QMessageBox::warning(this, "Lỗi", "Không tìm thấy môn học!");
        return;
    }

    // Tìm câu hỏi cần xoá và kiểm tra trạng thái đã thi
    CauHoi* prev = nullptr;
    CauHoi* current = monHoc->headCauhoi;
    while (current) {
        if (current->id == id) {
            if (current->daThi) {
                QMessageBox::warning(this, "Cảnh báo", "Câu hỏi đã có sinh viên làm, không thể xoá!");
                return;
            }
            // Xác nhận với người dùng trước khi xoá
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Xác nhận xoá", "Bạn có chắc chắn muốn xoá câu hỏi này?",
                                          QMessageBox::Yes | QMessageBox::No);
            if (reply == QMessageBox::No) {
                return;
            }

            if (prev == nullptr) {
                // Xoá câu hỏi đầu danh sách
                monHoc->headCauhoi = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            break;
        }
        prev = current;
        current = current->next;
    }

    // Load lại bảng câu hỏi
    ui->bangDuLieu->setRowCount(0);
    loadCauHoi(root);
}

void GIao_Vien::hieuChinhCauHoi()
{
    int currentRow = ui->bangDuLieu->currentRow();

    QString monHoc = ui->bangDuLieu->item(currentRow, 0)->text();
    QString fullId = ui->bangDuLieu->item(currentRow, 1)->text();

    QString mamh = monHoc;
    QString idStr = fullId.mid(mamh.length());
    int id = idStr.toInt();

    // Tìm câu hỏi thông qua hàm findCauHoi
    CauHoi* cauHoi = findCauHoi(root, mamh, id);
    qDebug() << "Kiểm tra cauHoi:" << (cauHoi != nullptr ? "Không null" : "Null") << ", daThi:" << (cauHoi != nullptr ? cauHoi->daThi : false);

    // Kiểm tra xem câu hỏi đã thi chưa
    if (cauHoi != nullptr && cauHoi->daThi) {
        QMessageBox::warning(this, "Cảnh báo", "Câu hỏi đã thi, không thể chỉnh sửa!");
        return;
    }

    hieuchinh_CauHoi dialog(this, mamh, id, root);
    if (dialog.exec() == QDialog::Accepted) {
        ui->bangDuLieu->setRowCount(0);
        loadCauHoi(root);
    }
}

void GIao_Vien::loadCauHoi(ptrMonHoc root)
{
    if (root == nullptr) {
        return;
    }

    loadCauHoi(root->left);

    CauHoi* cauHoi = root->MH.headCauhoi;
    while (cauHoi != nullptr) {

        int row = ui->bangDuLieu->rowCount(); // Lấy số hàng hiện tại trong bảng
        ui->bangDuLieu->insertRow(row);      // Thêm một hàng mới

        ui->bangDuLieu->setItem(row, 0, new QTableWidgetItem(root->MH.MAMH));
        QString idCauHoi = root->MH.MAMH + QString::number(cauHoi->id);
        ui->bangDuLieu->setItem(row, 1, new QTableWidgetItem(idCauHoi));
        ui->bangDuLieu->setItem(row, 2, new QTableWidgetItem(root->MH.TENMH));
        ui->bangDuLieu->setItem(row, 3, new QTableWidgetItem(cauHoi->noiDung));
        ui->bangDuLieu->setItem(row, 4, new QTableWidgetItem(cauHoi->A));
        ui->bangDuLieu->setItem(row, 5, new QTableWidgetItem(cauHoi->B));
        ui->bangDuLieu->setItem(row, 6, new QTableWidgetItem(cauHoi->C));
        ui->bangDuLieu->setItem(row, 7, new QTableWidgetItem(cauHoi->D));

        cauHoi = cauHoi->next;
    }

    qDebug() << "Dang load cay con ben phai cua: " << root->MH.MAMH;
    loadCauHoi(root->right);
}


void GIao_Vien::on_sinhVien_clicked() {
    ui->tinhNangCauHoi->hide();
    ui->tinhNangLop->hide();
    ui->tinhNangSinhVien->show();

    // Thiết lập context menu cho bảng Sinh viên
    ui->bangDuLieu->setContextMenuPolicy(Qt::CustomContextMenu);
    disconnect(ui->bangDuLieu, &QTableWidget::customContextMenuRequested, this, &GIao_Vien::showCauHoiContextMenu);
    disconnect(ui->bangDuLieu, &QTableWidget::customContextMenuRequested, this, &GIao_Vien::showLopContextMenu);
    connect(ui->bangDuLieu, &QTableWidget::customContextMenuRequested, this, &GIao_Vien::showSinhVienContextMenu);

    ui->bangDuLieu->setColumnCount(5);
    ui->bangDuLieu->setColumnWidth(0, 300);
    ui->bangDuLieu->setColumnWidth(1, 350);
    ui->bangDuLieu->setColumnWidth(2, 150);
    ui->bangDuLieu->setColumnWidth(3, 200);
    ui->bangDuLieu->setColumnWidth(4, 150);

    connect(ui->locLop, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &GIao_Vien::onLopComboBoxChanged);
    loadSinhVien();
    connect(ui->timMSSV, &QLineEdit::textEdited, this, &GIao_Vien::onTextEdited);
    connect(ui->timMSSV, &QLineEdit::textChanged, this, &GIao_Vien::timKiemSinhVien);
}

void GIao_Vien::on_sapXep_clicked()
{
    if (!dasapxep) {
        dasapxep = true;
        for (int i = 0; i < MAX; ++i) {
            qDebug() << "CB sap xep";
            if (danhSachLop[i] == nullptr) {
                break;
            }

            SinhVien* head = danhSachLop[i]->DSSV;
            if (head == nullptr || head->next == nullptr) {
                continue;
            }

            // Đếm số lượng sinh viên
            int count = demSVLop(danhSachLop[i]);

            // Tạo mảng cấp phát động
            SinhVien** arr = new SinhVien*[count];
            SinhVien* temp = head;
            for (int j = 0; j < count; ++j) {
                arr[j] = temp;
                temp = temp->next;
            }

            // Sắp xếp mảng bằng quicksort
            quickSortArray(arr, 0, count - 1);

            // Nối lại danh sách liên kết từ mảng đã sắp xếp
            head = arr[0];
            SinhVien* current = head;
            for (int j = 1; j < count; ++j) {
                current->next = arr[j];
                current = current->next;
            }
            current->next = nullptr;

            delete[] arr;

            // Cập nhật lại danh sách sinh viên của lớp
            danhSachLop[i]->DSSV = head;
        }

        // Tải lại bảng sinh viên sau khi sắp xếp
        loadSinhVien();
        qDebug() << "Đã sắp xếp danh sách sinh viên theo tên.";
    }
}

void GIao_Vien::on_themNhieuSV_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Excel File"), "", tr("Excel Files (*.xlsx *.xls)"));
    if (!fileName.isEmpty()) {
        qDebug() << "File selected:" << fileName;
    }
    loadSinhVienTuFile(danhSachLop, fileName, dasapxep);
    loadSinhVien();
}


void GIao_Vien::on_lop_clicked()
{
    int rows = demSoLop(danhSachLop);
    ui->tinhNangSinhVien->hide();
    ui->tinhNangCauHoi->hide();
    ui->tinhNangLop->show();



    ui->bangDuLieu->setContextMenuPolicy(Qt::CustomContextMenu);
    disconnect(ui->bangDuLieu, &QTableWidget::customContextMenuRequested, this, &GIao_Vien::showCauHoiContextMenu);
    disconnect(ui->bangDuLieu, &QTableWidget::customContextMenuRequested, this, &GIao_Vien::showSinhVienContextMenu);
    connect(ui->bangDuLieu, &QTableWidget::customContextMenuRequested, this, &GIao_Vien::showLopContextMenu);
    // contextMenu->addAction(deleteAction);
    // contextMenu->addAction(editAction);

    // connect(ui->bangDuLieu, &QTableWidget::customContextMenuRequested, this, &GIao_Vien::showContextMenu);
    // connect(deleteAction, &QAction::triggered, this, &GIao_Vien::xoaLop);
    // connect(editAction, &QAction::triggered, this, &GIao_Vien::hieuChinhLop);

    ui->bangDuLieu->setRowCount(rows);
    ui->bangDuLieu->setColumnCount(2);
    ui->bangDuLieu->setColumnWidth(0, 400);
    ui->bangDuLieu->setColumnWidth(1, 750);

    QStringList headers;
    headers << "Mã Lớp" << "Tên Lớp";
    ui->bangDuLieu->setHorizontalHeaderLabels(headers);
    loadLop();
    connect(ui->timMaLop, &QLineEdit::textEdited, this, &GIao_Vien::onTextEdited_2);
    // connect(ui->timMaLop, &QLineEdit::textChanged, this, &GIao_Vien::timLop);
}


void GIao_Vien::loadLop() {
    ui->bangDuLieu->clear();
    QStringList headers;
    headers << "Mã Lớp" << "Tên Lớp";
    ui->bangDuLieu->setHorizontalHeaderLabels(headers);

    int rows = demSoLop(danhSachLop);
    ui->bangDuLieu->setRowCount(rows);
    int row = 0;

    // Duyệt qua mảng lớp
    for (int i = 0; i < 10000; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }
        QString malop = danhSachLop[i]->MALOP;
        QString tenlop = danhSachLop[i]->TENLOP;


        // Tạo và thêm các mục cho từng cột trong hàng
        QTableWidgetItem *malopItem = new QTableWidgetItem(malop);
        QTableWidgetItem *tenlopItem = new QTableWidgetItem(tenlop);


        // Đặt các mục vào bảng
        ui->bangDuLieu->setItem(row, 0, malopItem);
        ui->bangDuLieu->setItem(row, 1, tenlopItem);

        row++;
    }
}



void GIao_Vien::on_sapXep_3_clicked(){
    dasapxep = true;
    for (int i = 0; i < 10000; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }

        Lop* lopArray[10000];
        int lopCount = 0;

        for (int j = 0; j < 10000; ++j) {
            if (danhSachLop[j] == nullptr) {
                break;
            }
            lopArray[lopCount++] = danhSachLop[j];
        }

        // Sắp xếp mảng lớp theo tên lớp (TENLOP)
        bool swapped;
        do {
            swapped = false;
            for (int k = 0; k < lopCount - 1; ++k) {
                if (lopArray[k]->MALOP < lopArray[k + 1]->MALOP) {
                    // Hoán đổi các lớp nếu tên lớp trước đó lớn hơn lớp sau
                    Lop* temp = lopArray[k];
                    lopArray[k] = lopArray[k + 1];
                    lopArray[k + 1] = temp;

                    swapped = true;
                }
            }
        } while (swapped);

        // Cập nhật lại danh sách lớp sau khi sắp xếp
        for (int k = 0; k < lopCount; ++k) {
            danhSachLop[k] = lopArray[k];
        }
    }

    // Tải lại bảng lớp sau khi sắp xếp
    loadLop();
    qDebug() << "Đã sắp xếp danh sách lớp theo tên.";


}


void GIao_Vien::on_themlop_clicked() {
    Them_Lop dialog(danhSachLop, this);
    if (dialog.exec() == QDialog::Accepted) {
        QString maLop = dialog.getMaLop();
        QString tenLop = dialog.getTenLop();

        // Xử lý thêm lớp mới
        qDebug() << "Đã thêm lớp mới: Mã lớp: " << maLop << ", Tên lớp: " << tenLop;

        // Ví dụ: thêm lớp vào danh sách lớp
        Lop* newLop = new Lop();
        newLop->MALOP = maLop;
        newLop->TENLOP = tenLop;
        // Gọi phương thức thêm lớp vào danh sách lớp
        // themLopVaoDanhSach(newLop);
        // themLopVaoDanhSach(newLop, maLop);
        loadLop();
    }
}

void GIao_Vien::on_themNhieuLop_clicked()
{

}

// void GIao_Vien::timLop(const QString &text) {
//     ui->bangDuLieu->setRowCount(0); // Xóa dữ liệu cũ trên bảng
//     int row = 0;

//     // Duyệt qua danh sách lớp
//     for (int i = 0; i < 10000; ++i) {
//         if (danhSachLop[i] == nullptr) {
//             break;
//         }

//         QString maLop = danhSachLop[i]->MALOP;
//         QString tenLop = danhSachLop[i]->TENLOP;

//         // Kiểm tra nếu mã lớp hoặc tên lớp chứa từ khóa
//         if (maLop.contains(text, Qt::CaseInsensitive)) {
//             ui->bangDuLieu->insertRow(row); // Thêm hàng mới vào bảng

//             // Đặt thông tin lớp vào từng cột
//             ui->bangDuLieu->setItem(row, 0, new QTableWidgetItem(maLop));
//             ui->bangDuLieu->setItem(row, 1, new QTableWidgetItem(tenLop));


//             row++; // Tăng chỉ số hàng
//         }
//     }
// }





void GIao_Vien::onTextEdited_2(const QString &text) {

    disconnect(ui->timMaLop, &QLineEdit::textEdited, this, &GIao_Vien::onTextEdited_2);

    // Chuyển đổi văn bản thành chữ hoa
    QString upperText = text.toUpper();

    // Đặt lại giá trị trong QLineEdit và đưa con trỏ về cuối
    ui->timMaLop->setText(upperText);
    ui->timMaLop->setCursorPosition(upperText.length());

    // Kết nối lại tín hiệu textEdited
    connect(ui->timMaLop, &QLineEdit::textEdited, this, &GIao_Vien::onTextEdited_2);
}


void GIao_Vien::hieuChinhLop() {
    int row = ui->bangDuLieu->currentRow();

    // Kiểm tra xem có hàng nào được chọn không
    // if (row < 0) {
    //     QMessageBox::warning(this, "Lỗi", "Vui lòng chọn lớp học để hiệu chỉnh!");
    //     return;
    // }

    // Lấy thông tin lớp từ bảng
    QString maLop = ui->bangDuLieu->item(row, 0)->text();
    QString tenLop = ui->bangDuLieu->item(row, 1)->text();

    HieuChinh_Lop dialog(maLop, tenLop, danhSachLop, this);  // Khởi tạo đúng đối tượng
    if (dialog.exec() == QDialog::Accepted) {
        loadLop();  // Cập nhật danh sách lớp
    }
}

void xoaLopKhoiDanhSach(const QString& maLop, Lop** danhSachLop) {
    for (int i = 0; i < 10000; ++i) {
        if (danhSachLop[i] == nullptr) {
            break; // Kết thúc nếu không còn lớp nào trong danh sách
        }
        if (danhSachLop[i]->MALOP == maLop) {
            // Giải phóng bộ nhớ danh sách sinh viên của lớp
            SinhVien* current = danhSachLop[i]->DSSV;
            while (current != nullptr) {
                SinhVien* temp = current;
                current = current->next;
                delete temp; // Xóa từng sinh viên
            }

            // Xóa lớp khỏi bộ nhớ
            delete danhSachLop[i];

            // Dịch chuyển các phần tử phía sau lên trước để lấp chỗ trống
            for (int j = i; j < 9999; ++j) {
                danhSachLop[j] = danhSachLop[j + 1];
            }
            danhSachLop[9999] = nullptr; // Đảm bảo phần tử cuối cùng là nullptr
            return; // Thoát khi đã xóa lớp
        }
    }
}

// void GIao_Vien::xemDiemMon(){

// }


void GIao_Vien::xoaLop() {
    // Lấy danh sách các hàng được chọn
    QModelIndexList selectedRows = ui->bangDuLieu->selectionModel()->selectedRows();

    // Nếu không có hàng nào được chọn, thoát khỏi hàm
    if (selectedRows.isEmpty()) {
        return;
    }

    // Lấy chỉ số của hàng đầu tiên được chọn
    int row = selectedRows.first().row();

    // Lấy mã lớp từ cột tương ứng
    QString maLop = ui->bangDuLieu->item(row, 0)->text();

    // Hiển thị hộp thoại xác nhận xóa
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(
        this,
        "Xóa Lớp",
        "Bạn có chắc chắn muốn xóa lớp với mã lớp: " + maLop + "?",
        QMessageBox::Yes | QMessageBox::No
        );

    // Nếu người dùng chọn "Không", thoát khỏi hàm
    if (reply == QMessageBox::No) {
        return;
    }

    // Gọi hàm xóa lớp khỏi danh sách nội bộ
    xoaLopKhoiDanhSach(maLop, danhSachLop);

    // Xóa hàng khỏi bảng
    ui->bangDuLieu->removeRow(row);
}

void GIao_Vien::on_luuDL_clicked()
{
    // Hiển thị thông báo thành công
    ui->thongBaoLuu->setText("Bạn đã lưu thành công");
    ui->thongBaoLuu->setStyleSheet("QLabel { color : green; qproperty-alignment: 'AlignCenter'; }");
    ui->thongBaoLuu->show();

    // Tự động ẩn thông báo sau 3 giây
    QTimer::singleShot(3000, this, [=]() {
        ui->thongBaoLuu->hide();
    });
}

void GIao_Vien::on_quanlymonhoc_clicked()
{
    quan_Ly_Mon *dialog = new quan_Ly_Mon(this, root);
    if (dialog->exec() == QDialog::Accepted) {
        // Load lại bảng câu hỏi sau khi quản lý môn học
        ui->bangDuLieu->setRowCount(0);
        loadCauHoi(root);
        bool isFirst = true;
        dsMonHoc(root, isFirst);
        setupComboBoxFilter(ui->locCauHoi, monHocList);
    }
    delete dialog;
}
