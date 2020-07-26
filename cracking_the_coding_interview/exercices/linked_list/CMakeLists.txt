cmake_minimum_required(VERSION 2.8)

find_package(GTest REQUIRED)


#global include for all targets
include_directories(linked_list_test include)


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
add_executable(linked_list_test  ${SRC})
set_property(TARGET linked_list_test PROPERTY CXX_STANDARD 17)
target_include_directories(linked_list_test  PUBLIC ${GTEST_INCLUDE_DIRS})
target_link_libraries(linked_list_test  pthread ${GTEST_BOTH_LIBRARIES})