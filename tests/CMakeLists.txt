cmake_minimum_required(VERSION 2.8)
project(vendor_unit_tests)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

#enable c++ 11
SET(CMAKE_CXX_FLAGS "-std=c++11 -g ${CMAKE_CXX_FLAGS}")

#add gtest
if (NOT TARGET gtest_main)
    add_subdirectory(googletest)
endif ()

include_directories(${gtest_SOURCE_DIR}/include ${gmock_SOURCE_DIR}/include)

#add files with new test here
set(test_sources simple_vendor_test.cpp stream_vendorio_test.cpp)

add_executable(poptests ${test_sources})
target_link_libraries(poptests gtest_main vendor gtest gmock)

