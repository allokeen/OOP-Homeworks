set(GOOGLETEST ../../googletest)

include_directories(${GOOGLETEST}/googletest/include)
link_directories(${GOOGLETEST}/build/lib)

set(TEST_HEADERS )
set(TEST_SOURCES src/DummyTest.cpp)

add_executable(01_cmake_test ${TEST_HEADERS} ${TEST_SOURCES})
target_include_directories(01_cmake_test PUBLIC include)
target_link_libraries(01_cmake_test 01_cmake_lib gtest gtest_main pthread)
