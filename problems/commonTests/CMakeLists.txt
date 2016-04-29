cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
find_package(GTest REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/..)


file(GLOB SRC
    "*.h"
    "*.cpp"
)

add_executable(sorttest  ${SRC} )
set_property(TARGET sorttest PROPERTY CXX_STANDARD 14)
target_link_libraries(sorttest  ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)
