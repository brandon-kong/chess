cmake_minimum_required(VERSION 3.14)
cmake_policy(SET CMP0135 NEW)

project(chess)

file(GLOB TEST_SOURCES "test/*.test.cpp")
file(GLOB SOURCES "src/*.cpp")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    test_suite
    ${TEST_SOURCES}
    ${SOURCES}
)

add_executable(
    chess
    ${SOURCES}
)

target_link_libraries(
    test_suite
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_suite)