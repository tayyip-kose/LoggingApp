# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\LogApp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\LogApp_autogen.dir\\ParseCache.txt"
  "LogApp_autogen"
  )
endif()
