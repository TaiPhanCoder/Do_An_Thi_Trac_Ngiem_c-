# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\THI_TRAC_NGHIEM_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\THI_TRAC_NGHIEM_autogen.dir\\ParseCache.txt"
  "THI_TRAC_NGHIEM_autogen"
  )
endif()
