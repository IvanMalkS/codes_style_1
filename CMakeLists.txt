cmake_minimum_required(VERSION 3.29)
project(codes_style)

set(CMAKE_CXX_STANDARD 20)

add_executable(codes_style main.cpp
        1/1.cpp
        1/knapsack.cpp
        1/knapsack.h
        2/2.cpp
        2/king_path.cpp
        2/king_path.h
        3/3.cpp
        3/k_numbers.cpp
        3/k_numbers.h
        4/4.cpp
        4/expression_evaluator.cpp
        4/expression_evaluator.h)
