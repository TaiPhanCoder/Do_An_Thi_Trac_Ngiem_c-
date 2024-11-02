// #include <QFile>
// #include <QTextStream>
// #include <QString>
// #include <QDebug>
// #include "cau_hoi.h"
// #include "globals.h"

// int* taoRanDom(int question_count, int bank_size) {
//     int* result_array = new int[question_count];

//     // Tạo mảng phụ để lưu các số đã sử dụng
//     bool* used = new bool[bank_size + 1]();

//     int count = 0;
//     while (count < question_count) {
//         int random_num = rand() % (bank_size - count) + 1 + count;
//         if (!used[random_num]) {
//             result_array[count] = random_num;
//             used[random_num] = true;
//             count++;
//         }
//     }

//     delete[] used;
//     return result_array;
// }

// void swap(int& a, int& b) {
//     int temp = a;
//     a = b;
//     b = temp;
// }

// int partition(int arr[], int low, int high) {
//     int pivot = arr[low];  // chọn phần tử đầu làm pivot
//     int i = low - 1;
//     int j = high + 1;
//     while (true) {
//         do {
//             i++;
//         } while (arr[i] < pivot);

//         do {
//             j--;
//         } while (arr[j] > pivot);

//         if (i >= j) {
//             return j;
//         }
//         swap(arr[i], arr[j]);
//     }
// }

// // Hàm quicksort
// void quicksort(int arr[], int low, int high) {
//     if (low < high) {
//         int partitionIndex = partition(arr, low, high);
//         quicksort(arr, low, partitionIndex);
//         quicksort(arr, partitionIndex + 1, high);
//     }
// }

// CauHoi* newCauHoi(QString id, QString noiDung, QString A, QString B, QString C, QString D, QChar dapAnDung) {
//     CauHoi* cauHoi = new CauHoi;
//     cauHoi->id = id;
//     cauHoi->noiDung = noiDung;
//     cauHoi->A = A;
//     cauHoi->B = B;
//     cauHoi->C = C;
//     cauHoi->D = D;
//     cauHoi->dapAnDung = dapAnDung;
//     cauHoi->next = nullptr;
//     return cauHoi;
// }

// CauHoi* shuffleQuestions(CauHoi* head) {
//     // Bước 1: Tạo mảng động để chứa các câu hỏi từ danh sách liên kết
//     CauHoi** questionArray = new CauHoi*[5];
//     int index = 0;

//     // Thu thập tất cả câu hỏi từ danh sách liên kết vào mảng
//     CauHoi* current = head;
//     while (current != nullptr && index < 5) {
//         questionArray[index] = current;
//         current = current->next;
//         index++;  // Tăng index sau mỗi lần thêm câu hỏi
//     }

//     // In ra câu hỏi trong mảng trước khi xáo trộn
//     // for (int i = 0; i < 5; ++i) {
//     //     qDebug() << questionArray[i]->noiDung;
//     // }

//     // Bước 2: Xáo trộn câu hỏi
//     for (int i = 0; i < 5; ++i) {
//         // Tạo số ngẫu nhiên từ i đến 4 (5 - 1)
//         int randomIndex = rand() % (5 - i) + i;

//         // Hoán đổi câu hỏi tại vị trí i và vị trí randomIndex
//         CauHoi* temp = questionArray[i];
//         questionArray[i] = questionArray[randomIndex];
//         questionArray[randomIndex] = temp;
//     }

//     // Bước 3: Tạo lại danh sách liên kết từ mảng đã xáo trộn
//     CauHoi* newHead = nullptr;
//     CauHoi* newTail = nullptr;

//     for (int i = 0; i < 5; ++i) {
//         CauHoi* cauHoi = questionArray[i];
//         cauHoi->next = nullptr; // Đảm bảo mỗi câu hỏi không trỏ đến câu hỏi cũ
//         if (newHead == nullptr) {
//             newHead = cauHoi;
//             newTail = cauHoi;
//         } else {
//             newTail->next = cauHoi;
//             newTail = cauHoi;
//         }
//     }

//     // Giải phóng bộ nhớ của mảng
//     delete[] questionArray;

//     // Trả về danh sách liên kết mới đã xáo trộn
//     return newHead;
// }


// CauHoi* docCauHoiTuFile(const QString& monHoc) {
//     QFile file(":/TK-MK-PTIT/MH-CauHoi.txt");
//     if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//         qWarning() << "Không thể mở file!";
//         return nullptr;
//     }

//     QTextStream in(&file);
//     CauHoi* head = nullptr;

//     while (!in.atEnd()) {
//         QString line = in.readLine();
//         QStringList parts = line.split("|");

//         // Tìm đúng môn học
//         if (parts.size() >= 2 && parts[1].trimmed() == monHoc) {
//             // Đọc số lượng câu hỏi
//             // qDebug() << parts[1].trimmed();
//             QString soLuongStr = in.readLine();
//             // qDebug() << soLuongStr;
//             int soLuongCauHoi = soLuongStr.toInt();

//             int lastPosition = 0;  // Biến để lưu lại vị trí câu hỏi đã đọc cuối cùng
//             int* arr = taoRanDom(5,soLuongCauHoi);
//             // qDebug() << "Mảng câu hỏi ngẫu nhiên:";
//             quicksort(arr,0,4);
//             // for (int i = 0; i < 5; ++i) {
//             //     qDebug() << "arr[" << i << "] = " << arr[i];
//             // }
//             for (int i = 0; i < 5; ++i) {
//                 int currentIdx = arr[i];  // Lấy vị trí câu hỏi từ mảng arr
//                 QString line;

//                 // Tìm đúng vị trí câu hỏi theo `arr[i]`, bắt đầu từ vị trí lastPosition
//                 while (lastPosition < currentIdx && !in.atEnd()) {
//                     line = in.readLine();
//                     lastPosition++;
//                 }

//                 if (!line.isEmpty()) {
//                     QStringList cauHoiParts = line.split("|");
//                     if (cauHoiParts.size() == 7) {
//                         QString id = cauHoiParts[0];
//                         QString noiDung = cauHoiParts[1];
//                         QString A = cauHoiParts[2];
//                         QString B = cauHoiParts[3];
//                         QString C = cauHoiParts[4];
//                         QString D = cauHoiParts[5];
//                         QChar dapAnDung = cauHoiParts[6].at(0);

//                         // Tạo câu hỏi mới và thêm vào danh sách liên kết
//                         CauHoi* cauHoi = newCauHoi(id, noiDung, A, B, C, D, dapAnDung);
//                         if (head == nullptr) {
//                             head = cauHoi;
//                         } else {
//                             cauHoi->next = head;
//                             head = cauHoi;
//                         }
//                     }
//                 }
//             }
//             delete[] arr;
//             break;
//         }
//     }
//     file.close();
//     // CauHoi* temp = head;
//     // while (temp!=nullptr) {
//     //     qDebug() << temp->noiDung;
//     // }
//     // head = shuffleQuestions(head);
//     return head;
// }

// int main() {
//     // Ví dụ: đọc file của môn học INT1303
//     QString monhoc = "AN TOÀN BẢO MẬT HỆ THỐNG THÔNG TIN";
//     CauHoi* cuhoirandom = docCauHoiTuFile(monhoc);
//     CauHoi* temp = cuhoirandom;
//     while (temp != nullptr) {
//         qDebug() << temp->noiDung;
//         temp = temp->next;
//     }
//     CauHoi* cauhoi = shuffleQuestions(cuhoirandom);
//     CauHoi* temp1 = cauhoi;
//     while (temp1 != nullptr) {
//         qDebug() << temp1->noiDung;
//         temp1 = temp1->next;
//     }

//     return 0;
// }
