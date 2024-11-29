#include "giao_vien.h"
#include "ui_giao_vien.h"
#include "sinhvien.h"
#include "hieuchinh.h"
#include "excel.h"
#include"lop.h"
#include "mamh.h"
#include"them_sinh_vien.h"
#include<QDebug>
#include<QTableWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QCompleter>
#include <QLineEdit>

bool dasapxep = false;
NodeMonHoc* root = nullptr;

GIao_Vien::GIao_Vien(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GIao_Vien)
{
    ui->setupUi(this);
    this->setWindowTitle("Giảng Viên - PTIT");
    QPixmap pixmap(":/logo/ad27bc12ca81e862ceb35328122757ee.png");
    QPixmap scaledPixmap = pixmap.scaled(ui->logo->size(), Qt::KeepAspectRatio);
    ui->logo->setPixmap(scaledPixmap);
    root =loadToanBoCauHoi();
    on_sinhVien_clicked();
    ui->bangDuLieu->setEditTriggers(QAbstractItemView::NoEditTriggers);
    setupComboBoxFilter(ui->locLop);
    loadLopVaoComboBox();
}

GIao_Vien::~GIao_Vien()
{
    delete ui;
}

void GIao_Vien::showContextMenu(const QPoint &pos) {
    QModelIndex index = ui->bangDuLieu->indexAt(pos);
    if (!index.isValid()) {
        return;
    }

    ui->bangDuLieu->selectRow(index.row());

    contextMenu->exec(ui->bangDuLieu->viewport()->mapToGlobal(pos));
}

void xoaSinhVienKhoiDanhSach(const QString &masv, const QString &tenLop) {
    for (int i = 0; i < 10000; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }

        if (danhSachLop[i]->TENLOP == tenLop) {
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
    QModelIndexList selectedRows = ui->bangDuLieu->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        return;
    }

    int row = selectedRows.first().row();

    QString masv = getSelectedStudentMasv(row);
    QString tenLop = getSelectedStudentLop(row);

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Xóa Sinh Viên", "Bạn có chắc chắn muốn xóa sinh viên với MSSV: " + masv,
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) {
        return;
    }

    xoaSinhVienKhoiDanhSach(masv, tenLop);

    ui->bangDuLieu->removeRow(row);
}

void duyetDanhSach() {
    for (int i = 0; i < 10000; ++i) {
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
    ui->bangDuLieu->clear();
    QStringList headers;
    headers << "MSSV" << "Họ" << "Tên" <<"Lớp" << "Giới tính";
    ui->bangDuLieu->setHorizontalHeaderLabels(headers);
    int rows = demSinhVien();
    ui->bangDuLieu->setRowCount(rows);
    int row = 0;

    // Duyệt qua mảng lớp
    for (int i = 0; i < 10000; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }
        SinhVien* current = danhSachLop[i]->DSSV;
        QString tenLop = danhSachLop[i]->MALOP;

        while (current != nullptr) {
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

void GIao_Vien::timSinhVien(const QString &text) {
    ui->bangDuLieu->setRowCount(0);

    int row = 0;

    // Duyệt qua mảng lớp
    for (int i = 0; i < 10000; ++i) {
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
        ui->locCauHoi->insertItem(0, "Tất Cả Câu Hỏi");
        int indexAllQuestions = 0;
        ui->locCauHoi->setItemData(indexAllQuestions, Qt::AlignCenter, Qt::TextAlignmentRole);
    }

    ui->locCauHoi->addItem(root->MH.TENMH, QVariant::fromValue(root->MH.MAMH));
    int index = ui->locCauHoi->count() - 1;
    ui->locCauHoi->setItemData(index, Qt::AlignCenter, Qt::TextAlignmentRole);

    dsMonHoc(root->left, false);

    dsMonHoc(root->right, false);
}

void GIao_Vien::locCauHoi(const QString& selectedCauHoi) {
    ui->bangDuLieu->clear();
    ui->bangDuLieu->setRowCount(0);
    int row = 0;

    // Nếu người dùng chọn "Tất Cả Câu Hỏi"
    if (selectedCauHoi == "Tất Cả Câu Hỏi") {
        // Lấy tổng số câu hỏi trong toàn bộ cây
        int totalQuestions = demTatCaCauHoi(root);
        ui->bangDuLieu->setRowCount(totalQuestions);  // Cập nhật số dòng của bảng
        loadCauHoi(root, row);  // Tải tất cả câu hỏi vào bảng
        return;  // Dừng hàm ngay tại đây, không cần duyệt cây nữa
    }

    // Tìm mã môn học (MAMH) từ itemData trong combobox
    QString selectedMAMH = "";
    int count = ui->locCauHoi->count();
    for (int i = 0; i < count; ++i) {
        if (ui->locCauHoi->itemText(i) == selectedCauHoi) {
            selectedMAMH = ui->locCauHoi->itemData(i).toString();  // Lấy MAMH từ itemData
            break;
        }
    }

    // Duyệt qua cây để tìm mã môn học (MAMH) tương ứng
    NodeMonHoc* current = root;
    while (current != nullptr) {
        if (current->MH.MAMH == selectedMAMH) {
            CauHoi* currentCauHoi = current->MH.headCauhoi;
            while (currentCauHoi != nullptr) {
                QTableWidgetItem* mamhItem = new QTableWidgetItem(current->MH.MAMH);
                QTableWidgetItem* tenmhItem = new QTableWidgetItem(current->MH.TENMH);
                QTableWidgetItem* cauHoiItem = new QTableWidgetItem(currentCauHoi->noiDung);
                QTableWidgetItem* answerAItem = new QTableWidgetItem(currentCauHoi->A);
                QTableWidgetItem* answerBItem = new QTableWidgetItem(currentCauHoi->B);
                QTableWidgetItem* answerCItem = new QTableWidgetItem(currentCauHoi->C);
                QTableWidgetItem* answerDItem = new QTableWidgetItem(currentCauHoi->D);

                ui->bangDuLieu->insertRow(row);
                ui->bangDuLieu->setItem(row, 0, mamhItem);
                ui->bangDuLieu->setItem(row, 1, tenmhItem);
                ui->bangDuLieu->setItem(row, 2, cauHoiItem);
                ui->bangDuLieu->setItem(row, 3, answerAItem);
                ui->bangDuLieu->setItem(row, 4, answerBItem);
                ui->bangDuLieu->setItem(row, 5, answerCItem);
                ui->bangDuLieu->setItem(row, 6, answerDItem);

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
}

void GIao_Vien::onCauHoiComboBoxChanged(int index) {
    QString selectedCauHoi = ui->locCauHoi->itemText(index);
    locCauHoi(selectedCauHoi);
}

void GIao_Vien::loadLopVaoComboBox() {
    ui->locLop->clear();

    ui->locLop->addItem("Tất Cả Sinh Viên");

    for (int i = 0; i < 10000; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }
        ui->locLop->addItem(danhSachLop[i]->MALOP);
    }

    for (int i = 0; i < ui->locLop->count(); ++i) {
        ui->locLop->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    }
}

void GIao_Vien::onLopComboBoxChanged(int index) {
    QString selectedLop = ui->locLop->itemText(index);
    loadSinhVienLop(selectedLop);
}

void GIao_Vien::setupComboBoxFilter(QComboBox *comboBox) {
    comboBox->setEditable(true); // Mặc định không cho chỉnh sửa

    // Thêm QCompleter để hỗ trợ gợi ý
    QCompleter *completer = new QCompleter(comboBox);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setFilterMode(Qt::MatchContains);
    comboBox->setCompleter(completer);
}

void GIao_Vien::loadSinhVienLop(const QString &lop) {
    if (lop == "Tất Cả Sinh Viên") {
        loadSinhVien();
        return;
    }

    ui->bangDuLieu->setRowCount(0);

    for (int i = 0; i < 10000; ++i) {
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
    Them_Sinh_Vien dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString masv = dialog.getMSSV();
        QString ho = dialog.getHo();
        QString ten = dialog.getTen();
        QString phai = dialog.getGioiTinh();
        QString lop = dialog.getLop();

        SinhVien* newSV = taoNodeSinhVien(masv, ho, ten, phai, "123");

        if (dasapxep) {
            themSinhVienVaoLopCoThuTu(newSV, lop);
        } else {
            themSinhVienVaoLop(newSV, lop);
        }

        loadSinhVien();

        qDebug() << "Đã thêm sinh viên mới vào bảng dữ liệu. Thông tin sinh viên: MSSV:" << newSV->masv << ", Họ:" << newSV->ho << ", Tên:" << newSV->ten << ", Giới tính:" << newSV->phai << ", Lớp:" << lop;
    }
}

void GIao_Vien::hieuChinhSV() {
    int row = ui->bangDuLieu->currentRow();

    QString mssv = ui->bangDuLieu->item(row, 0)->text();
    QString ho = ui->bangDuLieu->item(row, 1)->text();
    QString ten = ui->bangDuLieu->item(row, 2)->text();
    QString lop = ui->bangDuLieu->item(row, 3)->text();
    QString gioiTinh = ui->bangDuLieu->item(row, 4)->text();
    HieuChinh dialog(mssv, ho, ten, lop, gioiTinh, this);

    if (dialog.exec() == QDialog::Accepted){
        loadSinhVien();
    }
}

void GIao_Vien::on_cauHoi_clicked()
{
    ui->tinhNangSinhVien->hide();
    ui->tinhNangCauHoi->show();

    ui->bangDuLieu->clear();
    ui->bangDuLieu->setColumnCount(7);

    ui->bangDuLieu->setColumnWidth(0, 100);
    ui->bangDuLieu->setColumnWidth(1, 250);
    ui->bangDuLieu->setColumnWidth(2, 300);
    ui->bangDuLieu->setColumnWidth(3, 200);
    ui->bangDuLieu->setColumnWidth(4, 200);
    ui->bangDuLieu->setColumnWidth(5, 200);
    ui->bangDuLieu->setColumnWidth(6, 200);

    QStringList headers;
    headers << "Mã MH" << "Tên Môn Học" << "Câu Hỏi" << "A" << "B" << "C" << "D";
    ui->bangDuLieu->setHorizontalHeaderLabels(headers);
    int totalQuestions = demTatCaCauHoi(root);
    int row = 0;
    ui->bangDuLieu->setRowCount(totalQuestions);
    loadCauHoi(root, row);
    connect(ui->locCauHoi, SIGNAL(currentIndexChanged(int)), this, SLOT(onCauHoiComboBoxChanged(int)));
    bool isFirst = true;
    dsMonHoc(root, isFirst);
}

void GIao_Vien::loadCauHoi(ptrMonHoc root, int &row)
{
    if (root == nullptr) {
        qDebug() << "Root la nullptr, tra ve.";
        return;
    }

    qDebug() << "Dang load cay con ben trai cua: " << root->MH.MAMH;
    loadCauHoi(root->left, row);

    CauHoi* cauHoi = root->MH.headCauhoi;
    while (cauHoi != nullptr) {
        qDebug() << "Dang load cau hoi: " << cauHoi->noiDung;
        ui->bangDuLieu->setItem(row, 0, new QTableWidgetItem(root->MH.MAMH));
        ui->bangDuLieu->setItem(row, 1, new QTableWidgetItem(root->MH.TENMH));
        ui->bangDuLieu->setItem(row, 2, new QTableWidgetItem(cauHoi->noiDung));
        ui->bangDuLieu->setItem(row, 3, new QTableWidgetItem(cauHoi->A));
        ui->bangDuLieu->setItem(row, 4, new QTableWidgetItem(cauHoi->B));
        ui->bangDuLieu->setItem(row, 5, new QTableWidgetItem(cauHoi->C));
        ui->bangDuLieu->setItem(row, 6, new QTableWidgetItem(cauHoi->D));
        cauHoi = cauHoi->next;
        row++;
    }

    qDebug() << "Dang load cay con ben phai cua: " << root->MH.MAMH;
    loadCauHoi(root->right, row);
}

void GIao_Vien::on_sinhVien_clicked() {
    ui->tinhNangCauHoi->hide();
    ui->tinhNangSinhVien->show();

    ui->bangDuLieu->setContextMenuPolicy(Qt::CustomContextMenu);

    contextMenu = new QMenu(this);
    deleteAction = new QAction("Xóa", this);
    editAction = new QAction("Hiệu chỉnh", this);

    contextMenu->addAction(deleteAction);
    contextMenu->addAction(editAction);

    connect(ui->bangDuLieu, &QTableWidget::customContextMenuRequested, this, &GIao_Vien::showContextMenu);
    connect(deleteAction, &QAction::triggered, this, &GIao_Vien::xoaSV);
    connect(editAction, &QAction::triggered, this, &GIao_Vien::hieuChinhSV);

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
    connect(ui->timMSSV, &QLineEdit::textChanged, this, &GIao_Vien::timSinhVien);
}

void GIao_Vien::on_sapXep_clicked()
{
    dasapxep = true;
    for (int i = 0; i < 10000; ++i) {
        qDebug() << "CB sap xep";
        if (danhSachLop[i] == nullptr) {
            break;
        }

        SinhVien* head = danhSachLop[i]->DSSV;
        if (head == nullptr || head->next == nullptr) {
            continue;
        }

        bool swapped;
        do {
            swapped = false;
            SinhVien* current = head;
            SinhVien* prev = nullptr;
            SinhVien* next = current->next;

            while (next != nullptr) {
                if (current->ten > next->ten) {
                    // Đổi chỗ hai node
                    if (prev == nullptr) {
                        // Đổi chỗ tại đầu danh sách
                        head = next;
                    } else {
                        prev->next = next;
                    }
                    current->next = next->next;
                    next->next = current;

                    // Cập nhật con trỏ
                    swapped = true;
                    prev = next;
                    next = current->next;
                } else {
                    // Di chuyển con trỏ
                    prev = current;
                    current = next;
                    next = next->next;
                }
            }
        } while (swapped);

        // Cập nhật lại danh sách sinh viên của lớp
        danhSachLop[i]->DSSV = head;
    }

    // Tải lại bảng sinh viên sau khi sắp xếp
    loadSinhVien();
    qDebug() << "Đã sắp xếp danh sách sinh viên theo tên.";
}

void GIao_Vien::on_themNhieuSV_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Excel File"), "", tr("Excel Files (*.xlsx *.xls)"));
    if (!fileName.isEmpty()) {
        qDebug() << "File selected:" << fileName;
    }
    loadSinhVienTuFile(fileName);
    loadSinhVien();
}

