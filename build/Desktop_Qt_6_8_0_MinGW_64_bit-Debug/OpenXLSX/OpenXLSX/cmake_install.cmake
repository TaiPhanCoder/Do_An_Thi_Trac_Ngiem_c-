# Install script for directory: D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/THI_TRAC_NGHIEM")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Qt/Tools/mingw1310_64/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OpenXLSX/headers" TYPE FILE FILES "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/OpenXLSX/OpenXLSX/OpenXLSX-Exports.hpp")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OpenXLSX/headers" TYPE FILE FILES
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/IZipArchive.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLCell.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLCellIterator.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLCellRange.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLCellReference.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLCellValue.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLColor.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLColumn.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLCommandQuery.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLComments.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLConstants.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLContentTypes.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLDateTime.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLDocument.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLException.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLFormula.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLIterator.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLMergeCells.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLProperties.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLRelationships.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLRow.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLRowData.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLSharedStrings.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLSheet.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLStyles.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLWorkbook.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLXmlData.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLXmlFile.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLXmlParser.hpp"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLZipArchive.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OpenXLSX" TYPE FILE FILES "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/OpenXLSX.hpp")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "lib" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/output/libOpenXLSXd.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX" TYPE FILE FILES
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/OpenXLSXConfig.cmake"
    "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/OpenXLSX/OpenXLSX/OpenXLSX/OpenXLSXConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX/OpenXLSXTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX/OpenXLSXTargets.cmake"
         "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/OpenXLSX/OpenXLSX/CMakeFiles/Export/c72cc94553a1a0c9b05f75dae42fb1d7/OpenXLSXTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX/OpenXLSXTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX/OpenXLSXTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX" TYPE FILE FILES "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/OpenXLSX/OpenXLSX/CMakeFiles/Export/c72cc94553a1a0c9b05f75dae42fb1d7/OpenXLSXTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX" TYPE FILE FILES "D:/DO_AN_THI_TRAC_NGHIEM/Do_An_Thi_Trac_Ngiem_c-/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/OpenXLSX/OpenXLSX/CMakeFiles/Export/c72cc94553a1a0c9b05f75dae42fb1d7/OpenXLSXTargets-debug.cmake")
  endif()
endif()

