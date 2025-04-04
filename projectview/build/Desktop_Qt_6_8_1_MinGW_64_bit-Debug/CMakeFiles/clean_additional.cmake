# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\projectview_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\projectview_autogen.dir\\ParseCache.txt"
  "projectview_autogen"
  )
endif()
