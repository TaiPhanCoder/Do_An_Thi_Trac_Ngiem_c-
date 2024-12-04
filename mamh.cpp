#include "mamh.h"
#include "cau_hoi.h"

MaMH::MaMH() {}
#include<algorithm>
#include<QDebug>
#include<QFile>
using namespace std;

typedef NodeMonHoc* ptrMonHoc;

// Hàm tính chiều cao của node
int height(ptrMonHoc n) {
    if (n == NULL)
        return 0;
    return n->height;
}

ptrMonHoc newNode(QString mamh_input, QString tenmh_input) {
    ptrMonHoc node = new NodeMonHoc;
    node->MH.MAMH = mamh_input;
    node->MH.TENMH = tenmh_input;
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

ptrMonHoc insertNodeAVL(ptrMonHoc node, QString mamh_input, QString tenmh_input) {
    if (node == nullptr)
        return newNode(mamh_input, tenmh_input);

    if (mamh_input < node->MH.MAMH)
        node->left = insertNodeAVL(node->left, mamh_input, tenmh_input);
    else if (mamh_input > node->MH.MAMH)
        node->right = insertNodeAVL(node->right, mamh_input, tenmh_input);
    else
        return node; // Mã môn học đã tồn tại

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Cân bằng cây AVL

    // Trường hợp Left Left
    if (balance > 1 && mamh_input < node->left->MH.MAMH)
        return rightRotate(node);

    // Trường hợp Right Right
    if (balance < -1 && mamh_input > node->right->MH.MAMH)
        return leftRotate(node);

    // Trường hợp Left Right
    if (balance > 1 && mamh_input > node->left->MH.MAMH) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Trường hợp Right Left
    if (balance < -1 && mamh_input < node->right->MH.MAMH) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

ptrMonHoc readFileAndBuildAVL() {
    ptrMonHoc root = nullptr;
    QFile file(":/TK-MK-PTIT/MH-CauHoi.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Không thể mở file!";
        return root;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split("|");

        // Kiểm tra nếu dòng có đúng 3 phần
        if (parts.size() == 2) {
            QString mamh = parts[0].trimmed();  // Mã môn học
            QString tenmh = parts[1].trimmed(); // Tên môn học
            root = insertNodeAVL(root, mamh, tenmh); // Thêm node vào cây AVL
        }
    }

    file.close();
    return root;
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
    while (p != nullptr) {
        if (p->MH.MAMH == mamh_input) // So sánh giữa hai QString
            return p;
        else if (p->MH.MAMH > mamh_input)
            p = p->left;
        else
            p = p->right;
    }
    return nullptr;
}

// Đếm số lượng node
int demNode(ptrMonHoc p) {
    if (p == NULL)
        return 0;
    return 1 + demNode(p->left) + demNode(p->right);
}

int demTatCaCauHoi(ptrMonHoc root) {
    if (root == nullptr) {
        qDebug() << "Null lun r bay oi";
        return 0;
    }

    int leftCount = demTatCaCauHoi(root->left);
    int rightCount = demTatCaCauHoi(root->right);
    int currentCount = demCauHoi(root->MH.headCauhoi);
    return leftCount + rightCount + currentCount;
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

ptrMonHoc loadToanBoCauHoi() {
    ptrMonHoc root = nullptr;
    QFile file(":/TK-MK-PTIT/MH-CauHoi.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Không thể mở file!";
        return root;
    }

    QTextStream in(&file);
    ptrMonHoc currentNode = nullptr;
    CauHoi* tail = nullptr;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split("|");

        // Kiểm tra nếu đây là phần mã môn học và tên môn học
        if (parts.size() == 2) {
            QString mamh = parts[0].trimmed();
            QString tenmh = parts[1].trimmed();
            root = insertNodeAVL(root, mamh, tenmh);
            currentNode = SearchNode(root, mamh);
            tail = nullptr;

            if (currentNode == nullptr) {
                qDebug() << "Lỗi: Không tìm thấy node môn học sau khi thêm mã môn học:" << mamh;
            }
        }
        else if (parts.size() == 7 && currentNode != nullptr) {
            int id = parts[0].toInt();
            QString noiDung = parts[1];
            QString A = parts[2];
            QString B = parts[3];
            QString C = parts[4];
            QString D = parts[5];
            QChar dapAnDung = parts[6].at(0);

            CauHoi* newCauHoi = taoNodeCauHoi(id, noiDung, A, B, C, D, dapAnDung);

            if (newCauHoi == nullptr) {
                qDebug() << "Lỗi: Không thể tạo node câu hỏi với ID:" << id;
                continue;
            }

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
    return root;
}


