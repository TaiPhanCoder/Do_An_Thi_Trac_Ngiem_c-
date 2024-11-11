cmake_minimum_required(VERSION 3.16)

project(THI_TRAC_NGHIEM VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        dang_nhap.cpp
        dang_nhap.h
        dang_nhap.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(THI_TRAC_NGHIEM
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        resources.qrc
        trac_nghiem.h trac_nghiem.cpp trac_nghiem.ui
        giao_vien.h giao_vien.cpp giao_vien.ui
        globals.h
        globals.cpp
        thong_tin_thi.h thong_tin_thi.cpp thong_tin_thi.ui
        cau_hoi.h cau_hoi.cpp
        test.cpp
        mamh.h mamh.cpp
        cau_hoi_da_thi.h cau_hoi_da_thi.cpp
        sinhvien.h sinhvien.cpp
        sinhvien.h sinhvien.cpp
        lop.h lop.cpp
        excel.h excel.cpp
        them_sinh_vien.h them_sinh_vien.cpp them_sinh_vien.ui
        hieuchinh.h hieuchinh.cpp hieuchinh.ui

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET THI_TRAC_NGHIEM APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(THI_TRAC_NGHIEM SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(THI_TRAC_NGHIEM
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(THI_TRAC_NGHIEM PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.THI_TRAC_NGHIEM)
endif()
set_target_properties(THI_TRAC_NGHIEM PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
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
