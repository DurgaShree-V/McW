cmake_minimum_required(VERSION 3.21)

project(myApp
    VERSION 1.0
    DESCRIPTION "A brief CMake experiment"
    LANGUAGES CXX)

add_executable(myApp
    hello.cpp
    main.cpp)

