#ifndef GLOBALS_H
#define GLOBALS_H
#include<QString>
#include "cau_hoi_da_thi.h"

struct DiemThi{
    QString maMH;
    float diem;
    DiemThi* next;
};

extern bool GV;
extern int times;
extern int questions;
extern QString monhoc;
extern QString maMH;

#endif
