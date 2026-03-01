cmake_minimum_required(VERSION 3.10)

project(DiceRollTests)

add_executable(DiceRollTests test.cpp)

target_include_directories(DiceRollTests PUBLIC "../src")

# hook and configure dependencies
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory("../googletest" EXCLUDE_FROM_ALL)
enable_testing()