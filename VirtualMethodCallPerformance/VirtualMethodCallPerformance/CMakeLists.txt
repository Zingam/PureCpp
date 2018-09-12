################################################################################
cmake_minimum_required (VERSION 3.11)
################################################################################
message ("CMake version: " ${CMAKE_VERSION})
################################################################################

################################################################################
# Project properties
################################################################################

project ("VirtualMethodCallPerformance")

add_executable (${PROJECT_NAME}
  "Sources/EventHandlers.cpp"
  "Sources/EventHandlers.hpp"
  "Sources/Events.cpp"
  "Sources/Events.hpp"
  "Sources/EventType.hpp"
  "Sources/main.cpp"
)
