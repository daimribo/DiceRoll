cmake_minimum_required(VERSION 3.10)

project(DiceRoll)

set(CMAKE_CXX_STANDARD 20)

# hook and configure dependencies
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(googletest EXCLUDE_FROM_ALL)
enable_testing()

add_executable(DiceRoll src/DnD.cpp)

add_executable(DiceRollTests test/test.cpp)

target_include_directories(DiceRollTests PUBLIC "src", "googletest/googletest/include")

target_include_directories(DiceRollTests PUBLIC ${CMAKE_SOURCE_DIR})
target_link_libraries(DiceRollTests gtest gtest_main)
