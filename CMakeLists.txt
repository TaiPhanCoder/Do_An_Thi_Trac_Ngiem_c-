cmake_minimum_required(VERSION 3.16)

project(THI_TRAC_NGHIEM VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Thêm thư mục OpenXLSX vào dự án
add_subdirectory(OpenXLSX)

set(PROJECT_SOURCES
    main.cpp
    dang_nhap.cpp
    dang_nhap.h
    dang_nhap.ui
    resources.qrc
    trac_nghiem.h trac_nghiem.cpp trac_nghiem.ui
    giao_vien.h giao_vien.cpp giao_vien.ui


    thong_tin_thi.h thong_tin_thi.cpp thong_tin_thi.ui
    cau_hoi.h cau_hoi.cpp
    test.cpp
    mamh.h mamh.cpp
    cau_hoi_da_thi.h cau_hoi_da_thi.cpp
    sinhvien.h sinhvien.cpp
    lop.h lop.cpp
    excel.h excel.cpp
    them_sinh_vien.h them_sinh_vien.cpp them_sinh_vien.ui
    hieuchinh_SinhVien.h hieuchinh_SinhVien.cpp hieuchinh_SinhVien.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(THI_TRAC_NGHIEM
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        themcauhoi.h themcauhoi.cpp themcauhoi.ui
        hieuchinh_cauhoi.h hieuchinh_cauhoi.cpp hieuchinh_cauhoi.ui
        xemdiem.h xemdiem.cpp xemdiem.ui
        them_lop.h them_lop.cpp them_lop.ui
        hieuchinh_lop.h hieuchinh_lop.cpp hieuchinh_lop.ui

    )
else()
    if(ANDROID)
        add_library(THI_TRAC_NGHIEM SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(THI_TRAC_NGHIEM
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Liên kết OpenXLSX và Qt Widgets với executable
target_link_libraries(THI_TRAC_NGHIEM PRIVATE Qt${QT_VERSION_MAJOR}::Widgets OpenXLSX)

# Các thiết lập khác cho dự án
set_target_properties(THI_TRAC_NGHIEM PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS THI_TRAC_NGHIEM
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(THI_TRAC_NGHIEM)
endif()
