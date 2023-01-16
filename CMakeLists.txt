cmake_minimum_required()

cmake_policy(SET CMP0048 NEW)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED true)

project(main)

add_executable(main main.cpp)
add_subdirectory(stopwatch)

target_link_libraries(main PUBLIC stopwatch)
target_include_directories(main PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/stopwatch"
)