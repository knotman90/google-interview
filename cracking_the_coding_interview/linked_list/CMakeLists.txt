cmake_minimum_required(VERSION 2.8)

project(LinkedList)

set(EXTRA_WARNING_GNU "-g -O0 -march=native -Wextra -Wdisabled-optimization -Wunsafe-loop-optimizations -Wshadow -Wpointer-arith -Wcast-qual -Wunreachable-code")

find_package(GTest REQUIRED)


#global include for all targets
include_directories(linked_list_test include)

#tests
add_executable(linked_list_test  test/linked_list_test.cpp)
set_property(TARGET linked_list_test PROPERTY CXX_STANDARD 17)
target_include_directories(linked_list_test  PUBLIC ${GTEST_INCLUDE_DIRS})
target_include_directories(linked_list_test  PUBLIC tests)
target_link_libraries(linked_list_test  pthread ${GTEST_BOTH_LIBRARIES})