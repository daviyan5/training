cmake_minimum_required(VERSION 3.10)
project(training)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/stage)

message(STATUS "CMakeLists.txt in root directory")
add_subdirectory(src)
