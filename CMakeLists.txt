cmake_minimum_required(VERSION 3.10)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_library(applibrary Graph.cpp Edge.cpp) 

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runMain main.cpp)
target_link_libraries(runMain ${GTEST_LIBRARIES} pthread applibrary) 

add_executable(runTests tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread applibrary) 