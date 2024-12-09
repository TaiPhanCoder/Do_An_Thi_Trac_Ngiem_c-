# Install script for directory: E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OpenXLSX/headers" TYPE FILE FILES "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/OpenXLSX/OpenXLSX/OpenXLSX-Exports.hpp")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OpenXLSX/headers" TYPE FILE FILES
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/IZipArchive.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLCell.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLCellIterator.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLCellRange.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLCellReference.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLCellValue.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLColor.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLColumn.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLCommandQuery.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLComments.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLConstants.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLContentTypes.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLDateTime.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLDocument.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLException.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLFormula.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLIterator.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLMergeCells.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLProperties.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLRelationships.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLRow.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLRowData.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLSharedStrings.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLSheet.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLStyles.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLWorkbook.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLXmlData.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLXmlFile.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLXmlParser.hpp"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/headers/XLZipArchive.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OpenXLSX" TYPE FILE FILES "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/OpenXLSX.hpp")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "lib" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/output/libOpenXLSXd.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX" TYPE FILE FILES
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/OpenXLSX/OpenXLSX/OpenXLSXConfig.cmake"
    "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/OpenXLSX/OpenXLSX/OpenXLSX/OpenXLSXConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX/OpenXLSXTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX/OpenXLSXTargets.cmake"
         "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/OpenXLSX/OpenXLSX/CMakeFiles/Export/c72cc94553a1a0c9b05f75dae42fb1d7/OpenXLSXTargets.cmake")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX" TYPE FILE FILES "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/OpenXLSX/OpenXLSX/CMakeFiles/Export/c72cc94553a1a0c9b05f75dae42fb1d7/OpenXLSXTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/OpenXLSX" TYPE FILE FILES "E:/bulientuc/Do_An_Thi_Trac_Ngiem_c-/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/OpenXLSX/OpenXLSX/CMakeFiles/Export/c72cc94553a1a0c9b05f75dae42fb1d7/OpenXLSXTargets-debug.cmake")
  endif()
endif()

