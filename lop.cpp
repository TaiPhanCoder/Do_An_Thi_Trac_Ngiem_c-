#include "lop.h"
#include "sinhvien.h"

#include <QFile>
#include <QDebug>

lop::lop() {}

void themSinhVienVaoLopCoThuTu(SinhVien* newSV, const QString &lop, Lop** danhSachLop) {
    int i = 0;
    while (danhSachLop[i] != nullptr) {
        if (danhSachLop[i]->MALOP == lop) {
            SinhVien* current = danhSachLop[i]->DSSV;
            SinhVien* prev = nullptr;

            while (current != nullptr && current->ten < newSV->ten) {
                prev = current;
                current = current->next;
            }

            if (prev == nullptr) {
                newSV->next = danhSachLop[i]->DSSV;
                danhSachLop[i]->DSSV = newSV;
            } else {
                prev->next = newSV;
                newSV->next = current;
            }
            return;
        }
        ++i;
    }
}

void themSinhVienVaoLop(SinhVien* newSV, const QString &lop, Lop** danhSachLop) {
    int i = 0;
    while (danhSachLop[i] != nullptr) {
        if (danhSachLop[i]->MALOP == lop) {
            newSV->next = danhSachLop[i]->DSSV;
            danhSachLop[i]->DSSV = newSV;
            return;
        }
        ++i;
    }
}

int demSoLop(Lop* danhSachLop[]) {
    int count = 0;
    for (int i = 0; i < MAX; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }
        count++;
    }
    return count;
}

bool checkMSSV(const QString &newMssv, Lop** danhSachLop) {
    for (int i = 0; i < 10000; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }
        SinhVien* current = danhSachLop[i]->DSSV;
        while (current != nullptr) {
            if (current->masv == newMssv) {
                qDebug() << "MSSV bị trùng:" << newMssv;
                return false;
            }
            current = current->next;
        }
    }
    return true;
}

int demSVLop(Lop* lop) {
    int count = 0;
    SinhVien* current = lop->DSSV;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

void xoaSinhVienKhoiLop(SinhVien* sv, const QString& lop, Lop** danhSachLop) {
    for (int i = 0; i < 10000; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }
        if (danhSachLop[i]->MALOP == lop) {
            SinhVien* current = danhSachLop[i]->DSSV;
            SinhVien* prev = nullptr;
            while (current != nullptr) {
                if (current == sv) {
                    if (prev == nullptr) {
                        // Nếu sinh viên cần xóa là sinh viên đầu danh sách
                        danhSachLop[i]->DSSV = current->next;
                    } else {
                        // Xóa sinh viên khỏi danh sách liên kết
                        prev->next = current->next;
                    }
                    delete current; // Xóa đối tượng sinh viên khỏi bộ nhớ
                    return;
                }
                prev = current;
                current = current->next;
            }
        }
    }
}

SinhVien* timSinhVien(const QString& mssv, const QString& lop, Lop** danhSachLop) {
    for (int i = 0; i < 10000; ++i) {
        if (danhSachLop[i] == nullptr) {
            break;
        }
        if (danhSachLop[i]->MALOP == lop) {
            SinhVien* current = danhSachLop[i]->DSSV;
            while (current != nullptr) {
                if (current->masv == mssv) {
                    return current;
                }
                current = current->next;
            }
        }
    }
    return nullptr;
}

void lapdssinhvien(const QString &filename, Lop* danhSachLop[]) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Không thể mở file!";
        return;
    }

    QTextStream in(&file);
    Lop* currentLop = nullptr;
    SinhVien* currentSV = nullptr;

    int lopIndex = 0;
    int soLop = in.readLine().toInt();  // Đọc số lượng lớp

    for (int i = 0; i < soLop; ++i) {
        // Đọc thông tin lớp
        QString line = in.readLine().trimmed();
        if (line.contains('|')) {
            QStringList lopFields = line.split('|');
            if (lopFields.size() == 2) {
                currentLop = new Lop;
                currentLop->MALOP = lopFields.at(0).trimmed();
                currentLop->TENLOP = lopFields.at(1).trimmed();
                currentLop->DSSV = nullptr;

                if (lopIndex < MAX) {
                    danhSachLop[lopIndex++] = currentLop;
                } else {
                    qDebug() << "Danh sách lớp đã đầy!";
                    break;
                }
            }
        }

        // Đọc số lượng sinh viên trong lớp
        int soSinhVien = in.readLine().toInt();
        SinhVien* tail = nullptr;
        for (int j = 0; j < soSinhVien; ++j) {
            line = in.readLine().trimmed();
            QStringList studentFields = line.split('|');
            if (studentFields.size() == 5) {
                QString masv = studentFields.at(0).trimmed();
                QString ho = studentFields.at(1).trimmed();
                QString ten = studentFields.at(2).trimmed();
                QString phai = studentFields.at(3).trimmed();
                QString password = studentFields.at(4).trimmed();

                SinhVien* newSV = taoNodeSinhVien(masv, ho, ten, phai, password);
                if (currentLop->DSSV == nullptr) {
                    currentLop->DSSV = newSV;
                    tail = newSV;
                } else {
                    themSinhVien(tail, newSV);
                    tail = newSV;
                }
                currentSV = newSV;

                // Đọc số môn học đã thi
                int soMonHocDaThi = in.readLine().toInt();
                for (int k = 0; k < soMonHocDaThi; ++k) {
                    QString line = in.readLine().trimmed();
                    QStringList monHocFields = line.split('|');
                    if (monHocFields.size() == 2) {
                        QString maMH = monHocFields.at(0).trimmed();
                        float diem = monHocFields.at(1).toFloat();

                        monHocDaThi* newMonHoc = newmonHocDaThi(maMH, diem, 0);
                        themMonHoc(currentSV->ds_diemthi, newMonHoc);

                        // Đọc số câu hỏi đã thi
                        int soCauThi = in.readLine().toInt();
                        newMonHoc->soCauThi = soCauThi; // Gán số câu thi cho thuộc tính soCauThi
                        newMonHoc->mangDaThi = new DaThi[soCauThi];

                        for (int m = 0; m < soCauThi; ++m) {
                            QStringList cauHoiFields = in.readLine().trimmed().split('|');
                            if (cauHoiFields.size() == 2) {
                                int id = cauHoiFields.at(0).toInt();
                                QChar dapAn = cauHoiFields.at(1).trimmed().at(0);
                                newMonHoc->mangDaThi[m].id = id;
                                newMonHoc->mangDaThi[m].dapAn = dapAn;
                            }
                        }
                    }
                }
            }
        }
    }

    file.close();
    qDebug() << "Dữ liệu đã được đọc thành công.";
}
