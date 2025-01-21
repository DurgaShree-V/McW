cmake_minimum_required(VERSION 3.1)

project(main
    VERSION 1.0
    DESCRIPTION "A brief CMake experiment"
    LANGUAGES CXX)

add_executable(main
    main.cpp
    symtable_link.cpp)