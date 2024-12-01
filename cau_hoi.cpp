#include "cau_hoi.h"
#include <QString>
#include <QFile>
#include <QDebug>

CauHoi *headCauhoi = nullptr;

cau_hoi::cau_hoi() {}

CauHoi* taoNodeCauHoi(int id, QString noiDung, QString A, QString B, QString C, QString D, QChar dapAnDung) {

    CauHoi* cauHoi = new CauHoi;
    cauHoi->id = id;
    cauHoi->noiDung = noiDung;
    cauHoi->A = A;
    cauHoi->B = B;
    cauHoi->C = C;
    cauHoi->D = D;
    cauHoi->dapAnDung = dapAnDung;
    cauHoi->next = nullptr;

    return cauHoi;
}

void shuffleArray(CauHoi* arr[], int questions) {
    std::srand(std::time(0));

    for (int i = 0; i < questions; ++i) {
        int randomIndex = rand() % (questions - i) + i;
        CauHoi* temp = arr[i];
        arr[i] = arr[randomIndex];
        arr[randomIndex] = temp;
    }
}

CauHoi** loadCauHoiThi(const QString &monHoc, int &questions, int &soCauHoi) {
    QFile file(":/TK-MK-PTIT/MH-CauHoi.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Không thể mở file câu hỏi.";
        return nullptr;
    }

    QTextStream in(&file);
    CauHoi** cauhoiArray = nullptr;
    bool foundMonHoc = false;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();

        if (line.contains(monHoc)) {
            foundMonHoc = true;
            line = in.readLine().trimmed(); // Đọc dòng chứa số lượng câu hỏi
            soCauHoi = line.toInt();

            if (soCauHoi < questions) {
                return nullptr;
            }

            cauhoiArray = new CauHoi*[soCauHoi + 5]; // Cấp phát mảng động

            for (int i = 0; i < soCauHoi; ++i) {
                QString cauHoiLine = in.readLine().trimmed();
                QStringList parts = cauHoiLine.split('|');
                if (parts.size() == 7) {
                    int id = parts[0].toInt();
                    QString noiDung = parts[1];
                    QString A = parts[2];
                    QString B = parts[3];
                    QString C = parts[4];
                    QString D = parts[5];
                    QChar dapAnDung = parts[6].at(0);

                    cauhoiArray[i] = taoNodeCauHoi(id, noiDung, A, B, C, D, dapAnDung);
                } else {
                    qDebug() << "Lỗi định dạng câu hỏi.";
                }
            }
            break;
        }
    }

    if (!foundMonHoc) {
        qDebug() << "Không tìm thấy môn học:" << monHoc;
    }

    file.close();
    shuffleArray(cauhoiArray, soCauHoi);
    return cauhoiArray;
}

CauHoi* DsachCauHoiThi(CauHoi** cauhoiArray, int questions) {
    CauHoi* head = nullptr;

    for (int i = 0; i < questions; ++i) {
        cauhoiArray[i]->next = head;
        head = cauhoiArray[i];
    }

    return head;
}

int demCauHoi(CauHoi* head) {
    int count = 0;
    CauHoi* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void duyetDSach(CauHoi* head) {
    CauHoi* current = head;
    while (current != nullptr) {
        qDebug() << "ID Câu hỏi:" << current->id;
        current = current->next;
    }
}
