cmake_minimum_required(VERSION 3.10)
project(01_cmake)

set(HEADERS include/Dummy.h)
set(SOURCES src/Dummy.cpp)

add_library(01_cmake_lib ${HEADERS} ${SOURCES})
target_include_directories(01_cmake_lib PUBLIC include)

add_executable(01_cmake src/main.cpp)
target_link_libraries(01_cmake 01_cmake_lib)

add_subdirectory(test)