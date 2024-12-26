#include "mamh.h"
#include "cau_hoi.h"

MaMH::MaMH() {}
#include<algorithm>
#include<QDebug>
#include<QFile>
using namespace std;

typedef NodeMonHoc* ptrMonHoc;

CauHoi** loadCauHoiThi(ptrMonHoc root, const QString &mamh, int &questions, int &socauhoi) {
    // Tìm môn học thông qua mã môn học
    MonHoc* monHoc = SearchMonHoc(root, mamh);

    if (monHoc == nullptr) {
        qDebug() << "Không tìm thấy môn học với mã:" << mamh;
        return nullptr;
    }

    // Tạo mảng con trỏ cho các câu hỏi, số lượng là socauhoi
    CauHoi** cauhoiArray = new CauHoi*[socauhoi];

    int index = 0;
    CauHoi* current = monHoc->headCauhoi;

    // Thêm các câu hỏi từ danh sách liên kết vào mảng con trỏ
    while (current != nullptr && index < socauhoi) {
        cauhoiArray[index] = current;
        current = current->next;
        index++;
    }

    // Trộn ngẫu nhiên mảng câu hỏi
    shuffleArray(cauhoiArray, questions, index);

    return cauhoiArray;
}

CauHoi* DsachCauHoiThi(ptrMonHoc root, CauHoi** cauhoiArray, int questions, int slCauHoi, const QString &maMH){
    CauHoi* head = nullptr;

    MonHoc* monHoc = SearchMonHoc(root, maMH);

    // Nối danh sách các câu hỏi để thi (từ 0 đến < questions)
    for (int i = 0; i < questions; ++i) {
        cauhoiArray[i]->next = head;
        head = cauhoiArray[i];
    }

    // Nối danh sách các câu hỏi còn lại vào monHoc.dscauhoi
    if (questions < slCauHoi) {
        monHoc->headCauhoi = nullptr;
        for (int i = questions; i < slCauHoi; ++i) {
            cauhoiArray[i]->next = monHoc->headCauhoi;
            monHoc->headCauhoi = cauhoiArray[i];
        }
    } else {
        monHoc->headCauhoi = nullptr;
    }

    return head;
}

// Hàm tính chiều cao của node
int height(ptrMonHoc n) {
    if (n == NULL)
        return 0;
    return n->height;
}

// Hàm xóa toàn bộ cây AVL
void deleteAVLTree(NodeMonHoc* root) {
    if (root == nullptr) return;

    // Xóa toàn bộ danh sách câu hỏi của môn học
    CauHoi* current = root->MH.headCauhoi;
    while (current != nullptr) {
        CauHoi* temp = current;
        current = current->next;
        delete temp;
    }

    // Gọi đệ quy để xóa các node con bên trái và phải
    deleteAVLTree(root->left);
    deleteAVLTree(root->right);

    // Xóa chính node môn học
    delete root;
}

int demCauHoi(ptrMonHoc root, QString mamh) {
    // Tìm môn học trong cây AVL
    MonHoc* monHoc = SearchMonHoc(root, mamh);

    if (monHoc == nullptr) {
        qDebug() << "Không tìm thấy môn học với mã:" << mamh;
        return 0;
    }

    int count = 0;
    CauHoi* current = monHoc->headCauhoi;

    // Duyệt qua danh sách liên kết các câu hỏi và đếm số lượng
    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

MonHoc* SearchMonHoc(ptrMonHoc p, QString mamh_input) {
    if (p == nullptr) {
        return nullptr; // Trả về nullptr nếu node rỗng
    }
    if (p->MH.MAMH == mamh_input) {
        return &(p->MH); // Trả về địa chỉ của MonHoc nếu tìm thấy mã môn học
    }
    else if (mamh_input < p->MH.MAMH) {
        return SearchMonHoc(p->left, mamh_input); // Tìm ở cây con bên trái
    }
    else {
        return SearchMonHoc(p->right, mamh_input); // Tìm ở cây con bên phải
    }
}

ptrMonHoc newNode(QString mamh, QString tenmh, int tinchi) {
    ptrMonHoc node = new NodeMonHoc;
    node->MH.MAMH = mamh;
    node->MH.TENMH = tenmh;
    node->MH.tinChi = tinchi;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Hàm xoay phải
ptrMonHoc rightRotate(ptrMonHoc y) {
    ptrMonHoc x = y->left;
    ptrMonHoc T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Hàm xoay trái
ptrMonHoc leftRotate(ptrMonHoc x) {
    ptrMonHoc y = x->right;
    ptrMonHoc T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Hàm lấy hệ số cân bằng
int getBalance(ptrMonHoc n) {
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

ptrMonHoc insertNodeAVL(ptrMonHoc node, QString mamh, QString tenmh, int tinchi) {
    if (node == nullptr)
        return newNode(mamh, tenmh, tinchi);

    if (mamh < node->MH.MAMH)
        node->left = insertNodeAVL(node->left, mamh, tenmh, tinchi);
    else if (mamh > node->MH.MAMH)
        node->right = insertNodeAVL(node->right, mamh, tenmh, tinchi);
    else
        return node; // Mã môn học đã tồn tại

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Cân bằng cây AVL

    // Trường hợp Left Left
    if (balance > 1 && mamh < node->left->MH.MAMH)
        return rightRotate(node);

    // Trường hợp Right Right
    if (balance < -1 && mamh > node->right->MH.MAMH)
        return leftRotate(node);

    // Trường hợp Left Right
    if (balance > 1 && mamh > node->left->MH.MAMH) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Trường hợp Right Left
    if (balance < -1 && mamh < node->right->MH.MAMH) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

ptrMonHoc minValueNode(ptrMonHoc node) {
    ptrMonHoc current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

ptrMonHoc deleteNodeAVL(ptrMonHoc root, QString mamh_input) {
    if (root == nullptr)
        return root;

    // So sánh trực tiếp với QString MAMH trong node
    if (mamh_input < root->MH.MAMH)
        root->left = deleteNodeAVL(root->left, mamh_input);
    else if (mamh_input > root->MH.MAMH)
        root->right = deleteNodeAVL(root->right, mamh_input);
    else {
        // Trường hợp node cần xóa có 1 hoặc 0 con
        if ((root->left == nullptr) || (root->right == nullptr)) {
            ptrMonHoc temp = root->left ? root->left : root->right;

            // Trường hợp không có con
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp; // Sao chép nội dung của con duy nhất vào root
            delete temp;
        } else {
            // Trường hợp node cần xóa có 2 con: Lấy giá trị nhỏ nhất bên phải
            ptrMonHoc temp = minValueNode(root->right);
            root->MH.MAMH = temp->MH.MAMH;
            root->MH.TENMH = temp->MH.TENMH;
            root->right = deleteNodeAVL(root->right, temp->MH.MAMH);
        }
    }

    // Nếu cây chỉ còn lại 1 node thì trả về
    if (root == nullptr)
        return root;

    // Cập nhật chiều cao của node hiện tại
    root->height = 1 + max(height(root->left), height(root->right));

    // Kiểm tra hệ số cân bằng của node hiện tại
    int balance = getBalance(root);

    // Cân bằng lại cây AVL nếu cần

    // Trường hợp Left Left
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Trường hợp Left Right
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Trường hợp Right Right
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Trường hợp Right Left
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


// Duyệt cây theo thứ tự NLR
void duyetLNR(ptrMonHoc root, QStringList &danhSachMonHoc) {
    if (root != nullptr) {
        duyetLNR(root->left, danhSachMonHoc);
        danhSachMonHoc << root->MH.TENMH;  // Thêm tên môn học vào danh sách
        duyetLNR(root->right, danhSachMonHoc);
    }
}

// Duyệt cây theo thứ tự LRN
void duyetLRN(ptrMonHoc p) {
    if (p != NULL) {
        duyetLRN(p->left);
        duyetLRN(p->right);
        // cout << p->MH.MAMH << " - " << p->MH.TENMH << endl;
    }
}

// Tìm kiếm môn học theo mã môn học
ptrMonHoc SearchNode(ptrMonHoc p, QString mamh_input) {
    if (p == nullptr) {
        return nullptr; // Trả về nullptr nếu node rỗng
    }
    if (p->MH.MAMH == mamh_input) {
        return p; // Trả về node nếu tìm thấy mã môn học
    }
    else if (mamh_input < p->MH.MAMH) {
        return SearchNode(p->left, mamh_input); // Tìm ở cây con bên trái
    }
    else {
        return SearchNode(p->right, mamh_input); // Tìm ở cây con bên phải
    }
}
// Đếm số lượng node
int demNode(ptrMonHoc p) {
    if (p == NULL)
        return 0;
    return 1 + demNode(p->left) + demNode(p->right);
}

NodeMonHoc* findMonHoc(NodeMonHoc* root, QString mamh)
{
    NodeMonHoc* current = root;
    while (current != nullptr) {
        if (current->MH.MAMH == mamh) {
            return current;
        } else if (mamh < current->MH.MAMH) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return nullptr;
}

CauHoi* findCauHoi(NodeMonHoc* root, QString mamh, int id)
{
    NodeMonHoc* monHocNode = findMonHoc(root, mamh);
    if (monHocNode == nullptr) {
        return nullptr;
    }
    CauHoi* headCauHoi = monHocNode->MH.headCauhoi;
    CauHoi* cauHoi = headCauHoi;
    while (cauHoi != nullptr) {
        if (cauHoi->id == id) {
            return cauHoi;
        }
        cauHoi = cauHoi->next;
    }
    return nullptr;
}

void luuLRN(ptrMonHoc root, QTextStream &out) {
    if (root == nullptr) return;

    luuLRN(root->left, out);

    // Ghi thông tin môn học
    out << root->MH.MAMH << "|" << root->MH.TENMH << "\n";

    // Đếm số lượng câu hỏi của môn học
    int count = 0;
    CauHoi* current = root->MH.headCauhoi;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    out << count << "\n";

    // Ghi thông tin các câu hỏi của môn học
    current = root->MH.headCauhoi;
    while (current != nullptr) {
        out << current->id << "|"
            << current->noiDung << "|"
            << current->A << "|"
            << current->B << "|"
            << current->C << "|"
            << current->D << "|"
            << current->dapAnDung << "|"
            << (current->daThi ? "T" : "F") << "\n";

        if (current->next == nullptr) {
            out << "\n"; // Thêm dòng trống nếu là câu hỏi cuối cùng
        }

        current = current->next;
    }

    luuLRN(root->right, out);
}

void luuMonHocVaCauHoi(ptrMonHoc root, const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Không thể mở file để ghi:" << filePath;
        return;
    }

    QTextStream out(&file);

    // Duyệt qua toàn bộ cây AVL của môn học
    luuLRN(root, out);

    file.close();
    qDebug() << "Lưu thành công file môn học và câu hỏi tại:" << filePath;
}

void loadToanBoCauHoi(ptrMonHoc &root, const QString &filepath) {
    QFile file(filepath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Không thể mở file:" << filepath;
        return;
    }

    QTextStream in(&file);
    ptrMonHoc currentNode = nullptr;
    CauHoi* tail = nullptr;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split("|");

        // Kiểm tra nếu đây là phần mã môn học, tên môn học và tín chỉ
        if (parts.size() == 3) {
            QString mamh = parts[0].trimmed();
            QString tenmh = parts[1].trimmed();
            int tinchi = parts[2].toInt();
            root = insertNodeAVL(root, mamh, tenmh, tinchi);
            currentNode = SearchNode(root, mamh);
            qDebug() << currentNode->MH.TENMH;
            tail = nullptr;

            if (currentNode == nullptr) {
                qDebug() << "Lỗi: Không tìm thấy node môn học sau khi thêm mã môn học:" << mamh;
            }
        }
        else if (parts.size() == 8 && currentNode != nullptr) { // Sửa thành 8 phần tử để thêm cột daThi
            int id = parts[0].toInt();
            QString noiDung = parts[1];
            QString A = parts[2];
            QString B = parts[3];
            QString C = parts[4];
            QString D = parts[5];
            QChar dapAnDung = parts[6].at(0);
            bool daThi = (parts[7].trimmed() == "T"); // Thêm phần này để đọc và gán cờ daThi

            CauHoi* newCauHoi = taoNodeCauHoi(id, noiDung, A, B, C, D, dapAnDung);

            if (newCauHoi == nullptr) {
                qDebug() << "Lỗi: Không thể tạo node câu hỏi với ID:" << id;
                continue;
            }

            newCauHoi->daThi = daThi; // Gán giá trị cờ daThi

            // Thêm câu hỏi vào danh sách liên kết đơn của môn học hiện tại
            if (currentNode->MH.headCauhoi == nullptr) {
                currentNode->MH.headCauhoi = newCauHoi;
                tail = newCauHoi;  // Tail sẽ là node đầu tiên
            } else {
                tail->next = newCauHoi;  // Thêm node mới vào sau tail
                tail = newCauHoi;        // Cập nhật lại tail là node vừa thêm
            }
        }
    }

    file.close();
}
