cmake_minimum_required()

cmake_policy(SET CMP0048 NEW)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED true)

project(timer)

add_executable(timer timer.cpp)