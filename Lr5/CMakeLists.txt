cmake_minimum_required(VERSION 3.5)

project(KMP)

set(CMAKE_CXX_STANDARD 11)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(patternSearch src/patternSearch.cpp src/kmp.cpp src/kmp.h)
add_executable(shiftSearch src/shiftSearch.cpp src/kmp.cpp src/kmp.h)
add_executable(naiveSearch src/naiveSearch.cpp src/kmp.cpp src/kmp.h)
add_executable(comparisonTest src/comparisonTest.cpp src/algComparison.cpp src/algComparison.h)

add_executable(testPrefix test/testPrefix.cpp test/kmpTest.cpp test/kmpTest.h src/kmp.cpp src/kmp.h)
add_executable(testPattern test/testPattern.cpp test/kmpTest.cpp test/kmpTest.h src/kmp.cpp src/kmp.h)
add_executable(testShift test/testShift.cpp test/kmpTest.cpp test/kmpTest.h src/kmp.cpp src/kmp.h)

target_link_libraries(testPrefix ${GTEST_LIBRARIES} pthread)
target_link_libraries(testPattern ${GTEST_LIBRARIES} pthread)
target_link_libraries(testShift ${GTEST_LIBRARIES} pthread)

add_test(TestPrefix "./testPrefix")
add_test(TestPattern "./testPattern")
add_test(TestShift "./testShift")
