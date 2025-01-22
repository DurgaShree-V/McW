cmake_minimum_required(VERSION 3.5)

project(main
    VERSION 1.0
    DESCRIPTION "A brief CMake experiment"
    LANGUAGES CXX)

add_executable(main
    main.cpp
    symtable_link.cpp)

enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(googletest)

add_executable(symtable_test
    symtable_test.cpp
    symtable_link.cpp)

target_link_libraries(symtable_test
    gtest
    gtest_main)

add_test(NAME SymTableTest COMMAND symtable_test)
