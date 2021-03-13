cmake_minimum_required(VERSION 3.15)
project(push_swap)

#set(CMAKE_CXX_STANDARD 98)
set (CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

add_executable(push_swap push_swap/main.c push_swap/instructions.c push_swap/algo.c push_swap/selection_sort.c push_swap/wtf_sort.c push_swap/bubble_sort.c utils/utils.c)