cmake_minimum_required(VERSION 3.10)

project(signal)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -O2 -std=c++20")

add_executable(signal src/main.cpp src/signal.cpp)
add_executable(measure src/measure.cpp src/signal.cpp)
add_executable(measure_corr src/measure_corr.cpp src/signal.cpp)
add_executable(correlation src/correlation.cpp src/signal.cpp)
add_executable(auto_correlation src/auto_correlation.cpp src/signal.cpp)
