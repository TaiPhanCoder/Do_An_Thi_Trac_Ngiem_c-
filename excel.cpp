// #include "excel.h"
// #include <QDebug>
// #include <OpenXLSX,hpp>
// #include <QString>

// excel::excel() {}

// void manageStudentData(const QString& filePath, const QString& action, const QString& mssv, const QString& ho, const QString& ten, const QString& phai) {
//     // Chuyển đổi đường dẫn từ QString sang std::string
//     std::string path = filePath.toStdString();

//     // Mở file Excel
//     OpenXLSX::XLDocument doc;
//     doc.open(path);
//     auto worksheet = doc.workbook().sheet(0); // Giả sử bạn làm việc với sheet đầu tiên

//     if (action == "add") {
//         // Tìm hàng cuối cùng có dữ liệu
//         int row = 1;
//         while (!worksheet.cell("A" + std::to_string(row)).value().isEmpty()) {
//             row++;
//         }

//         // Thêm dữ liệu sinh viên vào hàng mới
//         worksheet.cell("A" + std::to_string(row)).value() = mssv.toStdString();
//         worksheet.cell("B" + std::to_string(row)).value() = ho.toStdString();
//         worksheet.cell("C" + std::to_string(row)).value() = ten.toStdString();
//         worksheet.cell("D" + std::to_string(row)).value() = phai.toStdString();

//         qDebug() << "Sinh viên đã được thêm vào danh sách.";
//     } else if (action == "delete") {
//         // Tìm sinh viên cần xóa
//         int row = 1;
//         while (!worksheet.cell("A" + std::to_string(row)).value().isEmpty()) {
//             if (worksheet.cell("A" + std::to_string(row)).value().get<std::string>() == mssv.toStdString()) {
//                 // Xóa dữ liệu bằng cách làm rỗng các ô
//                 worksheet.cell("A" + std::to_string(row)).value().clear();
//                 worksheet.cell("B" + std::to_string(row)).value().clear();
//                 worksheet.cell("C" + std::to_string(row)).value().clear();
//                 worksheet.cell("D" + std::to_string(row)).value().clear();
//                 qDebug() << "Sinh viên có MSSV" << mssv << "đã được xóa.";
//                 break;
//             }
//             row++;
//         }
//     } else if (action == "edit") {
//         // Tìm sinh viên cần chỉnh sửa
//         int row = 1;
//         while (!worksheet.cell("A" + std::to_string(row)).value().isEmpty()) {
//             if (worksheet.cell("A" + std::to_string(row)).value().get<std::string>() == mssv.toStdString()) {
//                 // Cập nhật thông tin sinh viên
//                 worksheet.cell("B" + std::to_string(row)).value() = ho.toStdString();
//                 worksheet.cell("C" + std::to_string(row)).value() = ten.toStdString();
//                 worksheet.cell("D" + std::to_string(row)).value() = phai.toStdString();
//                 qDebug() << "Thông tin sinh viên có MSSV" << mssv << "đã được cập nhật.";
//                 break;
//             }
//             row++;
//         }
//     } else {
//         qDebug() << "Hành động không hợp lệ.";
//     }

//     // Lưu file và đóng
//     doc.save();
//     doc.close();
// }
