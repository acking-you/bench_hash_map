cmake_minimum_required(VERSION 3.30)
project(cpp_map)

set(CMAKE_CXX_STANDARD 20)

option(USE_ABSL "Enable absl library and bench_swiss_table executable" OFF)

include_directories(src/)


add_executable(bench_std_hashmap src/bin/test_std_hashmap.cc)

if (USE_ABSL)
    message(STATUS "USE_ABSL=ON")
    find_package(absl CONFIG REQUIRED)
    add_executable(bench_swiss_table src/bin/test_swiss_table.cc)
    target_link_libraries(bench_swiss_table PRIVATE absl::flat_hash_map)
endif ()
