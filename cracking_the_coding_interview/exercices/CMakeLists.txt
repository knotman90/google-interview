cmake_minimum_required(VERSION 2.8)

project(Exercices)

set(EXTRA_WARNING_GNU "-g -O0 -march=native -Wextra -Wdisabled-optimization -Wunsafe-loop-optimizations -Wshadow -Wpointer-arith -Wcast-qual -Wunreachable-code")

add_subdirectory(linked_list)


add_subdirectory(bit_manipulation)