cmake_minimum_required(VERSION 2.8)

project(LinkedList)

set(EXTRA_WARNING_GNU "-g -O0 -march=native -Wextra -Wdisabled-optimization -Wunsafe-loop-optimizations -Wshadow -Wpointer-arith -Wcast-qual -Wunreachable-code")

find_package(GTest REQUIRED)


#global include for all targets
include_directories(bit_manipulation_test include)

link_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/source
)


file(GLOB SRC
    "include/*.h"
    "source/*.cpp"
    "test/*.cpp"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)



#tests
add_executable(bit_manipulation_test  test/bit_manipulation_test.cpp)
set_property(TARGET bit_manipulation_test PROPERTY CXX_STANDARD 17)
target_include_directories(bit_manipulation_test  PUBLIC ${GTEST_INCLUDE_DIRS})
target_link_libraries(bit_manipulation_test  pthread ${GTEST_BOTH_LIBRARIES})

