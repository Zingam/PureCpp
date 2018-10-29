################################################################################
cmake_minimum_required (VERSION 3.11)
################################################################################
message ("CMake version: " ${CMAKE_VERSION})
################################################################################

################################################################################
# Project properties
################################################################################

project ("Operator_new_Overloading")

add_executable (${PROJECT_NAME}
  "Sources/main.cpp"
)
set_target_properties(${PROJECT_NAME}
  PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
)
