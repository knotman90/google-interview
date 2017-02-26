cmake_minimum_required(VERSION 2.8)
project(projectEuler)

include_directories(./include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES euler.cpp)

add_executable(euler ${SOURCE_FILES})
target_link_libraries(euler gmp gmpxx)
