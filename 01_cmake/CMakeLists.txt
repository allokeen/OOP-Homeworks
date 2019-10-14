cmake_minimum_required(VERSION 3.13.3)
project(01_cmake)

include_directories(../googletest/googletest/googletest/include)
link_directories(../googletest/googletest/build/lib)

#------------pliki wykonywalne
add_executable( main.exe main.cpp Dummy.h)
add_executable( test.exe test.cpp Dummy.h)

#------------biblioteka libutils.a
add_library (utils STATIC main.cpp test.cpp)

#add_executable(01_cmake main.cpp Dummy.h test.cpp)

find_library(utils cmake-build-debug)
target_link_libraries(main.exe utils pthread)
target_link_libraries(test.exe gtest gtest_main pthread)