#ifndef EXCEL_H
#define EXCEL_H
#include <QFileDialog>
#include "lop.h"

class excel
{
public:
    excel();
};

void loadSinhVienTuFile(Lop* danhSachLop[], const QString &fileName, bool dasapxep);

#endif // EXCEL_H
